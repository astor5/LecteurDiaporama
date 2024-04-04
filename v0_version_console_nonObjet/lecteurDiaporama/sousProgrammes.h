#ifndef SOUS_PROGRAMMES_POUR_VERSIONS_INITIALES_H
#define SOUS_PROGRAMMES_POUR_VERSIONS_INITIALES_H
#include <iostream>
#include <vector>
#include "image.h"
#include "typeDiaporama.h"
using namespace std;


/* Sous-programmes provisoires pour versions Non encore graphiques
 * -------------------------------------------------------------- */
void afficherImageCouranteDansDiaporamaCourant (const Diaporama& pDiaporama, unsigned int pImageCourante, const Image& pImage);
/* Affichage à l'acran des infos de l'image courante dans son diaporama
 *    - titre du diaporama
      - image courante : titre, famille, contenu
      - rang de l'image courante dans le diaporama / nbre total d'images du diaporama */

void saisieVerifChoixActionSurImageCourante(char& pChoixAction);
// Saisie du choix d'action de l'utilisateur vis-à-vis de l'image et diaporama courants

unsigned int saisieVerifChoixDiaporama(const Diaporamas& pDiaporamas);
// Retourne un numéro de diaporama choisi par l'utilisateur (dans la liste des diaporamas existants)

void declencherAction(char pChoixAction, const Diaporamas& pDiaporamas, unsigned int& pDiaporamaCourant,
                      unsigned int& pImageCourante, const Images& pImages);
/* Selon le pChoix fait l'utilisateur, réalise une des actions A)vancer, R)eculer, C)hoisir un autre diaporama, Q)quitter */


/* Sous-programmes provisoires pour versions antérieures à l'implantation de la BD
----------------------------------------------------------------------------------*/
void charger (Images& pImages);
/* Chargement du tableau des images avec seules les informations textuelles de quelques images.
   Dans une version ultérieure, ces informations seront stockées dans une Base de Données.
*/

void charger (Diaporamas& pDiaporamas);
/* Chargement du tableau des diaporamas avec des diaporamas préalablement construits 'en dur'.
   Dans une version ultérieure, le diaporama courant affiché par le Lecteur de diaporamas sera chargé à partir
   d'une base de données.
*/


/* Déclarations des sous-programmes utilisés par le lecteur de diaporamas
 * ---------------------------------------------------------------------- */

void avancer(const Diaporama& pDiaporama, unsigned int& pPosImageCourante);            // incrémente pPosImageCourante, modulo nbImages(pDiaporama)
void reculer(const Diaporama& pDiaporama, unsigned int& pPosImageCourante);             // décrémente pPosImageCourante, modulo nbImages(pDiaporama)
void changerDiaporama(unsigned int pNumDiaporama);    // permet de choisir un diaporama, 0 si aucun diaporama souhaité
unsigned int nbImages(const Diaporama& pDiaporama);    // affiche la taille du diaporama pDiaporama

void triCroissantRang (Diaporama& pDiaporama);
/* Tri du diaporama pDiaporama par ordre croissant de *rang* des ses images
   A garder aussi lors de l'implémentation de la BD */

#endif // SOUS_PROGRAMMES_POUR_VERSIONS_INITIALES_H
