#include "connection.h"

Connection::Connection(){}

Connection::~Connection()
{
closeConnection();
}



bool Connection::createConnection()
{
    db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projetQt");
    db.setUserName("oumaima");
    db.setPassword("oumaima");

    bool ok=false;
    if (db.open()) ok= true;

    return ok;
}

void Connection::closeConnection()
{
    db.close();
}

