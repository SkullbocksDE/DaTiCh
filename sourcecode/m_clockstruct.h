#ifndef M_CLOCKSTRUCT
#define M_CLOCKSTRUCT

#define DEFAULT_CLOCK_VISIBLE true
#define DEFAULT_CLOCK_HOURHAND_VISIBLE true
#define DEFAULT_CLOCK_MINUTEHAND_VISIBLE true
#define DEFAULT_CLOCK_SECONDHAND_VISIBLE true
#define DEFAULT_CLOCK_HOURTICK_VISIBLE true
#define DEFAULT_CLOCK_MINUTETICK_VISIBLE true
#define DEFAULT_CLOCK_SECONDTICK_VISIBLE true
#define DEFAULT_CLOCK_HOURHAND_COLOR QColor( 0, 0, 0, 255 )
#define DEFAULT_CLOCK_MINUTEHAND_COLOR QColor( 0, 0, 0, 255 )
#define DEFAULT_CLOCK_SECONDHAND_COLOR QColor( 0, 0, 0, 255 )
#define DEFAULT_CLOCK_HOURTICK_COLOR QColor( 0, 0, 0, 255 )
#define DEFAULT_CLOCK_MINUTETICK_COLOR QColor( 0, 0, 0, 255 )
#define DEFAULT_CLOCK_SECONDTICK_COLOR QColor( 0, 0, 0, 255 )

#include <QColor>

/**
 * @brief The data container for the presentation of the clock.
 * @details This structure stores i. e. if the clock should be painted or not or what color the minuteHand should have.
 */
struct MClockStruct
{
    /**
     * @brief Constructor of the structure, which will initialize all available variables.
     */
    MClockStruct( )
    {
        clock = DEFAULT_CLOCK_VISIBLE;
        hourHand = DEFAULT_CLOCK_HOURHAND_VISIBLE;
        minuteHand = DEFAULT_CLOCK_MINUTEHAND_VISIBLE;
        secondHand = DEFAULT_CLOCK_SECONDHAND_VISIBLE;
        hourTick = DEFAULT_CLOCK_HOURTICK_VISIBLE;
        minuteTick = DEFAULT_CLOCK_MINUTETICK_VISIBLE;
        secondTick = DEFAULT_CLOCK_SECONDTICK_VISIBLE;
        hourHandColor = DEFAULT_CLOCK_HOURHAND_COLOR;
        minuteHandColor = DEFAULT_CLOCK_MINUTEHAND_COLOR;
        secondHandColor = DEFAULT_CLOCK_SECONDHAND_COLOR;
        hourTickColor = DEFAULT_CLOCK_HOURTICK_COLOR;
        minuteTickColor = DEFAULT_CLOCK_MINUTETICK_COLOR;
        secondTickColor = DEFAULT_CLOCK_SECONDTICK_COLOR;
    }
    bool clock; //!< Should the clock be painted or not.
    bool hourHand; //!< Should the hour hand be painted or not.
    bool minuteHand; //!< Should the minute hand be painted or not.
    bool secondHand; //!< Should the second hand be painted or not.
    bool hourTick; //!< Should the hour tick be painted or not.
    bool minuteTick; //!< Should the minute tick be painted or not.
    bool secondTick; //!< Should the second tick be painted or not.
    QColor hourHandColor; //!< Color of the hour hand.
    QColor minuteHandColor; //!< Color of the minute hand.
    QColor secondHandColor; //!< Color of the second hand.
    QColor hourTickColor; //!< Color of the hour tick.
    QColor minuteTickColor; //!< Color of the minute tick.
    QColor secondTickColor; //!< Color of the second tick.
};

#endif // M_CLOCKSTRUCT

