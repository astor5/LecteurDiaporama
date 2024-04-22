#include <iostream>
#include "typeDiaporama.h"
using namespace std;

Diaporama::Diaporama(string titre):
    m_titre(titre){
}

Diaporama::Diaporama(unsigned short vitesseDefilement, unsigned int position):
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

unsigned int Diaporama::getNombreImages() const
{
    return getLocalisationImages().size();
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

void Diaporama::ajouterImage(const ImageDansDiaporama& image)
{
    m_localisationImages.push_back(image);
}

unsigned int Diaporama::nbImages() const
{
    return m_localisationImages.size();
}

void Diaporama::avancer() {
    if (this->getPosImageCouranteInt() == this->nbImages() - 1)
    {
        cout << "DEBUG : On avance (fin du diapo) " << endl;
        cout << "DEBUG : Position de l'image courante " << getPosImageCouranteInt() << endl; 
        this->setPosImageCouranteInt(0);
        cout << "DEBUG : Position de l'image courante apres le set " << this->getPosImageCouranteInt() << endl; 

    }
    else
    {
        cout << "DEBUG : On avance " << endl;
        cout << "DEBUG : Position de l'image courante " << getPosImageCouranteInt() << endl;
        setPosImageCouranteInt(getPosImageCouranteInt() + 1);
        cout << "DEBUG : Position de l'image courante apres le set " << this->getPosImageCouranteInt() << endl; 
    }
}

void Diaporama::reculer()
{
    if (this->getPosImageCouranteInt() == 0)
    {
        cout << "DEBUG : On recule (debut du diapo) " << endl;
        cout << "DEBUG : Position de l'image courante " << getPosImageCouranteInt() << endl; 
        this->setPosImageCouranteInt(this->nbImages() - 1);
        cout << "DEBUG : Position de l'image courante apres le set " << getPosImageCouranteInt() << endl; 
    }
    else
    {
        cout << "DEBUG : On recule " << endl;
        cout << "DEBUG : Position de l'image courante " << getPosImageCouranteInt() << endl; 
        this->setPosImageCouranteInt(this->getPosImageCouranteInt() - 1);
        cout << "DEBUG : Position de l'image courante apres le set " << getPosImageCouranteInt() << endl; 
    }
}

void Diaporama::afficherImageCouranteDansDiaporamaCourant() {
    cout << endl << endl;
    //setPosImageCouranteInt(0);
    cout << "DIAPORAMA : " << getTitre() << endl << endl;
    cout << this->getLocalisationImages()[getPosImageCouranteInt()].getRang() << " sur " << nbImages() << " / ";  //Méthode d'affichage 1
    getLocalisationImages()[getPosImageCouranteInt()].afficher();
    cout << getPositionImage().getRang() << " sur " << nbImages() << " / ";                                 //Méthode d'affichage 2
    getPositionImage().afficher();
}

void Diaporama::triCroissantRang() {
    unsigned int taille = this->nbImages();
    ImageDansDiaporama imageDansDiapo;
    for (unsigned int ici = taille - 1; ici >= 1; ici--) {
        for (unsigned int i = 0; i < ici; i++) {
            if (m_localisationImages[i].getPosition() > m_localisationImages[i + 1].getPosition()) {
                imageDansDiapo = m_localisationImages[i];
                m_localisationImages[i] = m_localisationImages[i + 1];
                m_localisationImages[i + 1] = imageDansDiapo;
            }
        }
    }
}
