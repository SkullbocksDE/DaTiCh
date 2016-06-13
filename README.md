# DaTiCh
DaTiCh (Date Time Changer) does what it does .. to change the datetime.

![alt tag](https://github.com/SkullbocksDE/DaTiCh/blob/master/materials/images/appicon.png)
Please pull the documentation for more information: [Documentation](documentation/html)

With DaTiCh, a shorten for DateTimeChanger, it's possible to change/receive the system datetime. Furthermore it can act as a standalone app like the gui implementation of the operating system. The features will be a complete control over the appearance of the clock/calender.


## Features
- Can be used as console app to control system date/time via arguments
- ![alt tag](https://github.com/SkullbocksDE/DaTiCh/blob/master/documentation/images/terminal.png)
- Can be used as standalone app.
- ![alt tag](https://github.com/SkullbocksDE/DaTiCh/blob/master/documentation/images/wizard.png)
- Fully control over the appearance of the clock/calender.
- ![alt tag](https://github.com/SkullbocksDE/DaTiCh/blob/master/documentation/images/options.png)
- Trayicon
- ![alt tag](https://github.com/SkullbocksDE/DaTiCh/blob/master/documentation/images/tray.png)

## Qt
The application is written under Qt5.X. It uses the Qt Resource System, QSplashScreen, QSystemTrayIcon, Qt Examples and other Qt things.

## Languages
Currently there are two languages available: German and English-UK The 'language' folder contains a 'source-to-ts.bat' and a 'ts-to-qm.bat'. You can use them to easily generate the ts-files from the project file and the qm-files from the ts-files. You can also load the project file within Qt Creator and navigate to Tools -> Extern -> Linguist If you are using the bat-files remember that you need to change the Qt path to your system environment.

## Installation
To create a setup file of the executeable application file and its DLLs you will find a folder named 'installer'. This folder contains a file called 'Installer.iss' which is a configuration file for [InnoSetup](http://www.jrsoftware.org/isinfo.php). You can use this file to generate your setup file.

## Documentation
The documentation was created by using [Doxygen](http://www.stack.nl/~dimitri/doxygen/). The project itself has a folder named 'documentation'. The folder contains a file named DoxyGenfile which is a configuration file for Doxygen. You can recreate or change the documentation by using this file or the created bat-file. The bat-file will help you a bit to create the documentation more easily. If you are using the DoxyGenfile remember to change the following variables to your system environment:
- QHG_LOCATION
- PROJECT_LOGO
- INPUT
- OUTPUT_DIRECTORY
- AGFILES

You can you the qch-file to include the documentation within Qt Creator: Tools->Options->Help->Documentation->Add.. 
![alt tag](https://github.com/SkullbocksDE/DaTiCh/blob/master/documentation/images/qt-help.png)

## ToDo
The ToDo list of the DaTiCh project.
- Test under Unix
- Implement missing gates for UNIX
- Implement missing UNIX functions
- Create Unit-Tests
- UNIX terminal script for Doxygen
- Finish documentation
- Add licenses
