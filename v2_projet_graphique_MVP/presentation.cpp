#include "presentation.h"

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
