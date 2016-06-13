#include "m_clockpage.h"

MClockPage::MClockPage( QWidget *parent ) : MWidget( parent )
{
    this->initClass( );
}

void MClockPage::initClass( )
{
    this->initObjects( );
    this->initGuiElements( );
    this->initLayout( );
    this->initWindow( );
    this->initDefaultValues( );
    this->initConnections( );
    this->updateLanguage( );
}

void MClockPage::initObjects( )
{
}

void MClockPage::initGuiElements( )
{
    previewGroup = new MGroupBox( this );
    previewGroup->setCheckable( true );
    previewGroup->setChecked( true );
    previewGroup->setIcon( ":/images/image" );
    animationLabel = new QLabel( this );
    animationCheck = new QCheckBox( this );
    previewClock = new AnalogClock( this );

    visibleGroup = new MGroupBox( this );
    visibleGroup->setCheckable( true );
    visibleGroup->setChecked( true );
    visibleGroup->setIcon( ":/images/eye" );
    clockLabel = new QLabel( this );
    clockCheck = new QCheckBox( this );
    hourHandLabel = new QLabel( this );
    hourHandCheck = new QCheckBox( this );
    minuteHandLabel = new QLabel( this );
    minuteHandCheck = new QCheckBox( this );
    secondHandLabel = new QLabel( this );
    secondHandCheck = new QCheckBox( this );
    hourTickLabel = new QLabel( this );
    hourTickCheck = new QCheckBox( this );
    minuteTickLabel = new QLabel( this );
    minuteTickCheck = new QCheckBox( this );
    secondTickLabel = new QLabel( this );
    secondTickCheck = new QCheckBox( this );
    numbersLabel = new QLabel( this );
    numbersCheck = new QCheckBox( this );

    colorGroup = new MGroupBox( this );
    colorGroup->setCheckable( true );
    colorGroup->setChecked( true );
    colorGroup->setIcon( ":/images/color" );
    hourHandColorLabel = new QLabel( this );
    hourHandColorField = new MColorButton( this );
    minuteHandColorLabel = new QLabel( this );
    minuteHandColorField = new MColorButton( this );
    secondHandColorLabel = new QLabel( this );
    secondHandColorField = new MColorButton( this );
    hourTickColorLabel = new QLabel( this );
    hourTickColorField = new MColorButton( this );
    minuteTickColorLabel = new QLabel( this );
    minuteTickColorField = new MColorButton( this );
    secondTickColorLabel = new QLabel( this );
    secondTickColorField = new MColorButton( this );
    numbersColorLabel = new QLabel( this );
    numbersColorField = new MColorButton( this );

    settingsGroup = new MGroupBox( this );
    settingsGroup->setCheckable( true );
    settingsGroup->setChecked( true );
    settingsGroup->setIcon( ":/images/settings" );
    numberFontLabel = new QLabel( this );
    numberFontCombo = new QFontComboBox( this );
    intervalLabel = new QLabel( this );
    intervalSpin = new QSpinBox( this );
    intervalSpin->setRange( 1, 1000000 );
}

void MClockPage::initLayout( )
{
    visibleLayout = new QGridLayout;
    visibleLayout->addWidget( clockLabel, 10, 0 );
    visibleLayout->addWidget( clockCheck, 10, 1 );
    visibleLayout->addWidget( hourHandLabel, 20, 0 );
    visibleLayout->addWidget( hourHandCheck, 20, 1 );
    visibleLayout->addWidget( minuteHandLabel, 30, 0 );
    visibleLayout->addWidget( minuteHandCheck, 30, 1 );
    visibleLayout->addWidget( secondHandLabel, 40, 0 );
    visibleLayout->addWidget( secondHandCheck, 40, 1 );
    visibleLayout->addWidget( hourTickLabel, 50, 0 );
    visibleLayout->addWidget( hourTickCheck, 50, 1 );
    visibleLayout->addWidget( minuteTickLabel, 60, 0 );
    visibleLayout->addWidget( minuteTickCheck, 60, 1 );
    visibleLayout->addWidget( secondTickLabel, 70, 0 );
    visibleLayout->addWidget( secondTickCheck, 70, 1 );
    visibleLayout->addWidget( numbersLabel, 80, 0 );
    visibleLayout->addWidget( numbersCheck, 80, 1 );
    visibleGroup->setLayout( visibleLayout );

    colorLayout = new QGridLayout;
    colorLayout->addWidget( hourHandColorLabel, 10, 0 );
    colorLayout->addWidget( hourHandColorField, 10, 1 );
    colorLayout->addWidget( minuteHandColorLabel, 20, 0 );
    colorLayout->addWidget( minuteHandColorField, 20, 1 );
    colorLayout->addWidget( secondHandColorLabel, 30, 0 );
    colorLayout->addWidget( secondHandColorField, 30, 1 );
    colorLayout->addWidget( hourTickColorLabel, 40, 0 );
    colorLayout->addWidget( hourTickColorField, 40, 1 );
    colorLayout->addWidget( minuteTickColorLabel, 50, 0 );
    colorLayout->addWidget( minuteTickColorField, 50, 1 );
    colorLayout->addWidget( secondTickColorLabel, 60, 0 );
    colorLayout->addWidget( secondTickColorField, 60, 1 );
    colorLayout->addWidget( numbersColorLabel, 70, 0 );
    colorLayout->addWidget( numbersColorField, 70, 1 );
    colorGroup->setLayout( colorLayout );

    settingsLayout = new QGridLayout;
    settingsLayout->addWidget( numberFontLabel, 10, 0 );
    settingsLayout->addWidget( numberFontCombo, 10, 1 );
    settingsLayout->addWidget( intervalLabel, 20, 0 );
    settingsLayout->addWidget( intervalSpin, 20, 1 );
    settingsGroup->setLayout( settingsLayout );

    previewLayout = new QGridLayout;
    previewLayout->addWidget( animationLabel, 10, 0 );
    previewLayout->addWidget( animationCheck, 10, 1 );
    previewLayout->addWidget( previewClock, 20, 0, 1, 2 );
    previewGroup->setLayout( previewLayout );

    optionsLayout = new QVBoxLayout;
    optionsLayout->addWidget( visibleGroup, 0, Qt::AlignTop );
    optionsLayout->addWidget( colorGroup, 0, Qt::AlignTop );
    optionsLayout->addWidget( settingsGroup, 0, Qt::AlignTop );

    subLayout = new QHBoxLayout;
    subLayout->addLayout( optionsLayout, 0 );
    subLayout->addWidget( previewGroup, 0, Qt::AlignTop );

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout( subLayout );
    mainLayout->addStretch( 1 );
}

void MClockPage::initConnections( )
{
    connect( hourHandColorField, SIGNAL(sendColor(QColor)), previewClock, SLOT(setHourHandColor(QColor)) );
    connect( minuteHandColorField, SIGNAL(sendColor(QColor)), previewClock, SLOT(setMinuteHandColor(QColor)) );
    connect( secondHandColorField, SIGNAL(sendColor(QColor)), previewClock, SLOT(setSecondHandColor(QColor)) );

    connect( hourTickColorField, SIGNAL(sendColor(QColor)), previewClock, SLOT(setHourTickColor(QColor)) );
    connect( minuteTickColorField, SIGNAL(sendColor(QColor)), previewClock, SLOT(setMinuteTickColor(QColor)) );
    connect( secondTickColorField, SIGNAL(sendColor(QColor)), previewClock, SLOT(setSecondTickColor(QColor)) );

    connect( numbersColorField, SIGNAL(sendColor(QColor)), previewClock, SLOT(setNumberColor(QColor)) );

    connect( hourHandCheck, SIGNAL(toggled(bool)), previewClock, SLOT(setHourHand(bool)) );
    connect( minuteHandCheck, SIGNAL(toggled(bool)), previewClock, SLOT(setMinuteHand(bool)) );
    connect( secondHandCheck, SIGNAL(toggled(bool)), previewClock, SLOT(setSecondHand(bool)) );

    connect( numbersCheck, SIGNAL(toggled(bool)), previewClock, SLOT(setNumbers(bool)) );

    connect( animationCheck, SIGNAL(toggled(bool)), previewClock, SLOT(setAnimation(bool)) );

    connect( intervalSpin, SIGNAL(valueChanged(int)), previewClock, SLOT(setInterval(int)) );
    connect( numberFontCombo, SIGNAL(currentFontChanged(QFont)), previewClock, SLOT(setNumberFont(QFont)) );
}

void MClockPage::initWindow( )
{
    this->setLayout( mainLayout );
}

void MClockPage::initDefaultValues( )
{
}

void MClockPage::updateLanguage( )
{
    previewGroup->setTitle( tr("Preview") );
    animationLabel->setText( tr("Animation") );

    visibleGroup->setTitle( tr("Visibilities") );
    clockLabel->setText( tr("Clock") );
    hourHandLabel->setText( tr("Hour Hand") );
    minuteHandLabel->setText( tr("Minute Hand") );
    secondHandLabel->setText( tr("Second Hand") );
    hourTickLabel->setText( tr("Hour Tick") );
    minuteTickLabel->setText( tr("Minute Tick") );
    secondTickLabel->setText( tr("Second Tick") );
    numbersLabel->setText( tr("Numbers") );

    colorGroup->setTitle( tr("Colors") );
    hourHandColorLabel->setText( tr("Hour Hand") );
    minuteHandColorLabel->setText( tr("Minute Hand") );
    secondHandColorLabel->setText( tr("Second Hand") );
    hourTickColorLabel->setText( tr("Hour Tick") );
    minuteTickColorLabel->setText( tr("Minute Tick") );
    secondTickColorLabel->setText( tr("Second Tick") );
    numbersColorLabel->setText( tr("Numbers") );

    settingsGroup->setTitle( tr("Settings") );
    intervalLabel->setText( tr("Interval") );
    intervalSpin->setSuffix( tr(" ms") );
    numberFontLabel->setText( tr("Number Font") );
}
