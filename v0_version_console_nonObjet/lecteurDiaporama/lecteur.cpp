#include "lecteur.h"

Lecteur::Lecteur(bool pEstVide, unsigned short int s)
{



}

Lecteur::Lecteur(const Lecteur & monLecteur)
{

}

bool Lecteur::getEstManuel() const
{
    return this->m_estManuel;
}

bool Lecteur::getEstVide() const
{
    return this->m_estVide;
}

void Lecteur::lireDiaporama(const Diaporama & monDiaporama) const
{

}

void Lecteur::arreterLecture(const Diaporama & monDiaporama) const
{

}

void Lecteur::charger(const Diaporama & monDiaporama)
{
    m_diaporama = monDiaporama;
}

void Lecteur::enleverDiaporama()
{

}
