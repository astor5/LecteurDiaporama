#include <iostream>
#include "lecteur.h"
using namespace std;

Lecteur::Lecteur()
{

}

Lecteur::~Lecteur()
{

}

/*
void Lecteur::avancer(const DiaporamasT& unDiapo)
{
    if (nbImages(unDiapo) > 0) {
            m_posImageCourante = (m_posImageCourante+1) % nbImages(unDiapo);
    }
}

void Lecteur::reculer(const DiaporamasT& unDiapo)
{
    if (nbImages(unDiapo) > 0) {
            m_posImageCourante = (m_posImageCourante-1) % nbImages(unDiapo);
    }
}*/

void Lecteur::changerDiaporama(const DiaporamasT& monDiapo, unsigned int pNumDiaporama)
{

}

void Lecteur::charger(DiaporamaT& monDiapo)
{
    ImageDansDiaporama imageDansDiapo(0,1);
    Diaporama diaporama("Diaporama par défaut", 0);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    monDiapo.push_back(diaporama);

    diaporama.getLocalisationImages().clear();

    // Diaporama de Pantxika
    diaporama.setTitre("Diaporama Pantxika");
    diaporama.setVitesseDefilement(2);

    // Les images du diaporama de Pantxika
    imageDansDiapo.setPosition(4);
    imageDansDiapo.setRang(3);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    imageDansDiapo.setPosition(1);
    imageDansDiapo.setRang(2);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo.setPosition(2);
    imageDansDiapo.setRang(4);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo.setPosition(3);
    imageDansDiapo.setRang(1);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    monDiapo.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.getLocalisationImages().clear();

    // Diaporama de Thierry
    diaporama.setTitre("Diaporama de Thierry");
    diaporama.setVitesseDefilement(4);

    // Les images du diaporama de Thierry
    imageDansDiapo.setPosition(4);
    imageDansDiapo.setRang(1);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo.setPosition(1);
    imageDansDiapo.setRang(2);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo.setPosition(2);
    imageDansDiapo.setRang(3);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo.setPosition(3);
    imageDansDiapo.setRang(4);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    monDiapo.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.getLocalisationImages().clear();

    // Diaporama de Yann
    diaporama.setTitre("Diaporama Yann");
    diaporama.setVitesseDefilement(3);

    // Les images du diaporama de Yann
    imageDansDiapo.setPosition(4);
    imageDansDiapo.setRang(2);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo.setPosition(1);
    imageDansDiapo.setRang(1);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo.setPosition(2);
    imageDansDiapo.setRang(4);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo.setPosition(3);
    imageDansDiapo.setRang(3);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    monDiapo.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.getLocalisationImages().clear();

    // Diaporama de Manu
    diaporama.setTitre("Diaporama Manu");
    diaporama.setVitesseDefilement(1);

    // Les images du diaporama de Yann
    imageDansDiapo.setPosition(4);
    imageDansDiapo.setRang(4);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo.setPosition(1);
    imageDansDiapo.setRang(3);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo.setPosition(2);
    imageDansDiapo.setRang(2);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo.setPosition(3);
    imageDansDiapo.setRang(1);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    // ajout du diaporama dans le tableau de diaporamas
    monDiapo.push_back(diaporama);
    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.getLocalisationImages().clear();
}

unsigned int saisieVerifChoixDiaporama(const DiaporamaT& pDiaporamas)
{
    unsigned int choixSaisi;
    int choixDiaporama; // valeur retournée

    while (true)
    {
        system("cls");  // effacer l'écran
         cout << endl << endl << "CHANGEMENT DIAPORAMA : " << endl << endl;
        for (unsigned int num = 1; num < pDiaporamas.size(); num++)
        {
            cout << num << ": " << pDiaporamas[num].getTitre();
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

void declencherAction(char pChoixAction, const DiaporamaT& pDiaporamas, unsigned int& pDiaporamaCourant,
                      unsigned int& pImageCourante, const ImageT& pImages)
/* Selon le pChoix fait l'utilisateur, réalise une des actions A)vancer, R)eculer, C)hoisir un autre diaporama, Q)quitter */
{
    unsigned int position;
    unsigned int choixDiaporama;
    switch (pChoixAction)
    {
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
