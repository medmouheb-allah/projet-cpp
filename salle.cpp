#include "salle.h"

Salle::Salle(){};

Salle::Salle(int num_salle, int capacite, QString localisation, QString style)
{
    this->num_salle= num_salle;
    this->capacite=capacite;
    this->localisation=localisation;
    this->style=style;
};

//CRUD
bool Salle::ajouter()
{

    QSqlQuery query;
    //QString res = QString::number(num_salle);

    query.prepare("insert into SALLE_EVENEMENT (num_salle, capacite, localisation, style) values (:num_salle, :capacite, :localisation, :style)");
    query.bindValue(":num_salle", num_salle);
    query.bindValue(":capacite", capacite);
    //query.bindValue(":num_salle", num_salle);
    query.bindValue(":localisation", localisation);
    query.bindValue(":style", style);

    return query.exec();

};

QSqlQueryModel * Salle:: afficher()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select num_salle, capacite, localisation, style from SALLE_EVENEMENT" );

    //Header
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_salle"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("capacite"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("localisation"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("style"));

    return model;
};

bool Salle::supprimer(int num_salle)
{

    QSqlQuery query;
    //QString res = QString::number(num_salle);

    query.prepare("delete from SALLE_EVENEMENT where num_salle=:num_salle");
    query.bindValue(":num_salle", num_salle);

    return query.exec();

};



bool Salle::modifier ()
{

    QSqlQuery query;
    //QString res = QString::number(num_salle);

    query.prepare("update SALLE_EVENEMENT set capacite = :capacite, localisation=:localisation, style=:style where num_salle=:num_salle");
    query.bindValue(":num_salle", num_salle);
    query.bindValue(":capacite", capacite);
    query.bindValue(":localisation", localisation);
    query.bindValue(":style", style);

    return query.exec();

};


























