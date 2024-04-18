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

unsigned int Diaporama::nbImages() const
{
    return m_localisationImages.size();
}

void Diaporama::avancer(unsigned int& posImageCourante) const {
    if (posImageCourante == m_localisationImages.size() - 1) {
        posImageCourante = 0;
    } else {
        posImageCourante++;
    }
}

void Diaporama::reculer(unsigned int& posImageCourante) const {
    if (posImageCourante == 0) {
        posImageCourante = m_localisationImages.size() - 1;
    } else {
        posImageCourante--;
    }
}

void Diaporama::afficherImageCouranteDansDiaporamaCourant(unsigned int pImageCourante) const {
    cout << endl << endl;
    cout << "DIAPORAMA : " << m_titre << endl << endl;
    cout << m_localisationImages[pImageCourante].getRang() << " sur " << nbImages() << " / ";
    m_localisationImages[pImageCourante].getImage().afficher();
}

void Diaporama::triCroissantRang() {
    unsigned int taille = this->nbImages();
    ImageDansDiaporama imageDansDiapo(0,0);
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
