#ifndef MODELE_H
#define MODELE_H

#include <QObject>
#include "diaporama.h"
#include "database.h"
#include <iostream>
using namespace std;

class Modele : public QObject
{
    Q_OBJECT

public:
    enum UnEtat {automatique, manuel};
    enum EtatLecteur {initial, charge};

    void changementEtat();
    void changementEtatLecteur();

    UnEtat getEtat();
    EtatLecteur getEtatLecteur();

    void setEtat(UnEtat);
    void setEtatLecteur(EtatLecteur);

    Modele(UnEtat e=manuel, EtatLecteur l=initial);


    //Getter
    unsigned short int getVitesseDefilement() const;
    Diaporama * getDiaporamaCourant();
    vector<Diaporama*> getTabDiaporamas();
    database * getDatabase();

    void setTabDiaporamas(vector<Diaporama*>);


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
    EtatLecteur _etatLecteur;
    database * db;
};

#endif // MODELE_H
