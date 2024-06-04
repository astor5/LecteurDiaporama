#include "lecteurvue.h"
#include "presentation.h"
#include "ui_lecteurvue.h"
#include "modele.h"
#include "vitessedefilement.h"
#include "choixdiaporama.h"
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
    QObject::connect(ui->actionCharger_diaporama, SIGNAL(triggered()), this, SLOT(sl_ouvrirChoixDiaporama()));
    QObject::connect(ui->actionEnlever_le_diaporama, SIGNAL(triggered()), this, SLOT(sl_enleverDiporama()));
    QObject::connect(ui->actionVitesse_de_defilement, SIGNAL(triggered()), this, SLOT(sl_ouvrirVitesseDefilement()));
    QObject::connect(ui->actionA_propos, SIGNAL(triggered()), this, SLOT(sl_aPropos()));

    //navigation entre les bouton avec tab
    QWidget::setTabOrder(ui->bSuivant, ui->bPrecedent);
    QWidget::setTabOrder(ui->bPrecedent, ui->bSuivant);

    setWindowTitle("Lecteur de Diaporama"); //Ajout du titre à notre application
    setWindowIcon(QIcon(":/images/VLC.png")); //Ajout de l'icone de notre application
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
    majPresentation(getPresentation()->getDiapoActuel(), getPresentation()->getModele()->getEtat(), getPresentation()->getModele()->getEtatLecteur());
}

void lecteurVue::majPresentation(Diaporama * diapo, Modele::UnEtat etat, Modele::EtatLecteur etatLec)
{
    if (etatLec == Modele::initial)
    {
        ui->bPrecedent->setDisabled(true);
        ui->bSuivant->setDisabled(true);
        ui->bArreterDiaporama->setDisabled(true);
        ui->bLancerDiaporama->setDisabled(true);

        ui->lTitreDiaporama->setText(QString::fromStdString("Titre du diaporama"));
        ui->lTitreImage->setText(QString::fromStdString("Titre de l'image"));
        ui->lCatrgorieImage->setText(QString::fromStdString("Catégorie de l'image"));
        ui->lRangImage->setText(QString::fromStdString("Rang de l'image"));
        ui->imageDiapo->setPixmap(QPixmap(QString::fromStdString(":/images/Disney_tapis.gif")));
    }
    else
    {
        ui->lTitreDiaporama->setText(QString::fromStdString(diapo->getTitre()));
        ui->lTitreImage->setText(QString::fromStdString(diapo->getImageCourante().getTitre())); //getImageCourante est une fonction qui renvoie une imageDansDiaporama
        ui->lCatrgorieImage->setText(QString::number(diapo->getImageCourante().getRang()));
        ui->lRangImage->setText(QString::fromStdString(diapo->getImageCourante().getImage().getCategorie()));
        ui->imageDiapo->setPixmap(QPixmap(QString::fromStdString(diapo->getImageCourante().getImage().getChemin())));

        ui->bPrecedent->setDisabled(false);
        ui->bSuivant->setDisabled(false);
        ui->bLancerDiaporama->setDisabled(false);

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
    maDlg.setVitesseDefilementDialog(getPresentation()->demandeVitesseDefilement());
    int reponse = maDlg.exec();

    if(reponse==1)
    {
        getPresentation()->demandeSetVitesseDefilement(maDlg.getVitesseDefilementDialog());
    }
    else if (reponse == 0)
    {
        maDlg.setVitesseDefilementDialog(getPresentation()->demandeVitesseDefilement());
    }

    maDlg.hide();
    this->show();
}

void lecteurVue::sl_ouvrirChoixDiaporama()
{
    choixdiaporama maDlg(this);

    this->hide();

    for (unsigned int i = 0; i < getPresentation()->getModele()->getTabDiaporamas().size(); i ++)
    {
        maDlg.ajouterItem(QString::fromStdString(getPresentation()->demandeTitreDiaporama(i)));
    }

    int reponse = maDlg.exec();

    if (reponse == 1)
    {
        getPresentation()->demandeChangementDiaporama(maDlg);
    }

    maDlg.hide();
    this->show();
}

void lecteurVue::sl_chargerDiaporama()
{
    getPresentation()->demanderCharger();
}

void lecteurVue::sl_enleverDiporama()
{
    getPresentation()->demandeVider();
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
    QString message = "Version : 8 MVP\n\n"
                      "Date de création : 01/06/2024\n\n"
                      "Auteurs : ARANDIA Iban, CHIPY Thibault, LATXAGUE Thibault";

    QMessageBox aPropos;
    aPropos.setIconPixmap(QPixmap(":/images/info_icon.png"));
    aPropos.information(nullptr, titre, message);

}
