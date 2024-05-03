#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include "modele.h"
#include "lecteurvue.h"

class Presentation : public QObject
{ Q_OBJECT
public:
    explicit Presentation(QObject *parent = nullptr);
private:
    Modele * _leModele;
    lecteurVue * _laVue;
public:
    Presentation();

    Modele* getModele() const;
    lecteurVue* getVue() const;
    void setModele(Modele *);
    void setVue(lecteurVue *);



};

#endif // PRESENTATION_H
