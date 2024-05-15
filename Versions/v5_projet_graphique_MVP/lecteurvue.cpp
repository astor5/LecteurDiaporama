#include "lecteurvue.h"
#include "presentation.h"
#include "ui_lecteurvue.h"
#include "modele.h"
#include "vitessedefilement.h"
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
    QObject::connect(ui->bLancerDiaporama, SIGNAL(clicked()), this, SLOT(sl_lancerDiaporama()));
    QObject::connect(ui->bArreterDiaporama, SIGNAL(clicked()), this, SLOT(sl_arreterDiaporama()));

    //conexion de boutons de la barre de menu
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(sl_quitter()));
    QObject::connect(ui->actionCharger_diaporama, SIGNAL(triggered()), this, SLOT(sl_chargerDiaporama()));
    //QObject::connect(ui->actionCharger_diaporama, SIGNAL(triggered()), this, SLOT(sl_ouvrirVitesseDefilement()));
    QObject::connect(ui->actionEnlever_le_diaporama, SIGNAL(triggered()), this, SLOT(sl_enleverDiporama()));
    //QObject::connect(ui->actionVitesse_de_defilement, SIGNAL(triggered()), this, SLOT(sl_vitesseDefilement()));
    QObject::connect(ui->actionVitesse_de_defilement, SIGNAL(triggered()), this, SLOT(sl_ouvrirVitesseDefilement()));
    QObject::connect(ui->actionA_propos, SIGNAL(triggered()), this, SLOT(sl_aPropos()));

    //navigation entre les bouton avec tab
    QWidget::setTabOrder(ui->bSuivant, ui->bPrecedent);
    QWidget::setTabOrder(ui->bPrecedent, ui->bSuivant);

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
    majPresentation(getPresentation()->getDiapoActuel(), getPresentation()->getModele()->getEtat());
}

void lecteurVue::majPresentation(Diaporama * diapo, Modele::UnEtat etat)
{
    ui->lTitreDiaporama->setText(QString::fromStdString(diapo->getTitre()));
    ui->lTitreImage->setText(QString::fromStdString(diapo->getImageCourante().getTitre())); //getImageCourante est une fonction qui renvoie une imageDansDiaporama
    ui->lCatrgorieImage->setText(QString::number(diapo->getImageCourante().getRang()));
    ui->lRangImage->setText(QString::fromStdString(diapo->getImageCourante().getImage().getCategorie()));
    ui->imageDiapo->setPixmap(QPixmap(QString::fromStdString(diapo->getImageCourante().getImage().getChemin())));

    switch (etat) {
    case Modele::manuel:
        ui->bArreterDiaporama->setDisabled(true);
        break;
    case Modele::automatique:
        ui->bArreterDiaporama->setDisabled(false);
        break;
    default:
        ui->bArreterDiaporama->setDisabled(true);
        break;
    }
}

void lecteurVue::sl_suivant()
{

    getPresentation()->demanderAvancer();
}

void lecteurVue::sl_precedent()
{

    getPresentation()->demanderReculer();
}

void lecteurVue::sl_quitter()
{
    QApplication::quit();
}

void lecteurVue::sl_ouvrirVitesseDefilement()
{
    vitessedefilement maDlg(this);

    this->hide();
    maDlg.setVitesseDefilementDialog(maDlg.getVitesseDefilementDialog());
    maDlg.exec();
    maDlg.hide();
    getPresentation()->getDiapoActuel()->setVitesseDefilement(maDlg.getVitesseDefilementDialog());
    cout << maDlg.getVitesseDefilementDialog() << endl;
    this->show();
}

void lecteurVue::sl_chargerDiaporama()
{
    qDebug() << "Chargement du diaporama";
    getPresentation()->demanderCharger();
}

void lecteurVue::sl_enleverDiporama()
{
    qDebug() << "Enlever le diaporama";
}

void lecteurVue::sl_vitesseDefilement()
{
    qDebug() << "Je change la vitesse de défilement";
}

void lecteurVue::sl_lancerDiaporama()
{
    getPresentation()->demanderLancementDiapo();
    getPresentation()->demandeModeAutomatique();
}

void lecteurVue::sl_arreterDiaporama()
{
    getPresentation()->demanderArretDiapo();
}

void lecteurVue::sl_aPropos()
{
    QString titre = "A propos";
    QString message = "Version : 3\n\n"
                      "Date de création : 03/05/2024\n\n"
                      "Auteurs : ARANDIA Iban, CHIPY Thibault, LATXAGUE Thibault";

    QMessageBox::information(nullptr, titre, message);
}
