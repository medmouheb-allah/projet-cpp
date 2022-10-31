#include "client.h"
#include<QSqlQuery>
#include<QtDebug>
#include <iostream>
#include<QObject>
#include <QString>
using namespace std;
//ici c'st la gestion de client
Client::Client()
{
    id_client=0;
    nom=" ";
    prenom="";
    adr_email="";
    phone="";


}
Client::Client(int x ,QString y,QString z,QString t,QString w)
{

    id_client=x;
    nom=y;
    prenom=z;
    adr_email=t;
    phone=w;


}
int Client::getid()
{
    return id_client;

}
QString Client::getnom()
{
    return nom;

}
QString Client::getprenom()
{
    return prenom;

}
QString Client::getemail()
{
    return adr_email;

}
QString Client::gettel()
{
    return phone;

}
void Client::setid(int id)
{
    this->id_client=id;

}
void Client::setnom(QString nom)
{
    this->nom=nom;
}
void Client::setprenom(QString prenom)
{
    this->prenom=prenom;
}
void Client::settel(QString tel)
{
    this->phone=tel;
}
void Client::setemail(QString e_mail)
{
    this->adr_email=e_mail;
}
bool Client::ajouter()
{

   QSqlQuery query;
   QString res=QString::number(id_client);
        query.prepare("INSERT INTO CLIENT_ (ID_CLIENT, NOM, PRENOM, ADR_EMAIL, PHONE)" "values (:id, :forname, :surname, :toname, :monname)");
        query.bindValue(":id", res);
        query.bindValue(":forname", nom);
        query.bindValue(":surname", prenom);
        query.bindValue(":toname", adr_email);
        query.bindValue(":monname", phone);

        return query.exec();




}
 QSqlQueryModel*Client:: afficher()
 {
     QSqlQueryModel* model=new QSqlQueryModel();


     model->setQuery("SELECT* FROM CLIENT_");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("e_mail"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
     return model;

 }



 bool Client::supprimer(int id)
 {
     QSqlQuery query;
     QString res=QString::number(id);
     query.prepare("Delete From CLIENT_ where Id_CLIENT = :id");
     query.bindValue(0, res);
     return query.exec();


 }
 bool Client::modifier(int id_client,QString nom,QString prenom,QString adr_email,QString phone)
 {
      QSqlQuery query;
     query.prepare("update client_ set id_client=:id_client,nom=:nom,prenom=:prenom,adr_email=:adr_email,phone=:phone where id_client=:id_client");
     query.bindValue(":id_client",id_client);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":adr_email",adr_email);
     query.bindValue(":phone",phone);
     return query.exec();

 }
 QSqlQueryModel* Client:: tester()
 {
     QSqlQueryModel* model=new QSqlQueryModel();// declaration d'un modele
    model->setQuery("SELECT id_client FROM CLIENT_");// ce modele contient les cin des client seulement
    //model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    return model;
 }




