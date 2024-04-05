#ifndef LECTEUR_H
#define LECTEUR_H

class Lecteur {
private:
    bool m_estManuel;
    unsigned short int m_vitesseDefilement; //Vitesse de défilement en secondes

public:
    Lecteur(bool=true, unsigned short int=2); //Le mode est manuel par défaut et la vitesse est de 2 secondes par défaut
    Lecteur(const Lecteur&);
    ~Lecteur();

    bool getEstManuel(const Lecteur&) const;
    unsigned short int vitesseDefilement(const Lecteur&) const;
    void changerModeDefilement(const Lecteur&);



};

#endif // LECTEUR_H
