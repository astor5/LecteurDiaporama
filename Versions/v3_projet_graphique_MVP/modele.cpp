#include "modele.h"

Modele::Modele()
{
}

Diaporama * Modele::getDiaporamaCourant() const
{
    return _Diaporamas[_diaporamaCourant];
}

void Modele::setDiaporamaCourant(int pos)
{
    _diaporamaCourant = pos;
}

void Modele::avancer() {
    if (getDiaporamaCourant()->getPosImageCouranteInt() == getDiaporamaCourant()->getNombreImages() - 1)
    {
        getDiaporamaCourant()->setPosImageCouranteInt(0);

    }
    else
    {
        getDiaporamaCourant()->setPosImageCouranteInt(getDiaporamaCourant()->getPosImageCouranteInt() + 1);
    }
}

void Modele::reculer()
{
    if (getDiaporamaCourant()->getPosImageCouranteInt() == 0)
    {
        getDiaporamaCourant()->setPosImageCouranteInt(getDiaporamaCourant()->getNombreImages() - 1);
    }
    else
    {
        getDiaporamaCourant()->setPosImageCouranteInt(getDiaporamaCourant()->getPosImageCouranteInt() - 1);
    }
}

void Modele::charger()
{
    getDiaporamaCourant()->charger(getDiaporamaCourant()->getToutesImages());
    getDiaporamaCourant()->chargerDiapos(getDiaporamaCourant()->getToutesImages());
}
