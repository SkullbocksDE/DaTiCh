#include "mainwindow.h"

MainWindow::MainWindow( QWidget *parent ) : QMainWindow( parent )
{
    this->initClass( );
}

void MainWindow::initClass( )
{
    this->initObjects( );
    this->initGuiElements( );
    this->initLayout( );
    this->initWindow( );
    this->initDefaultValues( );
    this->initConnections( );
}

void MainWindow::initObjects( )
{

}
#include <QBitmap>
void MainWindow::initGuiElements( )
{
    this->menuBar();
    this->menuBar()->addAction( new QAction("test",this) );
    this->menuBar()->hide();

    trayIcon = new QSystemTrayIcon( QIcon(":/images/appicon"), this );
    showAction = new QAction( tr("Show"), this );
    showAction->setIcon( QIcon(":/images/eye") );
    optionsAction = new QAction( tr("Options"), this );
    optionsAction->setIcon( QIcon(":/images/options") );
    wizardAction = new QAction( tr("Wizard"), this );
    wizardAction->setIcon( QIcon(":/images/wizard") );
    exitAction = new QAction( tr("Exit"), this );
    exitAction->setIcon( QIcon(":/images/exit") );
    trayMenu = new QMenu( this );
    trayMenu->addAction( showAction );
    trayMenu->addAction( optionsAction );
    trayMenu->addAction( wizardAction );
    trayMenu->addAction( exitAction );
    trayIcon->setContextMenu( trayMenu );
    trayIcon->show( );
//    this->setAttribute( Qt::WA_NoSystemBackground, true);
//    this->setAttribute( Qt::WA_TranslucentBackground, true);
//    this->setStyleSheet("background:transparent;");
//    this->setWindowFlags( Qt::SplashScreen );
//    QPalette pal = this->palette();
//    pal.setBrush(QPalette::Base, Qt::transparent);
//    this->setPalette(pal);
    this->setAutoFillBackground(false);
    QPixmap pixmap = this->grab();
    this->setMask(pixmap.createHeuristicMask());
    testWidget = new QWidget;
    this->setCentralWidget( testWidget );
}

void MainWindow::initLayout( )
{

}

void MainWindow::initWindow( )
{

}

void MainWindow::initDefaultValues( )
{

}

void MainWindow::initConnections( )
{
    connect( showAction, SIGNAL(triggered()), this, SLOT(show()) );
    connect( showAction, SIGNAL(triggered()), this, SLOT(raise()) );
    connect( exitAction, SIGNAL(triggered()), this, SLOT(close()) );
    connect( exitAction, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()) );
    connect( wizardAction, SIGNAL(triggered()), this, SLOT(showWizard()) );
}

void MainWindow::updateLanguage( )
{

}


MainWindow::~MainWindow( )
{

}

void MainWindow::keyPressEvent( QKeyEvent *event )
{
    if( event->modifiers().testFlag(Qt::AltModifier) == true )
    {
        if( this->menuBar()->isVisible() == true )
        {
            this->menuBar()->hide( );
            this->setWindowFlags( Qt::SplashScreen );
            this->show( );
        }
        else
        {
            this->menuBar()->show( );
            this->setWindowFlags( Qt::Window );
            this->show( );
        }
    }
}

void MainWindow::paintEvent( QPaintEvent *event )
{
    QMainWindow::paintEvent( event );
//    QPixmap pixmap(size());
//         pixmap.fill(Qt::transparent);
//         QPainter p( this );
//              p.drawPixmap(0,0,pixmap);
//         setMask(pixmap.mask());
}

void MainWindow::showWizard( )
{
    MSystemDateTime::wizard( );
}
