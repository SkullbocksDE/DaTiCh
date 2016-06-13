#ifndef M_LANGUAGEHANDLER_H
#define M_LANGUAGEHANDLER_H

#include <QObject>
#include <QTranslator>
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QDirIterator>

/**
 * @brief This class will handle the translations of the application.
 * @details This class is based on two qrc-files: languages.qrc and qt_languagges.qrc.
 * Both files includes the qm-translation files for the application messages and the internal Qt messages.
 * The qm-translations of Qt are located in: {QT-DIR}\QtX.X.X\X.X\{compiler}\translations
 * Qt or better QApplication references only on one intance of QTranslator.
 * If you loose the reference to it, you can't handle language changes anymore.
 * Furthermore you can't access this function from other classes until they get the pointer.
 * @todo If Qt implements "QList<QTranslator*> QApplication::installedTranslators( );" remove the extern global define or to find better work-a-round.
 */
class MLanguageHandler : public QObject
{

    Q_OBJECT

public:
    /**
     * @brief Enum to handle the different translators for Qt and the application.
     */
    enum TranslationType { App, //!< Values that controls the #appTranslator
                           Qt //!< Values that controls the #qtTranslator
                         };
    Q_ENUMS( TranslationType )

    /**
     * @brief Constructor of the class.
     * @param[in] QObject Pointer to a parent object.
     */
    MLanguageHandler( QObject *parent = 0 );
    /**
     * @brief This method will call #loadLanguage twice; first for Qt and then for App.
     * @param[in] QString Name of the language i. e. 'German' or 'English-UK'
     * @return bool Returns if the installations of #qtTranslator and #appTranslator were successfully.
     */
    bool changeLanguage( QString languageName );
    /**
     * @brief This method will return all available translations of the application.
     * @details This method will handle the qrc-file languages.qrc as a folder and collects all available qm-file with their aliases.
     * @return QStringList Returns a list with all available translations of the application.
     */
    QStringList availableLanguages( );

private:
    /**
     * @brief This method will try based on the TranslationType to install #qtTranslator or #appTranslator for the given language name.
     * @param[in] QString Name of the language i. e. 'German' or 'English-UK'
     * @param[in] TranslationType The type of the to installing QTranslator.
     * @return bool Returns if the installations of #qtTranslator and #appTranslator were successfully.
     */
    bool loadLanguage( QString languageName, TranslationType type = App );

    QTranslator qtTranslator; //!< Translator for internal Qt messages.
    QTranslator appTranslator; //!< Translator for application messages.

};
extern MLanguageHandler *languageHandler; //!< Global pointer to the class MLanguageHandler
                                          //!< We need this global pointer to have an all time
                                          //!< available instance of the two QTranslator MLanguageHandler::qtTranslator and MLanguageHandler::appTranslator.
                                          //!< The first is for Qt internal messages and the second for the application messages.

#endif // M_LANGUAGEHANDLER_H
