#include <iostream>
#include "lecteur.h"
using namespace std;

//***********************************************************************************
//                                  Nouvelle classe
//***********************************************************************************


Lecteur::Lecteur()
{

}

Lecteur::Lecteur(vector<Diaporama> diapo, unsigned int numero, unsigned int nombre):
    m_toutesDiapos(diapo),
    m_numDiapoCourant(numero),
    m_nombreDiapos(nombre){
}

vector<Diaporama> Lecteur::getToutesDiapos() const
{
    return m_toutesDiapos;
}

Diaporama Lecteur::getDiapoCourant() const
{
    return getToutesDiapos()[getNumDiapoCourant()];
}

unsigned int Lecteur::getNumDiapoCourant() const
{
    return m_numDiapoCourant;
}

unsigned int Lecteur::getNombreDiapos() const
{
    return m_nombreDiapos;
}

void Lecteur::setToutesDiapos(const vector<Diaporama> & diapos)
{
    m_toutesDiapos = diapos;
}

void Lecteur::setNumDiapoCourant(unsigned int numero)
{
    m_numDiapoCourant = numero;
}

void Lecteur::setNombreDiapos(unsigned int nombre)
{
    m_nombreDiapos = nombre;
}

void Lecteur::declencherAction(char pChoixAction)
{
    unsigned int position;
    unsigned int choixDiaporama;
    switch (pChoixAction)
    {
        case 'A':
            this->getDiapoCourant().avancer();
            //position = this->getDiapoCourant().getLocalisationImages()[pImageCourante].getPosition();
            this->getDiapoCourant().afficherImageCouranteDansDiaporamaCourant ();
            break;
        case 'R':
            this->getDiapoCourant().reculer();
            //position = this->getDiapoCourant().getLocalisationImages()[pImageCourante].getPosition();
            this->getDiapoCourant().afficherImageCouranteDansDiaporamaCourant ();
            break;
        case 'C' :
            cout << "Choisissez un Diaporama " << endl;
            choixDiaporama = this->saisieVerifChoixDiaporama();
            // Changer de diaporama
            this->setNumDiapoCourant(choixDiaporama);
            //pImageCourante = 0;
            break;

        default : break;
    }
}

void Lecteur::saisieVerifChoixActionSurImageCourante(char & pChoixAction)
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

unsigned int Lecteur::saisieVerifChoixDiaporama()
{
    unsigned int choixSaisi;
    int choixDiaporama; // valeur retournée

    while (true)
    {
        system("cls");  // effacer l'écran
         cout << endl << endl << "CHANGEMENT DIAPORAMA : " << endl << endl;
        for (unsigned int num = 1; num < getToutesDiapos().size(); num++)
        {
            cout << num << ": " << getToutesDiapos()[num].getTitre();
            if (num != getToutesDiapos().size()-1) { cout << endl; }
        }
        cout << ".......  votre choix ? "; cin >> choixSaisi;
        choixDiaporama = choixSaisi;

        if ((choixDiaporama >= 1)&&(choixDiaporama < static_cast<unsigned int>(getToutesDiapos().size())))
        {
            break;
        }
    }
    return choixDiaporama;
}

void Lecteur::charger(Images & pImages)
{
    Image imageACharger;
    int debug;

    imageACharger = Image("objet", "", "C:\\cartesDisney\\Disney_tapis.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("personnage", "Blanche Neige", "C:\\cartesDisney\\Disney_4.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("personnage", "Alice", "C:\\cartesDisney\\Disney_2.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("animal", "Mickey", "C:\\cartesDisney\\Disney_19.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("personnage", "Pinnochio", "C:\\cartesDisney\\Disney_29.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("objet", "chateau", "C:\\cartesDisney\\Disney_0.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("personnage", "Minnie", "C:\\cartesDisney\\Disney_14.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("animal", "Bambi", "C:\\cartesDisney\\Disney_3.gif");
    pImages.push_back(imageACharger);

    cout << "Images chargées (atteinte de fin de programme)" << endl;
    cin >> debug;
}

void Lecteur::chargerDiapos(Images & pImages)
{
    Image image;
    ImageDansDiaporama imageDansDiapo;
    int debug;

    Diaporama diaporama("Diaporama par défaut", 2);

    imageDansDiapo = ImageDansDiaporama(pImages,0,1);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    getToutesDiapos().push_back(diaporama);

    // Diaporama de Pantxika
    Diaporama diapoPantxika("Diaporama Pantxika",2);

    // Les images du diaporama de Pantxika
    imageDansDiapo = ImageDansDiaporama(pImages,4,3);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,1,2);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,2,4);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,3,1);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    // ajout du diaporama dans le tableau de diaporamas
    getToutesDiapos().push_back(diaporama);

    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.getLocalisationImages().clear();

    // Diaporama de Thierry
    Diaporama diapoThierry("Diaporama de Thierry", 4);

    // Les images du diaporama de Thierry
    imageDansDiapo = ImageDansDiaporama(pImages,4,1);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,1,2);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,2,3);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,3,4);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    // ajout du diaporama dans le tableau de diaporamas
    getToutesDiapos().push_back(diaporama);

    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.getLocalisationImages().clear();

    // Diaporama de Yann
    Diaporama diapoYann("Diaporama Yann", 3);

    // Les images du diaporama de Yann
    imageDansDiapo = ImageDansDiaporama(pImages,4,2);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,1,1);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,4,2);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,3,3);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    // ajout du diaporama dans le tableau de diaporamas
    getToutesDiapos().push_back(diaporama);

    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.getLocalisationImages().clear();

    // Diaporama de Manu
    Diaporama diapoManu("Diaporama Manu", 1);

    // Les images du diaporama de Yann
    imageDansDiapo = ImageDansDiaporama(pImages,4,4);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,1,3);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,2,2);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,3,1);
    diaporama.getLocalisationImages().push_back(imageDansDiapo);

    // ajout du diaporama dans le tableau de diaporamas
    m_toutesDiapos.push_back(diaporama);

    // vider la variable temporaire avant de la remplir avec le diaporama suivant
    diaporama.getLocalisationImages().clear();

    cout << "Images chargées (atteinte de fin de programme)" << endl;
    cin >> debug;
}

void Lecteur::afficherDiapoCourant()
{

}









//***********************************************************************************
//                                  Ancienne classe
//***********************************************************************************


/*
Lecteur::Lecteur()
{

}

Lecteur::~Lecteur()
{

}
*/
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
/*
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
// Selon le pChoix fait l'utilisateur, réalise une des actions A)vancer, R)eculer, C)hoisir un autre diaporama, Q)quitter
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
*/
