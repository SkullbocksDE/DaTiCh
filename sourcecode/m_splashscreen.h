#ifndef M_SPLASHSCREEN_H
#define M_SPLASHSCREEN_H

#define DEFAULT_SPLASH_TIMER_MS 1000
#define DEFAULT_SPLASH_TRANSPARENCY_TIMER_MS 10
#define DEFAULT_SPLASH_SKIPABLE false

#include <QSplashScreen>
#include <QCloseEvent>
#include <QTimer>

/**
 * @brief Extension of the QSplashScreen class to have fading effects.
 * @details This extension of the QSplashScreen tries to achieve fading effects.
 *
 * The class works as a normal QSplashScreen with three new features:
 * @li A splash timer to hold the splash at a mininum of x milliseconds.
 * @li A transparency timer to regulate the fading speed.
 * @li Skipable by the user via mouse or key, but controlable.
 *
 * Mainly the fading effect is based on QWidget::setWindowOpacity.
 *
 * Note: The timeline = 1. Transparency Timer, 2. Splash Timer, 3. Transparency Timer
 */
class MSplashScreen : public QSplashScreen
{

    Q_OBJECT

public:
    MSplashScreen( const QPixmap &pixmap = QPixmap(), Qt::WindowFlags f = Qt::WindowFlags() );
    MSplashScreen( QWidget *parent, const QPixmap &pixmap = QPixmap(), Qt::WindowFlags f = Qt::WindowFlags() );
    /**
     * @brief Overwritten function to control the QSplashScreen::finish function in dependency to the timers.
     * @see #splashTimer
     * @see #transparencyTimer
     */
    void finish( QWidget *w );
    /**
     * @brief Overwritten function to control the QSplashScreen::show function and to call #startTimer.
     */
    void show( );
    /**
     * @brief Function to set the minimum hold time (0% transparency) of the splashscreen in milliseconds.
     * @param[in] int Minimum hold time in milliseconds.
     * @pre Should be called before #show
     */
    void setTimer( int timeMs = DEFAULT_SPLASH_TIMER_MS );
    /**
     * @brief Function to set the refresh time of the transparency change/fade in milliseconds.
     * @param[in] int Refresh time of the transparency change/fade in milliseconds.
     * @pre Should be called before #show
     */
    void setTransparencyTimer( int timeMs = DEFAULT_SPLASH_TRANSPARENCY_TIMER_MS );
    /**
     * @brief Function to set if the splashscreen is skipable via mouse click and the keys: ESC, SPACE or ENTER
     * @param[in] bool Skipable or not.
     * @pre Should be called before #show
     */
    void setSkipable( bool _skipable = DEFAULT_SPLASH_SKIPABLE );

public slots:

private slots:
    /**
     * @brief Function to check if the given #waitWidget is ready or not. Connected to #splashTimer via QTimer::timeout.
     */
    void showWaitWidget( );
    /**
     * @brief Function to set the #transparency of the widgets. Connected to #transparencyTimer via QTimer::timeout.
     */
    void changeTransparency( );

protected:
    /**
     * @brief Overwritten function to control the closeEvent, only closing if #transparency is zero.
     */
    void closeEvent( QCloseEvent *event );
    /**
     * @brief Overwritten function to control the #setSkipable function.
     * @param[in] QMouseEvent Event from the system.
     */
    void mousePressEvent( QMouseEvent *event );
    /**
     * @brief Overwritten function to control the #setSkipable function.
     * @param[in] QKeyEvent Event from the system.
     */
    void keyPressEvent( QKeyEvent *event );

private:
    /**
     * @brief Function will start #transparencyTimer and is called by #show
     */
    void startTimer( );
    /**
     * @brief Function to skip the fade sequence.
     * @details This function skips the fade sequence if the user clicks the splash via mouse or presses one of these keys: ESC, SPACE or ENTER
     * @see #setSkipable
     */
    void skip( );
    QTimer splashTimer; //!< Timer to hold the splashscreen at x milliseconds visible at 0% transparency.
    QTimer transparencyTimer; //!< Timer to handle the fading effect of the splash and the finished widget.
    int transparency; //!< Variable to store the current transpency level.
    QWidget *waitWidget; //!< Widget which will be set with #finish
    bool showing; //!< Variable to detect the current splashscreen state if its fading in or fading out.
    bool skipable; //!< Variable to decide if the splashscreen can be skipped via mouse click.
                   //!< @see #setSkipable

};

#endif // M_SPLASHSCREEN_H
