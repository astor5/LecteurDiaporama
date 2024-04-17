#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>

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

private:
    Ui::lecteurVue *ui;
};
#endif // LECTEURVUE_H
