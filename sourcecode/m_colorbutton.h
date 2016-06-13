#ifndef M_COLORBUTTON_H
#define M_COLORBUTTON_H

#include <QWidget>
#include <QPainter>
#include <QColorDialog>
#include <QPaintEvent>
#include <QMouseEvent>

#define DEFAULT_COLORBUTTON_COLOR QColor( 255, 255, 255 )

/**
 * @brief This class will present a ColorButton build by using QWidget.
 * @details The MColorButton is able to popup a QColorDialog if you click the component via #mousePressEvent. After choosing a color, the color will be displayed.
 * @see mousePressEvent
 * @see setColor
 */
class MColorButton : public QWidget
{

    Q_OBJECT

public:
    /**
     * @brief Constructor of the class.
     * @param[in] QWidget Pointer to a parent widget.
     */
    MColorButton( QWidget *parent = 0 );
    /**
     * @brief Constructor of the class.
     * @param[in] QWidget Pointer to a parent widget.
     * @param[in] QColor First color which should be displayed.
     */
    MColorButton( QWidget *parent, QColor color );
    /**
     * @brief Constructor of the class.
     * @param[in] QWidget Pointer to a parent widget.
     * @param[in] int Red channel of the color which should be displayed.
     * @param[in] int Green channel of the color which should be displayed.
     * @param[in] int Blue channel of the color which should be displayed.
     */
    MColorButton( QWidget *parent, int red, int green, int blue );
    /**
     * @brief Function to get the current color.
     * @param[out] QColor Returns the current choosen color.
     */
    QColor getColor( );

public slots:
    /**
     * @brief Function to set a new color.
     * @param[in] QColor Color which should be displayed.
     */
    void setColor( QColor color );
    /**
     * @brief Function to set a new color.
     * @param[in] int Red channel of the color which should be displayed.
     * @param[in] int Green channel of the color which should be displayed.
     * @param[in] int Blue channel of the color which should be displayed.
     */
    void setColor( int red, int green, int blue );

signals:
    /**
     * @brief Signal which will send the color, when the user chooses a new color via the color dialog.
     */
    void sendColor( QColor );

protected:
    /**
     * @brief Overwritten function of QWidget to present the color.
     * @param[in] QPaintEvent Pointer to the paintevent handle.
     */
    void paintEvent( QPaintEvent *event );
    /**
     * @brief Overwritten function of QWidget::mousePressEvent to open up a QColorDialog after a mouse click.
     * @param[in] QMouseEvent Pointer to the mouseevent handle.
     * @see QColorDialog::getColor
     */
    void mousePressEvent( QMouseEvent *event );

private:
    QColor buttonColor; //!< QColor to store the color of the button.

};

#endif // M_COLORBUTTON_H
