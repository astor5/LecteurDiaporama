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
    if (actif) {_timer->start(); }
    else {_timer->stop(); }
}

void Presentation::setExtremitesDiapoDroit(bool extremite)
{
    _extremiteDiapoDroit = extremite;
}

bool Presentation::getExtremitesDiapoDroit()
{
    return _extremiteDiapoDroit;
}

void Presentation::setExtremitesDiapoGauche(bool extremite)
{
    _extremiteDiapoGauche = extremite;
}

bool Presentation::getExtremitesDiapoGauche()
{
    return _extremiteDiapoGauche;
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
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat());
}

void Presentation::demanderReculer()
{
    if (getModele()->getEtat() == Modele::manuel)
    {
        getModele()->reculer();
    }
    getModele()->changementEtat();
    getModele()->touchePressee();
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat());
}

void Presentation::demanderCharger()
{
    getModele()->charger();
}

void Presentation::demandeChangementMode()
{
    if (getModele()->getEtat() == Modele::automatique)
    {
        getModele()->setEtat(Modele::manuel);
    }
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat());
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
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat());
}

void Presentation::demanderArretDiapo()
{
    getModele()->changementEtat();
    setTimerActif(false);
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat());
}

void Presentation::demandeModeAutomatique()
{
    if (getModele()->getEtat() == Modele::automatique)
    {
        _timer = new QTimer(this);
        QObject::connect(_timer, &QTimer::timeout, this, &Presentation::onTimeout);
        _timer->setInterval(getModele()->getDiaporamaCourant()->getVitesseDefilement()*1000);
        setTimerActif(true);
    }
    else
    {
        setTimerActif(false);
    }

    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat());
}

void Presentation::onTimeout()
{
    if (getModele()->getEtat() == Modele::automatique)
    {
        getModele()->avancer();
        getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat());
    }
    else
    {
        setTimerActif(false);
    }
    getVue()->majPresentation(getDiapoActuel(), getModele()->getEtat());
}
