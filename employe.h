#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>
#include<QString>
#include <QPrinter>
#include <QPrintDialog>
class employe
{
    QString nom,prenom,email,genre ;
    int id,num ;
public:
    employe(){} ;
    employe(int,QString,QString,QString,int,QString) ;

    QString getnom(){return  nom ;}
    QString getprenom(){return  prenom ;}
    QString getemail(){return  email ;}
    QString getgenre() {return genre ;}

    int getID(){return id ;}
    int getnum() {return  num ;}

    void setnom(QString n){nom=n ;}
    void setprenom(QString p){prenom=p ;}
    void setemail(QString e){email=e ;}
    void setgenre(QString g) {genre=g ;}

    void setID(int i){id=i ;}
    void setnum(int nt){num=nt ;}

    bool ajouter() ;
    QSqlQueryModel *afficher();
    bool supprimer(int) ;
    QSqlQueryModel*  tester() ;
    bool  modifier(int ,QString ,QString,QString ,int,QString ) ;

    QSqlQueryModel * AfficherTrieCIN() ;
    QSqlQueryModel * AfficherTrieNom() ;
    QSqlQueryModel * AfficherTriePrenom() ;

    QSqlQueryModel * rechercherafficher(QString ) ;
    
    QString  export_pdf() ;
};

#endif // EMPLOYE_H
