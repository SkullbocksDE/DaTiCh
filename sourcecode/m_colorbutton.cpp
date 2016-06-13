#include "m_colorbutton.h"

MColorButton::MColorButton( QWidget *parent ) : QWidget( parent )
{
    buttonColor = DEFAULT_COLORBUTTON_COLOR;
    this->setMinimumWidth( 20 );
}

MColorButton::MColorButton( QWidget *parent, QColor color ) : QWidget( parent )
{
    if( color.isValid() == true )
    {
        buttonColor = color;
    }
    else
    {
        buttonColor = DEFAULT_COLORBUTTON_COLOR;
    }
}

MColorButton::MColorButton( QWidget *parent, int red, int green, int blue ) : QWidget( parent )
{
    buttonColor = QColor( red, green, blue );
}

void MColorButton::setColor( QColor color )
{
    buttonColor = color;
    this->repaint( );
}

QColor MColorButton::getColor( )
{
    return buttonColor;
}

void MColorButton::setColor( int red, int green, int blue )
{
    buttonColor = QColor( red, green, blue );
    this->repaint( );
}

void MColorButton::paintEvent( QPaintEvent *event )
{
    QPainter painter( this );
    painter.setPen( buttonColor );
    painter.setBrush( QBrush(buttonColor,Qt::SolidPattern) );
    painter.drawRect( 0, 0, this->width()-1, this->height()-1 );

    QRadialGradient rGradient;
    rGradient.setCenter( this->width()/4,this->height()/2);
    rGradient.setFocalPoint( this->width()/4,this->height()/2);
    rGradient.setRadius( this->width()/2);
    rGradient.setColorAt( 0, QColor(255,255,255,64) );
    rGradient.setColorAt( 0.7, QColor(255,255,255,0) );

    painter.fillRect( 0, 0, this->width(), this->height(), rGradient );

    painter.setPen( QColor(0,0,0) );
    painter.setBrush( Qt::NoBrush );
    painter.drawRect( 0, 0, this->width()-1, this->height()-1 );
    event->accept( );
}

void MColorButton::mousePressEvent( QMouseEvent *event )
{
    QColor tempColor = QColorDialog::getColor( buttonColor, this, tr("Select color") );
    if( tempColor.isValid() == true )
    {
        buttonColor = tempColor;
        this->repaint( );
        emit sendColor( buttonColor );
    }
    event->accept( );
}
