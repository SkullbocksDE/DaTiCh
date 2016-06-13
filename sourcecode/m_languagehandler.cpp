#include "m_languagehandler.h"

MLanguageHandler *languageHandler;

MLanguageHandler::MLanguageHandler( QObject *parent ) : QObject( parent )
{

}

bool MLanguageHandler::changeLanguage( QString languageName )
{
    if( MLanguageHandler::loadLanguage( languageName ) == true )
    {
        return MLanguageHandler::loadLanguage( languageName, Qt );
    }
    else
        return false;
}

bool MLanguageHandler::loadLanguage( QString languageName, TranslationType type )
{
    if( languageName.isEmpty() == false )
    {
        QString translatorPath = "";
        switch( type )
        {
            case Qt:
            {
                translatorPath += ":/qt_languages/"+languageName;
                qApp->removeTranslator( &qtTranslator );
                if( qtTranslator.load( translatorPath ) == true )
                {
                    return qApp->installTranslator( &qtTranslator );
                }
            }
            break;
            case App:
            default:
            {
                translatorPath += ":/languages/"+languageName;
                appTranslator.isEmpty();
                qApp->removeTranslator( &appTranslator );
                if( appTranslator.load( translatorPath ) == true )
                {
                    return qApp->installTranslator( &appTranslator );
                }
            }
            break;
        }
    }
    else
        return false;
}

QStringList MLanguageHandler::availableLanguages( )
{
    QDirIterator it( ":/languages/", QDirIterator::Subdirectories );
    QStringList languageList;
    while( it.hasNext() == true )
    {
        languageList << it.next( ).replace( ":/languages/", "" );
    }
    return languageList;
}
