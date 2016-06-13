# --------------------------------------------------------
# Project: DateTimeChanger
# ShortName: DaTiCh
# --------------------------------------------------------
# Author: Mike Knappe
# Version: v.0.1.0.0
#
# --------------------------------------------------------


# --------------------------------------------------------
# Versions
# --------------------------------------------------------
# + v.0.1.0.0: Fundament of the Creator
# --------------------------------------------------------


# --------------------------------------------------------
# Info
# --------------------------------------------------------
#
# --------------------------------------------------------


# --------------------------------------------------------
# Project Defines
# --------------------------------------------------------
    PROJECTNAME = DaTiCh

    PROJECT_DIR = $$_PRO_FILE_PWD_/

    PROJECT_VERSION = v.0.1.0.0
# --------------------------------------------------------


# --------------------------------------------------------
# Compilation Name
# --------------------------------------------------------
    TARGET = $${PROJECTNAME}
# --------------------------------------------------------


# --------------------------------------------------------
# Qt Settings
# --------------------------------------------------------
    QT += core gui widgets
# --------------------------------------------------------


# --------------------------------------------------------
# Qt Compile Settings
# --------------------------------------------------------
    CONFIG += console
    TEMPLATE = app
    QMAKE_CXXFLAGS = -std=c++0x              #C++11 define
# --------------------------------------------------------


# --------------------------------------------------------
# Project Defines
# --------------------------------------------------------
    DEFINES += WIN32
    DEFINES += APP_VERSION=\\\"0.1.0.0\\\"
    DEFINES += APP_NAME=\\\"DaTiCh\\\"
# --------------------------------------------------------


# --------------------------------------------------------
# Project SOURCES
# --------------------------------------------------------
SOURCES +=  sourcecode/main.cpp \
            sourcecode/mainwindow.cpp \
            sourcecode/analogclock.cpp \
            sourcecode/m_colorbutton.cpp \
            sourcecode/m_groupbox.cpp \
            sourcecode/m_clockpage.cpp \
            sourcecode/m_calendarpage.cpp \
            sourcecode/m_optionsdialog.cpp \
            sourcecode/m_datetimedialog.cpp \
            sourcecode/m_systemdatetime.cpp \
            sourcecode/m_console.cpp \
            sourcecode/m_consolearguments.cpp \
            sourcecode/m_consoleappearance.cpp \
            sourcecode/m_widget.cpp \
            sourcecode/m_languagehandler.cpp \
    sourcecode/m_splashscreen.cpp
# --------------------------------------------------------


# --------------------------------------------------------
# Project Headers
# --------------------------------------------------------
HEADERS  += sourcecode/mainwindow.h \
            sourcecode/analogclock.h \
            sourcecode/m_colorbutton.h \
            sourcecode/m_clockstruct.h \
            sourcecode/m_groupbox.h \
            sourcecode/m_clockpage.h \
            sourcecode/m_calendarpage.h \
            sourcecode/m_optionsdialog.h \
            sourcecode/m_datetimedialog.h \
            sourcecode/m_systemdatetime.h \
            sourcecode/m_console.h \
            sourcecode/m_consolearguments.h \
            sourcecode/m_consoleappearance.h \
            sourcecode/m_widget.h \
            sourcecode/m_languagehandler.h \
    sourcecode/m_splashscreen.h
# --------------------------------------------------------


# --------------------------------------------------------
# Project Includes
# --------------------------------------------------------
#
# --------------------------------------------------------


# --------------------------------------------------------
# Project Depends
# --------------------------------------------------------
    DEPENDPATH +=
# --------------------------------------------------------


# --------------------------------------------------------
# Project Languages
# --------------------------------------------------------
    TRANSLATIONS += languages/German.ts \
                    languages/English-UK.ts
# --------------------------------------------------------


# --------------------------------------------------------
# Qt Project Settings
# --------------------------------------------------------
    PROJECT_SETTINGS_DIR = $${PROJECT_DIR}project_settings/
    include( $${PROJECT_SETTINGS_DIR}Project_Compile_Settings.pri )
    include( $${PROJECT_SETTINGS_DIR}Project_Ressources.pri )
    include( $${PROJECT_SETTINGS_DIR}Project_Languages.pri )
# --------------------------------------------------------
