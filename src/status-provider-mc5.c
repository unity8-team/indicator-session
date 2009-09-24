/*
A small wrapper utility to load indicators and put them as menu items
into the gnome-panel using it's applet interface.

Copyright 2009 Canonical Ltd.

Authors:
    Ted Gould <ted@canonical.com>

This program is free software: you can redistribute it and/or modify it 
under the terms of the GNU General Public License version 3, as published 
by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but 
WITHOUT ANY WARRANTY; without even the implied warranties of 
MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR 
PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along 
with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "libempathy/empathy-account-manager.h"

#include "status-provider.h"
#include "status-provider-mc5.h"
#include "status-provider-mc5-marshal.h"

#include <dbus/dbus-glib.h>

static gchar * sp_to_mc_map[STATUS_PROVIDER_STATUS_LAST] = {
	/* STATUS_PROVIDER_STATUS_ONLINE,  */  "available",
	/* STATUS_PROVIDER_STATUS_AWAY,    */  "away",
	/* STATUS_PROVIDER_STATUS_DND      */  "busy",
	/* STATUS_PROVIDER_STATUS_INVISIBLE*/  "hidden",
	/* STATUS_PROVIDER_STATUS_OFFLINE  */  "offline",
	/* STATUS_PROVIDER_STATUS_DISCONNECTED*/NULL
};

static TpConnectionPresenceType sp_to_tp_map[STATUS_PROVIDER_STATUS_LAST] = {
	/* STATUS_PROVIDER_STATUS_ONLINE,  */    TP_CONNECTION_PRESENCE_TYPE_AVAILABLE,
	/* STATUS_PROVIDER_STATUS_AWAY,    */    TP_CONNECTION_PRESENCE_TYPE_AWAY,
	/* STATUS_PROVIDER_STATUS_DND      */    TP_CONNECTION_PRESENCE_TYPE_BUSY,
	/* STATUS_PROVIDER_STATUS_INVISIBLE*/    TP_CONNECTION_PRESENCE_TYPE_HIDDEN,
	/* STATUS_PROVIDER_STATUS_OFFLINE  */    TP_CONNECTION_PRESENCE_TYPE_OFFLINE,
	/* STATUS_PROVIDER_STATUS_DISCONNECTED*/ TP_CONNECTION_PRESENCE_TYPE_UNSET
};

static StatusProviderStatus tp_to_sp_map[TP_CONNECTION_PRESENCE_TYPE_ERROR + 1] = {
	/* TP_CONNECTION_PRESENCE_TYPE_UNSET          */  STATUS_PROVIDER_STATUS_DISCONNECTED,
	/* TP_CONNECTION_PRESENCE_TYPE_OFFLINE        */  STATUS_PROVIDER_STATUS_OFFLINE,
	/* TP_CONNECTION_PRESENCE_TYPE_AVAILABLE      */  STATUS_PROVIDER_STATUS_ONLINE,
	/* TP_CONNECTION_PRESENCE_TYPE_AWAY           */  STATUS_PROVIDER_STATUS_AWAY,
	/* TP_CONNECTION_PRESENCE_TYPE_EXTENDED_AWAY  */  STATUS_PROVIDER_STATUS_AWAY,
	/* TP_CONNECTION_PRESENCE_TYPE_HIDDEN         */  STATUS_PROVIDER_STATUS_INVISIBLE,
	/* TP_CONNECTION_PRESENCE_TYPE_BUSY           */  STATUS_PROVIDER_STATUS_DND,
	/* TP_CONNECTION_PRESENCE_TYPE_UNKNOWN        */  STATUS_PROVIDER_STATUS_DISCONNECTED,
	/* TP_CONNECTION_PRESENCE_TYPE_ERROR          */  STATUS_PROVIDER_STATUS_DISCONNECTED
};

typedef struct _StatusProviderMC5Private StatusProviderMC5Private;
struct _StatusProviderMC5Private {
	EmpathyAccountManager * manager;
	StatusProviderStatus status;
};

#define STATUS_PROVIDER_MC5_GET_PRIVATE(o) \
(G_TYPE_INSTANCE_GET_PRIVATE ((o), STATUS_PROVIDER_MC5_TYPE, StatusProviderMC5Private))

/* Prototypes */
/* GObject stuff */
static void status_provider_mc5_class_init (StatusProviderMC5Class *klass);
static void status_provider_mc5_init       (StatusProviderMC5 *self);
static void status_provider_mc5_dispose    (GObject *object);
static void status_provider_mc5_finalize   (GObject *object);
/* Internal Funcs */
static void set_status (StatusProvider * sp, StatusProviderStatus status);
static StatusProviderStatus get_status (StatusProvider * sp);
static void presence_changed (EmpathyAccountManager * eam, guint type, const gchar * type_str, const gchar * message, StatusProviderMC5 * sp);

G_DEFINE_TYPE (StatusProviderMC5, status_provider_mc5, STATUS_PROVIDER_TYPE);

/* Create the class.  We over ride a few functions but nothing
   really shocking.  Most interesting is the set and get status. */
static void
status_provider_mc5_class_init (StatusProviderMC5Class *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	g_type_class_add_private (klass, sizeof (StatusProviderMC5Private));

	object_class->dispose = status_provider_mc5_dispose;
	object_class->finalize = status_provider_mc5_finalize;

	StatusProviderClass * spclass = STATUS_PROVIDER_CLASS(klass);

	spclass->set_status = set_status;
	spclass->get_status = get_status;

	return;
}

/* Creating an instance of the status provider.  We set the variables
   and create an EmpathyAccountManager object.  It does all the hard
   work in this module of tracking MissionControl and enumerating the
   accounts and all that jazz. */
static void
status_provider_mc5_init (StatusProviderMC5 *self)
{
	StatusProviderMC5Private * priv = STATUS_PROVIDER_MC5_GET_PRIVATE(self);

	priv->status = STATUS_PROVIDER_STATUS_OFFLINE;
	priv->manager = EMPATHY_ACCOUNT_MANAGER(g_object_new(EMPATHY_TYPE_ACCOUNT_MANAGER, NULL));

	g_signal_connect(G_OBJECT(priv->manager), "global-presence-changed", G_CALLBACK(presence_changed), self);

	return;
}

/* Unref the account manager and move on.  Sadly, we're
   leaving the show. */
static void
status_provider_mc5_dispose (GObject *object)
{
	StatusProviderMC5Private * priv = STATUS_PROVIDER_MC5_GET_PRIVATE(object);

	if (priv->manager != NULL) {
		g_object_unref(priv->manager);
		priv->manager = NULL;
	}

	G_OBJECT_CLASS (status_provider_mc5_parent_class)->dispose (object);
	return;
}

/* Pass to superclass */
static void
status_provider_mc5_finalize (GObject *object)
{

	G_OBJECT_CLASS (status_provider_mc5_parent_class)->finalize (object);
	return;
}

/**
	status_provider_mc5_new:

	Creates a new #StatusProviderMC5 object.  No parameters or anything
	like that.  Just a convience function.

	Return value: A new instance of #StatusProviderMC5
*/
StatusProvider *
status_provider_mc5_new (void)
{
	return STATUS_PROVIDER(g_object_new(STATUS_PROVIDER_MC5_TYPE, NULL));
}

/* Setting the status in the empathy account manager.  We're
   basically requesting a global status.  This may or may not
   get applied to all accounts.  It's really the best we can
   hope to do. */
static void
set_status (StatusProvider * sp, StatusProviderStatus status)
{
	StatusProviderMC5Private * priv = STATUS_PROVIDER_MC5_GET_PRIVATE(sp);
	if (priv->manager == NULL) {
		priv->status = STATUS_PROVIDER_STATUS_DISCONNECTED;
		return;
	}

	empathy_account_manager_request_global_presence(priv->manager, sp_to_tp_map[status], sp_to_mc_map[status], "");

	return;
}

/* Gets the status, uses the cached value that we have.  Asking
   would just be painful. */
static StatusProviderStatus
get_status (StatusProvider * sp)
{
	g_return_val_if_fail(IS_STATUS_PROVIDER_MC5(sp), STATUS_PROVIDER_STATUS_DISCONNECTED);
	StatusProviderMC5Private * priv = STATUS_PROVIDER_MC5_GET_PRIVATE(sp);

	if (priv->manager == NULL) {
		return STATUS_PROVIDER_STATUS_DISCONNECTED;
	}

	return priv->status;
}

/* A signal handler for when the EmpatyAccountManager believes
   that the global status has changed.  It roughly calculates this
   by finding the most available of all accounts that are active. */
static void
presence_changed (EmpathyAccountManager * eam, guint type, const gchar * type_str, const gchar * message, StatusProviderMC5 * sp)
{
	StatusProviderMC5Private * priv = STATUS_PROVIDER_MC5_GET_PRIVATE(sp);

	g_debug("MC5 Status changed: %d %s %s", type, type_str, message);

	if (priv->status != tp_to_sp_map[type]) {
		priv->status = tp_to_sp_map[type];
		g_signal_emit(G_OBJECT(sp), STATUS_PROVIDER_SIGNAL_STATUS_CHANGED_ID, 0, priv->status, TRUE);
	}

	return;
}
