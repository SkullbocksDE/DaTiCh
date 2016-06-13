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

    MDateTimeDialog dlg( this );
    dlg.show();
    dlg.setWindowFlags( Qt::Widget );
    this->setCentralWidget( &dlg );
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
            this->menuBar()->hide();
        else
            this->menuBar()->show();
    }
}

void MainWindow::showWizard( )
{
    MSystemDateTime::wizard( );
}
