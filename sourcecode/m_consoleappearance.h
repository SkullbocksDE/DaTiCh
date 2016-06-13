#ifndef M_CONSOLEAPPEARANCE_H
#define M_CONSOLEAPPEARANCE_H

#include <QColor>
#include <QFont>

#define DEFAULT_CONSOLE_TEXT_COLOR QColor( 255, 255, 255 )
#define DEFAULT_CONSOLE_BACKGROUND_COLOR QColor( 0, 0, 0 )
#define DEFAULT_CONSOLE_FONT QFont()

struct MConsoleAppearance
{

public:
    MConsoleAppearance( QColor _textColor = DEFAULT_CONSOLE_TEXT_COLOR,
                       QColor _backgroundColor = DEFAULT_CONSOLE_BACKGROUND_COLOR,
                       QFont _font = DEFAULT_CONSOLE_FONT );
    QColor textColor;
    QColor backgroundColor;
    QFont font;
};

#endif // M_CONSOLEAPPEARANCE_H
