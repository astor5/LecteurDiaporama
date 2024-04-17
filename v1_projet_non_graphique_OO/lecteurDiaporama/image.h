#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
using namespace std;

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

    //Getters
    string getCategorie() const;                // catégorie de l'image (personne, animal, objet)
    string getTitre() const;                // intitulé de l'image
    string getRang() const;
    string getChemin() const;

    //Sous-programmes de base
    void charger();
    void saisieVerifChoixActionSurImageCourante();
};


#endif // IMAGE_H
