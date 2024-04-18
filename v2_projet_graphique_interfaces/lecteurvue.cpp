#include "lecteurvue.h"
#include "ui_lecteurvue.h"

lecteurVue::lecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lecteurVue)
{
    ui->setupUi(this);

    QObject::connect(ui->bSuivant, SIGNAL(clicked()), this, SLOT(sl_suivant()));
    QObject::connect(ui->bPrecedent, SIGNAL(clicked()), this, SLOT(sl_precedent()));
    QObject::connect(ui->bPause, SIGNAL(clicked()), this, SLOT(sl_pause()));
    QObject::connect(ui->rbModeDefilement, SIGNAL(clicked()), this, SLOT(sl_mode()));
    QObject::connect(ui->rbModeBoucle, SIGNAL(clicked()), this, SLOT(sl_boucle()));
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
