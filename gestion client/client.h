#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class Client
{
public:
    Client();
    Client(int,QString,QString,QString,QString);
    Client(QString,QString,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    QString getemail();
    QString gettel();
    void setid(int);
     void setnom(QString);
      void setprenom(QString);
       void setemail(QString);
       void settel(QString);
       bool ajouter();
       bool supprimer(int id);
       QSqlQueryModel* afficher();
        bool modifier(int id,QString nom,QString prenom,QString e_mail,QString tel);
        QSqlQueryModel*  tester();




private:
    int id_client;
    QString nom;
    QString prenom;
    QString adr_email;
    QString phone;


};

#endif // CLIENT_H
