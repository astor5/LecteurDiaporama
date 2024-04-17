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
    void changerDiaporama(unsigned int pNumDiaporama);    // permet de choisir un diaporama, 0 si aucun diaporama souhaité
    void triCroissantRang();    // Tri du diaporama pDiaporama par ordre croissant de *rang* des ses images
    unsigned int nbImages();    // affiche la taille de _diaporama

    //Autres méthodes
    //void afficher();            // affiche les informations sur lecteur-diaporama et image courante
    Image* imageCourante();     // retourne le pointeur vers l'image courante
    unsigned int numDiaporamaCourant();

private:
    unsigned m_numDiaporamaCourant;   // numéro du diaporama courant, par défaut 0
    Diaporama m_diaporama;            // pointeurs vers les images du diaporama
    unsigned int m_posImageCourante;  /* position, dans le diaporama,
                                        de l'image courante.
                                        Indéfini quand diaporama vide.
                                        Démarre à 0 quand diaporama non vide */
private:
    void chargerDiaporama();    // charge dans _diaporama les images du _numDiaporamaCourant
    void viderDiaporama();      // vide _diaporama de tous ses objets image et les delete
};

#endif // LECTEUR_H
