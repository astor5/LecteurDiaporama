#include "vitessedefilement.h"
#include "ui_vitessedefilement.h"

vitessedefilement::vitessedefilement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vitessedefilement)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->buttonBox, SIGNAL(clicked()), this, SLOT(reject()));

}

vitessedefilement::~vitessedefilement()
{
    delete ui;
}
