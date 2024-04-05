#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
using namespace std;

// Module de manipulation d'éléments de type Image

struct Images {
    string titre;              // intitulé de l'image
    string categorie;          // catégorie de l'image (personne, animal, objet)
    string chemin;
};

Images creerImage (string pTitre="", string pCategorie="", string pChemin = "");
//
string getCategorie(const Images& pImag);
string getTitre(const Images& pImag);
string getChemin(const Images& pImag);
void afficher(const Images& pImag);           // affiche tous les champs de l'image



class Image {
private :
    string m_titre;
    string m_categorie;
    string m_rang;
    string m_chemin;

public:
    Image(string = "", string = "", string="", string="");
    Image(const Image&);
    ~Image();

    string getCategorie(const Image&) const;
    string getTitre(const Image&) const;
    string getRang(const Image&) const;
    string getChemin(const Image&) const;
    void afficher(const Image&) const;
};


#endif // IMAGE_H
