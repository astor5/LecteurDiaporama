#ifndef LECTEUR_H
#define LECTEUR_H
#include "image.h"
#include "typeDiaporama.h"
#include <vector>



class Image;

class Lecteur
{
private:
    vector<Diaporama> m_toutesDiapos;
    unsigned int m_numDiapoCourant;
    unsigned int m_nombreDiapos;


public:
    /*** Constructeurs ***/
    Lecteur(); // Constructeur par défaut
    Lecteur(vector<Diaporama>, unsigned int, unsigned int);


    /*** Getters ***/
    vector<Diaporama> getToutesDiapos() const;
    Diaporama getDiapoCourant() const;
    unsigned int getNumDiapoCourant() const;
    unsigned int getNombreDiapos() const;

    /*** Setters ***/
    void setToutesDiapos(const vector<Diaporama>&);
    void setNumDiapoCourant(unsigned int);
    void setNombreDiapos(unsigned int);

    /*** Autres méthodes ***/
    void declencherAction(char);
    void saisieVerifChoixActionSurImageCourante(char&);
    unsigned int saisieVerifChoixDiaporama();
    void charger(Images&);
    void chargerDiapos(Images&);
    void afficherDiapoCourant();
};

/*

typedef vector<Image*> DiaporamasT;   // Structure de données contenant les infos sur les images
typedef vector<Diaporama> DiaporamaT;

class Lecteur {

private:
    unsigned m_numDiaporamaCourant;   // numéro du diaporama courant, par défaut 0
    DiaporamaT m_diaporama;            // pointeurs vers les images du diaporama
    unsigned int m_posImageCourante;*/  /* position, dans le diaporama,
                                        de l'image courante.
                                        Indéfini quand diaporama vide.
                                        Démarre à 0 quand diaporama non vide */
/*
public:
    Lecteur();
    ~Lecteur();

    //Méthode de la V0
    void avancer(const DiaporamasT&);             // incrémente _posImageCourante, modulo nbImages()
    void reculer(const DiaporamasT&);             // décrémente _posImageCourante, modulo nbImages()
    void changerDiaporama(const DiaporamasT&, unsigned int = 0);    // permet de choisir un diaporama, 0 si aucun diaporama souhaité
    unsigned int saisieVerifChoixDiaporama(const DiaporamaT&);
    unsigned int nbImages() const;
    void charger(DiaporamaT&);
    void declencherAction(char, const DiaporamaT&, unsigned int&,
                               unsigned int&, const ImageT& pImages);

    void declencherAction(char);
    void saisieVerifChoixActionSurImageCourante(char&);
    unsigned int saisieVerifChoixDiaporama();
    void charger(Images&);
    void chargerDiapos(Images&);
    void afficherDiapoCourant();
};*/

#endif // LECTEUR_H
