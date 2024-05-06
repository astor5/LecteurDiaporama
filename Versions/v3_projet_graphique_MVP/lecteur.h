/*#ifndef LECTEUR_H
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
    /*** Constructeurs ***
    Lecteur(); // Constructeur par défaut
    Lecteur(vector<Diaporama>, unsigned int = 0);


    /*** Getters ***
    vector<Diaporama> & getToutesDiapos();
    Diaporama & getDiapoCourant();
    unsigned int getNumDiapoCourant();
    unsigned int getNombreDiapos();

    /*** Setters ***
    void setToutesDiapos(const vector<Diaporama>&);
    void setNumDiapoCourant(unsigned int);
    void setNombreDiapos(unsigned int);

    /*** Autres méthodes ***
    void declencherAction(char);
    void saisieVerifChoixActionSurImageCourante(char&);
    unsigned int saisieVerifChoixDiaporama();
    void charger(Images&);
    void chargerDiapos(Images&);
};

#endif // LECTEUR_H

*/
