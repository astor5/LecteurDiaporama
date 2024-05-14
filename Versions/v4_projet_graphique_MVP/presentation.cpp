#include "presentation.h"
#include "lecteurvue.h"
Presentation::Presentation() {
}

Modele *Presentation::getModele() const
{
    return _leModele;
}

lecteurVue *Presentation::getVue() const
{
    return _laVue;
}

void Presentation::setModele(Modele * m)
{
    _leModele = m;
}

void Presentation::setVue(lecteurVue * v)
{
    _laVue = v;
}


ImageDansDiaporama Presentation::getImageActuelle()
{
    return _leModele->getDiaporamaCourant()->getImageCourante();
}

Diaporama *Presentation::getDiapoActuel()
{
    return getModele()->getDiaporamaCourant();
}


void Presentation::demanderAvancer()
{
    getModele()->avancer();
    getModele()->touchePressee();
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat());
}

void Presentation::demanderReculer()
{
    getModele()->reculer();
    getModele()->touchePressee();
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat());
}

void Presentation::demanderCharger()
{
    getModele()->charger();
}

void Presentation::demanderLancementDiapo()
{
    getModele()->changementEtat();
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat());
}

void Presentation::demanderArretDiapo()
{
    getModele()->changementEtat();
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat());
}

void Presentation::demandeModeAutomatique()
{
    getModele()->defilerAutomatiquement();
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat());
}

/*void Presentation::declencherAction(char pChoixAction)
{
    //unsigned int position;
    unsigned int choixDiaporama;
    switch (pChoixAction)
    {
    case 'A':
        cout << "DEBUG : titre du diapo courant " << getDiapoCourant().getTitre() << endl;
        this->getDiapoCourant().avancer();
        //position = this->getDiapoCourant().getLocalisationImages()[pImageCourante].getPosition();
        cout << "DEBUG : appel de la methode getPosImageCouranteInt " << this->getDiapoCourant().getPosImageCouranteInt();
        this->getDiapoCourant().afficherImageCouranteDansDiaporamaCourant ();
        break;
    case 'R':
        this->getDiapoCourant().reculer();
        //position = this->getDiapoCourant().getLocalisationImages()[pImageCourante].getPosition();
        cout << "DEBUG : appel de la methode getPosImageCouranteInt " << getDiapoCourant().getPosImageCouranteInt();
        this->getDiapoCourant().afficherImageCouranteDansDiaporamaCourant ();
        break;
    case 'C' :
        cout << "Choisissez un Diaporama " << endl;
        choixDiaporama = this->saisieVerifChoixDiaporama();
        // Changer de diaporama
        cout << "DEBUG : numero du diaporama courant : " << getNumDiapoCourant() << endl;
        this->setNumDiapoCourant(choixDiaporama);
        this->getDiapoCourant().setPosImageCouranteInt(0);
        cout << "DEBUG : numero du diaporama courant (apres le set) : " << getNumDiapoCourant() << endl;
        cout << "DEBUG : numero de l'image courante du diaporama courant : " << getDiapoCourant().getPosImageCouranteInt() << endl;
        //pImageCourante = 0;
        break;

    default : break;
    }
}
*/
