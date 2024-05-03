#include "lecteurvue.h"

#include <QApplication>
#include "presentation.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lecteurVue w;

    Modele *m = new Modele();
    Presentation * p = new Presentation();
    lecteurVue * v = new lecteurVue();

    p->setModele(m);
    p->setVue(v);

    v->setPresentation(p)


    w.show();
    return a.exec();


}
