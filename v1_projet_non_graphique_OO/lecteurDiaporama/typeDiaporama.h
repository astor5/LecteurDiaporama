#ifndef TYPE_DIAPORAMA_H
#define TYPE_DIAPORAMA_H
#include <iostream>
using namespace std;
#include <vector>
#include "image.h"
#include "ImageDansDiaporama.h"




class Diaporama {

private:
    string m_titre;
    unsigned short int m_vitesseDefilement; //Vitesse de défilement en secondes
    vector <ImageDansDiaporama> m_localisationImages; // images du diaporama



public:
    Diaporama(string = "", unsigned short int =0);
    Diaporama(const Diaporama&);
    ~Diaporama();

    typedef vector<Diaporama> DiaporamaT;

    //Getter
    string getTitre() const;
    vector<ImageDansDiaporama> getLocalisationImages();
    unsigned short int getVitesseDefilement() const;

    //Setter
    void setTitre(const string &);
    void setVitesseDefilement(unsigned int);
    void setLocalisationImages(const std::vector<ImageDansDiaporama> &);

    //Sous-programmes de base
    void afficherImageCouranteDansDiaporamaCourant(unsigned int) const;
    unsigned int nbImages() const;
    void avancer(unsigned int&) const;
    void reculer(unsigned int&) const;
    void triCroissantRang();
};




#endif // TYPE_DIAPORAMA_H

