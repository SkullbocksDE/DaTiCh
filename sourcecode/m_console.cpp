#include "m_console.h"

MConsole::MConsole( int argc, char *argv[] ) : QObject( 0 )
{
    if( argc >= 2 )
    {
        this->parseArguments( argc, argv );
    }
    else
    {
    }
}

void MConsole::parseArguments( int argc, char *argv[] )
{
    if( argc > 1 )
    {
        if( argc >= 2 )
        {
            printf( " " );
            qDebug() << " ";
            for( int i = 1; i < argc; i++ )
            {
                if( QString(argv[i]) == "-debug" || QString(argv[i]) == "-d" )
                {
                    arguments.debuggingEnabled = true;
                }
                if( QString(argv[i]) == "-release" || QString(argv[i]) == "-r" )
                {
                    arguments.debuggingEnabled = false;
                }
                if( QString(argv[i]) == "-help" || QString(argv[i]) == "-h" )
                {
                    arguments.displayHelp = true;
                }
                if( QString(argv[i]) == "-nogui" )
                {
                    arguments.guiVisible = false;
                }
                if( QString(argv[i]) == "-gui" )
                {
                    arguments.guiVisible = true;
                }
                if( QString(argv[i]) == "-menu" || QString(argv[i]) == "-m" )
                {
                    arguments.menuVisible = true;
                }
                if( QString(argv[i]) == "-nomenu" )
                {
                    arguments.menuVisible = false;
                }
            }
        }

        this->showParsingState( );

        this->sendDebugMessage( QObject::tr("* Argument count: %1").arg(argc) );
        this->sendDebugMessage( QObject::tr("* Argument values:") );
        for( int i = 0; i < argc; i++ )
        {
            this->sendDebugMessage( QString("%1 = %2").arg(i+1).arg(argv[i]) );
        }

        if( arguments.displayHelp == true )
        {
            this->showHelp( );
        }

        if( arguments.menuVisible == true )
        {
            this->showMenu( );
        }
    }
}

void MConsole::showParsingState( )
{
    this->sendDebugMessage( QObject::tr("* Debugging enabled: %1").arg( this->getArguments().debuggingEnabled==true?QObject::tr("yes"):QObject::tr("no") ) );
    this->sendDebugMessage( QObject::tr("* Display help: %1").arg( this->getArguments().displayHelp==true?QObject::tr("yes"):QObject::tr("no") ) );
    this->sendDebugMessage( QObject::tr("* Menu visible: %1").arg( this->getArguments().menuVisible==true?QObject::tr("yes"):QObject::tr("no") ) );
    this->sendDebugMessage( QObject::tr("* GUI visible: %1").arg( this->getArguments().guiVisible==true?QObject::tr("yes"):QObject::tr("no") ) );
    this->sendDebugMessage( "" );
}

void MConsole::sendDebugMessage( QString text )
{
    if( arguments.debuggingEnabled == true )
    {
        std::cout << text.toStdString( ) << std::endl;
    }
}

void MConsole::sendMessage( QString text, bool lineBreak, QColor textColor, QColor bgColor )
{
    MConsole::setConsoleColor( textColor, bgColor );
    std::cout << text.toStdString( );
    if( lineBreak == true )
    {
        std::cout << std::endl;
    }
}

void MConsole::waitToContinue( )
{
    MConsole::sendMessage( "" );
    MConsole::pause( );
    MConsole::clearScreen( );
}


MConsoleArguments MConsole::getDefaultArguments( )
{
    return MConsoleArguments( );
}

MConsoleArguments MConsole::getArguments( )
{
    return arguments;
}

int MConsole::parseConsoleTextColor( QColor color )
{
    int fColor = 0;
    if( color.red() > 0 )
    {
        fColor = FOREGROUND_RED;
    }
    if( color.blue() > 0 )
    {
        if( fColor != 0 )
            fColor |= FOREGROUND_BLUE;
        else
            fColor = FOREGROUND_BLUE;
    }
    if( color.green() > 0 )
    {
        if( fColor != 0 )
            fColor |= FOREGROUND_GREEN;
        else
            fColor = FOREGROUND_GREEN;
    }
    if( color.red() > 127 || color.green() > 127 ||  color.blue() > 127 )
    {
        fColor |= FOREGROUND_INTENSITY;
    }
    return fColor;
}

int MConsole::parseConsoleBackgroundColor( QColor color )
{
    int fColor = 0;
    if( color.red() > 0 )
    {
        fColor = BACKGROUND_RED;
    }
    if( color.blue() > 0 )
    {
        if( fColor != 0 )
            fColor |= BACKGROUND_BLUE;
        else
            fColor = BACKGROUND_BLUE;
    }
    if( color.green() > 0 )
    {
        if( fColor != 0 )
            fColor |= BACKGROUND_GREEN;
        else
            fColor = BACKGROUND_GREEN;
    }
    if( color.red() > 127 || color.green() > 127 ||  color.blue() > 127 )
    {
        fColor |= BACKGROUND_INTENSITY;
    }
    return fColor;
}

int MConsole::parseConsoleColor( QColor color, bool textColor )
{
    if( textColor == true )
    {
        return parseConsoleTextColor( color );
    }
    else
    {
        return parseConsoleBackgroundColor( color );
    }
}

void MConsole::setConsoleTextColor( QColor color )
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), parseConsoleColor(color) );
}

void MConsole::setConsoleBackgroundColor( QColor color )
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), parseConsoleColor(color,false) );
}

void MConsole::setConsoleColor( QColor textColor, QColor backgroundColor )
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), parseConsoleColor(textColor) | parseConsoleColor(backgroundColor,false) );
}

void MConsole::setConsoleFont( QFont font )
{
    CONSOLE_FONT_INFOEX cfi;
    GetCurrentConsoleFontEx( GetStdHandle(STD_OUTPUT_HANDLE), false, &cfi );
    cfi.cbSize = sizeof( cfi );
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 24;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy( cfi.FaceName, L"Consolas" ); // Choose your font
    SetCurrentConsoleFontEx( GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi );
}

#include <conio.h>
#include <iostream>
void MConsole::showAbout( )
{
    MConsole::sendMessage( QObject::tr("-=: AppInfo :=-"), true, Qt::yellow );
    MConsole::sendMessage( QObject::tr("* Name: %1").arg(APP_NAME) );
    MConsole::sendMessage( QObject::tr("* Version: %1").arg(APP_VERSION) );
    MConsole::sendMessage( QObject::tr("* Developer: %1").arg("Mike Knappe") );
    MConsole::sendMessage( QObject::tr("* Year: %1").arg("2016") );
    #ifdef QT_DEBUG
        MConsole::sendMessage( QObject::tr("* Release Mode: Debug") );
    #else
        MConsole::sendMessage( QObject::tr("* Release Mode: Release") );
    #endif
}

void MConsole::showHelp( )
{
    MConsole::sendMessage( QObject::tr("-=: Help Menu :=-"), true, Qt::green, Qt::black );
    MConsole::sendMessage( QObject::tr(" * Available commands: ") );
    MConsole::sendMessage( QObject::tr("'-debug' or '-d' will enable the debug mode.") );
    MConsole::sendMessage( QObject::tr("'-release' or '-r' will disable the debug mode.") );
    MConsole::sendMessage( QObject::tr("'-nogui' will deactivate the gui.") );
    MConsole::sendMessage( QObject::tr("'-gui' will activate the gui.") );
    MConsole::sendMessage( QObject::tr("'-help' or '-h' will display the help.") );
    MConsole::sendMessage( QObject::tr("'-menu' or '-m' will display the terminal/console menu.") );
    MConsole::sendMessage( QObject::tr("'-nomenu' will hide the terminal/console menu.") );
}

void MConsole::showMenu( )
{
    MConsole::sendMessage( QObject::tr("-=: Menu :=-"), true, Qt::green, Qt::black );
    MConsole::sendMessage( QObject::tr("0 = Exit") );
    MConsole::sendMessage( QObject::tr("1 = Show AppInfo") );
    MConsole::sendMessage( QObject::tr("2 = GetSystemTime") );
    MConsole::sendMessage( QObject::tr("3 = GetSystemDate") );
    MConsole::sendMessage( QObject::tr("4 = SetSystemTime") );
    MConsole::sendMessage( QObject::tr("5 = SetSystemDate") );
    MConsole::sendMessage( QObject::tr("6 = GetSystemTime (continous)") );
    MConsole::sendMessage( QObject::tr("7 = GetSystemDate (continous)") );
    MConsole::sendMessage( QObject::tr("8 = GetSystemDateTime (continous)") );
    MConsole::sendMessage( QObject::tr("9 = Change language") );
    MConsole::sendMessage( QObject::tr("10 = Show help") );
    MConsole::sendMessage( "" );
    MConsole::sendMessage( QObject::tr("Enter an entry: "), false );
    int input = 0;
    std::cin >> input;
    MConsole::parseMenu( input );
}

void MConsole::parseMenu( int input )
{


//    for( int k = 1; k < 255; k++ )
//    {


//    CONSOLE_SCREEN_BUFFER_INFO *ConsoleInfo = new CONSOLE_SCREEN_BUFFER_INFO();
//    GetConsoleScreenBufferInfo( hConsole, ConsoleInfo );
//    WORD OriginalColors = ConsoleInfo->wAttributes;
//    SetConsoleTextAttribute( hConsole, OriginalColors );

//    QColor textColor( 0, 255, 255 );
//    QColor bgColor( 255, 255, 0 );
//    MConsole::setConsoleColor( textColor, bgColor );


//    std::cout << "TEST" << std::endl;
//    COORD coord = {0,0};
//    DWORD dwWritten;
//    FillConsoleOutputAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | BACKGROUND_RED, 30000, coord, &dwWritten);

//    SetColorAndBackground( parseConsoleColor(textColor), parseConsoleColor(bgColor,false) );

//    QByteArray textByteColor = textColor.toRgb().value();// | 0x00;
//    SetConsoleTextAttribute( hConsole,  );
//    SetConsoleTextAttribute( hConsole, BACKGROUND_BLUE );

//        MConsole::sendMessage( "I want to be nice today!" );
//    }
//    if( textColor.blue() = 255 )

    int menuMin = 0;
    int menuMax = 10;
    MConsole::clearScreen( );
    if( input >= menuMin && input <= menuMax )
    {
        switch( input )
        {
            case 0:
            {
                return;
            }
            break;
            case 1:
            {
                MConsole::showAbout( );
                MConsole::waitToContinue( );
                MConsole::showMenu( );
            }
            break;
            case 2:
            {
                MConsole::sendMessage( QObject::tr("Current Time: %1").arg(MSystemDateTime::getSystemTime( ).toString("hh:mm:ss")) );
                MConsole::waitToContinue( );
                MConsole::showMenu( );
            }
            break;
            case 3:
            {
                MConsole::sendMessage( QObject::tr("Current Date: %1").arg(MSystemDateTime::getSystemDate( ).toString("yyyy.MM.dd")) );
                MConsole::waitToContinue( );
                MConsole::showMenu( );
            }
            break;
            case 4:
            {
                MConsole::sendMessage( QObject::tr("Insert format of the time: hh:mm:ss") );
                MConsole::sendMessage( QObject::tr("Your time: "), false );
                char inputChar[120];
                std::cin >> inputChar;
                std::cout << std::endl << std::endl;
                QStringList timeList = QString( inputChar ).split( ":" );
                QObject oHandle;
                QTime tHandle( QString(timeList.at(0)).toInt(),
                               QString(timeList.at(1)).toInt(),
                               QString(timeList.at(2)).toInt() );
                int ret = MSystemDateTime::setSystemTime( tHandle, &oHandle );
                if( ret == 0 )
                {
                    MConsole::sendMessage( QObject::tr("Your time was successfully set.") );
                }
                else
                {
                    MConsole::sendMessage( QObject::tr("Something went wrong during the time change.") );
                }
                MConsole::waitToContinue( );
                MConsole::showMenu( );
            }
            case 5:
            {
                MConsole::sendMessage( QObject::tr("Insert format of the date: yyyy.MM.dd") );
                MConsole::sendMessage( QObject::tr("Your date: "), false );
                char inputChar[120];
                std::cin >> inputChar;
                std::cout << std::endl << std::endl;
                QStringList timeList = QString( inputChar ).split( "." );
                QObject oHandle;
                QDate dHandle( QString(timeList.at(0)).toInt(),
                               QString(timeList.at(1)).toInt(),
                               QString(timeList.at(2)).toInt() );
                int ret = MSystemDateTime::setSystemDate( dHandle, &oHandle );
                if( ret == 0 )
                {
                    MConsole::sendMessage( QObject::tr("Your date was successfully set.") );
                }
                else
                {
                    MConsole::sendMessage( QObject::tr("Something went wrong during the date change.") );
                }
                MConsole::waitToContinue( );
                MConsole::showMenu( );
            }
            break;
            case 6:
            {
                while( true )
                {
                    MConsole::sendMessage( MSystemDateTime::getSystemTime( ).toString("hh:mm:ss") );
                    MConsole::sleep( );
                    MConsole::clearScreen( );

                    if( GetAsyncKeyState(0x4E) & 0x8000 )
                        break;
                }

                MConsole::waitToContinue( );
                MConsole::showMenu( );
            }
            break;
            case 7:
            {
                while( true )
                {
                    MConsole::sendMessage( MSystemDateTime::getSystemDate( ).toString("yyyy.MM.dd") );
                    MConsole::sleep( );
                    MConsole::clearScreen( );

                    if( GetAsyncKeyState(0x4E) & 0x8000 )
                        break;
                }

                MConsole::waitToContinue( );
                MConsole::showMenu( );
            }
            break;
            case 8:
            {
                while( true )
                {
                    MConsole::sendMessage( MSystemDateTime::getSystemTime( ).toString("hh:mm:ss") );
                    MConsole::sendMessage( MSystemDateTime::getSystemDate( ).toString("yyyy.MM.dd") );
                    MConsole::sleep( );
                    MConsole::clearScreen( );

                    if( GetAsyncKeyState(0x4E) & 0x8000 )
                        break;
                }

                MConsole::waitToContinue( );
                MConsole::showMenu( );
            }
            break;
            case 9:
            {
                MConsole::sendMessage( QObject::tr("-=: Languages :=-"), true, Qt::cyan );
                QStringList lngList = languageHandler->availableLanguages( );
                for( int u = 0; u < lngList.count(); u++ )
                {
                    MConsole::sendMessage( QString("%1. %2").arg(u+1).arg(lngList.at(u)) );
                }
                MConsole::sendMessage( "" );
                MConsole::sendMessage( QObject::tr("Enter an entry: "), false );
                int input = 0;
                std::cin >> input;
                if( input >= 1 && input <= lngList.count() )
                {
                    languageHandler->changeLanguage( lngList.at(input-1) );
                }
                else
                {
                    MConsole::sendMessage( QObject::tr("Please insert a valid entry. You inserted: %1").arg( input ) );
                }
                MConsole::showMenu( );
            }
            break;
            case 10:
            {
                MConsole::showHelp( );
                MConsole::waitToContinue( );
                MConsole::showMenu( );
            }
            break;
            default:
            {

            }
            break;
        }
    }
    else
    {
        MConsole::sendMessage( QObject::tr("Please insert a valid entry. You inserted: %1").arg( input ) );
    }
}


void MConsole::clearScreen( )
{
    system( "cls" );
}

void MConsole::pause( )
{
    system( "pause" );
}

void MConsole::sleep( int timeMs )
{
    Sleep( timeMs );
}
