#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <vector>
using namespace std;

class Image {
private :
    string m_titre;
    string m_categorie;
    string m_chemin;

public:
    Image(string = "", string = "", string="");//les paramètres dans l'ordre : titre, categorie, chemin
    Image(const Image&);
    //~Image(); //pas besoin de destructeur car on ne fait pas d'allocation dynamique (je crois)

    //Getters
    string getCategorie() const;                // catégorie de l'image (personne, animal, objet)
    string getTitre() const;                // intitulé de l'image
    string getChemin() const;

    //Sous-programmes de base
    void charger(vector<Image>&);
    void saisieVerifChoixActionSurImageCourante();
    void afficher() const;
};


#endif // IMAGE_H
