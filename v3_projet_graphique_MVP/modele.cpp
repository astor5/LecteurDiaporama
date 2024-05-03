#include "modele.h"

Modele::Modele()
{
}

Diaporama * Modele::getDiaporama() const
{
    return _leDiaporama;
}

void Modele::setDiaporama(Diaporama * d)
{
    _leDiaporama = d;
}

void Modele::avancer() {
    if (getDiaporama()->getPosImageCouranteInt() == getDiaporama()->getNombreImages() - 1)
    {
        getDiaporama()->setPosImageCouranteInt(0);

    }
    else
    {
        getDiaporama()->setPosImageCouranteInt(getDiaporama()->getPosImageCouranteInt() + 1);
    }
}

void Modele::reculer()
{
    if (getDiaporama()->getPosImageCouranteInt() == 0)
    {
        getDiaporama()->setPosImageCouranteInt(getDiaporama()->getNombreImages() - 1);
    }
    else
    {
        getDiaporama()->setPosImageCouranteInt(getDiaporama()->getPosImageCouranteInt() - 1);
    }
}
