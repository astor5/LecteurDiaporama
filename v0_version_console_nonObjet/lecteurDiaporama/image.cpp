#include "image.h"

Image creerImage(string pCategorie, string pTitre, string pChemin)
{
    Image image;
    image.categorie = pCategorie;
    image.titre = pTitre;
    image.chemin = pChemin;
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
