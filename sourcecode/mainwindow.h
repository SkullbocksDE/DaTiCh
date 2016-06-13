#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QKeyEvent>
#include <QMenuBar>
#include <QDebug>

#include "m_systemdatetime.h"

/**
 * @brief The MainWindow class which currently only calls MSystemDateTime::wizard in its constructor.
 */
class MainWindow : public QMainWindow
{
    
    Q_OBJECT

public:
    /**
     * @brief Constructor which currently only calls MSystemDateTime::wizard.
     */
    MainWindow( QWidget *parent = 0 );
    ~MainWindow( );

public slots:
    void updateLanguage( );

private slots:
    void showWizard( );

protected:
    void keyPressEvent( QKeyEvent *event );

private:
    void initClass( );
    void initObjects( );
    void initGuiElements( );
    void initLayout( );
    void initWindow( );
    void initDefaultValues( );
    void initConnections( );

    QSystemTrayIcon *trayIcon;
    QMenu *trayMenu;
    QAction *showAction;
    QAction *optionsAction;
    QAction *wizardAction;
    QAction *exitAction;

};

#endif // MAINWINDOW_H
