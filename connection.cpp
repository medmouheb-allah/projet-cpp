#include "connection.h"

connection::connection()
{

}
bool connection::createconnection()
{
    db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("test");//inserer le nom de la source de données ODBC
    db.setUserName("sarra");//inserer nom de l'utilisateur
    db.setPassword("sarra");//inserer le mot de passe de cet utilisateur
    if (db.open()) test=true;
    return test;

}
void connection::closeconnection()
{
    db.close();
}
