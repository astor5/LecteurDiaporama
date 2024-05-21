#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include "modele.h"
#include "QTimer"


class lecteurVue;
class Presentation : public QObject
{ Q_OBJECT
public:
private:
    Modele * _leModele;
    lecteurVue * _laVue;
    QTimer * _timer;
    bool _extremiteDiapoDroit;
    bool _extremiteDiapoGauche;

public:
    Presentation();
    Modele* getModele() const;
    lecteurVue* getVue() const;
    void setModele(Modele *);
    void setVue(lecteurVue *);
    void setTimerActif(bool);

    ImageDansDiaporama getImageActuelle();
    Diaporama * getDiapoActuel();
    QTimer* getTimer();

    void setExtremitesDiapoDroit(bool);
    bool getExtremitesDiapoDroit();
    void setExtremitesDiapoGauche(bool);
    bool getExtremitesDiapoGauche();

public slots:
    void demanderAvancer();
    void demanderReculer();
    void demanderCharger();
    void demanderLancementDiapo();
    void demanderArretDiapo();
    void demandeModeAutomatique();
    void onTimeout();
    void demandeChangementMode();

    //void declencherAction(char);
    //void saisieVerifChoixActionSurImageCourante(char&);
    //unsigned int saisieVerifChoixDiaporama();



};

#endif // PRESENTATION_H
