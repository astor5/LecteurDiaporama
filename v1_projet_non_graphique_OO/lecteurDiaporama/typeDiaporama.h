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

typedef vector<Image> ImagesT;
typedef vector<Diaporamas> DiaporamasT;


class Diaporama {

private:
    string m_titre;
    unsigned short int m_vitesseDefilement; //Vitesse de défilement en secondes
    vector <ImageDansDiaporama> localisationImages; // images du diaporama
    string m_filtre;

public:
    Diaporama(string = "", unsigned short int =2, vector<ImageDansDiaporama> = ,  string ="");
    Diaporama(const Diaporama&);
    ~Diaporama();

    //Getter
    string getTitre() const;
    string getFiltre() const;
    Diaporama getDiaporama() const;
    unsigned short int getVitesseDefilement() const;

    //Setter
    void modifierFiltre();

    //Sous-programmes de base
    void charger();
    void declencherAction();
    void saisieVerifChoixDiaporama();
    void afficherImageDansDiaporamaCourant();

    unsigned short int nombreImages() const;


};


#endif // TYPE_DIAPORAMA_H

