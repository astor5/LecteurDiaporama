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
    Image(string = "", string = "", string="", string="");//les paramètres dans l'ordre : titre, categorie, rang, chemin
    Image(const Image&);
    //~Image(); //pas besoin de destructeur car on ne fait pas d'allocation dynamique (je crois)

    string getCategorie() const;
    string getTitre() const;
    string getRang() const;
    string getChemin() const;
    void afficher() const;
};


#endif // IMAGE_H
