#include "modele.h"
#include "qdebug.h"
#include "QTimer"


Modele::Modele(UnEtat etat, UnMode mode)
{
    diapo = new Diaporama();
    diapo->chargerDiapos(diapo->charger(), _Diaporamas);
    setDiaporamaCourant(3);
    setEtat(etat);
    setMode(mode);
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
    if (getMode() == Modele::boucle)
    {
        qDebug() << "Mode boucle";
        if (getDiaporamaCourant()->getPosImageCouranteInt() == getDiaporamaCourant()->getNombreImages() - 1)
        {
            getDiaporamaCourant()->setPosImageCouranteInt(0);

        }
        else
        {
            getDiaporamaCourant()->setPosImageCouranteInt(getDiaporamaCourant()->getPosImageCouranteInt() + 1);
        }
    }
    else
    {
        qDebug() << "Mode initial dans avancement";
        getDiaporamaCourant()->setPosImageCouranteInt(getDiaporamaCourant()->getPosImageCouranteInt() + 1);
    }
}

void Modele::reculer()
{
    if (getMode() == Modele::boucle)
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
    else
    {
        qDebug() << "Mode initial dans recul";
        getDiaporamaCourant()->setPosImageCouranteInt(getDiaporamaCourant()->getPosImageCouranteInt() - 1);
    }
}

void Modele::charger()
{
    setDiaporamaCourant(0);
}

void Modele::touchePressee()
{
    if (getEtat() == Modele::automatique)
    {
        setEtat(Modele::manuel);
    }
}

void Modele::changementEtat()
{
    switch (getEtat()) {
    case Modele::manuel:
        setEtat(Modele::automatique);
        qDebug() << "Passage en mode auto";
        break;
    case Modele::automatique:
        setEtat(Modele::manuel);
        qDebug() << "Passage en mode manuel";
        break;
    default:
        setEtat(Modele::manuel);
        break;
    }
}

void Modele::changementMode()
{
    switch (getMode()) {
    case Modele::initial:
        setMode(Modele::boucle);
        qDebug() << "Passage en mode auto";
        break;
    case Modele::boucle:
        setMode(Modele::initial);
        qDebug() << "Passage en mode manuel";
        break;
    default:
        setMode(Modele::initial);
        break;
    }
}

bool Modele::defilageAutoPossible()
{
    bool result;
    result = false;
    if (getEtat() == Modele::automatique)
    {
        result = true;
    }
    return result;
}

Modele::UnEtat Modele::getEtat()
{
    return _etat;
}

Modele::UnMode Modele::getMode()
{
    return _mode;
}

void Modele::setEtat(UnEtat unEtat)
{
    _etat = unEtat;
}

void Modele::setMode(UnMode unMode)
{
    _mode = unMode;
}
