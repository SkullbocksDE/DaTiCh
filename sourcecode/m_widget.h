#ifndef M_WIDGET_H
#define M_WIDGET_H

#include <QWidget>

/**
 * @brief Wrapper class to have a fixed structure for widgets.
 * @details This is more a helper class to remind the developer not to forget to use this type of structure for widgets.
 *
 * #updateLanguage is important, because for the dynamic change of the language where all elements need to set their text again.
 *
 * #iniClass is important, because its called within the constructor and calls the other init-functions in a defined order.
 * @li #initObjects
 * @li #initGuiElements
 * @li #initLayout
 * @li #initWindow
 * @li #initDefaultValues
 * @li #initConnections
 * @li #updateLanguage
 *
 */
class MWidget : public QWidget
{

    Q_OBJECT

public:
    /**
     * @brief Constructor of the class
     * @param[in] QWidget Pointer to a parent widget.
     */
    MWidget( QWidget *parent = 0 );

signals:

public slots:
    /**
     * @brief This function will set to all elements the new translation.
     */
    virtual void updateLanguage( ) = 0;

private:
    /**
     * @brief initClass
     * @details The function will call the other init-functions. Keep the following order in mind:
     * @li #initObjects
     * @li #initGuiElements
     * @li #initLayout
     * @li #initWindow
     * @li #initDefaultValues
     * @li #initConnections
     * @li #updateLanguage
     */
    virtual void initClass( ) = 0;
    /**
     * @brief This function will init objects like structures, QObject's or QThread's.
     */
    virtual void initObjects( ) = 0;
    /**
     * @brief This function will init all graphical elements like QWidget's, QPushButton's, etc.
     */
    virtual void initGuiElements( ) = 0;
    /**
     * @brief This function will init all layouts to structure all graphical elements.
     */
    virtual void initLayout( ) = 0;
    /**
     * @brief This function will init the window itself and uses i. e. QWidget::setLayout or QWidget::setWindowFlags.
     */
    virtual void initWindow( ) = 0;
    /**
     * @brief This function will init the default values for the gui elements and also their data pendants.
     */
    virtual void initDefaultValues( ) = 0;
    /**
     * @brief This function will init all connections of the functions/elememts.
     * @see QObject::connect
     */
    virtual void initConnections( ) = 0;

};

#endif // M_WIDGET_H
