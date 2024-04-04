#include "sousProgrammes.h"
#include <iostream>
#include <vector>
#include "image.h"
#include "typeDiaporama.h"
using namespace std;


void afficherImageCouranteDansDiaporamaCourant (const Diaporama& pDiaporama, unsigned int pImageCourante, const Image& pImage)
{
    cout << endl << endl;
    cout << "DIAPORAMA : " << pDiaporama.titre << endl << endl;
    cout << pDiaporama.localisationImages[pImageCourante].rang << " sur " <<  nbImages(pDiaporama) << " / ";
    afficher(pImage);
}



void saisieVerifChoixActionSurImageCourante(char& pChoixAction)
{
    cout << endl << endl;
    while (true)
    {
        cout  << endl ;
        cout << "ACTIONS :" << "  A-vancer" << "  R-eculer" << "  C-hanger de diaporama " << "  Q-uitter .......  votre choix ? ";
        cin >> pChoixAction;
        pChoixAction = toupper(pChoixAction);

        if ((pChoixAction == 'A') || (pChoixAction == 'R') || (pChoixAction == 'C') || (pChoixAction == 'Q'))
        {
            break;
        }
    }
}
unsigned int saisieVerifChoixDiaporama(const Diaporamas& pDiaporamas)
{
    unsigned int choixSaisi;
    int choixDiaporama; // valeur retournée

    while (true)
    {
        system("cls");  // effacer l'écran
         cout << endl << endl << "CHANGEMENT DIAPORAMA : " << endl << endl;
        for (unsigned int num = 1; num < pDiaporamas.size(); num++)
        {
            cout << num << ": " << pDiaporamas[num].titre;
            if (num != pDiaporamas.size()-1) { cout << endl; }
        }
        cout << ".......  votre choix ? "; cin >> choixSaisi;
        choixDiaporama = choixSaisi;

        if ((choixDiaporama >= 1)&&(choixDiaporama < static_cast<unsigned int>(pDiaporamas.size())))
        {
            break;
        }
    }
    return choixDiaporama;
}

void declencherAction(char pChoixAction, const Diaporamas& pDiaporamas, unsigned int& pDiaporamaCourant,
                      unsigned int& pImageCourante, const Images& pImages)
/* Selon le pChoix fait l'utilisateur, réalise une des actions A)vancer, R)eculer, C)hoisir un autre diaporama, Q)quitter */
{
    unsigned int position;
    unsigned int choixDiaporama;
    switch (pChoixAction)
    {
        case 'A':
            avancer(pDiaporamas[pDiaporamaCourant], pImageCourante);
            position = pDiaporamas[pDiaporamaCourant].localisationImages[pImageCourante].pos;
            afficherImageCouranteDansDiaporamaCourant (pDiaporamas[pDiaporamaCourant], pImageCourante, pImages[position]);
            break;
        case 'R':
            reculer(pDiaporamas[pDiaporamaCourant], pImageCourante);
            position = pDiaporamas[pDiaporamaCourant].localisationImages[pImageCourante].pos;
            afficherImageCouranteDansDiaporamaCourant (pDiaporamas[pDiaporamaCourant], pImageCourante, pImages[position]);
            break;
        case 'C' :
            cout << "Choisissez un Diaporama " << endl;
            choixDiaporama = saisieVerifChoixDiaporama(pDiaporamas);
            // Changer de diaporama
            pDiaporamaCourant = choixDiaporama;
            pImageCourante = 0;
            break;

        default : break;
    }
}


void charger(Diaporamas& pDiaporamas)
{
    Image imageACharger;
    ImageDansDiaporama imageDansDiapo;
    Diaporama diaporama;

    // Diaporama par défaut
    diaporama.titre = "Diaporama par defaut";
    diaporama.vitesseDefilement = 1;

    // L'unique image du diaporama par défaut
    imageDansDiapo.pos = 0;
    imageDansDiapo.rang = 1;
    diaporama.localisationImages.push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.localisationImages.clear();

    // Diaporama de Pantxika
    diaporama.titre = "Diaporama Pantxika";
    diaporama.vitesseDefilement = 2;

    // Les images du diaporama de Pantxika
    imageDansDiapo.pos = 4;
    imageDansDiapo.rang = 3;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 1;
    imageDansDiapo.rang = 2;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 2;
    imageDansDiapo.rang = 4;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 3;
    imageDansDiapo.rang = 1;
    diaporama.localisationImages.push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.localisationImages.clear();

    // Diaporama de Thierry
    diaporama.titre = "Diaporama Thierry";
    diaporama.vitesseDefilement = 4;

    // Les images du diaporama de Thierry
    imageDansDiapo.pos = 4;
    imageDansDiapo.rang = 1;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 1;
    imageDansDiapo.rang = 2;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 2;
    imageDansDiapo.rang = 3;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 3;
    imageDansDiapo.rang = 4;
    diaporama.localisationImages.push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.localisationImages.clear();

    // Diaporama de Yann
    diaporama.titre = "Diaporama Yann";
    diaporama.vitesseDefilement = 3;

    // Les images du diaporama de Yann
    imageDansDiapo.pos = 4;
    imageDansDiapo.rang = 2;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 1;
    imageDansDiapo.rang = 1;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 2;
    imageDansDiapo.rang = 4;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 3;
    imageDansDiapo.rang = 3;
    diaporama.localisationImages.push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.localisationImages.clear();

    // Diaporama de Manu
    diaporama.titre = "Diaporama Manu";
    diaporama.vitesseDefilement = 1;

    // Les images du diaporama de Yann
    imageDansDiapo.pos = 4;
    imageDansDiapo.rang = 4;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 1;
    imageDansDiapo.rang = 3;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 2;
    imageDansDiapo.rang = 2;
    diaporama.localisationImages.push_back(imageDansDiapo);
    imageDansDiapo.pos = 3;
    imageDansDiapo.rang = 1;
    diaporama.localisationImages.push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    pDiaporamas.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.localisationImages.clear();

}
void charger (Images& pImages) {
    Image imageACharger;
    imageACharger = creerImage ("objet", "", "C:\\cartesDisney\\Disney_tapis.gif");
    pImages.push_back(imageACharger);
    imageACharger = creerImage ("personnage", "Blanche Neige", "C:\\cartesDisney\\Disney_4.gif");
    pImages.push_back(imageACharger);
    imageACharger = creerImage ("personnage", "Alice", "C:\\cartesDisney\\Disney_2.gif");
    pImages.push_back(imageACharger);
    imageACharger = creerImage ("animal", "Mickey", "C:\\cartesDisney\\Disney_19.gif");
    pImages.push_back(imageACharger);
    imageACharger = creerImage ("personnage", "Pinnochio", "C:\\cartesDisney\\Disney_29.gif");
    pImages.push_back(imageACharger);
    imageACharger = creerImage ("objet", "chateau", "C:\\cartesDisney\\Disney_0.gif");
    pImages.push_back(imageACharger);
    imageACharger = creerImage ("personnage", "Minnie", "C:\\cartesDisney\\Disney_14.gif");
    pImages.push_back(imageACharger);
    imageACharger = creerImage ("animal", "Bambi", "C:\\cartesDisney\\Disney_3.gif");
    pImages.push_back(imageACharger);
}

/* Corps des sous-programmes utilisés par la fonction main()
 * ------------------------------------------------------- */
void avancer(const Diaporama& pDiaporama, unsigned int& pPosImageCourante)
// avance à l'image suivante de l'image courante. Revient à l'image de rang 1 si terminé
{
    if (pPosImageCourante == pDiaporama.localisationImages.size() - 1)
    {
        pPosImageCourante = 0;
    }
    else {
        pPosImageCourante = pPosImageCourante + 1;
    }
}
void reculer(const Diaporama& pDiaporama, unsigned int& pPosImageCourante)
{
    if (pPosImageCourante == 0)
    {
        pPosImageCourante = pDiaporama.localisationImages.size() - 1;
    }
    else {
        pPosImageCourante = pPosImageCourante - 1;
    }
}

unsigned int nbImages(const Diaporama& pDiaporama)
{
    return pDiaporama.localisationImages.size();
}


void triCroissantRang (Diaporama &pDiaporama)
{   // par la méthode du triBulle
    unsigned int taille = pDiaporama.localisationImages.size();
    ImageDansDiaporama imageDansDiapo;
    for (unsigned int ici = taille-1; ici >=1 ; ici--)
    {
        // faire monter la bulle ici = déplacer l'élément de rang le plus grand en position ici
        // par échanges successifs
        for (unsigned int i = 0; i < ici; i++)
        {
            if (pDiaporama.localisationImages[i].rang > pDiaporama.localisationImages[i+1].rang)
            {
                // echanger les 2 éléments
                imageDansDiapo = pDiaporama.localisationImages[i];
                pDiaporama.localisationImages[i] = pDiaporama.localisationImages[i+1];
                pDiaporama.localisationImages[i+1] = imageDansDiapo;
            }
        }
    }
}

