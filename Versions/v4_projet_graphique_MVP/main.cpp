#include "presentation.h"
#include "lecteurvue.h"
#include "modele.h"
#include "qdebug.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Modele *m = new Modele();
    Presentation * p = new Presentation();
    lecteurVue w;


    p->setModele(m);
    p->setVue(&w);

    w.setPresentation(p);



    w.show();
    return a.exec();


}
