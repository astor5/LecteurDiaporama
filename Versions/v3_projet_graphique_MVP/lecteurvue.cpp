#include "lecteurvue.h"
#include "presentation.h"
#include "ui_lecteurvue.h"
#include <QMessageBox>
#include <QString>

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
    QWidget::setTabOrder(ui->bSuivant, ui->bPrecedent);
    QWidget::setTabOrder(ui->bPrecedent, ui->bPause);
    QWidget::setTabOrder(ui->bPause, ui->bSuivant);
}

lecteurVue::~lecteurVue()
{
    delete ui;
}

Presentation *lecteurVue::getPresentation() const
{
    return _laPresentation;
}

void lecteurVue::setPresentation(Presentation * p)
{
    _laPresentation = p;
}

void lecteurVue::majPresentation(ImageDansDiaporama * img)
{
    qDebug() << "mise a jour de l'interface ";
    ui->lTitreImage->setText(QString::fromStdString(img->getImage().getTitre()));
}

void lecteurVue::sl_suivant()
{
    qDebug() << "image suivante";
    getPresentation()->demanderAvancer();
    majPresentation(getPresentation()->getImageActuelle());
}

void lecteurVue::sl_precedent()
{
    qDebug() << "Image précédente";
    getPresentation()->demanderReculer();
    majPresentation(getPresentation()->getImageActuelle());
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
    QString titre = "A propos";
    QString message = "Version : 3\n\n"
                      "Date de création : 03/05/2024\n\n"
                      "Auteurs : ARANDIA Iban, CHIPY Thibault, LATXAGUE Thibault";

    QMessageBox::information(nullptr, titre, message);
}
