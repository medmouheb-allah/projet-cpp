#include "connexion.h"
//test git

Connexion::Connexion()
{

}

bool Connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projetQt");
db.setUserName("oumaima");
db.setPassword("oumaima");
if (db.open())
test=true;

    return  test;
}
