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

private:
    Ui::choixdiaporama *ui;
};

#endif // CHOIXDIAPORAMA_H
