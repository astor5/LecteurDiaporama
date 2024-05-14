#include <iostream>
#include "diaporama.h"
#include "qdebug.h"
using namespace std;

Diaporama::Diaporama(string titre):
    m_titre(titre){
}

Diaporama::Diaporama(unsigned short vitesseDefilement, unsigned int position):
    m_posImage(position){
}

Diaporama::Diaporama(const Diaporama & original):
    m_titre(original.m_titre),
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

ImageDansDiaporama Diaporama::getImageCourante() const
{
    return getLocalisationImages()[getPosImageCouranteInt()];
}

unsigned int Diaporama::getNombreImages() const
{
    return getLocalisationImages().size();
}

vector<Image> Diaporama::getToutesImages() const
{
    return _Images;
}


void Diaporama::setTitre(const string & titre)
{
    m_titre = titre;
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

vector<Image> Diaporama::charger()
{
    qDebug() << "chargement images";
    vector<Image> pImages;

    Image imageACharger("", "objet", "C:\\cartesDisney\\Disney_tapis.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("Blanche Neige", "personnage", "C:\\cartesDisney\\Disney_4.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("Alice", "personnage", "C:\\cartesDisney\\Disney_2.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("Mickey", "animal", "C:\\cartesDisney\\Disney_19.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("Pinnochio", "personnage", "C:\\cartesDisney\\Disney_29.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("chateau", "objet", "C:\\cartesDisney\\Disney_0.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("Minnie", "personnage", "C:\\cartesDisney\\Disney_14.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("Bambi", "animal", "C:\\cartesDisney\\Disney_3.gif");
    pImages.push_back(imageACharger);

    return pImages;
}

void Diaporama::chargerDiapos(vector<Image> pImages, vector<Diaporama *> & diaposCharges)
{
    qDebug() << "chargement Diapos";

    ImageDansDiaporama imageDansDiapo;

       qDebug() << "chargement Diapo 1";
    Diaporama * diaporama = new Diaporama("Diaporama par defaut");

    imageDansDiapo = ImageDansDiaporama(pImages,0,1);
    diaporama->ajouterImage(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,2,2);
    diaporama->ajouterImage(imageDansDiapo);
    diaporama->setPosImageCouranteInt(0);
    diaposCharges.push_back(diaporama);

    // Diaporama de Pantxika
    qDebug() << "chargement Diapo 2";
    Diaporama * diapoPantxika = new Diaporama("Diaporama Pantxika");

    // Les images du diaporama de Pantxika
    imageDansDiapo = ImageDansDiaporama(pImages,2,3);
    diapoPantxika->ajouterImage(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,4,1);
    diapoPantxika->ajouterImage(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,1,2);
    diapoPantxika->ajouterImage(imageDansDiapo);
    diapoPantxika->setPosImageCouranteInt(0);

    // ajout du diaporama dans le tableau de diaporamas
    diaposCharges.push_back(diapoPantxika);

    // Diaporama de Thierry
    qDebug() << "chargement Diapo 3";
    Diaporama * diapoThierry = new Diaporama("Diaporama de Thierry");

    // Les images du diaporama de Thierry
    imageDansDiapo = ImageDansDiaporama(pImages,4,1);
    diapoThierry->ajouterImage(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,1,2);
    diapoThierry->ajouterImage(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,2,3);
    diapoThierry->ajouterImage(imageDansDiapo);
    diapoThierry->setPosImageCouranteInt(0);

    // ajout du diaporama dans le tableau de diaporamas
    diaposCharges.push_back(diapoThierry);

    // Diaporama de Yann
    qDebug() << "chargement Diapo 4";
    Diaporama * diapoYann = new Diaporama("Diaporama Yann");

    // Les images du diaporama de Yann
    imageDansDiapo = ImageDansDiaporama(pImages,5,5);
    diapoYann->ajouterImage(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,3,1);
    diapoYann->ajouterImage(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,1,2);
    diapoYann->ajouterImage(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,2,3);
    diapoYann->ajouterImage(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,4,4);
    diapoYann->ajouterImage(imageDansDiapo);
    diapoYann->setPosImageCouranteInt(0);

    // ajout du diaporama dans le tableau de diaporamas
    diaposCharges.push_back(diapoYann);
    // Diaporama de Manu
    qDebug() << "chargement Diapo 5";
    Diaporama * diapoManu = new Diaporama("Diaporama Manu");

    // Les images du diaporama de Manu
    imageDansDiapo = ImageDansDiaporama(pImages,4,4);
    diapoManu->ajouterImage(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,1,3);
    diapoManu->ajouterImage(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,2,2);
    diapoManu->ajouterImage(imageDansDiapo);
    imageDansDiapo = ImageDansDiaporama(pImages,3,1);
    diapoManu->ajouterImage(imageDansDiapo);
    diapoManu->setPosImageCouranteInt(0);

    // ajout du diaporama dans le tableau de diaporamas
    diaposCharges.push_back(diapoManu);
    qDebug() << "Avant return";
}


/*
void Diaporama::afficherImageCouranteDansDiaporamaCourant() {
    cout << endl << endl;
    cout << "DIAPORAMA : " << getTitre() << endl << endl;
    cout << getPositionImage().getRang() << " sur " << nbImages() << " / ";
    getPositionImage().afficher();
}*/

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
