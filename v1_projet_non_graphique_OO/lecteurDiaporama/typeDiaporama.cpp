#include <iostream>
#include "typeDiaporama.h"
using namespace std;

Diaporama::Diaporama(string titre, unsigned short vitesseDefilement):
    m_titre(titre),
    m_vitesseDefilement(vitesseDefilement){
}

Diaporama::Diaporama(const Diaporama & original):
    m_titre(original.m_titre),
    m_vitesseDefilement(original.m_vitesseDefilement),
    m_localisationImages(original.m_localisationImages){
}

Diaporama::~Diaporama()
{
}

string Diaporama::getTitre() const
{
    return m_titre;
}

vector<ImageDansDiaporama> Diaporama::getLocalisationImages()
{
    return m_localisationImages;
}

unsigned short Diaporama::getVitesseDefilement() const
{
    return m_vitesseDefilement;
}

void Diaporama::setTitre(const string & titre)
{
    m_titre = titre;
}

void Diaporama::setVitesseDefilement(unsigned int nouvelleVitesse)
{
    m_vitesseDefilement = nouvelleVitesse;
}

void Diaporama::setLocalisationImages(const std::vector<ImageDansDiaporama> &images)
{
    m_localisationImages = images;
}

void Diaporama::charger()
{

}

void Diaporama::declencherAction()
{

}

void Diaporama::saisieVerifChoixDiaporama()
{

}

void Diaporama::afficherImageDansDiaporamaCourant()
{

}
