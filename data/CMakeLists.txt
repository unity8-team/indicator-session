find_package(GSettings REQUIRED)

##
##  GSettings schema
##

set (SCHEMA_NAME "com.canonical.indicator.session.gschema.xml")
set (SCHEMA_FILE "${CMAKE_CURRENT_BINARY_DIR}/${SCHEMA_NAME}")
set (SCHEMA_FILE_IN "${CMAKE_CURRENT_SOURCE_DIR}/${SCHEMA_NAME}.in")

# generate the .xml file using intltool
set (ENV{LC_ALL} "C") 
execute_process (COMMAND intltool-merge -quiet --xml-style --utf8 --no-translations "${SCHEMA_FILE_IN}" "${SCHEMA_FILE}")

# let UseGSettings do the rest
add_schema (${SCHEMA_NAME})

##
##  Systemd Unit File
##

# where to install
# Uncomment when we drop Vivid
# pkg_get_variable(SYSTEMD_USER_DIR systemd systemduserunitdir)
set (SYSTEMD_USER_DIR "/usr/lib/systemd/user")
message (STATUS "${SYSTEMD_USER_DIR} is the systemd user unit file install dir")

set (SYSTEMD_USER_NAME "${CMAKE_PROJECT_NAME}.service")
set (SYSTEMD_USER_FILE "${CMAKE_CURRENT_BINARY_DIR}/${SYSTEMD_USER_NAME}")
set (SYSTEMD_USER_FILE_IN "${CMAKE_CURRENT_SOURCE_DIR}/${SYSTEMD_USER_NAME}.in")

# build it
set (pkglibexecdir "${CMAKE_INSTALL_FULL_PKGLIBEXECDIR}")
configure_file ("${SYSTEMD_USER_FILE_IN}" "${SYSTEMD_USER_FILE}")

# install it
install (FILES "${SYSTEMD_USER_FILE}"
         DESTINATION "${SYSTEMD_USER_DIR}")

##
##  Upstart systemd override Job File
##

set (UPSTART_SYSTEMD_OVERRIDE_DIR "${CMAKE_INSTALL_FULL_DATADIR}/upstart/systemd-session/upstart")
message (STATUS "${UPSTART_SYSTEMD_OVERRIDE_DIR} is the Upstart override Job File for systemd dir")

install (FILES "${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_PROJECT_NAME}.override"
         DESTINATION "${UPSTART_SYSTEMD_OVERRIDE_DIR}")

##
##  Upstart Config File
##

# where to install
set (UPSTART_JOB_DIR "${CMAKE_INSTALL_FULL_DATADIR}/upstart/sessions")
message (STATUS "${UPSTART_JOB_DIR} is the Upstart Job install dir")

set (UPSTART_JOB_NAME "${CMAKE_PROJECT_NAME}.conf")
set (UPSTART_JOB_FILE "${CMAKE_CURRENT_BINARY_DIR}/${UPSTART_JOB_NAME}")
set (UPSTART_JOB_FILE_IN "${CMAKE_CURRENT_SOURCE_DIR}/${UPSTART_JOB_NAME}.in")

# build it
set (pkglibexecdir "${CMAKE_INSTALL_FULL_PKGLIBEXECDIR}")
configure_file ("${UPSTART_JOB_FILE_IN}" "${UPSTART_JOB_FILE}")

# install it
install (FILES "${UPSTART_JOB_FILE}"
         DESTINATION "${UPSTART_JOB_DIR}")


##
##  Unity Indicator File
##

# where to install
set (UNITY_INDICATOR_DIR "${CMAKE_INSTALL_FULL_DATAROOTDIR}/unity/indicators")
message (STATUS "${UNITY_INDICATOR_DIR} is the Unity Indicator install dir")

set (UNITY_INDICATOR_NAME "com.canonical.indicator.session")
set (UNITY_INDICATOR_FILE "${CMAKE_CURRENT_SOURCE_DIR}/${UNITY_INDICATOR_NAME}")

install (FILES "${UNITY_INDICATOR_FILE}"
         DESTINATION "${UNITY_INDICATOR_DIR}")


##
##  Icons
##

# where to install
set (ICON_DIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATADIR}/icons/hicolor")
message (STATUS "${ICON_DIR} is the Icon install dir")

install (DIRECTORY icons
         icons/16x16
         icons/22x22
         icons/24x24
         icons/32x32
         icons/scalable
         DESTINATION "${ICON_DIR}"
         FILES_MATCHING PATTERN "*.png" PATTERN "*.svg")

install(CODE "execute_process (COMMAND gtk-update-icon-cache -t -f ${ICON_DIR})"
        CODE "message (STATUS \"Updating icon cache\")")

