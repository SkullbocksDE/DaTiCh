#ifndef M_CONSOLE_H
#define M_CONSOLE_H

#ifdef WIN32
    #include <iostream>
    #include <windows.h>
#endif

#include <QObject>
#include <QDebug>

#include "m_systemdatetime.h"
#include "m_consolearguments.h"
#include "m_consoleappearance.h"
#include "m_languagehandler.h"

/**
 * @brief This class handles the given application arguments and gives a change to operate with the core functions of the application.
 * @details This class will filter the given arguments and decides what to do, to display the console menu or to debug the application.
 */
class MConsole : public QObject
{

    Q_OBJECT

public:
    /**
     * @brief Constructor of the class. Take the main() parameters as parameters for this constructor.
     * @param[in] int Argument count given to the application.
     * @param[in] char** Argument values given to the application.
     */
    MConsole( int argc, char *argv[] );
    /**
     * @brief Function to print the console/terminal menu.
     */
    static void showMenu( );
    /**
     * @brief Function to print the console/terminal about dialog.
     */
    static void showAbout( );
    /**
     * @brief Function to print the console/terminal help dialog.
     */
    static void showHelp( );
    /**
     * @brief Function to parse the input from the menu.
     * @param[in] int Input of the user. (menu entry)
     */
    static void parseMenu( int input );
    /**
     * @brief Function to print a newline, pause the system by waiting for user input and to clear the screen after an input.
     * @see #sendMessage
     * @see #pause
     * @see #clearScreen
     */
    static void waitToContinue( );
    /**
     * @brief Function to get the current parsed arguments of the console.
     * @return MConsoleArguments Returns the current parsed arguments.
     */
    MConsoleArguments getArguments( );
    /**
     * @brief Function to get the default argument states of the console.
     * @return MConsoleArguments Returns the default argument states.
     */
    static MConsoleArguments getDefaultArguments( );
    /**
     * @brief Function to decode QColor to terminal text color.
     * @param[in] QColor Color of the text.
     * @return int Returns the terminal color.
     */
    static int parseConsoleTextColor( QColor color );
    /**
     * @brief Function to decode QColor to terminal background color.
     * @param[in] QColor Color of the background.
     * @return int Returns the terminal background color.
     */
    static int parseConsoleBackgroundColor( QColor color );
    static int parseConsoleColor( QColor color, bool textColor = true );
    static void setConsoleTextColor( QColor color );
    static void setConsoleBackgroundColor( QColor color );
    static void setConsoleColor( QColor textColor, QColor backgroundColor );
    static void setConsoleFont( QFont font );
    /**
     * @brief This function will pause the system until the user enters a key.
     */
    static void pause( );
    /**
     * @brief This function will clear the display buffer of the terminal/console.
     */
    static void clearScreen( );
    /**
     * @brief This function will block all IOs at the terminal/console for x milliseconds.
     * @param[in] int Time in milliseconds
     */
    static void sleep( int timeMs = 500 );

private:
    MConsoleArguments arguments; //!< Variable to store the parsed arguments.
    /**
     * @brief Function to parse the given arguments to the application arguments.
     * @param[in] int Argument count given to the application.
     * @param[in] char** Argument values given to the application.
     */
    void parseArguments( int argc, char *argv[] );
    /**
     * @brief Function to send messages which have debug character to the console/terminal.
     * @param[in] QString Text which should be send.
     * @see MConsoleArguments::debuggingEnabled
     */
    void sendDebugMessage( QString text );
    /**
     * @brief Function to send messages to the console/terminal.
     * @param[in] QString Text which should be send.
     * @param[in] bool If there should be an automatically linebreak at the end or not.
     * @param[in] QColor Color of the text.
     * @param[in] QColor Color of the background.
     */
    static void sendMessage( QString text, bool lineBreak = true, QColor textColor = QColor(255,255,255), QColor bgColor = QColor(0,0,0) );
    /**
     * @brief Function to display the status of all arguments after they got parsed.
     */
    void showParsingState( );

};

#endif // M_CONSOLE_H
