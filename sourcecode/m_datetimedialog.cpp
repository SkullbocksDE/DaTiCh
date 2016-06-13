#include "m_datetimedialog.h"

MDateTimeDialog::MDateTimeDialog( QWidget *parent ) : QDialog( parent )
{
    optionsDialog = new MOptionsDialog( this );
    optionsButton = new QPushButton( this );
    optionsButton->setIcon( QIcon(":/images/options") );
    localeLabel = new QLabel( tr("Locale"), this );
    localeCombo = new QComboBox( this );
    int curLocaleIndex = -1;
    int index = 0;
    for( int _lang = QLocale::C; _lang <= QLocale::LastLanguage; ++_lang )
    {
        QLocale::Language lang = static_cast<QLocale::Language>( _lang );
        QList<QLocale::Country> countries = QLocale::countriesForLanguage( lang );
        for( int i = 0; i < countries.count(); ++i )
        {
            QLocale::Country country = countries.at( i );
            QString label = QLocale::languageToString( lang );
            label += QLatin1Char( '/' );
            label += QLocale::countryToString( country );
            QLocale locale( lang, country );
            if( this->locale().language() == lang && this->locale().country() == country )
                curLocaleIndex = index;
            localeCombo->addItem( label, locale );
            ++index;
        }
    }

    timeZoneLabel = new QLabel( tr("TimeZone"), this );
    timeZoneLabel->setVisible( false );
    timeZoneCombo = new QComboBox( this );
    timeZoneCombo->setVisible( false );

    dateLabel = new QLabel( tr("Date"), this );
    dateEdit = new QDateEdit( this );
    timeLabel = new QLabel( tr("Time"), this );
    calendar = new QCalendarWidget( this );
    calendar->setGridVisible( true );
    timeEdit = new QTimeEdit( this );
    timeEdit->setDisplayFormat( "hh:mm:ss" );
    utcPlusLabel = new QLabel( this );
    analogClock = new AnalogClock( this );
    okButton = new QPushButton( tr("OK"), this );
    cancelButton = new QPushButton( tr("Cancel"), this );

    connect( okButton, SIGNAL(clicked()), this, SLOT(accept()) );
    connect( cancelButton, SIGNAL(clicked()), this, SLOT(reject()) );
    connect( timeEdit, SIGNAL(timeChanged(QTime)), analogClock, SLOT(setCurrentTime(QTime)) );
    connect( analogClock, SIGNAL(sendNewTime(QTime)), this, SLOT(setTime(QTime)) );
    connect( calendar, SIGNAL(clicked(QDate)), dateEdit, SLOT(setDate(QDate)) );
    connect( dateEdit, SIGNAL(dateChanged(QDate)), calendar, SLOT(setSelectedDate(QDate)) );
    connect( localeCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(localeChanged(int)) );
    connect( calendar, SIGNAL(currentPageChanged(int,int)), this, SLOT(reformatCalendarPage()) );
    connect( timeZoneCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(refreshTimeZone(int)) );
    connect( optionsButton, SIGNAL(clicked()), optionsDialog, SLOT(show()) );

    timeLayout = new QHBoxLayout;
    timeLayout->addWidget( timeLabel );
    timeLayout->addWidget( timeEdit );
    timeLayout->addWidget( utcPlusLabel );

    mainLayout = new QGridLayout;
    mainLayout->addWidget( optionsButton, 5, 0, 1, 2 );
    mainLayout->addWidget( localeLabel, 10, 0 );
    mainLayout->addWidget( localeCombo, 10, 1 );
    mainLayout->addWidget( timeZoneLabel, 11, 0 );
    mainLayout->addWidget( timeZoneCombo, 11, 1 );
    mainLayout->addWidget( analogClock, 20, 0, 1, 2 );
    mainLayout->addLayout( timeLayout, 30, 0, 1, 2 );
    mainLayout->addWidget( calendar, 40, 0, 1, 2 );
    mainLayout->addWidget( dateLabel, 50, 0 );
    mainLayout->addWidget( dateEdit, 50, 1 );
    mainLayout->addWidget( okButton, 100, 0 );
    mainLayout->addWidget( cancelButton, 100, 1 );
    this->setLayout( mainLayout );

    if( curLocaleIndex != -1 )
        localeCombo->setCurrentIndex( curLocaleIndex );
    dateEdit->setDate( QDate::currentDate() );
    timeEdit->setTime( QTime::currentTime() );
    this->setHeaderTextStyle( "Bold" );
    this->reformatCalendarPage( );
}

void MDateTimeDialog::accept( )
{
    currDate = dateEdit->date( );
    currTime = timeEdit->time( );
    QDialog::accept( );
}

void MDateTimeDialog::reject( )
{
    QDialog::reject( );
}

QDate MDateTimeDialog::getCurrentDate( )
{
    return currDate;
}

QTime MDateTimeDialog::getCurrentTime( )
{
    return currTime;
}

void MDateTimeDialog::localeChanged( int index )
{
    const QLocale newLocale( localeCombo->itemData(index).toLocale() );
    calendar->setLocale( newLocale );
    this->setFirstDay( newLocale.firstDayOfWeek() );
//        QTime tTime = timeEdit->time();
//        newLocale.timeFormat();
    timeEdit->setLocale( newLocale );
    QTimeZone zZone( newLocale.country() );
    QList <QByteArray> tList = QTimeZone::availableTimeZoneIds( newLocale.country() );

    QString utcPlus = zZone.displayName( QDateTime( dateEdit->date(), timeEdit->time(), Qt::LocalTime ), QTimeZone::DefaultName, newLocale );
    utcPlusLabel->setText( utcPlus );

    this->refreshTimeZoneCombo( tList );
    if( tList.count() == 1 )
    {
        timeEdit->setDisplayFormat( newLocale.timeFormat() ); //fast perfekt, außer das TimeZone nicht nachgeführt wird
        timeEdit->setTimeSpec( Qt::TimeZone );
    }
}

void MDateTimeDialog::setFirstDay( Qt::DayOfWeek dow )
{
    calendar->setFirstDayOfWeek( dow );
}

void MDateTimeDialog::setTime( QTime time )
{
    timeEdit->blockSignals( true );
    timeEdit->setTime( time );
    timeEdit->blockSignals( false );
}

void MDateTimeDialog::setHeaderTextFormat( QTextCharFormat format )
{
    calendar->setHeaderTextFormat( format );
}

void MDateTimeDialog::setHeaderTextStyle( QString text )
{
    QTextCharFormat format;
    if( text == tr("Bold") )
    {
        format.setFontWeight( QFont::Bold );
    }
    else if (text == tr("Italic") )
    {
        format.setFontItalic( true );
    }
    else if (text == tr("Green") )
    {
        format.setForeground( Qt::green );
    }
    this->setHeaderTextFormat( format );
}

void MDateTimeDialog::refreshTimeZoneCombo( QList <QByteArray> tList )
{
    timeZoneCombo->blockSignals( true );
    if( tList.count() > 1 )
    {
        timeZoneCombo->clear( );
        QString str;
        foreach( str, tList )
            timeZoneCombo->addItem( str, str );
        timeZoneLabel->setVisible( true );
        timeZoneCombo->setVisible( true );
    }
    else
    {
        timeZoneLabel->setVisible( false );
        timeZoneCombo->setVisible( false );
    }
    timeZoneCombo->blockSignals( false );
}

void MDateTimeDialog::refreshTimeZone( int index )
{
//        timeEdit->setTi
}

void MDateTimeDialog::reformatCalendarPage( )
{
    //Underline first day in Month
    QTextCharFormat firstDayFormat;
    QDate firstMonthDay( calendar->yearShown(), calendar->monthShown(), 1 );
    firstDayFormat.setFontUnderline( true );
    calendar->setDateTextFormat( firstMonthDay, firstDayFormat);

    //Set Background of first Saturday
    QTextCharFormat firstFridayFormat;
    QDate firstFriday( calendar->yearShown(), calendar->monthShown(), 1 );
    while( firstFriday.dayOfWeek() != Qt::Saturday )
        firstFriday = firstFriday.addDays( 1 );
    firstFridayFormat.setBackground( QBrush(Qt::lightGray) );
    calendar->setDateTextFormat( firstFriday, firstFridayFormat );

    //Set Background of first Sunday
    QTextCharFormat firstFridayFormat1;
    QDate firstFriday1( calendar->yearShown(), calendar->monthShown(), 1 );
    while( firstFriday1.dayOfWeek() != Qt::Sunday )
        firstFriday1 = firstFriday1.addDays( 1 );
    firstFridayFormat1.setBackground( QBrush(Qt::lightGray) );
    calendar->setDateTextFormat( firstFriday1, firstFridayFormat1 );

    /*
    QTextCharFormat mayFirstFormat;
    const QDate mayFirst(calendar->yearShown(), 5, 1);

    QTextCharFormat firstFridayFormat;
    QDate firstFriday(calendar->yearShown(), calendar->monthShown(), 1);
    while (firstFriday.dayOfWeek() != Qt::Friday)
        firstFriday = firstFriday.addDays(1);

    if (firstFridayCheckBox->isChecked()) {
        firstFridayFormat.setForeground(Qt::blue);
    } else { // Revert to regular colour for this day of the week.
        Qt::DayOfWeek dayOfWeek(static_cast<Qt::DayOfWeek>(firstFriday.dayOfWeek()));
        firstFridayFormat.setForeground(calendar->weekdayTextFormat(dayOfWeek).foreground());
    }

    calendar->setDateTextFormat(firstFriday, firstFridayFormat);

    // When it is checked, "May First in Red" always takes precedence over "First Friday in Blue".
    if (mayFirstCheckBox->isChecked()) {
        mayFirstFormat.setForeground(Qt::red);
    } else if (!firstFridayCheckBox->isChecked() || firstFriday != mayFirst) {
        // We can now be certain we won't be resetting "May First in Red" when we restore
        // may 1st's regular colour for this day of the week.
        Qt::DayOfWeek dayOfWeek(static_cast<Qt::DayOfWeek>(mayFirst.dayOfWeek()));
        calendar->setDateTextFormat(mayFirst, calendar->weekdayTextFormat(dayOfWeek));
    }

    calendar->setDateTextFormat(mayFirst, mayFirstFormat);
    */
}
