#ifndef LOGIN_H
#define LOGIN_H
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include "QString"


class login
{
private:
    QString user ;
    int password ;

public:
    login() ;
    login(QString,int) ;
    ~login(){}

    QString getUsername(){return  user ;}
    int getMDP() {return  password ;}

    void setUsername(QString u){user= u ;}
    void setMDP(int p){password=p;}

  //  bool ajouter() ;
    bool log(QString,int);

};

#endif // LOGIN_H
