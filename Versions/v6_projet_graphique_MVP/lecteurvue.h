#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <QDebug>
#include <QShortcut>
#include <QWidget>

//#include "presentation.h"
#include "ImageDansDiaporama.h"
#include "modele.h"
#include "vitessedefilement.h"
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui {class lecteurVue;
}
#include "diaporama.h"

QT_END_NAMESPACE
class Presentation;
class lecteurVue : public QMainWindow
{
    Q_OBJECT

private:
    Ui::lecteurVue *ui;

    Presentation * _laPresentation;
    database * db;

public:
    lecteurVue(QWidget *parent = nullptr);
    ~lecteurVue();

    Presentation * getPresentation() const;
    void setPresentation(Presentation *);

    void majPresentation(Diaporama *, Modele::UnEtat, Modele::EtatLecteur);

public slots:
    void sl_suivant();
    void sl_precedent();
    void sl_quitter();
    void sl_chargerDiaporama();
    void sl_enleverDiporama();
    void sl_lancerDiaporama();
    void sl_arreterDiaporama();
    void sl_aPropos();
    void sl_ouvrirChoixDiaporama();
    void sl_ouvrirVitesseDefilement();

public:

};
#endif // LECTEURVUE_H
