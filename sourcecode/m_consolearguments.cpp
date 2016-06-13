#include "m_consolearguments.h"

MConsoleArguments::MConsoleArguments( bool _guiVisible, bool _menuVisible, bool _debuggingEnabled, bool _displayHelp )
{
    guiVisible = _guiVisible;
    menuVisible = _menuVisible;
    debuggingEnabled = _debuggingEnabled;
    displayHelp = _displayHelp;
}
