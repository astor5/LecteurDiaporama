#include "lecteurvue.h"
#include "ui_lecteurvue.h"

lecteurVue::lecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::lecteurVue)
{
    ui->setupUi(this);
}

lecteurVue::~lecteurVue()
{
    delete ui;
}
