#include "salle.h"


Salle::Salle(){};

Salle::Salle(int num_salle, int capacite, QString localisation, QString style, QPixmap img)
{
    this->num_salle= num_salle;
    this->capacite=capacite;
    this->localisation=localisation;
    this->style=style;
    this->img=img;
};

//CRUD

bool Salle::ajouter()
{


    QSqlQuery query;
    //conversion image Qpixmap img lel byte to base 64
    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);
    QPixmap pixMap = getImg();
    pixMap.save(&buffer,"PNG");

    query.prepare("insert into SALLE_EVENEMENT (num_salle, capacite, localisation, style, img) values (:num_salle, :capacite, :localisation, :style, :img)");
    query.bindValue(":num_salle", num_salle);
    query.bindValue(":capacite", capacite);
    query.bindValue(":localisation", localisation);
    query.bindValue(":style", style);
    query.bindValue(":img", QVariant(bytes.toBase64().data())); //blob

    return query.exec();

};

QSqlQueryModel * Salle:: afficher()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select num_salle, capacite, localisation, style from SALLE_EVENEMENT" );

    //Header
/*
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_salle"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("capacite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("localisation"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("style"));
*/
    return model;
};



bool Salle::supprimer(int num_salle)
{

    QSqlQuery query;

    query.prepare("delete from SALLE_EVENEMENT where num_salle=:num_salle");
    query.bindValue(":num_salle", num_salle);

    return query.exec();

};



bool Salle::modifier ()
{

    QSqlQuery query;
    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);
    QPixmap pixMap = getImg();
    pixMap.save(&buffer,"PNG");

    query.prepare("update SALLE_EVENEMENT set capacite = :capacite, localisation=:localisation, style=:style, img =:img where num_salle=:num_salle");
    query.bindValue(":num_salle", num_salle);
    query.bindValue(":capacite", capacite);
    query.bindValue(":localisation", localisation);
    query.bindValue(":style", style);
    query.bindValue(":img", QVariant(bytes.toBase64().data()));

    return query.exec();

};

/////////////////////////////////////////////////////////////////////////////
QSqlQueryModel* Salle:: tester()
{
   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT num_salle FROM SALLE_EVENEMENT");

   return model;
}

//////////////////////////////////////////////////////////////////////////////

bool Salle::supprimerTout()
{
    QSqlQuery query;

    query.prepare("delete from SALLE_EVENEMENT ");

    return query.exec();

}





