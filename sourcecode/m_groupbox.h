#ifndef M_GROUPBOX_H
#define M_GROUPBOX_H

#include <QWidget>
#include <QGroupBox>
#include <QPixmap>

/**
 * @brief This class will present a normal QGroupBox with some extra features like a collapsable container.
 * @details With MQGroupBox you are able to setup a collapsable groupbox with an icon in its header.
 * @see collapse
 * @see setFlat
 */
class MGroupBox : public QGroupBox
{

    Q_OBJECT

public:
    /**
     * @brief Constructor of the class.
     * @param[in] QWidget Pointer to a parent widget.
     */
    MGroupBox( QWidget *parent = 0 );

    /**
     * @brief Constructor of the class.
     * @param[in] QString The displayed title in the header.
     * @param[in] QWidget Pointer to a parent widget.
     */
    MGroupBox( const QString &title, QWidget* parent = 0 );

public slots:
    /**
     * @brief This function is overwritten and calls the parent function QGroupBox::setFlat and #collapse.
     * @param[in] bool If its flatten or not.
     */
    void setFlat( bool _flat );
    /**
     * @brief This function will set an icon to the header.
     * @param[in] QString Path to the icon. Can be relative, absolute or a resource path.
     */
    void setIcon( QString _path );
    /**
     * @brief This function will toggle the collapse state of the container.
     */
    void collapse( );

private:
    /**
     * @brief This function will adjust the style sheet of the groupbox.
     */
    void adjustStyleSheet( );

    QString savedSS; //!< QString to temporary store the internal stylesheet of the groupbox.
    QPixmap iconPixmap; //!< QPixmap to store the set Icon via ::setIcon.

};
#endif // M_GROUPBOX_H
