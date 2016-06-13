#ifndef DOXYGEN_DOCUMENTATION_H
#define DOXYGEN_DOCUMENTATION_H

/**
 * @mainpage Main Page of the DaTiCh documentation.
 * @tableofcontents
 * @section basic_sec Introduction
 * With DaTiCh, a shorten for DateTimeChanger, its possible to change/receive the system datetime.
 * Furthermore it can act as a standalone app like the gui implementation of the operating system.
 * The features will be a complete control over the appearance of the clock/calender.
 * @subsection features_subsec Features
 * @li Can be used as console app to control system date/time via arguments
 * 
 * @image html terminal.png
 * 
 * @li Can be used as standalone app.
 * 
 * @image html wizard.png
 * 
 * @li Fully control over the appearance of the clock/calender.
 * 
 * @image html options.png
 * 
 * @li Accessible menu over trayicon.
 * 
 * @image html tray.png
 *
 * @section qt_sec Qt
 * The application is writting under Qt5.X.
 * It uses the Qt Resource System, QSplashScreen, QSystemTrayIcon, Qt Examples and other Qt things.
 *
 * @section language_sec Languages
 * Currently there are two languages available: German and English-UK
 * The 'language' folder contains a 'source-to-ts.bat' and a 'ts-to-qm.bat'.
 * You can use them to easily generate the ts-files from the project file and the qm-files from the ts-files.
 * You can also load the project file within Qt Creator and navigate to Tools -> Extern -> Linguist
 * If you are using the bat-files remember that you need to change the Qt path to your system environment.
 *
 * @section installation_sec Installation
 * To create a setup file of the executeable application file and its DLLs you will find a folder named 'installer'.
 * This folder contains a file called 'Installer.iss' which is a configuration file for InnoSetup.
 * You can use this file to generate your setup file.
 *
 * @section docu_sec Documentation
 * The documentation was created by using Doxygen. The project itself has a folder named 'documentation'.
 * The folder contains a file named DoxyGenfile which is a configuration file for Doxygen.
 * You can recreate or change the documentation by using this file or the created bat-file.
 * The bat-file will help you a bit to create the documentation more easily.
 * If you are using the DoxyGenfile remember to change the following variables to your system environment:
 * @li QHG_LOCATION
 * @li PROJECT_LOGO
 * @li INPUT
 * @li OUTPUT_DIRECTORY
 * @li TAGFILES
 *
 * You can you the qch-file to include the documentation within Qt Creator: Tools->Options->Help->Documentation->Add..
 * @image html qt-help.png
 *
 * @section links_sec Links
 * @li @ref todo-list
 *
*/

#endif // DOXYGEN_DOCUMENTATION_H
