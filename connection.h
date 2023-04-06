#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class Connection
{
   QSqlDatabase db;
public:
    Connection();
    bool createconnect();
};

#endif // CONNECTION_H
