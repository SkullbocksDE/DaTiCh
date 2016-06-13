#include "m_splashscreen.h"

MSplashScreen::MSplashScreen( const QPixmap &pixmap, Qt::WindowFlags f ) : QSplashScreen( pixmap, f )
{
    connect( &splashTimer, SIGNAL(timeout()), this, SLOT(showWaitWidget()) );
    connect( &transparencyTimer, SIGNAL(timeout()), this, SLOT(changeTransparency()) );
    transparency = 0;
    waitWidget = nullptr;
    this->setTimer( );
    this->setTransparencyTimer( );
    this->setWindowOpacity( 0 );
    this->setSkipable( );
    showing = true;
}

MSplashScreen::MSplashScreen( QWidget *parent, const QPixmap &pixmap, Qt::WindowFlags f ) : QSplashScreen( parent, pixmap, f )
{
    connect( &splashTimer, SIGNAL(timeout()), this, SLOT(showWaitWidget()) );
    connect( &transparencyTimer, SIGNAL(timeout()), this, SLOT(changeTransparency()) );
    transparency = 0;
    waitWidget = nullptr;
    this->setTimer( );
    this->setTransparencyTimer( );
    this->setWindowOpacity( 0 );
    this->setSkipable( );
    showing = true;
}

void MSplashScreen::finish( QWidget *w )
{
    waitWidget = w;
    waitWidget->setWindowOpacity( 0.0f );
    if( showing == false && splashTimer.isActive() == false && transparencyTimer.isActive() == false )
    {
        this->close( );
    }
    else
    {
        waitWidget->hide( );
    }
}

void MSplashScreen::show( )
{
    QSplashScreen::show( );
    this->startTimer( );
}

void MSplashScreen::setTimer( int timeMs )
{
    splashTimer.setSingleShot( true );
    splashTimer.setInterval( timeMs );
}

void MSplashScreen::setTransparencyTimer( int timeMs )
{
    transparencyTimer.setSingleShot( false );
    transparencyTimer.setInterval( timeMs );
}

void MSplashScreen::setSkipable( bool _skipable )
{
    skipable = _skipable;
}

void MSplashScreen::startTimer( )
{
    transparencyTimer.start( );
}

void MSplashScreen::showWaitWidget( )
{
    if( waitWidget != nullptr )
    {
        this->close( );
    }
    else
    {
        waitWidget->hide( );
    }
}

void MSplashScreen::closeEvent( QCloseEvent *event )
{
    if( transparency > 0 )
    {
        event->ignore( );
        transparencyTimer.start( );
        waitWidget->show( );
    }
}

void MSplashScreen::mousePressEvent( QMouseEvent *event )
{
    event->ignore( );
    if( skipable == true )
    {
        this->skip( );
    }
}

void MSplashScreen::skip( )
{
    transparencyTimer.stop( );
    splashTimer.stop( );
    transparency = 0;
    showing = false;
    this->setWindowOpacity( 0 );
    waitWidget->setWindowOpacity( 255 );
    waitWidget->show( );
    this->close( );
}

void MSplashScreen::keyPressEvent( QKeyEvent *event )
{
    event->ignore( );
    if( skipable == true )
    {
        if( event->key() == Qt::Key_Escape || event->key() == Qt::Key_Space || event->key() == Qt::Key_Enter )
        {
            this->skip( );
        }
    }
}

void MSplashScreen::changeTransparency( )
{
    if( showing == true )
    {
        this->setWindowOpacity( transparency/255.0f );
        transparency++;
        this->raise( );
        this->setFocus( );
        if( transparency == 255 )
        {
            showing = false;
            transparencyTimer.stop( );
            splashTimer.start( );
        }
    }
    else
    {
        waitWidget->setWindowOpacity( 1 - transparency/255.0f );
        this->setWindowOpacity( transparency/255.0f );
        transparency--;
        this->raise( );
        this->setFocus( );
        if( transparency == 0 )
        {
            this->close( );
        }
    }
}
