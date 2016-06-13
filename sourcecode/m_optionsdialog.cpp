#include "m_optionsdialog.h"

MOptionsDialog::MOptionsDialog( QWidget *parent ) : QDialog( parent )
{
    contentsWidget = new QListWidget;
    contentsWidget->setViewMode( QListView::IconMode );
    contentsWidget->setIconSize( QSize(96, 84) );
    contentsWidget->setMovement( QListView::Static );
    contentsWidget->setMaximumWidth( 128 );
    contentsWidget->setSpacing( 12 );

    pagesWidget = new QStackedWidget;
    pagesWidget->addWidget( new MClockPage );
    pagesWidget->addWidget( new MCalendarPage );

    closeButton = new QPushButton( tr("Close"), this );

    this->createIcons( );
    contentsWidget->setCurrentRow( 0 );

    connect( closeButton, SIGNAL(clicked()), this, SLOT(close()) );

    horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget( contentsWidget );
    horizontalLayout->addWidget( pagesWidget, 1 );

    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch( 1 );
    buttonsLayout->addWidget( closeButton );

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout( horizontalLayout );
    mainLayout->addStretch( 1 );
    mainLayout->addSpacing( 12 );
    mainLayout->addLayout( buttonsLayout );
    this->setLayout( mainLayout );

    this->setWindowTitle( tr("Config Dialog") );

    this->setWindowIcon( QIcon(":/images/options") );
}

void MOptionsDialog::changePage( QListWidgetItem *current, QListWidgetItem *previous )
{
    if( !current )
        current = previous;

    pagesWidget->setCurrentIndex( contentsWidget->row(current) );
}

void MOptionsDialog::updateLanguage( )
{

}

void MOptionsDialog::createIcons( )
{
    clockButton = new QListWidgetItem( contentsWidget );
    clockButton->setIcon( QIcon(":/images/clock") );
    clockButton->setText( tr("Clock") );
    clockButton->setTextAlignment( Qt::AlignHCenter );
    clockButton->setFlags( Qt::ItemIsSelectable | Qt::ItemIsEnabled );

    calendarButton = new QListWidgetItem( contentsWidget );
    calendarButton->setIcon( QIcon(":/images/calendar") );
    calendarButton->setText( tr("Calendar") );
    calendarButton->setTextAlignment( Qt::AlignHCenter );
    calendarButton->setFlags( Qt::ItemIsSelectable | Qt::ItemIsEnabled );

    connect( contentsWidget,
            SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this,
            SLOT(changePage(QListWidgetItem*,QListWidgetItem*)) );
}
