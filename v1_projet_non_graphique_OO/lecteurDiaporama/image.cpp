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

void Image::afficher() const
{
    cout << "image(titre:" << this->getTitre() << ", categorie:"
         << this->getCategorie() << ", chemin:"<< this->getChemin() << ")" << endl;
}

void Image::charger(vector<Image>& pImages) {
    Image imageACharger;

    imageACharger = Image("objet", "", "C:\\cartesDisney\\Disney_tapis.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("personnage", "Blanche Neige", "C:\\cartesDisney\\Disney_4.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("personnage", "Alice", "C:\\cartesDisney\\Disney_2.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("animal", "Mickey", "C:\\cartesDisney\\Disney_19.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("personnage", "Pinnochio", "C:\\cartesDisney\\Disney_29.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("objet", "chateau", "C:\\cartesDisney\\Disney_0.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("personnage", "Minnie", "C:\\cartesDisney\\Disney_14.gif");
    pImages.push_back(imageACharger);

    imageACharger = Image("animal", "Bambi", "C:\\cartesDisney\\Disney_3.gif");
    pImages.push_back(imageACharger);
}
