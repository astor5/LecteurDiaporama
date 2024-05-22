#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>


#define DATABASE_NAME "s201"
#define CONNECT_TYPE "QODBC"

class database
{
public:
    database();
    bool openDataBase();
    void closeDataBase();

private:
    QSqlDatabase mydb;
};

#endif // DATABASE_H
