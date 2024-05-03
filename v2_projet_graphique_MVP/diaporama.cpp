#include "typeDiaporama.h"

Diaporama::Diaporama(string titre, Image monImage, unsigned short int vitesse, string filtreCategorie):
    m_titre(titre),
    m_image(monImage),
    m_vitesseDefilement(vitesse),
    m_filtre(filtreCategorie){
}

Diaporama::Diaporama(const Diaporama & original):
    m_titre(original.m_titre),
    m_image(original.m_image),
    m_vitesseDefilement(original.m_vitesseDefilement),
    m_filtre(original.m_filtre){
}

Diaporama::~Diaporama()
{

}

string Diaporama::getTitre() const
{
    return this->m_titre;
}

void Diaporama::passerAuSuivant() const
{

}

void Diaporama::passerAuPrecedent() const
{

}

void Diaporama::allerPremiereImage() const
{

}

unsigned short Diaporama::getVitesseDefilement() const
{
    return this->m_vitesseDefilement;
}

Diaporama Diaporama::getDiaporama() const
{
    return (*this);
}

string Diaporama::getFiltre() const
{
    return this->m_filtre;
}

void Diaporama::modifierFiltre()
{

}

unsigned short Diaporama::nombreImages() const
{
    return this->std::size();
}
