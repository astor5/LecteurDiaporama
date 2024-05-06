#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include "modele.h"
<<<<<<< HEAD

class lecteurVue;
=======
#include "lecteurvue.h"

>>>>>>> 422ce7f7bf4d2a9bff56053c7c809889e60194aa
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

<<<<<<< HEAD
    ImageDansDiaporama getImageActuelle();

=======
private slots:
>>>>>>> 422ce7f7bf4d2a9bff56053c7c809889e60194aa
    void demanderAvancer();
    void demanderReculer();

    //void declencherAction(char);
    //void saisieVerifChoixActionSurImageCourante(char&);
    //unsigned int saisieVerifChoixDiaporama();



};

#endif // PRESENTATION_H
