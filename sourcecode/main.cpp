#include <iostream>
#include <QApplication>
#include <QTranslator>

#include "m_console.h"
#include "mainwindow.h"
#include "m_splashscreen.h"

int main( int argc, char *argv[] )
{
    QApplication application( argc, argv );

    QStringList libList = qApp->libraryPaths();
    libList.append( qApp->applicationDirPath()+"/dlls" );
    qApp->setLibraryPaths( libList );

    //get current system language as string i. e. 'German'
    QString currentLanguage = QLocale::languageToString( QLocale::system().language() );

    languageHandler = new MLanguageHandler( 0 );
    languageHandler->changeLanguage( currentLanguage );

    MConsole console( argc, argv );

    if( console.getArguments().guiVisible == true )
    {

        QPixmap pixmap( ":/images/appicon" );
        MSplashScreen splash( pixmap );
        splash.setTimer( 3000 );
        splash.setSkipable( true );
        splash.show( );
        application.processEvents( );

        MainWindow mainWindow;
        mainWindow.show( );
        splash.finish( &mainWindow );

    }

    return application.exec( );
}
