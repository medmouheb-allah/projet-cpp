#include "evenement.h"

evenement::evenement()
{

}


evenement::evenement(int i,QString s1 ,QString s2,QString s3 ,QString s4,QString s5,QString s6 ,QString s7 ){
    code=i;
    nom=s1;
    description=s2;
    type=s3;
    date=s4;
    client=s5;
    emp=s6;
    salle=s7;

}


bool evenement::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO EVENEMENT (CODE, NOM,DESCRIPTION,TYPE,DATE_EV,ID_CLIENT, ID_EMP,SALLE) "
                                   "VALUES (:code, :nom, :description,:type,:date,:id_client,:id_emp,:salle)");
    query.bindValue(":code", code);
    query.bindValue(":nom",nom);
    query.bindValue(":description", description);
    query.bindValue(":type", type);
    query.bindValue(":date", date);
    query.bindValue(":id_client", client);
    query.bindValue(":id_emp", emp);
    query.bindValue(":salle", salle);

    return    query.exec();

}

bool evenement::modifier(int selected){

    QSqlQuery query;


    query.prepare(" UPDATE EVENEMENT SET NOM= :nom ,DESCRIPTION= :description ,TYPE= :type,DATE_EV= :date, "
                  "ID_CLIENT= :id_client, ID_EMP= :id_emp ,SALLE= :salle where CODE= :code");
    query.bindValue(":code", selected);
    query.bindValue(":nom",nom);
    query.bindValue(":description", description);
    query.bindValue(":type", type);
    query.bindValue(":date", date);
    query.bindValue(":id_client", client);
    query.bindValue(":id_emp", emp);
    query.bindValue(":salle", salle);

    return    query.exec();

}

 QSqlQueryModel * evenement::afficher(){

     QSqlQueryModel * modal=new QSqlQueryModel();
     modal->setQuery("SELECT * FROM EVENEMENT");

     return modal;

 }

  bool evenement::supprimer(int selected){

      QSqlQuery query;
      query.prepare("Delete from EVENEMENT where CODE = :code ");
      query.bindValue(":code", selected);
      return    query.exec();


  }



  void evenement::incrParking(){

      QSqlQuery query;
      query.prepare("update parking set nbrPlaces=nbrPlaces+1");
      query.exec();
  }



  void evenement::decrParking(){

      QSqlQuery query;
      query.prepare("update parking set nbrPlaces=nbrPlaces-1");
      query.exec();
  }


  QString evenement::count(){

      QSqlQuery query("select * from parking");
      while(query.next()){
          return query.value(0).toString();
      }

  }


  QSqlQueryModel * evenement::get_id_client(){

      QSqlQueryModel * modal=new QSqlQueryModel();
      modal->setQuery("SELECT ID_CLIENT FROM CLIENT_");

      return modal;

  }

  QSqlQueryModel * evenement::get_id_emp(){

      QSqlQueryModel * modal=new QSqlQueryModel();
      modal->setQuery("SELECT ID_EMP FROM EMPLOYE");

      return modal;

  }

  QSqlQueryModel * evenement::get_salle(){

      QSqlQueryModel * modal=new QSqlQueryModel();
      modal->setQuery("SELECT NUM_SALLE FROM SALLE_EVENEMENT where DISPONIBILITE='oui' ");

      return modal;

  }
