#ifndef TYPE_DIAPORAMA_H
#define TYPE_DIAPORAMA_H
#include <iostream>
using namespace std;
#include <vector>
#include "image.h"

struct ImageDansDiaporama {
    unsigned int pos;  // rang de l'image dans le tableau d'images (vector<Images>)
                       // = ordre de chargement initial des images dans la table des images
    unsigned int rang;  // rang de l'image dans le diaporama
                        // = ordre d'affichage choisi par l'utilisateur lors de la création du diaporama
};

struct Diaporama {
    string titre ;  // titre du diaporama
    unsigned int vitesseDefilement; // vitesse de défilement des images du diaporama
    vector <ImageDansDiaporama> localisationImages; // images du diaporama
};

typedef vector<Image> Images;
typedef vector<Diaporama> Diaporamas;
#endif // TYPE_DIAPORAMA_H
