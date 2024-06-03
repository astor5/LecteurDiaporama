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
    vector<Image> pImages;
    QSqlQuery query;
    QSqlQuery query2;
    QString insertions="SELECT D.titrePhoto, F.nomFamille, D.uriPhoto, DDD.rang FROM `Diapos` D JOIN DiaposDansDiaporama DDD ON DDD.idDiapo = D.idphoto JOIN Familles F ON F.idFamille = D.idFam JOIN Diaporamas DS ON DS.idDiaporama = DDD.idDiaporama WHERE DS.idDiaporama = :idDiapo ORDER BY DDD.Rang;";
    query2.prepare(insertions);
    int compteur = 0;

    if (query.exec("SELECT * FROM Diaporamas;"))
    {
        // Remplir le QTableWidget avec les résultats de la requête
        while (query.next())
        {
            Diaporama * diapoCharge = new Diaporama(query.value(1).toString().toStdString(), query.value(0).toInt(), query.value(2).toInt());
            mesDiapos.push_back(diapoCharge);
            query2.bindValue(":idDiapo", diapoCharge->getNumDiapoCourant());

            Image imageACharger("", "", ":/images/Disney_tapis.gif");
            pImages.push_back(imageACharger);

            if (query2.exec())
            {
                while(query2.next())
                {
                    compteur ++;
                }
                qDebug() << "Taille de la querry" << compteur;
                int tabRangs[compteur];
                // Remplir le QTableWidget avec les résultats de la requête

                query2.exec();
                compteur = 0;
                while (query2.next())
                {
                    // Titre, Object, Chemin
                    imageACharger = Image(query2.value(0).toString().toStdString(), query2.value(1).toString().toStdString(), query2.value(2).toString().toStdString());
                    qDebug() << query2.value(0);
                    pImages.push_back(imageACharger);
                    tabRangs[compteur] = query2.value(3).toInt();
                    qDebug() << query2.value(3).toInt();
                    qDebug() << compteur << "compteur";
                    compteur ++;
                }

                for (int i=0; i < pImages.size()-1; i++)
                {
                    ImageDansDiaporama imageDansDiapo = ImageDansDiaporama(pImages,i,tabRangs[i]);
                    diapoCharge->ajouterImage(imageDansDiapo);
                    diapoCharge->setPosImageCouranteInt(i);
                    qDebug() << QString::fromStdString(diapoCharge->getImageCourante().getTitre());
                    qDebug() << i << "valeur i";
                }

                diapoCharge->setPosImageCouranteInt(0);
                diapoCharge->triCroissantRang();

                qDebug() << "Toutes les images sont chargées";

            }
            else
            {
                qDebug() << "Erreur lors de l'exécution de la requête SQL: chargerImages";
            }

            qDebug() << diapoCharge->getToutesImages().size();
            qDebug() << "Fin de la fonction de chargement";
        }
    }
    else
    {
        qDebug() << "Erreur lors de l'exécution de la requête SQL:";
    }
}

void database::chargerImages(vector<Diaporama *> & mesDiapos)
{/*
    vector<Image> pImages;
    QSqlQuery query;
    Image imageACharger("", "", ":/images/Disney_tapis.gif");
    pImages.push_back(imageACharger);
    int compteur = 0;

    QString insertions="SELECT D.titrePhoto, F.nomFamille, D.uriPhoto, DDD.rang FROM `Diapos` D JOIN DiaposDansDiaporama DDD ON DDD.idDiapo = D.idphoto JOIN Familles F ON F.idFamille = D.idFam JOIN Diaporamas DS ON DS.idDiaporama = DDD.idDiaporama WHERE DS.idDiaporama = :idDiapo;";
    query.prepare(insertions);
    query.bindValue(":idDiapo", mesDiapos[]);



    if (query.exec())
    {
        while(query.next())
        {
            compteur ++;
        }
        qDebug() << "Taille de la querry" << compteur;
        int tabRangs[compteur];
        // Remplir le QTableWidget avec les résultats de la requête

        query.exec();
        compteur = 0;
        while (query.next())
        {
            // Titre, Object, Chemin
            imageACharger = Image(query.value(0).toString().toStdString(), query.value(1).toString().toStdString(), query.value(2).toString().toStdString());
            qDebug() << query.value(0);
            pImages.push_back(imageACharger);
            tabRangs[compteur] = query.value(3).toInt();
            qDebug() << query.value(3).toInt();
            qDebug() << compteur << "compteur";
            compteur ++;
        }

        for (int i=0; i < pImages.size()-1; i++)
        {
            ImageDansDiaporama imageDansDiapo = ImageDansDiaporama(pImages,i,tabRangs[i]);
            diaposCharges->ajouterImage(imageDansDiapo);
            diaposCharges->setPosImageCouranteInt(i);
            qDebug() << QString::fromStdString(diaposCharges->getImageCourante().getTitre());
            qDebug() << i << "valeur i";
        }

        diaposCharges->setPosImageCouranteInt(0);
        diaposCharges->triCroissantRang();

        qDebug() << "Toutes les images sont chargées";

    }
    else
    {
        qDebug() << "Erreur lors de l'exécution de la requête SQL: chargerImages";
    }

    qDebug() << diaposCharges->getToutesImages().size();
    qDebug() << "Fin de la fonction de chargement";*/
}

void database::chargerDiapos(vector<Image> pImages, vector<Diaporama *> & diaposCharges, int id)
{

    ImageDansDiaporama imageDansDiapo;

    // Les images du diaporama de Pantxika
    imageDansDiapo = ImageDansDiaporama(pImages,2,3);
    diaposCharges[id]->ajouterImage(imageDansDiapo);
    diaposCharges[id]->setPosImageCouranteInt(0);
    diaposCharges[id]->triCroissantRang();

    // ajout du diaporama dans le tableau de diaporamas
    diaposCharges.push_back(diaposCharges[id]);
}
