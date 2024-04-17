#ifndef TYPE_DIAPORAMA_H
#define TYPE_DIAPORAMA_H
#include <iostream>
using namespace std;
#include <vector>
#include "image.h"
#include "ImageDansDiaporama.h"

/*
struct ImageDansDiaporama {
    unsigned int pos;  // rang de l'image dans le tableau d'images (vector<Images>)
                       // = ordre de chargement initial des images dans la table des images
    unsigned int rang;  // rang de l'image dans le diaporama
                        // = ordre d'affichage choisi par l'utilisateur lors de la création du diaporama
};*/

struct Diaporamas {
    string titre ;  // titre du diaporama
    unsigned int vitesseDefilement; // vitesse de défilement des images du diaporama
    vector <ImageDansDiaporama> localisationImages; // images du diaporama
};




class Diaporama {

private:
    string m_titre;
    unsigned short int m_vitesseDefilement; //Vitesse de défilement en secondes
    vector <ImageDansDiaporama> localisationImages; // images du diaporama
    string m_filtre;

public:
    Diaporama(string = "", unsigned short int =2,  string ="");
    Diaporama(const Diaporama&);
    ~Diaporama();

    //Getter
    string getTitre() const;
    string getFiltre() const;
    vector<ImageDansDiaporama> getLocalisationImages();
    unsigned short int getVitesseDefilement() const;

    //Setter
    void modifierFiltre();
    void setTitre(const string &);
    void setVitesseDefilement(unsigned int nouvelleVitesse);
    void setLocalisationImages(const std::vector<ImageDansDiaporama> &images);

    //Sous-programmes de base
    void charger();
    void declencherAction();
    void saisieVerifChoixDiaporama();
    void afficherImageDansDiaporamaCourant();
};

inline Diaporama::Diaporama(string, unsigned short, string)
{

}

inline Diaporama::Diaporama(const Diaporama &)
{

}

inline Diaporama::~Diaporama()
{

}

inline string Diaporama::getTitre() const
{

}

inline string Diaporama::getFiltre() const
{

}

inline vector<ImageDansDiaporama> Diaporama::getLocalisationImages()
{

}

inline unsigned short Diaporama::getVitesseDefilement() const
{

}

inline void Diaporama::modifierFiltre()
{

}

inline void Diaporama::setTitre(const string &)
{

}

inline void Diaporama::setVitesseDefilement(unsigned int nouvelleVitesse)
{

}

inline void Diaporama::setLocalisationImages(const std::vector<ImageDansDiaporama> &images)
{

}

inline void Diaporama::charger()
{

}

inline void Diaporama::declencherAction()
{

}

inline void Diaporama::saisieVerifChoixDiaporama()
{

}

inline void Diaporama::afficherImageDansDiaporamaCourant()
{

}


typedef vector<Image> ImageT;
typedef vector<Diaporama> DiaporamaT;

#endif // TYPE_DIAPORAMA_H

