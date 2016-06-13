#ifndef M_DATETIMEDIALOG_H
#define M_DATETIMEDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QLayout>
#include <QTextCharFormat>
#include <QTime>
#include <QDate>
#include <QDateTime>
#include <QTimeEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QLabel>
#include <QComboBox>
#include <QCalendarWidget>
#include <QTimeZone>

#include "analogclock.h"
#include "m_optionsdialog.h"

/**
 * @brief This class will display the clock and the calendar setup in a QDialog to use its #accept and #reject functions.
 * @details This class uses QDialog as base, the Qt clock example to display a clock and the QCalendarWidget to display a calendar.
 * The clock and the calendar can the adjusted in its appearance with the OptionsDialog via the #optionsButton.
 * The gui inherits a QComboBox to change the locale via QLocale::countriesForLanguage and to change the timezone via QTimeZone::availableTimeZoneIds.
 * The interface tries to detect these things automatically for you, but you are able to change it on your own as the current time and date.
 */
class MDateTimeDialog : public QDialog
{

    Q_OBJECT

public:
    /**
     * @brief Constructor of the class.
     * @param[in] QWidget Pointer to a parent widget.
     */
    MDateTimeDialog( QWidget *parent = 0 );

public slots:
    /**
     * @brief Overwritten function of QDialog::accept.
     * @details The function will be called automatically or via the #okButton and stores the setup date fron #dateEdit to #currDate and time from #timeEdit to #currTime.
     */
    void accept( );
    /**
     * @brief Overwritten function of QDialog::reject.
     */
    void reject( );
    /**
     * @brief Function to receive the setup date.
     * @return QDate Returns #currDate
     */
    QDate getCurrentDate( );
    /**
     * @brief Function to receive the setup time.
     * @return QTime Returns #currTime
     */
    QTime getCurrentTime( );

private slots:
    /**
     * @brief Function to react on the change of the #localeCombo
     * @details After the user changed #localeCombo this function is called. It adjusts:
     * @li #calendar
     * @li #timeEdit
     * @li #utcPlusLabel
     *
     * @param[in] int Index of #localeCombo based on QLocale::countriesForLanguage
     */
    void localeChanged( int index );
    void setFirstDay( Qt::DayOfWeek dow );
    void setTime( QTime time );
    void setHeaderTextFormat( QTextCharFormat format );
    void setHeaderTextStyle( QString text );
    void refreshTimeZoneCombo( QList <QByteArray> tList );
    void refreshTimeZone( int index );
    void reformatCalendarPage( );

signals:

private:
    QGridLayout *mainLayout;
    QPushButton *optionsButton;
    MOptionsDialog *optionsDialog;
    AnalogClock *analogClock;
    QHBoxLayout *timeLayout;
    QLabel *timeLabel;
    QTimeEdit *timeEdit; //!< A gui element to present and change the time.
    QLabel *utcPlusLabel;
    QCalendarWidget *calendar;
    QLabel *localeLabel;
    QComboBox *localeCombo;
    QLabel *timeZoneLabel;
    QComboBox *timeZoneCombo;
    QLabel *dateLabel;
    QDateEdit *dateEdit; //!< A gui element to present and change the date.
    QPushButton *okButton;
    QPushButton *cancelButton;

    QDate currDate; //!< Stores the setup date as QDate via #dateEdit
    QTime currTime; //!< Stores the setup time as QTime via #timeEdit

};

#endif // M_DATETIMEDIALOG_H
