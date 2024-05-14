#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include "modele.h"


class lecteurVue;
class Presentation : public QObject
{ Q_OBJECT
public:
private:
    Modele * _leModele;
    lecteurVue * _laVue;
public:
    Presentation();
    Modele* getModele() const;
    lecteurVue* getVue() const;
    void setModele(Modele *);
    void setVue(lecteurVue *);

    ImageDansDiaporama getImageActuelle();
    Diaporama * getDiapoActuel();


public slots:
    void demanderAvancer();
    void demanderReculer();
    void demanderCharger();
    void demanderLancementDiapo();
    void demanderArretDiapo();

    //void declencherAction(char);
    //void saisieVerifChoixActionSurImageCourante(char&);
    //unsigned int saisieVerifChoixDiaporama();



};

#endif // PRESENTATION_H
