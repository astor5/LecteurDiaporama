#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
using namespace std;

// Module de manipulation d'éléments de type Image

struct Image {
    string titre;              // intitulé de l'image
    string categorie;          // catégorie de l'image (personne, animal, objet)
    string chemin;
};

Image creerImage (string pTitre="", string pCategorie="", string pChemin = "");
//
string getCategorie(const Image& pImag);
string getTitre(const Image& pImag);
string getChemin(const Image& pImag);
void afficher(const Image& pImag);           // affiche tous les champs de l'image


#endif // IMAGE_H
