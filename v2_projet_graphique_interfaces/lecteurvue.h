#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class lecteurVue;
}
QT_END_NAMESPACE

class lecteurVue : public QMainWindow
{
    Q_OBJECT

public:
    lecteurVue(QWidget *parent = nullptr);
    ~lecteurVue();

public slots:
    void sl_suivant();
    void sl_precedent();
    void sl_pause();
    void sl_mode();
    void sl_boucle();

private:
    Ui::lecteurVue *ui;
};
#endif // LECTEURVUE_H
