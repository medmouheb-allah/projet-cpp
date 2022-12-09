#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class Client
{
public:
    Client();
    Client(int,QString,QString,QString,QString,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    QString getemail();
    QString gettel();
     QString getgenre();
     QString getage();
    void setid(int);
     void setnom(QString);
      void setprenom(QString);
       void setemail(QString);
       void settel(QString);
        void setgenre(QString);
        void setage(QString);
       bool ajouter();
       bool supprimer(int id);
       QSqlQueryModel* afficher();
        QSqlQueryModel* aff();
        bool modifier(int id,QString nom,QString prenom,QString e_mail,QString tel,QString genre,QString age);
        QSqlQueryModel*  tester();
        QSqlQueryModel*  triid();
        QSqlQueryModel*  trinom();
         QSqlQueryModel*  triphone();
          QSqlQueryModel * rechercher(QString rech);
            QSqlQueryModel * rechercher_client(const QString &b);
              QSqlQueryModel * rech(const QString &b);
void incrParking();
void decrParking();
QString count();

private:
    int id_client;
    QString nom;
    QString prenom;
    QString adr_email;
    QString phone;
    QString genre;
    QString age;



};

#endif // CLIENT_H
