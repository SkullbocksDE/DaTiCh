#ifndef CLOCKPAGE_H
#define CLOCKPAGE_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QSpinBox>
#include <QFontComboBox>
#include <QLayout>

#include "m_groupbox.h"
#include "analogclock.h"
#include "m_colorbutton.h"
#include "m_widget.h"

class MClockPage : public MWidget
{

    Q_OBJECT

public:
    MClockPage( QWidget *parent = 0 );

public slots:
    void updateLanguage( );

private:
    void initClass( );
    void initObjects( );
    void initGuiElements( );
    void initLayout( );
    void initWindow( );
    void initDefaultValues( );
    void initConnections( );

    QVBoxLayout *mainLayout;
    QVBoxLayout *optionsLayout;
    QHBoxLayout *subLayout;

    MGroupBox *previewGroup;
    QGridLayout *previewLayout;
    QLabel *animationLabel;
    QCheckBox *animationCheck;
    AnalogClock *previewClock;

    MGroupBox *visibleGroup;
    QGridLayout *visibleLayout;
    QLabel *clockLabel;
    QCheckBox *clockCheck;
    QLabel *hourHandLabel;
    QCheckBox *hourHandCheck;
    QLabel *minuteHandLabel;
    QCheckBox *minuteHandCheck;
    QLabel *secondHandLabel;
    QCheckBox *secondHandCheck;
    QLabel *hourTickLabel;
    QCheckBox *hourTickCheck;
    QLabel *minuteTickLabel;
    QCheckBox *minuteTickCheck;
    QLabel *secondTickLabel;
    QCheckBox *secondTickCheck;
    QLabel *numbersLabel;
    QCheckBox *numbersCheck;

    MGroupBox *colorGroup;
    QGridLayout *colorLayout;
    QLabel *hourHandColorLabel;
    MColorButton *hourHandColorField;
    QLabel *minuteHandColorLabel;
    MColorButton *minuteHandColorField;
    QLabel *secondHandColorLabel;
    MColorButton *secondHandColorField;
    QLabel *hourTickColorLabel;
    MColorButton *hourTickColorField;
    QLabel *minuteTickColorLabel;
    MColorButton *minuteTickColorField;
    QLabel *secondTickColorLabel;
    MColorButton *secondTickColorField;
    QLabel *numbersColorLabel;
    MColorButton *numbersColorField;

    MGroupBox *settingsGroup;
    QGridLayout *settingsLayout;
    QLabel *intervalLabel;
    QSpinBox *intervalSpin;
    QLabel *numberFontLabel;
    QFontComboBox *numberFontCombo;

};

#endif // CLOCKPAGE_H
