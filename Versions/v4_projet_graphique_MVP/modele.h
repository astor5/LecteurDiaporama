#ifndef MODELE_H
#define MODELE_H

#include <QObject>
#include "diaporama.h"
#include <iostream>
using namespace std;

class Modele : public QObject
{
    Q_OBJECT

public:
    enum UnEtat {automatique, manuel};
    enum UnMode {initial, boucle};
    void changementEtat();
    void changementMode();
    UnEtat getEtat();
    UnMode getMode();
    void setEtat(UnEtat);
    void setMode(UnMode);
    Modele(UnEtat e=manuel, UnMode m=boucle);

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
    void touchePressee();
    bool defilageAutoPossible();

private:
    string m_titre;
    unsigned short int m_vitesseDefilement; //Vitesse de défilement en secondes
    vector <ImageDansDiaporama> m_localisationImages; // images du diaporama
    unsigned int m_posImage;

    Diaporama * diapo;
    vector<Diaporama *> _Diaporamas;
    int _diaporamaCourant;
    UnEtat _etat;
    UnMode _mode;
};

#endif // MODELE_H
