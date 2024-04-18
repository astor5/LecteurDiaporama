#ifndef IMAGEDANSDIAPORAMA_H
#define IMAGEDANSDIAPORAMA_H

#include <iostream>
#include "image.h"
using namespace std;

class ImageDansDiaporama {
private :
    Image m_image;
    unsigned int m_pos;
    unsigned int m_rang;

public:
    ImageDansDiaporama(unsigned int, unsigned int);//les paramètres dans l'ordre : titre, categorie, rang, chemin
    ImageDansDiaporama(const ImageDansDiaporama&);
    //~Image(); //pas besoin de destructeur car on ne fait pas d'allocation dynamique (je crois)

    unsigned int getPosition() const;
    unsigned int getRang() const;
    Image getImage() const;
};

#endif // IMAGEDANSDIAPORAMA_H
