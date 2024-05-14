#ifndef MODELE_H
#define MODELE_H

#include <QObject>
#include "diaporama.h"
#include <iostream>
using namespace std;

class Modele : public QObject
{
    Q_OBJECT

private:
    string m_titre;
    unsigned short int m_vitesseDefilement; //Vitesse de défilement en secondes
    vector <ImageDansDiaporama> m_localisationImages; // images du diaporama
    unsigned int m_posImage;

    vector<Diaporama *> _Diaporamas;
    int _diaporamaCourant;



public:
    Modele();

    //Getter
    unsigned short int getVitesseDefilement() const;
    Diaporama * getDiaporamaCourant() const;


    //Setter
    void setVitesseDefilement(unsigned int);
    void setDiaporamaCourant(int);

    //Sous-programmes de base
    void avancer();
    void reculer();
    //void afficherImageCouranteDansDiaporamaCourant();
    void triCroissantRang();

    void charger();

};

#endif // MODELE_H
