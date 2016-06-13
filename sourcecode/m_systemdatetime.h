#ifndef MSYSTEMDATETIME_H
#define MSYSTEMDATETIME_H

#include <QObject>
#include <QDate>
#include <QTime>
#include <QDateTime>
#include <QProcess>

#include <QDebug>

#include "m_datetimedialog.h"

/**
 * @brief This class is able to change the system datetime statically or to call a gui wizard.
 * @details This class can be used to change the system datetime.
 * Here a short overview of the typical system commands of windows and unix for datetime changes which will be used by this class.
 * @code
 * == WIN ==
 * Get Date: date /T
 * Get Time: time /T
 * Set Date: date 5/15/2009 || date 2/14/1999
 * Set Time: time 5:34:00 PM || time 12:15:00 AM || time 23:23:23
 * =========
 *
 * == UNIX ==
 * Get Date: date
 * Get Time: hwclock --show --utc
 * Set Date: date +%Y%m%d -s "20081128"
 * Set Time: date +%T -s "10:13:13"
 * ==========
 * @endcode
 */
class MSystemDateTime : public QObject
{

    Q_OBJECT

public:
    /**
     * @brief Constructor of the class.
     * @param[in] QObject Pointer to a parent object.
     */
    MSystemDateTime( QObject *parent = 0 );
    /**
     * @brief Static function to receive the current time.
     * @return QTime Current time.
     */
    static QTime getSystemTime( );
    /**
     * @brief Static function to receive the current date.
     * @return QDate Current date.
     */
    static QDate getSystemDate( );
    /**
     * @brief Static function to set a new system time.
     * @param[in] QTime The new system time.
     * @param[in] QObject Needed pointer to a QObject for QProcess.
     * @return int Returns the status of the QProcess::execute.
     */
    static int setSystemTime( QTime newTime, QObject *w );
    /**
     * @brief Static function to set a new system date.
     * @param[in] QDate The new system date.
     * @param[in] QObject Needed pointer to a QObject for QProcess.
     * @return int Returns the status of the QProcess::execute.
     */
    static int setSystemDate( QDate newDate, QObject *w );

private slots:
    /**
     * @brief Internal slot connected to QProcess to handle errors via execution.
     * @param[in] QProcess::ProcessError Error status of QProcess.
     */
    void handleProcessError( QProcess::ProcessError error );

public slots:
    /**
     * @brief Function to receive the last error as int.
     * @return int Returns #error.
     */
    int getError( );
    /**
     * @brief Function to receive the last error as QString.
     * @return QString Returns #errorString.
     */
    QString getErrorString( );
    /**
     * @brief Static function to call MDateTimeDialog the gui wizard to set a new system datetime.
     * @return bool Returns if the datetime change was successfully or not.
     */
    static bool wizard( );

private:
    int error; //!< Stores the status/error of the QProcess::execute.
    QString errorString; //!< Stores the resolved status/error of the QProcess::execute as QString.

};

#endif // MSYSTEMDATETIME_H
