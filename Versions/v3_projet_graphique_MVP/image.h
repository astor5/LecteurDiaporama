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
    Image(string = "Def", string = "Def", string="Def");//les paramètres dans l'ordre : titre, categorie, chemin
    Image(const Image&);

    //Getters
    string getCategorie() const;                // catégorie de l'image (personne, animal, objet)
    string getTitre() const;                    // intitulé de l'image
    string getChemin() const;

    //Sous-programmes de base
    //void charger(vector<Image>&);
    void afficher() const;
};

typedef vector<Image> Images;

#endif // IMAGE_H
