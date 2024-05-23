#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include "diaporama.h"


#define DATABASE_NAME "s201"
#define CONNECT_TYPE "QODBC"

class database
{
public:
    database();
    bool openDataBase();
    void closeDataBase();
    void chargerDiapos(vector<Diaporama *>&);
    void chargerImages(int, vector<Image>);

private:
    QSqlDatabase mydb;
};

#endif // DATABASE_H
