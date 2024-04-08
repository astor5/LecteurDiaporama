#include "image.h"


Image::Image(string titre, string categorie, string rang, string chemin):
    m_titre(titre),
    m_categorie(categorie),
    m_rang(rang),
    m_chemin(chemin){
}

Image::Image(const Image & original):
    m_titre(original.m_titre),
    m_categorie(original.m_categorie),
    m_rang(original.m_rang),
    m_chemin(original.m_chemin){
}

string Image::getCategorie() const
{
    return (*this).m_categorie;
}

string Image::getTitre() const
{
    return (*this).m_titre;
}

string Image::getRang() const
{
    return (*this).m_rang;
}

string Image::getChemin() const
{
    return (*this).m_chemin;
}

void Image::afficher() const
{
    cout << "image(titre:" << (*this).getTitre() << ", categorie:"
         << (*this).getCategorie() << ", chemin:"<< (*this).getChemin() << ")" << endl;
}


