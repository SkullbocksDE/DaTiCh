#ifndef M_OPTIONSDIALOG_H
#define M_OPTIONSDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QListWidget>
#include <QStackedWidget>
#include <QLayout>
#include <QIcon>
#include <QListWidgetItem>
#include <QPushButton>

#include "m_clockpage.h"
#include "m_calendarpage.h"

class MOptionsDialog : public QDialog
{

    Q_OBJECT

public:
    MOptionsDialog( QWidget *parent = 0 );

public slots:
    void changePage( QListWidgetItem *current, QListWidgetItem *previous );

    void updateLanguage( );

private:

private slots:

private:
    void createIcons( );

    QVBoxLayout *mainLayout;

    QHBoxLayout *horizontalLayout;
    QHBoxLayout *buttonsLayout;

    QListWidget *contentsWidget;
    QStackedWidget *pagesWidget;

    QListWidgetItem *clockButton;
    QListWidgetItem *calendarButton;

    QPushButton *closeButton;

};

#endif // M_OPTIONSDIALOG_H
