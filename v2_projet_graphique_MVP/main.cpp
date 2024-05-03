#include "lecteurvue.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lecteurVue w;
    w.show();
    return a.exec();
}
