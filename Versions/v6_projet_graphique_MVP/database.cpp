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
    QSqlQuery query; //Requete 1
    QSqlQuery query2; //Requete 2
    QString insertions="SELECT D.titrePhoto, F.nomFamille, D.uriPhoto, DDD.rang FROM `Diapos` D JOIN DiaposDansDiaporama DDD ON DDD.idDiapo = D.idphoto JOIN Familles F ON F.idFamille = D.idFam JOIN Diaporamas DS ON DS.idDiaporama = DDD.idDiaporama WHERE DS.idDiaporama = :idDiapo ORDER BY DDD.Rang;";
    //Au dessus on récupere les images d'un diapo en particulier
    query2.prepare(insertions);
    int compteur = 0;

    //On veut charger les diaporamas
    if (query.exec("SELECT * FROM Diaporamas;"))
    {
        // Tant qu'il y a des diaporamas
        while (query.next())
        {
            Diaporama * diapoCharge = new Diaporama(query.value(1).toString().toStdString(), query.value(2).toInt(), query.value(0).toInt()); //On le créé avec le titre et la vitesse de defilement
            mesDiapos.push_back(diapoCharge); //On envoie le diaporama dans le vecteur
            query2.bindValue(":idDiapo", diapoCharge->getNumDiapoCourant());
            qDebug() << "Numero du diapo courant" << diapoCharge->getNumDiapoCourant();

            Image imageACharger("", "", ":/images/Disney_tapis.gif");
            pImages.push_back(imageACharger); //ON insere dans le vecteur une premiere image vide

            //La requete pour les images
            if (query2.exec())
            {
                while(query2.next())
                {
                    compteur ++;
                }

                qDebug() << "Taille de la querry" << compteur;
                int tabRangs[compteur];

                query2.exec(); //On exec la requete
                compteur = 0;
                while (query2.next())
                {
                    // Cree une image avec Titre, Object, Chemin
                    imageACharger = Image(query2.value(0).toString().toStdString(), query2.value(1).toString().toStdString(), ":/images/" + query2.value(0).toString().toStdString());
                    pImages.push_back(imageACharger); //On l'envoie dans le vecteur
                    tabRangs[compteur] = query2.value(3).toInt(); //On met dans un tableau le rang de l'image
                    compteur ++;
                }

                //Tant qu'il a des images dans le vecteur d'images
                for (int i=0; i < pImages.size()-1; i++)
                {
                    ImageDansDiaporama imageDansDiapo = ImageDansDiaporama(pImages,i,tabRangs[i]); //On créé une image dans un diporama
                    diapoCharge->ajouterImage(imageDansDiapo); //On l'ajoute à notre diaporama
                    //diapoCharge->setPosImageCouranteInt(i); //Normalement ça sert à rien
                    //qDebug() << QString::fromStdString(diapoCharge->getImageCourante().getTitre());
                }
                compteur = 0; //On remet le compteur à 0
                diapoCharge->setPosImageCouranteInt(0); //On met l'image courant à 0
                diapoCharge->triCroissantRang(); //On trie le diaporama
                pImages.clear(); //On vide le vecteur d'images
            }
            else
            {
                qDebug() << "Erreur lors de l'exécution de la requête SQL: chargerImages";
            }
        }
        //qDebug() << diapoCharge->getToutesImages().size();
    }
    else
    {
        qDebug() << "Erreur lors de l'exécution de la requête SQL:";
    }
    qDebug() << "Fin de la fonction de chargement";
    qDebug() << "Toutes les images sont chargées";
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
