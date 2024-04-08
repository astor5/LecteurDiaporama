#include "image.h"

Image creerImage(string pCategorie, string pTitre, string pChemin)
{
    Image image;
    image.m_categorie = pCategorie;
    image.m_titre = pTitre;
    image.m_chemin = pChemin;
    return image;
}

string getCategorie(const Image& pImage)
{
    return pImage.categorie;
}

string getTitre(const Image& pImage)
{
    return pImage.titre;
}

string getChemin(const Image& pImage)
{
    return pImage.chemin;
}

void afficher(const Image& pImage)
{
    cout << "image(titre:" << getTitre(pImage) << ", categorie:"
         << getCategorie(pImage) << ", chemin:"<< getChemin(pImage) << ")" << endl;
}

Image::Image(string titre, string categorie, string rang, string chemin):
    m_titre(titre),
    m_categorie(categorie),
    m_rang(rang),
    m_chemin(chemin){
}

Image::Image(const Image & origin):
    m_titre(origin.m_titre),
    m_categorie(origin.m_categorie),
    m_rang(origin.m_rang),
    m_chemin(origin.m_chemin){
}

Image::~Image()
{

}
