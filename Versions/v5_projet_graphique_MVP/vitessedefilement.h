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

    unsigned int getVitesseDefilementDialog();
    void setVitesseDefilementDialog(unsigned int = 2);

private:
    Ui::vitessedefilement *ui;
    unsigned int _vitesse;
    bool _cancelTriggered;

private slots:
    void sl_boutonOk();
    void sl_boutonCancel();
};

#endif // VITESSEDEFILEMENT_H
