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

typedef vector<Images> ImagesT;
typedef vector<Diaporamas> DiaporamasT;


class Diaporama {

private:
    string m_titre;
    Image m_image;

public:
    Diaporama(string = "", Image = Image());
    Diaporama(const Diaporama&);
    ~Diaporama();

    string getTitre(const Diaporama&) const;
    void passerAuSuivant(const Diaporama&) const;
    void passerAuPrecedent(const Diaporama&) const;
    void allerPremiereImage(const Diaporama&) const;
    void changerModeDefilement(const Diaporama&);


};



#endif // TYPE_DIAPORAMA_H

