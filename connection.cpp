#include "connection.h"

Connection::Connection(){}

Connection::~Connection()
{
closeConnection();
}



bool Connection::createConnection()
{
    db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Achraf");
    db.setUserName("achraf");
    db.setPassword("esprit901");

    bool ok=false;
    if (db.open()) ok= true;

    return ok;
}

void Connection::closeConnection()
{
    db.close();
}

