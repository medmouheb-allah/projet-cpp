#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <QSqlQuery>
#include <QSqlQueryModel>

class evenement
{
public:
    evenement();
    evenement(int,QString,QString,QString,QString,QString,QString,QString);


    bool ajouter();
    bool modifier(int);
     QSqlQueryModel * afficher();
      bool supprimer(int);

      void incrParking();
      void decrParking();
        QString count();
     QSqlQueryModel * get_id_emp();
     QSqlQueryModel * get_id_client();
     QSqlQueryModel * get_salle();

      int code;
      QString nom, description, type, date,client,emp,salle;


};

#endif // EVENEMENT_H
