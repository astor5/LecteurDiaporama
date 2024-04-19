#include <iostream>
#include "typeDiaporama.h"
using namespace std;

Diaporama::Diaporama(string titre, unsigned short vitesseDefilement, unsigned int position):
    m_titre(titre),
    m_vitesseDefilement(vitesseDefilement),
    m_posImage(position){
}

Diaporama::Diaporama(const Diaporama & original):
    m_titre(original.m_titre),
    m_vitesseDefilement(original.m_vitesseDefilement),
    m_localisationImages(original.m_localisationImages),
    m_posImage(original.m_posImage){
}

Diaporama::~Diaporama()
{
}

string Diaporama::getTitre() const
{
    return m_titre;
}

vector<ImageDansDiaporama> Diaporama::getLocalisationImages() const
{
    return m_localisationImages;
}

unsigned int Diaporama::getPosImageCouranteInt() const
{
    return m_posImage;
}

ImageDansDiaporama Diaporama::getPositionImage() const
{
    return getLocalisationImages()[getPosImageCouranteInt()];
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

void Diaporama::setPosImageCouranteInt(const unsigned int& positionImgC)
{
    m_posImage = positionImgC;
}

unsigned int Diaporama::nbImages() const
{
    return m_localisationImages.size();
}

void Diaporama::avancer() {
    if (this->getPosImageCouranteInt() == this->nbImages() - 1)
    {
        this->setPosImageCouranteInt(0);
    }
    else
    {
        this->setPosImageCouranteInt(this->getPosImageCouranteInt() + 1);
    }
}

void Diaporama::reculer()
{
    if (this->getPosImageCouranteInt() == 0)
    {
        this->setPosImageCouranteInt(this->nbImages() - 1);
    }
    else
    {
        this->setPosImageCouranteInt(this->getPosImageCouranteInt() - 1);
    }
}

void Diaporama::afficherImageCouranteDansDiaporamaCourant() const {
    int debug;
    cout << endl << endl;
    cout << "DIAPORAMA : " << this->getTitre() << endl << endl;
    cout << "Avant l'appel de getPositionImage().getRang() " << endl;
    cin >> debug;
    cout << nbImages() << endl;
    cout << getPositionImage().getRang() << endl;
    cout << this->getPositionImage().getRang() << " sur " << nbImages() << " / ";
    this->getPositionImage().afficher();
}

void Diaporama::triCroissantRang() {
    unsigned int taille = this->nbImages();
    ImageDansDiaporama imageDansDiapo;
    for (unsigned int ici = taille - 1; ici >= 1; ici--) {
        for (unsigned int i = 0; i < ici; i++) {
            if (m_localisationImages[i].getRang() > m_localisationImages[i + 1].getRang()) {
                imageDansDiapo = m_localisationImages[i];
                m_localisationImages[i] = m_localisationImages[i + 1];
                m_localisationImages[i + 1] = imageDansDiapo;
            }
        }
    }
}
