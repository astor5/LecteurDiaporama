#ifndef VITESSEDEFILEMENT_H
#define VITESSEDEFILEMENT_H

#include <QDialog>

namespace Ui {
class vitessedefilement;
}

class vitessedefilement : public QDialog
{
    Q_OBJECT

public:
    explicit vitessedefilement(QWidget *parent = nullptr);
    ~vitessedefilement();

private:
    Ui::vitessedefilement *ui;
};

#endif // VITESSEDEFILEMENT_H
