#include "choixdiaporama.h"
#include "ui_choixdiaporama.h"

choixdiaporama::choixdiaporama(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choixdiaporama)
{
    ui->setupUi(this);

    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(sl_choixTitre()));
}

choixdiaporama::~choixdiaporama()
{
    delete ui;
}

void choixdiaporama::ajouterItem(QString titre)
{
    ui->comboBox->addItem(titre);
}

int choixdiaporama::recupIndex()
{
    return ui->comboBox->currentIndex();
}

void choixdiaporama::sl_choixTitre()
{
    qDebug() << recupIndex();
}
