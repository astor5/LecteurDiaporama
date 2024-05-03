#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <QDebug>
#include <QShortcut>
#include <QWidget>


class Presentation;
QT_BEGIN_NAMESPACE
namespace Ui {
class lecteurVue;
}
QT_END_NAMESPACE

class lecteurVue : public QMainWindow
{
    Q_OBJECT

private:
    Ui::lecteurVue *ui;

    Presentation * _laPresentation;

public:
    lecteurVue(QWidget *parent = nullptr);
    ~lecteurVue();

    Presentation * getPresentation() const;
    void setPresentation(Presentation *);

public slots:
    void sl_suivant();
    void sl_precedent();
    void sl_pause();
    void sl_mode();
    void sl_boucle();
    void sl_quitter();
    void sl_chargerDiaporama();
    void sl_enleverDiporama();
    void sl_vitesseDefilement();
    void sl_aPropos();
    void miseAJourVue();

public:

};
#endif // LECTEURVUE_H
