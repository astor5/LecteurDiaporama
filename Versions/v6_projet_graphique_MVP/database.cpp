#include "database.h"
#include "lecteurvue.h"

#include <QSqlQuery>

database::database()
{
    if (openDataBase())
    {
        qDebug() << "Ouverture réussie";
    }
    else
    {
        qDebug() << "Echec de l'ouverture";
    }
}

bool database::openDataBase()
{
    // Définir les paramètres de connexion à la base de données
    mydb = QSqlDatabase::addDatabase(CONNECT_TYPE);
    mydb.setDatabaseName(DATABASE_NAME);
    if (!mydb.open()) {
        qDebug() << "Impossible d'ouvrir la base de données:" ;
        return false;
   }

   qDebug() << "Connexion à la base de données réussie.";
   return true;

}

void database::closeDataBase()
{
    // Fermer la connexion à la base de données
    mydb.close();
    qDebug() << "Connexion à la base de données fermée.";
}
