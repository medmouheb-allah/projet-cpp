#include <QDebug>
#include <QSqlError>
#include<QObject>
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include "interface.h"
#include "facture.h"



Facture::Facture()
{

    DESCRIPTION="";
    QUANTITE="";
    PRIXUNIT="";
    TOTAL="";
}


Facture::Facture(QString DESCRIPTION,QString QUANTITE,QString PRIXUNIT,QString TOTAL)
{
    this->DESCRIPTION=DESCRIPTION;
    this->QUANTITE=QUANTITE;
    this->PRIXUNIT=PRIXUNIT;
    this->TOTAL=TOTAL;
}

void Facture::set_description(QString DESCRIPTION)
{
    this -> DESCRIPTION= DESCRIPTION;
}

void Facture::set_quantite(QString)
{
   this -> QUANTITE = QUANTITE;
}

void Facture::set_prixunit(QString)
{
   this -> PRIXUNIT = PRIXUNIT;
}

void Facture::set_total(QString)
{
     this -> TOTAL = TOTAL;
}
QString Facture::get_description()
{
    return DESCRIPTION;
}

QString Facture::get_quantite()
{
    return QUANTITE;
}

QString Facture::get_prixunit()
{
    return PRIXUNIT;
}

QString Facture::get_total()
{
    return TOTAL;
}

bool Facture::ajouter(){

    QSqlQuery query;


          query.prepare("INSERT INTO FACTURE (DESCRIPTION,QUANTITE , PRIXUNIT,TOTAL) "
                        "VALUES (:DESCRIPTION, :QUANTITE, :PRIXUNIT ,:TOTAL)");
          query.bindValue(":DESCRIPTION", DESCRIPTION);
          query.bindValue(":QUANTITE", QUANTITE);
          query.bindValue(":PRIXUNIT", PRIXUNIT);
          query.bindValue(":TOTAL", TOTAL);


        return  query.exec();

}
QSqlQueryModel* Facture::afficher(){

QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("select * from FACTURE");
model->setHeaderData(0, Qt::Horizontal,QObject::tr("DESCRIPTION"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("QUANTITE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIXUNIT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("TOTAL"));
return model;
}

bool Facture::modifier_facture(QString DESCRIPTION){

    QSqlQuery query;

   query.prepare("update FACTURE set QUANTITE=:QUANTITE,PRIXUNIT=:PRIXUNIT,TOTAL=:TOTAL where DESCRIPTION=:DESCRIPTION");
   query.bindValue(":DESCRIPTION",DESCRIPTION);
   query.bindValue(":QUANTITE", QUANTITE);
    query.bindValue(":PRIXUNIT",PRIXUNIT);
    query.bindValue(":TOTAL",TOTAL);


    return    query.exec();

}
