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
            string titreDiapo = query.value(1).toString().toStdString();
            int vitesseDiapo = query.value(2).toInt();
            int numeroDiapo = query.value(0).toInt();

            Diaporama * diapoCharge = new Diaporama(titreDiapo, vitesseDiapo, numeroDiapo); //On le créé avec le titre et la vitesse de defilement
            mesDiapos.push_back(diapoCharge); //On envoie le diaporama dans le vecteur
            diapoCharge->setVitesseDefilement(2);
            changerVitesseDefilement(diapoCharge);
            query2.bindValue(":idDiapo", diapoCharge->getNumDiapoCourant());

            Image imageACharger("", "", ":/images/Disney_tapis.gif");
            pImages.push_back(imageACharger); //ON insere dans le vecteur une premiere image vide

            //La requete pour les images
            if (query2.exec())
            {
                while(query2.next())
                {
                    compteur ++;
                }

                int tabRangs[compteur];
                query2.exec(); //On exec la requete
                compteur = 0;

                while (query2.next())
                {
                    string titreImage = query2.value(0).toString().toStdString();
                    string objetImage = query2.value(1).toString().toStdString();
                    string cheminImage = ":/images/" + query2.value(0).toString().toStdString();

                    // Cree une image avec Titre, Object, Chemin
                    imageACharger = Image(titreImage, objetImage, cheminImage);
                    pImages.push_back(imageACharger); //On l'envoie dans le vecteur
                    tabRangs[compteur] = query2.value(3).toInt(); //On met dans un tableau le rang de l'image
                    compteur ++;
                }

                //Tant qu'il a des images dans le vecteur d'images
                for (unsigned long long int i=0; i < pImages.size()-1; i++)
                {
                    ImageDansDiaporama imageDansDiapo = ImageDansDiaporama(pImages,i,tabRangs[i]); //On créé une image dans un diporama
                    diapoCharge->ajouterImage(imageDansDiapo); //On l'ajoute à notre diaporama
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
    }
    else
    {
        qDebug() << "Erreur lors de l'exécution de la requête SQL:";
    }
}

void database::changerVitesseDefilement(Diaporama* diapo)
{
    QSqlQuery query;
    QString insertion = "UPDATE Diaporamas SET vitesseDefilement = :vitesseDef WHERE idDiaporama = :idDiapo";
    query.prepare(insertion);
    query.bindValue(":vitesseDef", diapo->getVitesseDefilement());
    query.bindValue(":idDiapo", diapo->getNumDiapoCourant());

    if (!query.exec())
    {
        qDebug() << "Erreur dans la modification de la vitesse de defilement";
    }
}
