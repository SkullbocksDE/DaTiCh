#include "m_calendarpage.h"

MCalendarPage::MCalendarPage( QWidget *parent ) : MWidget( parent )
{
    this->initClass( );
}

void MCalendarPage::initClass( )
{
    this->initObjects( );
    this->initGuiElements( );
    this->initLayout( );
    this->initWindow( );
    this->initDefaultValues( );
    this->initConnections( );
    this->updateLanguage( );
}

void MCalendarPage::initObjects( )
{
}

void MCalendarPage::initGuiElements( )
{
    previewGroup = new MGroupBox( this );
    previewGroup->setCheckable( true );
    previewGroup->setChecked( true );
    previewGroup->setIcon( ":/images/eye" );
    calendar = new QCalendarWidget( this );

    optionsGroup = new MGroupBox( this );
    optionsGroup->setCheckable( true );
    optionsGroup->setChecked( true );
    optionsGroup->setIcon( ":/images/settings" );

    gridLabel = new QLabel( this );
    gridCheckBox = new QCheckBox( this );

    navigationLabel = new QLabel( this );
    navigationCheckBox = new QCheckBox( this );

    horizontalHeaderLabel = new QLabel( this );

    formatGroup = new MGroupBox( this );
    formatGroup->setCheckable( true );
    formatGroup->setChecked( true );
    formatGroup->setIcon( ":/images/format" );
    addFormatButton = new QPushButton( this );
    removeFormatButton = new QPushButton( this );
    formatTable = new QTableWidget( this );
    refreshFormatButton = new QPushButton( this );

    headerTextFormatCombo = new QComboBox( this );
    headerTextFormatCombo->addItem( tr("Bold") );
    headerTextFormatCombo->addItem( tr("Italic") );
    headerTextFormatCombo->addItem( tr("Plain") );

    horizontalHeaderCombo = new QComboBox( this );
    horizontalHeaderCombo->addItem( tr("Single letter day names"), QCalendarWidget::SingleLetterDayNames );
    horizontalHeaderCombo->addItem( tr("Short day names"), QCalendarWidget::ShortDayNames );
    horizontalHeaderCombo->addItem( tr("None"), QCalendarWidget::NoHorizontalHeader );

    verticalHeaderLabel = new QLabel( this );

    verticalHeaderCombo = new QComboBox( this );
    verticalHeaderCombo->addItem( tr("ISO week numbers"), QCalendarWidget::ISOWeekNumbers );
    verticalHeaderCombo->addItem( tr("None"), QCalendarWidget::NoVerticalHeader );

    textFormatsGroupBox = new QGroupBox( this );

//        weekdayColorCombo = createColorComboBox( );
//        weekdayColorCombo->setCurrentIndex( weekdayColorCombo->findText(tr("Black")) );

    weekdayColorLabel = new QLabel( this );
//        weekdayColorLabel->setBuddy( weekdayColorCombo );

//        weekendColorCombo = createColorComboBox( );
//        weekendColorCombo->setCurrentIndex( weekendColorCombo->findText(tr("Red")) );

    weekendColorLabel = new QLabel( this );


    headerTextFormatLabel = new QLabel( this );

    firstFridayCheckBox = new QCheckBox( this );

    mayFirstCheckBox = new QCheckBox( this );
}

void MCalendarPage::initLayout( )
{
    previewLayout = new QVBoxLayout;
    previewLayout->addWidget( calendar );
    previewGroup->setLayout( previewLayout );

    formatLayout = new QGridLayout( this );
    formatLayout->addWidget( addFormatButton, 10, 0 );
    formatLayout->addWidget( removeFormatButton, 10, 1 );
    formatLayout->addWidget( formatTable, 20, 0, 1, 2 );
    formatLayout->addWidget( refreshFormatButton, 30, 0, 1, 2 );
    formatGroup->setLayout( formatLayout );

    optionsLayout = new QGridLayout;
    optionsLayout->addWidget( gridLabel, 10, 0 );
    optionsLayout->addWidget( gridCheckBox, 10, 1 );
    optionsLayout->addWidget( navigationLabel, 20, 0 );
    optionsLayout->addWidget( navigationCheckBox, 20, 1 );
    optionsLayout->addWidget( horizontalHeaderLabel, 30, 0 );
    optionsLayout->addWidget( horizontalHeaderCombo, 30, 1 );
    optionsLayout->addWidget( verticalHeaderLabel, 40, 0 );
    optionsLayout->addWidget( verticalHeaderCombo, 40, 1 );
    optionsGroup->setLayout( optionsLayout );

    sideLayout = new QVBoxLayout;
    sideLayout->addWidget( optionsGroup, 0, Qt::AlignTop );
    sideLayout->addWidget( formatGroup, 0, Qt::AlignTop );

    mainLayout = new QHBoxLayout;
    mainLayout->addLayout( sideLayout );
    mainLayout->addWidget( previewGroup );
}

void MCalendarPage::initConnections( )
{
    connect( gridCheckBox, SIGNAL(toggled(bool)), calendar, SLOT(setGridVisible(bool)) );
    connect( navigationCheckBox, SIGNAL(toggled(bool)), calendar, SLOT(setNavigationBarVisible(bool)) );
    connect( horizontalHeaderCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(setHorizontalHeader(int)) );
    connect( verticalHeaderCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(setVerticalHeader(int)) );
    connect( addFormatButton, SIGNAL(clicked()), this, SLOT(addFormat()) );
    connect( removeFormatButton, SIGNAL(clicked()), this, SLOT(removeFormat()) );
    connect( refreshFormatButton, SIGNAL(clicked()), this, SLOT(refreshFormat()) );
}

void MCalendarPage::initWindow( )
{
    this->setLayout( mainLayout );
}

void MCalendarPage::initDefaultValues( )
{
}

void MCalendarPage::updateLanguage( )
{
    optionsGroup->setTitle( tr("Options") );
    gridLabel->setText( tr("Grid") );
    navigationLabel->setText( tr("Navigation") );
    horizontalHeaderLabel->setText( tr("Horizontal Header") );
    verticalHeaderLabel->setText( tr("Vertical Header") );
    previewGroup->setTitle( tr("Preview") );
    formatGroup->setTitle( tr("Format") );
    addFormatButton->setText( tr("Add Format") );
    removeFormatButton->setText( tr("Remove Format") );
    refreshFormatButton->setText( tr("Refresh Format") );
    QStringList hList;
    hList << tr("Date");
    hList << tr("Text Color");
    hList << tr("Background");
    formatTable->setColumnCount( hList.count() );
    formatTable->setHorizontalHeaderLabels( hList );


    textFormatsGroupBox->setTitle( tr("Text Formats") );
    weekdayColorLabel->setText( tr("&Weekday color:") );
    weekendColorLabel->setText( tr("Week&end color:") );

    headerTextFormatLabel->setText( tr("&Header text:") );
    firstFridayCheckBox->setText( tr("&First Friday in blue") );
    mayFirstCheckBox->setText( tr("May &1 in red") );

    headerTextFormatCombo->setItemText( 0, tr("Bold") );
    headerTextFormatCombo->setItemText( 1, tr("Italic") );
    headerTextFormatCombo->setItemText( 2, tr("Plain") );

    horizontalHeaderCombo->setItemText( 0, tr("Single letter day names") );
    horizontalHeaderCombo->setItemText( 1, tr("Short day names") );
    horizontalHeaderCombo->setItemText( 2, tr("None") );

    verticalHeaderCombo->setItemText( 0, tr("ISO week numbers") );
    verticalHeaderCombo->setItemText( 1, tr("None") );

}

void MCalendarPage::setHorizontalHeader( int index )
{
    calendar->setHorizontalHeaderFormat( (QCalendarWidget::HorizontalHeaderFormat)horizontalHeaderCombo->itemData( index ).toInt() );
}

void MCalendarPage::setVerticalHeader( int index )
{
    calendar->setVerticalHeaderFormat( (QCalendarWidget::VerticalHeaderFormat)verticalHeaderCombo->itemData( index ).toInt() );
}

void MCalendarPage::addFormat( )
{
    formatTable->insertRow( formatTable->rowCount() );
    formatTable->setCellWidget( formatTable->rowCount()-1, 0, new QDateEdit(this) );
    formatTable->setCellWidget( formatTable->rowCount()-1, 1, new MColorButton(this) );
    formatTable->setCellWidget( formatTable->rowCount()-1, 2, new MColorButton(this) );
}

void MCalendarPage::removeFormat( )
{
    QList<QTableWidgetItem*> sList = formatTable->selectedItems();
    for( int i = 0; i < sList.count(); i++ )
    {
        formatTable->removeRow( sList.at(i)->row() );
    }
}

void MCalendarPage::refreshFormat( )
{
    QDate cDate;
    QTextCharFormat cFormat;
    calendar->setDateTextFormat( cDate, cFormat );
    for( int i = 0; i < formatTable->rowCount(); i++ )
    {
        QTextCharFormat tFormat;
        tFormat.setForeground( qobject_cast<MColorButton*>(formatTable->cellWidget( i, 1 ))->getColor() );
        tFormat.setBackground( qobject_cast<MColorButton*>(formatTable->cellWidget( i, 2 ))->getColor() );
        calendar->setDateTextFormat( qobject_cast<QDateEdit*>(formatTable->cellWidget( i, 0 ))->date(), tFormat );
    }
}
