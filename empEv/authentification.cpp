#include "authentification.h"
#include <QSqlQuery>


login::login()
{


    user="";
    password=0;
}






login::login(QString u,int m)
{
    password=m;
    user=u;
}





bool login::log(QString user , int password)
{
    QSqlQuery qry;
    qry.prepare("SELECT PRENOM_EMP, ID_EMP FROM EMPLOYE WHERE USERNAME=\'"+ user +"\' AND MDP=\'" + password + "\'");
    qry.addBindValue(user);
    qry.addBindValue(password);
    if(qry.exec())
        if(qry.next())
            {
                QString use = QVariant(qry.value(0)).toString();
            if(user==use)
            {return true;}
        }
    return false;

}
