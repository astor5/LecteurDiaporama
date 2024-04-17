#include <iostream>
#include "image.h"
using namespace std;

Image::Image(string titre, string categorie, string chemin):
    m_titre(titre),
    m_categorie(categorie),
    m_chemin(chemin){
}

Image::Image(const Image & original):
    m_titre(original.m_titre),
    m_categorie(original.m_categorie),
    m_chemin(original.m_chemin){
}

string Image::getCategorie() const
{
    return this->m_categorie;
}

string Image::getTitre() const
{
    return this->m_titre;
}

string Image::getChemin() const
{
    return this->m_chemin;
}

void Image::charger()
{

}

void Image::saisieVerifChoixActionSurImageCourante()
{

}
