#ifndef IMAGEDANSDIAPORAMA_H
#define IMAGEDANSDIAPORAMA_H

#include <iostream>
#include "image.h"
using namespace std;

class ImageDansDiaporama : public Image {
private :
    unsigned int m_pos; // rang de l'image dans le tableau d'images (vector<Images>)
    unsigned int m_rang; // rang de l'image dans le diaporama

public:
    ImageDansDiaporama();
    ImageDansDiaporama(const Image&, unsigned int, unsigned int);//les paramètres dans l'ordre : titre, categorie, rang, chemin
    ImageDansDiaporama(Images&, unsigned int, unsigned int);
    //~Image(); //pas besoin de destructeur car on ne fait pas d'allocation dynamique (je crois)

    unsigned int getPosition() const;
    unsigned int getRang() const;
    Image getImage() const;

    void setPosition(unsigned int);
    void setRang(unsigned int);
};

#endif // IMAGEDANSDIAPORAMA_H
