#include "connection.h"

connection::connection()
{

}


bool connection::createconnection()
{
    bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projetQt");
db.setUserName("oumaima");
db.setPassword("oumaima");

if (db.open())
test=true;


    return  test;
}


void connection ::closeconnection()
{
      db.close() ;
}

