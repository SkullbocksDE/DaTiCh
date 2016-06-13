/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>

#include "analogclock.h"

AnalogClock::AnalogClock( QWidget *parent ) : QWidget( parent )
{
    this->currentTime = QTime::currentTime( );

    this->setWindowTitle( tr("Analog Clock") );
    this->setMinimumSize( 200, 200 );

    hourColor = QColor( 127, 0, 127 );
    minuteColor = QColor( 0, 127, 127, 191 );
    secondColor = QColor( 0, 0, 0, 200 );

    hourTickColor = QColor( 127, 0, 127 );
    minuteTickColor = QColor( 0, 127, 127, 191 );
    secondTickColor = QColor( 0, 0, 0, 200 );

    numberColor = QColor( 0, 0, 0, 255 );

    numberFont = QApplication::font( );

    hourHand = true;
    minuteHand = true;
    secondHand = true;
    numbers = true;
    animation = true;
    intervalMs = 1000;

    timer = new QTimer( this );
    connect( timer, SIGNAL(timeout()), this, SLOT(update()) );
    timer->setInterval( intervalMs );
    timer->start( );
}

void AnalogClock::setCurrentTime( QTime newTime )
{
    this->currentTime = newTime;
    this->elapsedTime = newTime;
    this->elapsedTime.start();
    this->update( );
}

void AnalogClock::setHourHandColor( QColor _color )
{
    hourColor = _color;
    this->repaint( );
}

void AnalogClock::setMinuteHandColor( QColor _color )
{
    minuteColor = _color;
    this->repaint( );
}

void AnalogClock::setSecondHandColor( QColor _color )
{
    secondColor = _color;
    this->repaint( );
}

void AnalogClock::setHourTickColor( QColor _color )
{
    hourTickColor = _color;
    this->repaint( );
}

void AnalogClock::setMinuteTickColor( QColor _color )
{
    minuteTickColor = _color;
    this->repaint( );
}

void AnalogClock::setSecondTickColor( QColor _color )
{
    secondTickColor = _color;
    this->repaint( );
}

void AnalogClock::setNumberColor( QColor _color )
{
    numberColor = _color;
    this->repaint( );
}

void AnalogClock::setHourHand( bool _visible )
{
    hourHand = _visible;
    this->repaint( );
}

void AnalogClock::setMinuteHand( bool _visible )
{
    minuteHand = _visible;
    this->repaint( );
}

void AnalogClock::setSecondHand( bool _visible )
{
    secondHand = _visible;
    this->repaint( );
}

void AnalogClock::setNumbers( bool _visible )
{
    numbers = _visible;
    this->repaint( );
}

void AnalogClock::setAnimation( bool _state )
{
    animation = _state;
    if( animation )
        timer->start( );
    else
        timer->stop( );
    this->repaint( );
}

void AnalogClock::setInterval( int timeMs )
{
    intervalMs = timeMs;
    timer->setInterval( intervalMs );
    this->repaint( );
}

void AnalogClock::setNumberFont( QFont _font )
{
    numberFont = _font;
    this->repaint( );
}

void AnalogClock::paintEvent( QPaintEvent * )
{
    QPainter painter( this );
    painter.setRenderHint( QPainter::Antialiasing );

    int fireSize = qMin( width()/2, height()/2 );
    QPoint firePoint( painter.window().width()/2, painter.window().height()/2 );
    QRadialGradient rg( firePoint, fireSize );
    rg.setColorAt( 0, QColor(255,215,0) );
    rg.setColorAt( 1, QColor(255,165,0) );
    painter.setBrush( QBrush(rg) );
    painter.drawEllipse( painter.window().width()/2-100, 0, 200, 200 );

    static const QPoint hourHandPoint[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -40)
    };
    static const QPoint minuteHandPoint[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -70)
    };
    static const QPoint secondHandPoint[3] = {
        QPoint(2, 2),
        QPoint(-2, 2),
        QPoint(0, -90)
    };

    int side = qMin( width(), height() );

    QTime time = this->currentTime;
    if( animation == true )
    {
        this->currentTime = this->currentTime.addMSecs( this->elapsedTime.elapsed() );
        emit sendNewTime( this->currentTime );
        this->elapsedTime.restart();
        time = this->currentTime;
    }

    painter.translate( width() / 2, height() / 2 );
    painter.scale( side / 200.0, side / 200.0 );

    painter.setPen( Qt::NoPen );
    painter.setBrush( hourColor );

    painter.save( );
    painter.rotate( 30.0 * ((time.hour() + time.minute() / 60.0)) );
    if( hourHand )
        painter.drawConvexPolygon( hourHandPoint, 3 );
    painter.restore( );

    painter.setPen( hourTickColor );
    for( int i = 0; i < 12; ++i )
    {
        painter.drawLine( 88, 0, 96, 0 );
        painter.rotate( 30.0 );
    }

    if( numbers == true )
    {
        painter.setPen( numberColor );
        painter.rotate( -60.0 );
        painter.setFont( numberFont );
        for( int i = 0; i < 12; ++i )
        {
            painter.drawText( 88, 0, QString::number(i+1) );
            painter.rotate( 30.0 );
        }
        painter.setFont( QApplication::font() );
        painter.rotate( 60.0 );
    }

    painter.setPen( Qt::NoPen );
    painter.setBrush( minuteColor );

    painter.save( );
    painter.rotate( 6.0 * (time.minute() + time.second() / 60.0) );
    if( minuteHand )
        painter.drawConvexPolygon( minuteHandPoint, 3 );
    painter.restore( );

    painter.setPen( minuteTickColor );
    for( int j = 0; j < 60; ++j )
    {
        if( (j % 5) != 0 )
            painter.drawLine( 92, 0, 96, 0 );
        painter.rotate( 6.0 );
    }

    painter.setPen( Qt::NoPen );
    painter.setBrush( secondColor );

    painter.save( );
    painter.rotate( 6.0 * (time.second() + ((time.msec()/1000.00)*60.0) / 60.0) );
    if( secondHand )
        painter.drawConvexPolygon( secondHandPoint, 3 );
    painter.restore( );

    painter.setPen( secondTickColor );
/*
    for( int j = 0; j < 60; ++j )
    {
        if( (j % 5) != 0 )
            painter.drawLine( 92, 0, 96, 0 );
        painter.rotate( 6.0 );
    }
*/
}
