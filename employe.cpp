#include "employe.h"
#include<iostream>
#include <QDebug>

employe::employe(int d,QString a,QString b,QString c,int e,QString f)
{
  nom=b ;
  prenom=c ;
  email=a ;
  id=d ;
  num=e ;
  genre=f ;
}


bool employe :: ajouter()
{
    QSqlQuery query ;
    QString res= QString::number(id) ;
    QString res2= QString::number(num) ;


    query.prepare("insert into EMPLOYE (ID_EMP,MAIL,NOM_EMP,PRENOM_EMP,TEL,GENRE)""values(:id,:email,:nom,:prenom,:num,:genre)") ;

    query.bindValue(":nom",nom) ;
    query.bindValue(":prenom",prenom) ;
    query.bindValue(":email",email) ;
    query.bindValue(":genre",genre) ;
    query.bindValue(":id",res) ;
    query.bindValue(":num",res2) ;


    return  query.exec() ;
}

bool  employe::supprimer(int id)
{

    QSqlQuery   query;
    QString res=QString::number(id) ;
    query.prepare("delete from EMPLOYE where ID_EMP=:id") ;
    query.bindValue(":id",res) ;

    return  query.exec() ;
}



QSqlQueryModel* employe:: tester()
{
    QSqlQueryModel* model=new QSqlQueryModel();// declaration d'un modele
   model->setQuery("SELECT ID_EMP FROM EMPLOYE");// ce modele contient les cin des employes
   //model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
   return model;
}




QSqlQueryModel * employe:: afficher()
{
  QSqlQueryModel * model=new QSqlQueryModel() ;

  model->setQuery("select * from EMPLOYE") ;
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("id")) ;
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("email")) ;
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom")) ;
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("prenom")) ;
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("num")) ;
  model->setHeaderData(5,Qt::Horizontal,QObject::tr("genre")) ;
 // qDebug() << res2 << '\n';
  return  model ;


}




bool employe::modifier(int id,QString email,QString nom,QString prenom,int num, QString genre)
 {



     QSqlQuery query ;

     QString res = QString::number(id);
     QString res2 = QString::number(num);




     query.prepare("UPDATE EMPLOYE set ID_EMP=:id,MAIL=:email,NOM_EMP=:nom,PRENOM_EMP=:prenom,TEL=:num,GENRE=:genre where ID_EMP=:id");

     //Création des variables liées
     query.bindValue(":id",res);
     query.bindValue(":email",email);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":num",res2) ;
     query.bindValue(":genre",genre);
     return query.exec();

}





QSqlQueryModel * employe::AfficherTrieCIN()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE ORDER BY ID_EMP");
    return model;
}




QSqlQueryModel * employe::AfficherTrieNom()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE ORDER BY NOM_EMP");
    return model;
}



QSqlQueryModel * employe::AfficherTriePrenom()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE ORDER BY PRENOM_EMP");
    return model;
}




QSqlQueryModel * employe::rechercherafficher(QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from EMPLOYE where ID_EMP like '"+nom+"%' or NOM_EMP LIKE '"+nom+"%' or PRENOM_EMP like '"+nom+"%'or TEL like '"+nom+"%' or MAIL like '"+nom+"%' or GENRE like '"+nom+"%' ");
    q.addBindValue("%"+ nom +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}

QSqlQueryModel * employe:: afficher2()
{
  QSqlQueryModel * model=new QSqlQueryModel() ;

  model->setQuery("select num_salle from salle_evenement ") ;

 // qDebug() << res2 << '\n';
  return  model ;


}
