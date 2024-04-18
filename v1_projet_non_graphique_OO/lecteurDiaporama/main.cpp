#include <iostream>
#include <vector>
#include "lecteur.h"

using namespace std;


int main()
{
    Image i1("titre", "chemin", "position ?");
    ImageT images;
    Lecteur l1;
    Diaporama d1("1er diapo", 0);
    DiaporamaT diaporama;
    unsigned int tailleImage = 0;
    unsigned int tailleDiaporama = 0;

    //d1.afficherImageCouranteDansDiaporamaCourant(0);
    i1.charger(images);
    l1.charger(diaporama);

    /*
    tailleImage = images.size();
    tailleDiaporama = diaporama.size();
    cout << tailleImage << endl;
    cout << tailleDiaporama << endl;*/

    unsigned int diaporamaCourant = 0;
    unsigned int imageCourante = 0;

    unsigned int pImageCourante;
    unsigned int pDiaporamaCourant = 0;
    unsigned int position = diaporama[diaporamaCourant].getLocalisationImages()[imageCourante].getPosition();

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
}

