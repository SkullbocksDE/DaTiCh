#include "m_systemdatetime.h"

MSystemDateTime::MSystemDateTime( QObject *parent ) : QObject( parent )
{
    this->error = -10;
}

QTime MSystemDateTime::getSystemTime( )
{
    return QTime::currentTime( );
}

QDate MSystemDateTime::getSystemDate( )
{
    return QDate::currentDate( );
}

int MSystemDateTime::setSystemTime( QTime newTime, QObject *w )
{
    QProcess *newP = new QProcess( w );
    MSystemDateTime p;

    connect( newP, SIGNAL(error(QProcess::ProcessError)), &p, SLOT(handleProcessError(QProcess::ProcessError)) );
    qDebug() << newTime.toString("hh:mm:ss");

#ifdef WIN32
    int retInt = newP->execute( QString("cmd.exe /C time ")+newTime.toString("hh:mm:ss") );
#elif UNIX
    int retInt = newP->execute( QString("date +%T -s \"")+newTime.toString("hh:mm:ss")+"\"" );
#endif
    if( p.getError() != -10 )
    {
        qDebug() << "Return Code: " << retInt;
        qDebug() << "Error Code: " << p.getError( );
        qDebug() << "Error String: " << p.getErrorString( );
        return p.getError();
    }
    return retInt;
}

int MSystemDateTime::setSystemDate( QDate newDate, QObject *w )
{
    QProcess *newP = new QProcess( w );
    MSystemDateTime p;
    connect( newP, SIGNAL(error(QProcess::ProcessError)), &p, SLOT(handleProcessError(QProcess::ProcessError)) );

    qDebug() << newDate.toString("M/dd/yyyy");
#ifdef WIN32
    int retInt = newP->execute( QString("cmd.exe /C date ")+newDate.toString("dd-MM-yyyy") );
#elif UNIX
    int retInt = newP->execute( QString("date +%Y%m%d -s \"")+newDate.toString("yyyyMMdd")+"\"" );
#endif
    if( p.getError() != -10 )
    {
        qDebug() << "Return Code: " << retInt;
        qDebug() << "Error Code: " << p.getError( );
        qDebug() << "Error String: " << p.getErrorString( );
        return p.getError();
    }
    return retInt;
}

void MSystemDateTime::handleProcessError( QProcess::ProcessError error )
{
    this->error = (int)error;
    switch( error )
    {
        case QProcess::FailedToStart:
        {
            this->errorString = "FailedToStart";
        }
        break;
        case QProcess::Crashed:
        {
            this->errorString = "Crashed";
        }
        break;
        case QProcess::Timedout:
        {
            this->errorString = "Timedout";
        }
        break;
        case QProcess::ReadError:
        {
            this->errorString = "ReadError";
        }
        break;
        case QProcess::WriteError:
        {
            this->errorString = "WriteError";
        }
        break;
        case QProcess::UnknownError:
        {
            this->errorString = "UnknownError";
        }
        break;
        default:
        {
            this->errorString = "";
        }
        break;
    }
}

int MSystemDateTime::getError( )
{
    return this->error;
}

QString MSystemDateTime::getErrorString( )
{
    return this->errorString;
}

bool MSystemDateTime::wizard( )
{
    MDateTimeDialog dlg( 0 );
    int retNr = dlg.exec( );
    if( retNr == QDialog::Accepted )
    {
        MSystemDateTime::setSystemDate( dlg.getCurrentDate(), &dlg );
        MSystemDateTime::setSystemTime( dlg.getCurrentTime(), &dlg );
        return true;
    }
    else if( retNr == QDialog::Rejected )
    {
        return false;
    }
    else
    {
        return false;
    }
}
