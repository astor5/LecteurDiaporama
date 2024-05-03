#include "lecteurvue.h"

#include <QApplication>
#include "presentation.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lecteurVue w;

    Modele *m = new Modele();
    Presentation * p = new Presentation();


    p->setModele(m);
    p->setVue(&w);

    w.setPresentation(p);


    w.show();
    return a.exec();


}
