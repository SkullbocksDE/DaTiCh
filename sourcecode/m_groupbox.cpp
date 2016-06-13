#include "m_groupbox.h"

MGroupBox::MGroupBox( QWidget *parent ) : QGroupBox( parent )
{
    connect( this, SIGNAL(toggled(bool)), this, SLOT(setFlat(bool)) );
    savedSS = this->styleSheet( );
    this->adjustStyleSheet( );
}

MGroupBox::MGroupBox( const QString &title, QWidget *parent ) : QGroupBox( title, parent )
{
    connect( this, SIGNAL(toggled(bool)), this, SLOT(setFlat(bool)) );
    savedSS = this->styleSheet( );
    this->adjustStyleSheet( );
}

void MGroupBox::setFlat( bool _flat )
{
    QGroupBox::setFlat( !_flat );
    this->collapse( );
}

void MGroupBox::setIcon( QString _path )
{
    iconPixmap = QPixmap( _path );
    int fontSize = 12;
    int borderWeight = 2;
    int paddingSize = (iconPixmap.height()-fontSize)/2 + borderWeight;
    adjustStyleSheet( );
    this->setStyleSheet( this->styleSheet() +
                         "QGroupBox::title {"
                             "background-color:#fff;"
                             "font-size:"+QString::number(fontSize)+"px;"
                             "subcontrol-origin: margin;"
                             "subcontrol-position: top left;"
                             "background-image: url('"+_path+"');"
                             "background-repeat:no-repeat;"
                             "background-position:left center;"
                             "vertical-align:middle;"
                             "padding:"+QString::number(paddingSize)+"px;"
                             "padding-left:36px;"
                             "border:"+QString::number(borderWeight)+"px outset #f30;"
                             "border-bottom:0px outset #fc0;"
                             "border-top-left-radius:6px;"
                             "border-top-right-radius:6px;"
                         "}"
                         "QGroupBox::title:flat {"
                             "background-color:#fff;"
                             "padding:"+QString::number(paddingSize)+"px;"
                             "padding-left:36px;"
                             "padding-left:36px;"
                             "border:"+QString::number(borderWeight)+"px outset #f30;"
                             "border-radius:0px;"
                             "border-bottom-right-radius:20px;"
                             "border-top-right-radius:20px;"
                         "}"
    );
}

void MGroupBox::collapse( )
{
    if( this->isChecked( ) == false )
    {
        int fontSize = 12;
        int borderWeight = 2;
        int paddingSize = (iconPixmap.height()-fontSize)/2 + borderWeight;
        this->setFixedHeight( paddingSize*2 + fontSize + borderWeight*2 + 1 );
    }
    else
    {
        this->setFixedHeight( this->sizeHint().height() );
    }
}

void MGroupBox::adjustStyleSheet( )
{
    int borderWeight = 2;
    this->setStyleSheet
    (
        savedSS +
        "QGroupBox {"
            "border:"+QString::number(borderWeight)+"px outset #f30;"
            "margin:0px;"
            "margin-top:38px;"
            "padding-right:20px;"
            "border-radius:20px;"
            "border-bottom-left-radius:0px;"
            "border-top-left-radius:0px;"
            "background-color:#fff;"
        "}"
        "QGroupBox:flat {"
            "border:0px outset #f30;"
            "margin:0px;"
            "margin-top:38px;"
            "border-radius:20px;"
            "border-bottom-left-radius:0px;"
            "border-top-left-radius:0px;"
            "background-color:transparent;"
        "}"
        "QGroupBox::indicator {"
            "subcontrol-origin: margin;"
            "subcontrol-position: center left;"
            "width: 7px;"
            "height: 7px;"
            "vertical-align:middle;"
        "}"
        "QGroupBox::indicator:unchecked {"
            "image: url(':/images/arrow_right');"
        "}"
        "QGroupBox::indicator:checked {"
            "image: url(':/images/arrow_down');"
        "}"
    );
}
