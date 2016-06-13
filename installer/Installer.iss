#define PROJECT_DIR "..\"
#define MATERIAL_DIR "materials\"
#define APPVERSION_FILE "m_applicationversion_defines.h"

#include PROJECT_DIR+""+MATERIAL_DIR+""+APPVERSION_FILE  

#define BUILD_DIR PROJECT_DIR+"..\builds\v."+APPVER_PRODUCTVERSION_STR+"\execute\release\" 

[Setup]
;Application Configuration
AppName = {#APPVER_PRODUCTNAME_STR}  
DefaultDirName = {pf}\{#APPVER_FULLPRODUCTNAME_STR}       
DefaultGroupName = {#APPVER_PRODUCTNAME_STR}\{#APPVER_PRODUCTVERSION_STR}

;Version Configuration   
AppVersion={#APPVER_PRODUCTVERSION_STR}
AppVerName={#APPVER_FULLPRODUCTNAME_STR}      
AppID={#APPVER_ID_STR}
VersionInfoCompany={#APPVER_COMPANYNAME_STR}
VersionInfoTextVersion={#APPVER_FILEDESCRIPTION_STR}
VersionInfoDescription={#APPVER_FILEDESCRIPTION_STR}

;Wizard Configuration
;WizardImageAlphaFormat=defined
WizardImageFile=images\installer_logo.bmp  
WizardSmallImageFile=images\appicon.bmp
WizardImageStretch=no
WizardImageBackColor=clWhite       
SetupIconFile=images\appicon.bmp
UninstallDisplayIcon={app}\{#APPVER_ORIGINALFILENAME_STR}

;Compile Configuration
SolidCompression=yes    
;Compression=lzma2
OutputDir=installer\
OutputBaseFilename={#APPVER_INSTALLERNAME_STR}
;InfoBeforeFile=help\lgpl_2.1.rtf
LicenseFile=docs\lgpl_3.0.rtf

;Language Configuration
ShowLanguageDialog=yes
LanguageDetectionMethod=locale
UsePreviousLanguage=no

;Publisher Configuration
AppPublisher={#APPVER_COMPANYNAME_STR}    
AppCopyright={#APPVER_LEGALCOPYRIGHT_STR}
AppPublisherURL={#APPVER_COMPANYURL_STR}
AppContact={#APPVER_COMPANYMAIL_STR}   
AppSupportURL={#APPVER_COMPANYURL_STR}
AppUpdatesURL={#APPVER_COMPANYURL_STR}

;Inno-Setup Languages
[Languages] 
Name: "en"; MessagesFile: "compiler:Default.isl"
Name: "gr"; MessagesFile: "compiler:Languages\German.isl"
Name: "ch"; MessagesFile: "compiler:Languages\Czech.isl"

[Files]           
Source: {#BUILD_DIR}*; DestDir: {app}; Flags: ignoreversion recursesubdirs createallsubdirs     
Source: docs\*; DestDir: {app}\docs; Flags: ignoreversion recursesubdirs createallsubdirs 
Source: ..\documentation\html\*; DestDir: {app}\documentation; Flags: ignoreversion recursesubdirs createallsubdirs 

[Tasks]
;german    
Name: startmenu; Description: "Startmenüeintrag erstellen ?"; Languages: gr
Name: desktopicon; Description: "Desktopverknüpfung erstellen ?"; Languages: gr
Name: quicklaunchicon; Description: "Verknüpfung in der Startleiste erstellen ?"; Languages: gr 

;english
Name: startmenu; Description: "Create a start menu item ?"; Languages: en ch
Name: desktopicon; Description: "Create link on the desktop ?"; Languages: en ch
Name: quicklaunchicon; Description: "Create link in task bar ?"; Languages: en ch


[Run]
;german
Filename: {app}\{#APPVER_ORIGINALFILENAME_STR}; Description: "Programm starten?"; Flags: postinstall shellexec; Languages: gr
;english/chinese
Filename: {app}\{#APPVER_ORIGINALFILENAME_STR}; Description: "Start application ?"; Flags: postinstall shellexec; Languages: en ch 

[Icons]
;german
Name: {group}\{#APPVER_FULLPRODUCTNAME_STR} starten; Filename: {app}\{#APPVER_ORIGINALFILENAME_STR}; WorkingDir: {app}; IconFilename: {app}\{#APPVER_ORIGINALFILENAME_STR}; Tasks: startmenu; Languages: gr
Name: {group}\{#APPVER_FULLPRODUCTNAME_STR} Dokumentation; Filename: {app}\documentation\index.html; WorkingDir: {app}\documentation; Tasks: startmenu; Languages: gr
Name: {group}\{#APPVER_FULLPRODUCTNAME_STR} entfernen; Filename: {uninstallexe}; IconFilename: {sys}\Shell32.dll; IconIndex: 31; Tasks: startmenu; Languages: gr
Name: {commondesktop}\{#APPVER_FULLPRODUCTNAME_STR} starten; Filename: {app}\{#APPVER_ORIGINALFILENAME_STR}; WorkingDir: {app}; IconFilename: {app}\help\pics\appicon.ico; Tasks: desktopicon; Languages: gr
Name: {userappdata}\Microsoft\Internet Explorer\Quick Launch\{#APPVER_FULLPRODUCTNAME_STR} starten; Filename: {app}\{#APPVER_ORIGINALFILENAME_STR}; WorkingDir: {app}; IconFilename: {app}\{#APPVER_ORIGINALFILENAME_STR}; Tasks: quicklaunchicon; Languages: gr

;english
Name: {group}\Start {#APPVER_FULLPRODUCTNAME_STR}; Filename: {app}\{#APPVER_ORIGINALFILENAME_STR}; WorkingDir: {app}; IconFilename: {app}\{#APPVER_ORIGINALFILENAME_STR}; Tasks: startmenu; Languages: en ch
Name: {group}\{#APPVER_FULLPRODUCTNAME_STR} Documentation; Filename: {app}\documentation\index.html; WorkingDir: {app}\documentation; Tasks: startmenu; Languages: en ch
Name: {group}\Uninstall {#APPVER_FULLPRODUCTNAME_STR}; Filename: {uninstallexe}; IconFilename: {sys}\Shell32.dll; IconIndex: 31; Tasks: startmenu; Languages: en ch
Name: {commondesktop}\Start {#APPVER_FULLPRODUCTNAME_STR}; Filename: {app}\{#APPVER_ORIGINALFILENAME_STR}; WorkingDir: {app}; IconFilename: {app}\{#APPVER_ORIGINALFILENAME_STR}; Tasks: desktopicon; Languages: en ch
Name: {userappdata}\Microsoft\Internet Explorer\Quick Launch\Start {#APPVER_FULLPRODUCTNAME_STR}; Filename: {app}\{#APPVER_ORIGINALFILENAME_STR}; WorkingDir: {app}; IconFilename: {app}\{#APPVER_ORIGINALFILENAME_STR}; Tasks: quicklaunchicon; Languages: en ch

Name: {group}\LGPL v.3.0; Filename: {app}\help\lgpl_3.0.rtf; Tasks: startmenu;

[UninstallDelete]
Type: filesandordirs; Name: {app}
