#ifndef LECTEUR_H
#define LECTEUR_H

#include "typeDiaporama.h"

class Lecteur {
private:
    bool m_estVide;
    bool m_estManuel;
    Diaporama m_diaporama;

public:
    Lecteur(bool=true, unsigned short int=2); //Le mode est manuel par défaut et la vitesse est de 2 secondes par défaut
    Lecteur(const Lecteur&);
    ~Lecteur();

    bool getEstManuel() const;
    bool getEstVide() const;
    void lireDiaporama(const Diaporama&) const;
    void arreterLecture(const Diaporama&) const;
    void charger(const Diaporama&);
    void enleverDiaporama();
    void changerModeDefilement(const Diaporama&);





};

#endif // LECTEUR_H
