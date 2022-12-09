#include "salle.h"



QSqlQueryModel * Salle::recherchernumsalle(QString num)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from SALLE_EVENEMENT where num_salle like '"+num+"' ");
    q.exec();
    model->setQuery(q);
    return (model);

}
QSqlQueryModel * Salle::rechercherlocalisation(QString localisation)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from SALLE_EVENEMENT where localisation like '"+localisation+"' ");
    q.exec();
    model->setQuery(q);
    return (model);

}

QSqlQueryModel * Salle::rechercherstyle(QString style)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from SALLE_EVENEMENT where style like '"+style+"' ");
    q.exec();
    model->setQuery(q);
    return (model);

}

QSqlQueryModel * Salle::recherchercapacite(QString capacite)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from SALLE_EVENEMENT where capacite like '"+capacite+"' ");
    q.exec();
    model->setQuery(q);
    return (model);

}

