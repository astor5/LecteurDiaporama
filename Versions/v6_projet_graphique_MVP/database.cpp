#include "database.h"
#include "lecteurvue.h"

#include <QSqlQuery>
#include "vector"

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

void database::chargerDiapos(vector<Diaporama *> & mesDiapos)
{
    // requête SQL n°1
    QSqlQuery query;
    if (query.exec("SELECT * FROM Diaporamas;"))
    {
        // Remplir le QTableWidget avec les résultats de la requête
        while (query.next())
        {
            Diaporama * diapoCharge = new Diaporama(query.value(1).toString().toStdString(), query.value(0).toInt(), query.value(2).toInt());
            mesDiapos.push_back(diapoCharge);
        }
    }
    else
    {
        qDebug() << "Erreur lors de l'exécution de la requête SQL:";
    }
}

void database::chargerImages(int id, vector<Image> pImages)
{
    QSqlQuery query;
    ImageDansDiaporama imageDansDiapo;
    Image imageACharger("", "", ":/images/Disney_tapis.gif");

    QString insertions="SELECT * FROM `Diapos` D JOIN DiaposDansDiaporama DDD ON DDD.idDiapo = D.idphoto JOIN Familles F ON F.idFamille = D.idFam JOIN Diaporamas DS ON DS.idDiaporama = DDD.idDiaporama WHERE DS.idDiaporama = :idDiapo;";
    query.prepare(insertions);
    query.bindValue(":idDiapo", id);

    if (query.exec())
    {
        // Remplir le QTableWidget avec les résultats de la requête
        while (query.next())
        {
            imageACharger = Image(query.value(1).toString().toStdString(), query.value(8).toString().toStdString(), query.value(3).toString().toStdString());
            pImages.push_back(imageACharger);
            qDebug() << query.value(1).toString(), query.value(8).toString(), query.value(3).toString();
        }
        qDebug() << "Toutes les images sont chargées";


    }
    else
    {
        qDebug() << "Erreur lors de l'exécution de la requête SQL: chargerImages";
    }
}

