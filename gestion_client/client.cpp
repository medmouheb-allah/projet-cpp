#include "client.h"
#include<QSqlQuery>
#include<QtDebug>
#include <iostream>
#include<QObject>
using namespace std;
//ici c'st la gestion de client
Client::Client()
{
    id_client=0;
    nom=" ";
    prenom="";
    adr_email="";
    phone="";
    genre="";
    age="";


}
Client::Client(int x ,QString y,QString z,QString t,QString w,QString a,QString aa)
{

    id_client=x;
    nom=y;
    prenom=z;
    adr_email=t;
    phone=w;
    genre=a;
    age=aa;


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
QString Client::getgenre()
{
    return genre;
}
QString Client::getage()
{
    return age;
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
 void Client::setgenre(QString a)
 {
     genre=a;
 }
 void Client::setage(QString aa)
 {
     age=aa;
 }
bool Client::ajouter()
{

   QSqlQuery query;
   QString res=QString::number(id_client);
        query.prepare("INSERT INTO CLIENT_ (ID_CLIENT, NOM, PRENOM, ADR_EMAIL, PHONE,genre,age)" "values (:id, :forname, :surname, :toname, :monname,:dest, :age)");
        query.bindValue(":id", res);
        query.bindValue(":forname", nom);
        query.bindValue(":surname", prenom);
        query.bindValue(":toname", adr_email);
        query.bindValue(":monname", phone);
        query.bindValue(":dest", genre);
        query.bindValue(":age", age);
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
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("genre"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("age"));

     return model;

 }
 QSqlQueryModel*Client:: aff()
 {
     QSqlQueryModel* model=new QSqlQueryModel();


     model->setQuery("SELECT id_client,nom,prenom,phone,TYPE,DATE_E FROM CLIENT_ INNER JOIN EVENT ON CLIENT_.id_client=EVENT.id");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Phone"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Type_evenemt"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));


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
 bool Client::modifier(int id_client,QString nom,QString prenom,QString adr_email,QString phone,QString genre,QString age)
 {
      QSqlQuery query;
     query.prepare("update client_ set id_client=:id_client,nom=:nom,prenom=:prenom,adr_email=:adr_email,phone=:phone,genre=:genre ,age=:age where id_client=:id_client");
     query.bindValue(":id_client",id_client);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":adr_email",adr_email);
     query.bindValue(":phone",phone);
      query.bindValue(":genre",genre);
      query.bindValue(":age",age);
     return query.exec();

 }
 QSqlQueryModel* Client:: tester()
 {
     QSqlQueryModel* model=new QSqlQueryModel();// declaration d'un modele
    model->setQuery("SELECT id_client FROM CLIENT_");// ce modele contient les cin des client seulement
    //model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    return model;
 }
 QSqlQueryModel* Client:: triid()
  {

      QSqlQueryModel* model=new QSqlQueryModel();// declaration d'un modele
     model->setQuery("SELECT * FROM CLIENT_ ORDER BY ID_CLIENT  DESC");
     return model;
  }
  QSqlQueryModel* Client:: trinom()
  {

      QSqlQueryModel* model=new QSqlQueryModel();// declaration d'un modele
     model->setQuery("SELECT * FROM CLIENT_ ORDER BY PRENOM ");
     return model;
  }
  QSqlQueryModel* Client:: triphone()
  {

      QSqlQueryModel* model=new QSqlQueryModel();// declaration d'un modele
     model->setQuery("SELECT * FROM CLIENT_ ORDER BY PHONE  DESC");
     return model;
  }
  QSqlQueryModel * Client::rechercher(QString rech)
  {
      QSqlQueryModel * model= new QSqlQueryModel();
      QString recher=("select * from CLIENT_ where nom like '%"+rech+"%' or prenom like '%"+rech+"%' or id_client like '%"+rech+"%'");
      model->setQuery(recher);
      return model;
  }
  QSqlQueryModel * Client::rechercher_client(const QString &b)
  {
     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("SELECT * FROM CLIENT_ WHERE (  ID_CLIENT || NOM || PRENOM || ADR_EMAIL || PHONE || GENRE|| AGE) LIKE '%"+b+"%'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("e_mail"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("genre"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("age"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("event"));
     return model;
  }
  QSqlQueryModel * Client::rech(const QString &b)
  {
     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("SELECT nom,prenom,phone,TYPE,DATE_E,id_client FROM CLIENT_ INNER JOIN EVENT ON CLIENT_.id_client=EVENT.id WHERE  ID_CLIENT  LIKE '%"+b+"%'");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Phone"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type_evenemt"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID"));

     return model;
  }
  void Client::incrParking(){
      QSqlQuery q;
      q.prepare("update parking set nbrPlaces=nbrPlaces+1");
      q.exec();
  }
  void Client::decrParking(){
      QSqlQuery q;
      q.prepare("update parking set nbrPlaces=nbrPlaces-1");
      q.exec();
  }
  QString Client::count(){
      QSqlQuery q("select * from parking");
      while(q.next()){
          return q.value(0).toString();
      }
  }





