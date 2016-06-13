#ifndef M_CALENDARPAGE_H
#define M_CALENDARPAGE_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QComboBox>
#include <QCalendarWidget>
#include <QLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDateEdit>
#include <QTextCharFormat>

#include "m_colorbutton.h"
#include "m_groupbox.h"
#include "m_widget.h"

class MCalendarPage : public MWidget
{

    Q_OBJECT

public:
    MCalendarPage( QWidget *parent = 0 );

public slots:
    void updateLanguage( );

private slots:
    void setHorizontalHeader( int index );
    void setVerticalHeader( int index );
    void addFormat( );
    void removeFormat( );
    void refreshFormat( );

private:
    void initClass( );
    void initObjects( );
    void initGuiElements( );
    void initLayout( );
    void initWindow( );
    void initDefaultValues( );
    void initConnections( );

    QHBoxLayout *mainLayout;

    QVBoxLayout *sideLayout;

    MGroupBox *optionsGroup;
    QGridLayout *optionsLayout;
    QLabel *gridLabel;
    QCheckBox *gridCheckBox;
    QLabel *navigationLabel;
    QCheckBox *navigationCheckBox;
    QLabel *horizontalHeaderLabel;
    QComboBox *horizontalHeaderCombo;
    QLabel *verticalHeaderLabel;
    QComboBox *verticalHeaderCombo;

    MGroupBox *formatGroup;
    QGridLayout *formatLayout;
    QPushButton *addFormatButton;
    QPushButton *removeFormatButton;
    QTableWidget *formatTable;
    QPushButton *refreshFormatButton;

    QCheckBox *firstFridayCheckBox;
    QCheckBox *mayFirstCheckBox;

    QGroupBox *textFormatsGroupBox;
    QLabel *weekdayColorLabel;
    QLabel *weekendColorLabel;
    QLabel *headerTextFormatLabel;
    QComboBox *weekdayColorCombo;
    QComboBox *weekendColorCombo;
    QComboBox *headerTextFormatCombo;

    MGroupBox *previewGroup;
    QVBoxLayout *previewLayout;
    QCalendarWidget *calendar;

};

#endif // CALENDARPAGE_H
