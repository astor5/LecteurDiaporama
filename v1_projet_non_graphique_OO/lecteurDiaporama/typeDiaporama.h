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
/*
struct Diaporamas {
    string titre ;  // titre du diaporama
    unsigned int vitesseDefilement; // vitesse de défilement des images du diaporama
    vector <ImageDansDiaporama> localisationImages; // images du diaporama
};*/

typedef vector<Image> ImageT;
typedef vector<Diaporama> DiaporamaT;


class Diaporama {

private:
    string m_titre;
    unsigned short int m_vitesseDefilement; //Vitesse de défilement en secondes
    vector <ImageDansDiaporama> m_localisationImages; // images du diaporama

public:
    Diaporama(string = "", unsigned short int =2);
    Diaporama(const Diaporama&);
    ~Diaporama();

    //Getter
    string getTitre() const;
    vector<ImageDansDiaporama> getLocalisationImages();
    unsigned short int getVitesseDefilement() const;

    //Setter
    void setTitre(const string &);
    void setVitesseDefilement(unsigned int nouvelleVitesse);
    void setLocalisationImages(const std::vector<ImageDansDiaporama> &images);

    //Sous-programmes de base
    void charger();
    void declencherAction();
    void saisieVerifChoixDiaporama();
    void afficherImageDansDiaporamaCourant(const DiaporamaT&, unsigned int, const ImageT&);
};




#endif // TYPE_DIAPORAMA_H

