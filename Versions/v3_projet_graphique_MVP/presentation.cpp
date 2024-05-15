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
    getVue()->majPresentation(getModele()->getDiaporamaCourant());
}

void Presentation::demanderReculer()
{
    getModele()->reculer();
    getVue()->majPresentation(getModele()->getDiaporamaCourant());
}

void Presentation::demanderCharger()
{
    getModele()->charger();
    getVue()->majPresentation(getModele()->getDiaporamaCourant());
}
