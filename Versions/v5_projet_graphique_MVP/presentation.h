#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include "modele.h"
#include "QTimer"
#include "choixdiaporama.h"


class lecteurVue;
class Presentation : public QObject
{ Q_OBJECT
public:
private:
    Modele * _leModele;
    lecteurVue * _laVue;
    QTimer * _timer;

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
    void demandeModeAutomatique();
    void onTimeout();
    void demandeChangementMode();
    void demandeChangementDiaporama(choixdiaporama&);
    void demandeVider();
    int demandeNumeroDiaporama();
    int demandeVitesseDefilement();
    void demandeSetVitesseDefilement(int);
    int demandeNombreDiapos();
    std::string demandeTitreDiaporama(int);

    //void declencherAction(char);
    //void saisieVerifChoixActionSurImageCourante(char&);
    //unsigned int saisieVerifChoixDiaporama();



};

#endif // PRESENTATION_H
