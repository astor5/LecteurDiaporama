#ifndef LECTEUR_H
#define LECTEUR_H
#include "image.h"
#include <vector>

typedef vector<Image*> Diaporama;   // Structure de données contenant les infos sur les images

class Lecteur
{
public:
    Lecteur();
    ~Lecteur();

    //Méthode de la V0
    void avancer();             // incrémente _posImageCourante, modulo nbImages()
    void reculer();             // décrémente _posImageCourante, modulo nbImages()
    void changerDiaporama(unsigned int = 0);    // permet de choisir un diaporama, 0 si aucun diaporama souhaité
    void triCroissantRang();    // Tri du diaporama pDiaporama par ordre croissant de *rang* des ses images
    unsigned int nbImages();    // affiche la taille de _diaporama

private:
    unsigned m_numDiaporamaCourant;   // numéro du diaporama courant, par défaut 0
    Diaporama m_diaporama;            // pointeurs vers les images du diaporama
    unsigned int m_posImageCourante;  /* position, dans le diaporama,
                                        de l'image courante.
                                        Indéfini quand diaporama vide.
                                        Démarre à 0 quand diaporama non vide */
};

#endif // LECTEUR_H
