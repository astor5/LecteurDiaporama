#include "lecteur.h"

Lecteur::Lecteur(bool pEstVide, bool pEstManuel)
{
 m_estVide=pEstVide;
 m_estManuel=pEstManuel;

}

Lecteur::Lecteur(const Lecteur & original):
   m_estVide(original.m_estVide),
   m_estManuel(original.m_estManuel){
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
