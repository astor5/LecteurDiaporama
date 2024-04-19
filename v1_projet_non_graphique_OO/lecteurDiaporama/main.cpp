#include <iostream>
#include <vector>
#include "lecteur.h"

using namespace std;

int test();
void saisieVerifChoixActionSurImageCourante(char& pChoixAction);
void declencherAction(char pChoixAction, const DiaporamaT& pDiaporamas, unsigned int& pDiaporamaCourant,
                      unsigned int& pImageCourante, const ImageT& pImages);

int main()
{
    /* -------------------------------------------------------------------------------------
     * Charge les images et les diaporamas 'en dur' ... en attendant l'implantation de la BD :
     * - Charger les images et diaporamas
     * Dans un second temps, ces contenus proviendront d'une base de données
     --------------------------------------------------------------------------------------*/
    ImageT images;          // les images
    DiaporamaT diaporamas;  // les diaporamas

    Image i1("titre", "chemin", "position ?");  //Une image
    Diaporama d1("Diapo defaut", 0);            //Un diaporama
    Lecteur l1;                                 //Un lecteur

    // Chargement des urls des images, chargement des diaporamas
    i1.charger(images);
    l1.charger(diaporamas);

    unsigned int taille_images = images.size();
    unsigned int taille_diaporamas = diaporamas.size();

    // Tri des images contenues dans les diaporamas pour les placer dans l'ordre d'apparition (rang) souhaité par l'utilisateur
    for (unsigned int posDiapo = 0; posDiapo < taille_diaporamas; posDiapo++)
    {
        d1.triCroissantRang();
    }


    /* ---------------------
     * Lecteur de diaporamas
     * --------------------- */

    // Elements autres que les images et diaporamas
    unsigned int diaporamaCourant ; // identifiant du diaporama courant = indice dans le tableau diaporamas
    unsigned int imageCourante ;    // identifiant de l'image courante du diaporama courant
                                    // = indice de l'image dans le tableau diaporamas[diaporamaCourant].images, trié par ordre croissant de rang

    /* Initialiser le diaporama et l'image courants
     * ---------------
       Les valeurs courantes sont définies par défaut
       --> cela suppose qu'il y a toujours au moins 1 diaporama avec au moins 1 image dedans.
       Autre option (meilleure, à mettre en place dans la version graphique)) :
       - pas de diaporama courant au lancement de l'application
       - le diaporama courant est choisi par l'utilisateur parmi une liste de diaporamas disponibles. */

    diaporamaCourant = 0;
    imageCourante = 0;


    /* Faire fonctionner le lecteur
       --------------*/
    char choixAction ;              // pour saisir le choix de l'utilisateur dans le menu d'actions possibles
    unsigned int choixDiaporama ;  // pour saisir le numéro de diaporama choisi par l'utilisiateur
    while (true)
    {

        /* Affichage à l'écran des infos de l'image courante dans son diaporama   */
        system("cls");  // effacer l'écran
        unsigned int position = diaporamas[diaporamaCourant].getLocalisationImages()[imageCourante].getPosition();
        d1.afficherImageCouranteDansDiaporamaCourant (position);


        /* Menu des actions possibles (saisie choix utilisateur) :
         * A-vancer, R-eculer, C-hanger de diaporama, Q-uitter */

        saisieVerifChoixActionSurImageCourante(choixAction);
        if (choixAction == 'Q')
        {
            break;
        }

        /* Faire l'action demandée (Avancer - Reculer - Changer de Diaporama - Quitter) */
        system("cls");  // effacer l'écran
        declencherAction(choixAction, diaporamas, diaporamaCourant, imageCourante, images);
    }

    /* Fin
       --------------*/
      cout << "Au revoir " << endl;
      return 0;
}


void declencherAction(char pChoixAction, const DiaporamaT& pDiaporamas, unsigned int& pDiaporamaCourant,
                      unsigned int& pImageCourante, const ImageT& pImages)
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















int test(){
    Image i1("titre", "chemin", "position ?");
    ImageT images;
    Lecteur l1;
    Diaporama d1("1er diapo", 0);
    DiaporamaT diaporama;
    unsigned int tailleImage = 0;
    unsigned int tailleDiaporama = 0;


    i1.charger(images);
    l1.charger(diaporama);

    /*
    tailleImage = images.size();
    tailleDiaporama = diaporama.size();
    cout << tailleImage << endl;
    cout << tailleDiaporama << endl;*/

    unsigned int diaporamaCourant = 0;
    unsigned int imageCourante = 0;

    unsigned int pImageCourante = 0;
    unsigned int pDiaporamaCourant = 0;
    unsigned int position = diaporama[diaporamaCourant].getLocalisationImages()[imageCourante].getPosition();

    d1.afficherImageCouranteDansDiaporamaCourant(position);

    cout << "La position est de : " << position << endl;
    cout << "Choisissez un Diaporama " << endl;
    unsigned int choixSaisi;
    int choixDiaporama; // valeur retournée

    while (true)
    {
        system("cls");  // effacer l'écran
         cout << endl << endl << "CHANGEMENT DIAPORAMA : " << endl << endl;
        for (unsigned int num = 1; num < diaporama.size(); num++)
        {
            cout << num << ": " << diaporama[num].getTitre();
            if (num != diaporama.size()-1) { cout << endl; }
        }
        cout << ".......  votre choix ? "; cin >> choixSaisi;
        choixDiaporama = choixSaisi;

        if ((choixDiaporama >= 1)&&(choixDiaporama < static_cast<unsigned int>(diaporama.size())))
        {
            break;
        }
    }
    // Changer de diaporama
    pDiaporamaCourant = choixDiaporama;
    pImageCourante = 0;

    d1.afficherImageCouranteDansDiaporamaCourant (imageCourante);

    return 0;
}
