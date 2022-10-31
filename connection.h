#ifndef CONNECTION_H
#define CONNECTION_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>


class connection
{
    QSqlDatabase db ;
public:
    connection();
    bool createconnection();
    void closeconnection() ;

};


#endif // CONNECTION_H
