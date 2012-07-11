/*
 * Generated by gdbus-codegen 2.33.3. DO NOT EDIT.
 *
 * The license of this code is the same as for the source it was derived from.
 */

#ifndef __DBUS_USER_H__
#define __DBUS_USER_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for org.freedesktop.Accounts.User */

#define TYPE_ACCOUNTS_USER (accounts_user_get_type ())
#define ACCOUNTS_USER(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_ACCOUNTS_USER, AccountsUser))
#define IS_ACCOUNTS_USER(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_ACCOUNTS_USER))
#define ACCOUNTS_USER_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), TYPE_ACCOUNTS_USER, AccountsUserIface))

struct _AccountsUser;
typedef struct _AccountsUser AccountsUser;
typedef struct _AccountsUserIface AccountsUserIface;

struct _AccountsUserIface
{
  GTypeInterface parent_iface;



  gboolean (*handle_set_account_type) (
    AccountsUser *object,
    GDBusMethodInvocation *invocation,
    gint arg_accountType);

  gboolean (*handle_set_automatic_login) (
    AccountsUser *object,
    GDBusMethodInvocation *invocation,
    gboolean arg_enabled);

  gboolean (*handle_set_email) (
    AccountsUser *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_email);

  gboolean (*handle_set_home_directory) (
    AccountsUser *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_homedir);

  gboolean (*handle_set_icon_file) (
    AccountsUser *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_filename);

  gboolean (*handle_set_language) (
    AccountsUser *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_language);

  gboolean (*handle_set_location) (
    AccountsUser *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_location);

  gboolean (*handle_set_locked) (
    AccountsUser *object,
    GDBusMethodInvocation *invocation,
    gboolean arg_locked);

  gboolean (*handle_set_password) (
    AccountsUser *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_password,
    const gchar *arg_hint);

  gboolean (*handle_set_password_mode) (
    AccountsUser *object,
    GDBusMethodInvocation *invocation,
    gint arg_mode);

  gboolean (*handle_set_real_name) (
    AccountsUser *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_name);

  gboolean (*handle_set_shell) (
    AccountsUser *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_shell);

  gboolean (*handle_set_user_name) (
    AccountsUser *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_name);

  gboolean (*handle_set_xsession) (
    AccountsUser *object,
    GDBusMethodInvocation *invocation,
    const gchar *arg_x_session);

  gint  (*get_account_type) (AccountsUser *object);

  gboolean  (*get_automatic_login) (AccountsUser *object);

  const gchar * (*get_email) (AccountsUser *object);

  const gchar * (*get_home_directory) (AccountsUser *object);

  const gchar * (*get_icon_file) (AccountsUser *object);

  const gchar * (*get_language) (AccountsUser *object);

  const gchar * (*get_location) (AccountsUser *object);

  gboolean  (*get_locked) (AccountsUser *object);

  guint64  (*get_login_frequency) (AccountsUser *object);

  const gchar * (*get_password_hint) (AccountsUser *object);

  gint  (*get_password_mode) (AccountsUser *object);

  const gchar * (*get_real_name) (AccountsUser *object);

  const gchar * (*get_shell) (AccountsUser *object);

  gboolean  (*get_system_account) (AccountsUser *object);

  guint64  (*get_uid) (AccountsUser *object);

  const gchar * (*get_user_name) (AccountsUser *object);

  const gchar * (*get_xsession) (AccountsUser *object);

  void (*changed) (
    AccountsUser *object);

};

GType accounts_user_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *accounts_user_interface_info (void);
guint accounts_user_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void accounts_user_complete_set_user_name (
    AccountsUser *object,
    GDBusMethodInvocation *invocation);

void accounts_user_complete_set_real_name (
    AccountsUser *object,
    GDBusMethodInvocation *invocation);

void accounts_user_complete_set_email (
    AccountsUser *object,
    GDBusMethodInvocation *invocation);

void accounts_user_complete_set_language (
    AccountsUser *object,
    GDBusMethodInvocation *invocation);

void accounts_user_complete_set_xsession (
    AccountsUser *object,
    GDBusMethodInvocation *invocation);

void accounts_user_complete_set_location (
    AccountsUser *object,
    GDBusMethodInvocation *invocation);

void accounts_user_complete_set_home_directory (
    AccountsUser *object,
    GDBusMethodInvocation *invocation);

void accounts_user_complete_set_shell (
    AccountsUser *object,
    GDBusMethodInvocation *invocation);

void accounts_user_complete_set_icon_file (
    AccountsUser *object,
    GDBusMethodInvocation *invocation);

void accounts_user_complete_set_locked (
    AccountsUser *object,
    GDBusMethodInvocation *invocation);

void accounts_user_complete_set_account_type (
    AccountsUser *object,
    GDBusMethodInvocation *invocation);

void accounts_user_complete_set_password_mode (
    AccountsUser *object,
    GDBusMethodInvocation *invocation);

void accounts_user_complete_set_password (
    AccountsUser *object,
    GDBusMethodInvocation *invocation);

void accounts_user_complete_set_automatic_login (
    AccountsUser *object,
    GDBusMethodInvocation *invocation);



/* D-Bus signal emissions functions: */
void accounts_user_emit_changed (
    AccountsUser *object);



/* D-Bus method calls: */
void accounts_user_call_set_user_name (
    AccountsUser *proxy,
    const gchar *arg_name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_user_call_set_user_name_finish (
    AccountsUser *proxy,
    GAsyncResult *res,
    GError **error);

gboolean accounts_user_call_set_user_name_sync (
    AccountsUser *proxy,
    const gchar *arg_name,
    GCancellable *cancellable,
    GError **error);

void accounts_user_call_set_real_name (
    AccountsUser *proxy,
    const gchar *arg_name,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_user_call_set_real_name_finish (
    AccountsUser *proxy,
    GAsyncResult *res,
    GError **error);

gboolean accounts_user_call_set_real_name_sync (
    AccountsUser *proxy,
    const gchar *arg_name,
    GCancellable *cancellable,
    GError **error);

void accounts_user_call_set_email (
    AccountsUser *proxy,
    const gchar *arg_email,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_user_call_set_email_finish (
    AccountsUser *proxy,
    GAsyncResult *res,
    GError **error);

gboolean accounts_user_call_set_email_sync (
    AccountsUser *proxy,
    const gchar *arg_email,
    GCancellable *cancellable,
    GError **error);

void accounts_user_call_set_language (
    AccountsUser *proxy,
    const gchar *arg_language,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_user_call_set_language_finish (
    AccountsUser *proxy,
    GAsyncResult *res,
    GError **error);

gboolean accounts_user_call_set_language_sync (
    AccountsUser *proxy,
    const gchar *arg_language,
    GCancellable *cancellable,
    GError **error);

void accounts_user_call_set_xsession (
    AccountsUser *proxy,
    const gchar *arg_x_session,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_user_call_set_xsession_finish (
    AccountsUser *proxy,
    GAsyncResult *res,
    GError **error);

gboolean accounts_user_call_set_xsession_sync (
    AccountsUser *proxy,
    const gchar *arg_x_session,
    GCancellable *cancellable,
    GError **error);

void accounts_user_call_set_location (
    AccountsUser *proxy,
    const gchar *arg_location,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_user_call_set_location_finish (
    AccountsUser *proxy,
    GAsyncResult *res,
    GError **error);

gboolean accounts_user_call_set_location_sync (
    AccountsUser *proxy,
    const gchar *arg_location,
    GCancellable *cancellable,
    GError **error);

void accounts_user_call_set_home_directory (
    AccountsUser *proxy,
    const gchar *arg_homedir,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_user_call_set_home_directory_finish (
    AccountsUser *proxy,
    GAsyncResult *res,
    GError **error);

gboolean accounts_user_call_set_home_directory_sync (
    AccountsUser *proxy,
    const gchar *arg_homedir,
    GCancellable *cancellable,
    GError **error);

void accounts_user_call_set_shell (
    AccountsUser *proxy,
    const gchar *arg_shell,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_user_call_set_shell_finish (
    AccountsUser *proxy,
    GAsyncResult *res,
    GError **error);

gboolean accounts_user_call_set_shell_sync (
    AccountsUser *proxy,
    const gchar *arg_shell,
    GCancellable *cancellable,
    GError **error);

void accounts_user_call_set_icon_file (
    AccountsUser *proxy,
    const gchar *arg_filename,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_user_call_set_icon_file_finish (
    AccountsUser *proxy,
    GAsyncResult *res,
    GError **error);

gboolean accounts_user_call_set_icon_file_sync (
    AccountsUser *proxy,
    const gchar *arg_filename,
    GCancellable *cancellable,
    GError **error);

void accounts_user_call_set_locked (
    AccountsUser *proxy,
    gboolean arg_locked,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_user_call_set_locked_finish (
    AccountsUser *proxy,
    GAsyncResult *res,
    GError **error);

gboolean accounts_user_call_set_locked_sync (
    AccountsUser *proxy,
    gboolean arg_locked,
    GCancellable *cancellable,
    GError **error);

void accounts_user_call_set_account_type (
    AccountsUser *proxy,
    gint arg_accountType,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_user_call_set_account_type_finish (
    AccountsUser *proxy,
    GAsyncResult *res,
    GError **error);

gboolean accounts_user_call_set_account_type_sync (
    AccountsUser *proxy,
    gint arg_accountType,
    GCancellable *cancellable,
    GError **error);

void accounts_user_call_set_password_mode (
    AccountsUser *proxy,
    gint arg_mode,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_user_call_set_password_mode_finish (
    AccountsUser *proxy,
    GAsyncResult *res,
    GError **error);

gboolean accounts_user_call_set_password_mode_sync (
    AccountsUser *proxy,
    gint arg_mode,
    GCancellable *cancellable,
    GError **error);

void accounts_user_call_set_password (
    AccountsUser *proxy,
    const gchar *arg_password,
    const gchar *arg_hint,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_user_call_set_password_finish (
    AccountsUser *proxy,
    GAsyncResult *res,
    GError **error);

gboolean accounts_user_call_set_password_sync (
    AccountsUser *proxy,
    const gchar *arg_password,
    const gchar *arg_hint,
    GCancellable *cancellable,
    GError **error);

void accounts_user_call_set_automatic_login (
    AccountsUser *proxy,
    gboolean arg_enabled,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean accounts_user_call_set_automatic_login_finish (
    AccountsUser *proxy,
    GAsyncResult *res,
    GError **error);

gboolean accounts_user_call_set_automatic_login_sync (
    AccountsUser *proxy,
    gboolean arg_enabled,
    GCancellable *cancellable,
    GError **error);



/* D-Bus property accessors: */
guint64 accounts_user_get_uid (AccountsUser *object);
void accounts_user_set_uid (AccountsUser *object, guint64 value);

const gchar *accounts_user_get_user_name (AccountsUser *object);
gchar *accounts_user_dup_user_name (AccountsUser *object);
void accounts_user_set_user_name (AccountsUser *object, const gchar *value);

const gchar *accounts_user_get_real_name (AccountsUser *object);
gchar *accounts_user_dup_real_name (AccountsUser *object);
void accounts_user_set_real_name (AccountsUser *object, const gchar *value);

gint accounts_user_get_account_type (AccountsUser *object);
void accounts_user_set_account_type (AccountsUser *object, gint value);

const gchar *accounts_user_get_home_directory (AccountsUser *object);
gchar *accounts_user_dup_home_directory (AccountsUser *object);
void accounts_user_set_home_directory (AccountsUser *object, const gchar *value);

const gchar *accounts_user_get_shell (AccountsUser *object);
gchar *accounts_user_dup_shell (AccountsUser *object);
void accounts_user_set_shell (AccountsUser *object, const gchar *value);

const gchar *accounts_user_get_email (AccountsUser *object);
gchar *accounts_user_dup_email (AccountsUser *object);
void accounts_user_set_email (AccountsUser *object, const gchar *value);

const gchar *accounts_user_get_language (AccountsUser *object);
gchar *accounts_user_dup_language (AccountsUser *object);
void accounts_user_set_language (AccountsUser *object, const gchar *value);

const gchar *accounts_user_get_xsession (AccountsUser *object);
gchar *accounts_user_dup_xsession (AccountsUser *object);
void accounts_user_set_xsession (AccountsUser *object, const gchar *value);

const gchar *accounts_user_get_location (AccountsUser *object);
gchar *accounts_user_dup_location (AccountsUser *object);
void accounts_user_set_location (AccountsUser *object, const gchar *value);

guint64 accounts_user_get_login_frequency (AccountsUser *object);
void accounts_user_set_login_frequency (AccountsUser *object, guint64 value);

const gchar *accounts_user_get_icon_file (AccountsUser *object);
gchar *accounts_user_dup_icon_file (AccountsUser *object);
void accounts_user_set_icon_file (AccountsUser *object, const gchar *value);

gboolean accounts_user_get_locked (AccountsUser *object);
void accounts_user_set_locked (AccountsUser *object, gboolean value);

gint accounts_user_get_password_mode (AccountsUser *object);
void accounts_user_set_password_mode (AccountsUser *object, gint value);

const gchar *accounts_user_get_password_hint (AccountsUser *object);
gchar *accounts_user_dup_password_hint (AccountsUser *object);
void accounts_user_set_password_hint (AccountsUser *object, const gchar *value);

gboolean accounts_user_get_automatic_login (AccountsUser *object);
void accounts_user_set_automatic_login (AccountsUser *object, gboolean value);

gboolean accounts_user_get_system_account (AccountsUser *object);
void accounts_user_set_system_account (AccountsUser *object, gboolean value);


/* ---- */

#define TYPE_ACCOUNTS_USER_PROXY (accounts_user_proxy_get_type ())
#define ACCOUNTS_USER_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_ACCOUNTS_USER_PROXY, AccountsUserProxy))
#define ACCOUNTS_USER_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_ACCOUNTS_USER_PROXY, AccountsUserProxyClass))
#define ACCOUNTS_USER_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_ACCOUNTS_USER_PROXY, AccountsUserProxyClass))
#define IS_ACCOUNTS_USER_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_ACCOUNTS_USER_PROXY))
#define IS_ACCOUNTS_USER_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_ACCOUNTS_USER_PROXY))

typedef struct _AccountsUserProxy AccountsUserProxy;
typedef struct _AccountsUserProxyClass AccountsUserProxyClass;
typedef struct _AccountsUserProxyPrivate AccountsUserProxyPrivate;

struct _AccountsUserProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  AccountsUserProxyPrivate *priv;
};

struct _AccountsUserProxyClass
{
  GDBusProxyClass parent_class;
};

GType accounts_user_proxy_get_type (void) G_GNUC_CONST;

void accounts_user_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
AccountsUser *accounts_user_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
AccountsUser *accounts_user_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void accounts_user_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
AccountsUser *accounts_user_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
AccountsUser *accounts_user_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define TYPE_ACCOUNTS_USER_SKELETON (accounts_user_skeleton_get_type ())
#define ACCOUNTS_USER_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), TYPE_ACCOUNTS_USER_SKELETON, AccountsUserSkeleton))
#define ACCOUNTS_USER_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), TYPE_ACCOUNTS_USER_SKELETON, AccountsUserSkeletonClass))
#define ACCOUNTS_USER_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), TYPE_ACCOUNTS_USER_SKELETON, AccountsUserSkeletonClass))
#define IS_ACCOUNTS_USER_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), TYPE_ACCOUNTS_USER_SKELETON))
#define IS_ACCOUNTS_USER_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), TYPE_ACCOUNTS_USER_SKELETON))

typedef struct _AccountsUserSkeleton AccountsUserSkeleton;
typedef struct _AccountsUserSkeletonClass AccountsUserSkeletonClass;
typedef struct _AccountsUserSkeletonPrivate AccountsUserSkeletonPrivate;

struct _AccountsUserSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  AccountsUserSkeletonPrivate *priv;
};

struct _AccountsUserSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType accounts_user_skeleton_get_type (void) G_GNUC_CONST;

AccountsUser *accounts_user_skeleton_new (void);


G_END_DECLS

#endif /* __DBUS_USER_H__ */
