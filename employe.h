#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>
#include<QString>

class employe
{
    QString nom,prenom,email ;
    int id,num ;
public:
    employe(){} ;
    employe(int,QString,QString,QString,int) ;

    QString getnom(){return  nom ;}
    QString getprenom(){return  prenom ;}
    QString getemail(){return  email ;}

    int getID(){return id ;}
    int getnum() {return  num ;}

    void setnom(QString n){nom=n ;}
    void setprenom(QString p){prenom=p ;}
    void setemail(QString e){email=e ;}

    void setID(int i){id=i ;}
    void setnum(int nt){num=nt ;}

    bool ajouter() ;
    QSqlQueryModel *afficher();
    bool supprimer(int) ;
    bool  modifier(int ,QString ,QString,QString ,int ) ;

    QSqlQueryModel * AfficherTrieCIN() ;
    QSqlQueryModel * AfficherTrieNom() ;
    QSqlQueryModel * AfficherTriePrenom() ;

    QSqlQueryModel * rechercherafficher(QString ) ;
};

#endif // EMPLOYE_H
