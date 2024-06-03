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

QTimer* Presentation::getTimer()
{
    return _timer;
}

void Presentation::setTimerActif(bool actif)
{
    if (actif) { _timer->start(); }
    else { _timer->stop(); }
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
    if (getModele()->getEtat() == Modele::manuel)
    {
        getModele()->avancer();
    }
    getModele()->changementEtat();
    getModele()->touchePressee();
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat(), getModele()->getEtatLecteur());
}

void Presentation::demanderReculer()
{
    if (getModele()->getEtat() == Modele::manuel)
    {
        getModele()->reculer();
    }
    getModele()->changementEtat();
    getModele()->touchePressee();
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat(), getModele()->getEtatLecteur());
}

void Presentation::demanderCharger()
{
    getModele()->setEtatLecteur(Modele::charge);
    getModele()->charger();
}

void Presentation::demandeChangementMode()
{
    if (getModele()->getEtat() == Modele::automatique)
    {
        getModele()->setEtat(Modele::manuel);
    }
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat(), getModele()->getEtatLecteur());
}

void Presentation::demandeChangementDiaporama(choixdiaporama &unChoix)
{
    getModele()->setEtatLecteur(Modele::charge);
    getModele()->setEtat(Modele::manuel);
    getModele()->setDiaporamaCourant(unChoix.recupIndex()); //Enlevement du +1 apres recupIndex()
    getModele()->getDiaporamaCourant()->setPosImageCouranteInt(0);
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat(), getModele()->getEtatLecteur());
}

void Presentation::demanderLancementDiapo()
{
    if (getModele()->getEtat() == Modele::manuel)
    {
        getModele()->changementEtat();
    }
    else
    {
        setTimerActif(false);
    }
    getModele()->getDiaporamaCourant()->setPosImageCouranteInt(0);
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat(), getModele()->getEtatLecteur());
}

void Presentation::demanderArretDiapo()
{
    getModele()->changementEtat();
    setTimerActif(false);
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat(), getModele()->getEtatLecteur());
}

int Presentation::demandeNumeroDiaporama()
{
    return getModele()->getDiaporamaCourant()->getNumDiapoCourant();
}

void Presentation::demandeVider()
{
    getModele()->changementEtat();
    getModele()->setEtatLecteur(Modele::initial);
    //getModele()->setDiaporamaCourant(0);
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat(), getModele()->getEtatLecteur());
}

void Presentation::demandeModeAutomatique()
{
    _timer = new QTimer(this);
    QObject::connect(_timer, &QTimer::timeout, this, &Presentation::onTimeout);
    _timer->setInterval(getModele()->getDiaporamaCourant()->getVitesseDefilement()*1000);
    if (getTimer()->isActive()==false)
    {
        setTimerActif(true);
    }
    else
    {
        setTimerActif(false);
    }

    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat(), getModele()->getEtatLecteur());
}

void Presentation::onTimeout()
{
    if (getModele()->getEtat() == Modele::automatique)
    {
        getModele()->avancer();
        getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat(), getModele()->getEtatLecteur());
    }
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat(), getModele()->getEtatLecteur());
}

int Presentation::demandeVitesseDefilement()
{
    return getModele()->getVitesseDefilement();
}

void Presentation::demandeSetVitesseDefilement(int vitDefilement)
{
    getDiapoActuel()->setVitesseDefilement(vitDefilement);
}

int Presentation::demandeNombreDiapos()
{
    return getModele()->getTabDiaporamas().size();
}

std::string Presentation::demandeTitreDiaporama(int numDiapo)
{
    return getModele()->getTabDiaporamas()[numDiapo]->getTitre();
}










