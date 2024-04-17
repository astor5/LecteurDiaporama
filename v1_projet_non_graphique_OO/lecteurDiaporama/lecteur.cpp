#include <iostream>
#include "lecteur.h"
using namespace std;

Lecteur::Lecteur()
{

}

Lecteur::~Lecteur()
{

}

void Lecteur::avancer(const DiaporamasT& unDiapo)
{
    if (nbImages(unDiapo) > 0) {
            m_posImageCourante = (m_posImageCourante+1) % nbImages(unDiapo);
    }
}

void Lecteur::reculer(const DiaporamasT& unDiapo)
{
    if (nbImages(unDiapo) > 0) {
            m_posImageCourante = (m_posImageCourante-1) % nbImages(unDiapo);
    }
}

void Lecteur::changerDiaporama(unsigned int pNumDiaporama)
{

}

void Lecteur::triCroissantRang(DiaporamaT &pDiaporama)
{

}

unsigned int Lecteur::nbImages(const DiaporamasT& unDiaporama)
{
    return unDiaporama.size();
}
