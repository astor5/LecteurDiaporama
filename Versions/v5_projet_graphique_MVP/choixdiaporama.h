#ifndef CHOIXDIAPORAMA_H
#define CHOIXDIAPORAMA_H

#include <QDialog>

namespace Ui {
class choixdiaporama;
}

class choixdiaporama : public QDialog
{
    Q_OBJECT

public:
    explicit choixdiaporama(QWidget *parent = nullptr);
    ~choixdiaporama();

    void ajouterItem(QString);
    int recupIndex();

private:
    Ui::choixdiaporama *ui;

private slots:
    void sl_choixTitre();
};

#endif // CHOIXDIAPORAMA_H
