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
    Image m_image;
    bool m_estManuel;
    unsigned short int m_vitesseDefilement; //Vitesse de défilement en secondes
    string m_filtre;

public:
    Diaporama(string = "", Image = Image());
    Diaporama(const Diaporama&);
    ~Diaporama();

    string getTitre(const Diaporama&) const;
    void passerAuSuivant(const Diaporama&) const;
    void passerAuPrecedent(const Diaporama&) const;
    void allerPremiereImage(const Diaporama&) const;
    void changerModeDefilement(const Diaporama&);
    unsigned short int getVitesseDefilement(const Diaporama&) const;
    Diaporama getDiaporama(const Diaporama&) const;
    string getFiltre(const Diaporama&) const;
    void modifierFiltre(const Diaporama&);


};



#endif // TYPE_DIAPORAMA_H

