#include <iostream>
#include <vector>
#include "lecteur.h"

using namespace std;

int test();

int main()
{
    /* -------------------------------------------------------------------------------------
     * Charge les images et les diaporamas 'en dur' ... en attendant l'implantation de la BD :
     * - Charger les images et diaporamas
     * Dans un second temps, ces contenus proviendront d'une base de données
     --------------------------------------------------------------------------------------*/
    vector<Image> images;          // les images

    Lecteur l1;                                 //Un lecteur

    // Chargement des urls des images, chargement des diaporamas
    l1.charger(images);
    l1.chargerDiapos(images);

    //On précise que le diaporama courant est celui par défaut
    l1.setNumDiapoCourant(0);

    // Tri des images contenues dans les diaporamas pour les placer dans l'ordre d'apparition (rang) souhaité par l'utilisateur
    for (unsigned int var = 0; var < l1.getNombreDiapos(); ++var) {
        for (unsigned int posDiapo = 0; posDiapo < l1.getDiapoCourant().getNombreImages(); posDiapo++)
        {
            l1.getToutesDiapos()[var].triCroissantRang();
        }
    }


    /* ---------------------
     * Lecteur de diaporamas
     * --------------------- */

    /* Initialiser le diaporama et l'image courants
     * ---------------
       Les valeurs courantes sont définies par défaut
       --> cela suppose qu'il y a toujours au moins 1 diaporama avec au moins 1 image dedans.
       Autre option (meilleure, à mettre en place dans la version graphique)) :
       - pas de diaporama courant au lancement de l'application
       - le diaporama courant est choisi par l'utilisateur parmi une liste de diaporamas disponibles. */


    /* Faire fonctionner le lecteur
       --------------*/
    char choixAction ;              // pour saisir le choix de l'utilisateur dans le menu d'actions possibles
    while (true)
    {

        /* Affichage à l'écran des infos de l'image courante dans son diaporama   */
        system("cls");  // effacer l'écran
        l1.getDiapoCourant().afficherImageCouranteDansDiaporamaCourant();


        /* Menu des actions possibles (saisie choix utilisateur) :
         * A-vancer, R-eculer, C-hanger de diaporama, Q-uitter */

        l1.saisieVerifChoixActionSurImageCourante(choixAction);
        if (choixAction == 'Q')
        {
            break;
        }

        /* Faire l'action demandée (Avancer - Reculer - Changer de Diaporama - Quitter) */
        system("cls");  // effacer l'écran
        l1.declencherAction(choixAction);
    }

    /* Fin
       --------------*/
      cout << "Au revoir " << endl;
      return 0;
}










/*
int test(){
    Image i1("titre", "chemin", "position ?");
    ImageT images;
    Lecteur l1;
    Diaporama d1("1er diapo", 0);
    DiaporamaT diaporama;
    unsigned int tailleImage = 0;
    unsigned int tailleDiaporama = 0;


    i1.charger(images);
    l1.charger(diaporama);*/

    /*
    tailleImage = images.size();
    tailleDiaporama = diaporama.size();
    cout << tailleImage << endl;
    cout << tailleDiaporama << endl;*/
    /*
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
*/
