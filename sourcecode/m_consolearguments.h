#ifndef M_CONSOLEARGUMENTS_H
#define M_CONSOLEARGUMENTS_H

#define DEFAULT_CONSOLE_GUI_VISIBLE true
#define DEFAULT_CONSOLE_MENU_VISIBLE false
#define DEFAULT_CONSOLE_DEBUGGING_ENABLED false
#define DEFAULT_CONSOLE_DISPLAY_HELP false

struct MConsoleArguments
{

public:
    MConsoleArguments( bool _guiVisible = DEFAULT_CONSOLE_GUI_VISIBLE,
                       bool _menuVisible = DEFAULT_CONSOLE_MENU_VISIBLE,
                       bool _debuggingEnabled = DEFAULT_CONSOLE_DEBUGGING_ENABLED,
                       bool _displayHelp = DEFAULT_CONSOLE_DISPLAY_HELP );
    bool guiVisible;
    bool menuVisible;
    bool debuggingEnabled;
    bool displayHelp;
};

#endif // M_CONSOLEARGUMENTS_H
