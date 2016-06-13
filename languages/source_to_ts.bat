@echo off
echo Qt TS generator
echo Saving current dir "%CD%" to CURRENT_DIR ..
set CURRENT_DIR=%CD%
echo Saving done!
IF NOT "%QTLINGUIST_DIR%"=="" goto CHECKLINGU
echo System environment variable QTLINGUIST_DIR is undefined!
GOTO SCANLINUG

:CHECKLINGU
IF NOT EXIST %QTLINGUIST_DIR% echo System environment variable QTLINGUIST_DIR defined, but link is dead: "%QTLINGUIST_DIR%"
GOTO SCANLINUG

:SCANLINUG
echo Scanning for Qt Linguist ..
set QTLINGUIST_DIR=C:\Qt\Qt5.6.0\5.6\mingw49_32\bin
IF NOT EXIST %QTLINGUIST_DIR% GOTO NOLINGUDIR

:STARTLINGU
echo Qt Linguist dir found at: %QTLINGUIST_DIR%
echo Switching to Qt Linguist dir ..
pushd %QTLINGUIST_DIR%
echo Switching done!

:ASKLINGU
echo Start Qt Linguist? [y/n]
set /p startLingu=">> "
If "%startLingu%" == "n" goto ENDLINGU
If "%startLingu%" == "N" goto ENDLINGU
If "%startLingu%" == "y" goto RUNLINGU
If "%startLingu%" == "Y" goto RUNLINGU
echo Wrong key, please insert a valid key!
goto ASKLINGU

:RUNLINGU
echo Starting Qt Linguist..
%QTLINGUIST_DIR%\lupdate.exe "%CURRENT_DIR%\..\DaTiCh_Qt5.5_v.0.1.0.0.pro"
echo Qt Linguist finished!

:ASKAGAIN
echo Do you want to rerun Qt Linguist? [y/n]
set /p startLingu=">> "
If "%startLingu%" == "n" goto ENDLINGU
If "%startLingu%" == "N" goto ENDLINGU
If "%startLingu%" == "y" goto ENDLINGU
If "%startLingu%" == "Y" goto ENDLINGU
echo Wrong key, please insert a valid key!
goto ASKAGAIN

:ENDLINGU
echo Session terminated!
PAUSE
exit

:NOLINGUDIR
echo No Qt Linguist dir found at: %QTLINGUIST_DIR%
set QTLINGUIST_DIR=C:\Qt\Qt5.5.0\5.5\mingw49_32\bin
IF NOT EXIST %QTLINGUIST_DIR% GOTO NONOLINGUDIR
GOTO STARTLINGU

:NONOLINGUDIR
echo No Qt Linguist dir found at: %QTLINGUIST_DIR%
echo Giving up!
echo Please set a system environment variable called QTLINGUIST_DIR to your Qt Linguist binary dir.
echo OR run lupdate from your Qt environment manually.
echo OR open the project file with the Qt Creator -^> Extras -^> Extern -^> Linguist.
echo Leaving session!
PAUSE
exit
