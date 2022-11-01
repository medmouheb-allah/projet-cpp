#include "fournisseur.h"
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include"interface.h"
#include<QObject>
Fournisseur::Fournisseur()
{
    ID_FOURNISSEUR="";
    NOM="";
    PRENOM="";
    EMAIL="";
    NUMERO="";
}
Fournisseur::Fournisseur(QString ID_FOURNISSEUR,QString NOM,QString PRENOM,QString EMAIL ,QString NUMERO)
{
    this ->ID_FOURNISSEUR =ID_FOURNISSEUR ;
    this -> NOM=NOM;
    this -> PRENOM = PRENOM;
    this -> EMAIL = EMAIL;
    this -> NUMERO = NUMERO;
}
QString  Fournisseur::getid()
{
    return ID_FOURNISSEUR;
}
QString Fournisseur::getnum()
{
    return NUMERO;
}
QString Fournisseur::getnom()
{
    return NOM;


}
QString Fournisseur::getprenom()
{
    return PRENOM;
}
QString Fournisseur::getemail()
{
    return EMAIL;
}
void Fournisseur::setid(QString ID_FOURNISSEUR)
{

    this ->ID_FOURNISSEUR=ID_FOURNISSEUR;
}
void Fournisseur::setnum(QString NUMERO)
{
    this -> NUMERO= NUMERO;

}
void Fournisseur::setnom(QString NOM){
    this -> NOM = NOM ;

}
void Fournisseur::setprenom(QString PRENOM)
{
    this ->PRENOM = PRENOM;

}
void Fournisseur::setemail(QString EMAIL)
{
    this -> EMAIL = EMAIL;
}
bool Fournisseur::ajouter()
{


    QSqlQuery query;


          query.prepare("INSERT INTO FOURNISSEUR (ID_FOUNISSEUR, NOM, PRENOM,EMAIL,NUMERO) "
                        "VALUES (:ID_FOUNISSEUR, :NOM, :PRENOM ,:EMAIL, :NUMERO)");
          query.bindValue(":ID_FOUNISSEUR", ID_FOURNISSEUR);
          query.bindValue(":NOM", NOM);
          query.bindValue(":PRENOM", PRENOM);
          query.bindValue(":EMAIL", EMAIL);
          query.bindValue(":NUMERO", NUMERO);



        return  query.exec();



}




QSqlQueryModel* Fournisseur::afficher()

{
QSqlQueryModel*model=new QSqlQueryModel();

model->setQuery("SELECT* FROM FOURNISSEUR");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMERO"));



return model;

}
bool Fournisseur::modifier_fournisseur(QString ID_FOURNISSEUR)

{
    QSqlQuery query;

   query.prepare("update FOURNISSEUR set NOM=:NOM,PRENOM=:PRENOM,NUMERO=:NUMERO,EMAIL=:EMAIL where ID_FOUNISSEUR=:ID_FOUNISSEUR");
   query.bindValue(":ID_FOUNISSEUR",ID_FOURNISSEUR);
   query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM",PRENOM);
    query.bindValue(":EMAIL",EMAIL);
    query.bindValue(":NUMERO",NUMERO);


    return    query.exec();

}

bool Fournisseur::supprimer(QString  ID_FOURNISSEUR)

{



    QSqlQuery query;


          query.prepare("Delete from fournisseur where ID_FOUNISSEUR =:ID");
          query.bindValue(":ID", ID_FOURNISSEUR );
          return query.exec();
}
