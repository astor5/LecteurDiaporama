#include "choixdiaporama.h"
#include "ui_choixdiaporama.h"

choixdiaporama::choixdiaporama(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choixdiaporama)
{
    ui->setupUi(this);

    ui->comboBox->addItem("cc");
    ui->comboBox->addItem("bonjoir");
    ui->comboBox->addItem("he he he");
}

choixdiaporama::~choixdiaporama()
{
    delete ui;
}
