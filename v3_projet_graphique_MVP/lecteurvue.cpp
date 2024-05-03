#include "lecteurvue.h"
#include "ui_lecteurvue.h"
#include <QDialog>
#include <QMessageBox>

lecteurVue::lecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lecteurVue)
{
    ui->setupUi(this);

    //connexion des boutons
    QObject::connect(ui->bSuivant, SIGNAL(clicked()), this, SLOT(sl_suivant()));
    QObject::connect(ui->bPrecedent, SIGNAL(clicked()), this, SLOT(sl_precedent()));
    QObject::connect(ui->bPause, SIGNAL(clicked()), this, SLOT(sl_pause()));

    //connextion des radio-boutons
    QObject::connect(ui->rbModeDefilement, SIGNAL(clicked()), this, SLOT(sl_mode()));
    QObject::connect(ui->rbModeBoucle, SIGNAL(clicked()), this, SLOT(sl_boucle()));

    //conexion de boutons de la barre de menu
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(sl_quitter()));
    QObject::connect(ui->actionCharger_diaporama, SIGNAL(triggered()), this, SLOT(sl_chargerDiaporama()));
    QObject::connect(ui->actionEnlever_le_diaporama, SIGNAL(triggered()), this, SLOT(sl_enleverDiporama()));
    QObject::connect(ui->actionVitesse_de_defilement, SIGNAL(triggered()), this, SLOT(sl_vitesseDefilement()));
    QObject::connect(ui->actionA_propos, SIGNAL(triggered()), this, SLOT(sl_aPropos()));

    //navigation entre les bouton avec tab
   // QWidget::setTabOrder({ui->bSuivant, ui->bPrecedent, ui->bPause, ui->bSuivant});
}

lecteurVue::~lecteurVue()
{
    delete ui;
}

void lecteurVue::sl_suivant()
{
    qDebug() << "image suivante";
}

void lecteurVue::sl_precedent()
{
    qDebug() << "Image précédente";
}

void lecteurVue::sl_pause()
{
    qDebug() << "defilement mis en pause";
}

void lecteurVue::sl_mode()
{
    qDebug() << "mode de défilement mis à : " << ui->rbModeDefilement->isChecked();
}

void lecteurVue::sl_boucle()
{
    qDebug() << "mode de boucle mis à : " << ui->rbModeBoucle->isChecked();
}

void lecteurVue::sl_quitter()
{
    qDebug() << "Quitter";
    QApplication::quit();

}

void lecteurVue::sl_chargerDiaporama()
{
    qDebug() << "charger un diaporama";
}

void lecteurVue::sl_enleverDiporama()
{
    qDebug() << "Enlever le diaporama";
}

void lecteurVue::sl_vitesseDefilement()
{
    qDebug() << "changement de vitesse de défilement";
}

void lecteurVue::sl_aPropos()
{
    QMessageBox::information(   "  Version         ");
    QMessageBox::

    qDebug() << "A propos";
}
