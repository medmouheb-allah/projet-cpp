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
    ID_FOURNISSEUR="";
    CODE_EVENNEMENT=0;
}


Facture::Facture (QString DESCRIPTION,QString QUANTITE,QString PRIXUNIT,QString TOTAL,QString ID_FOURNISSEUR,int CODE_EVENNEMENT)
{
    this->DESCRIPTION=DESCRIPTION;
    this->QUANTITE=QUANTITE;
    this->PRIXUNIT=PRIXUNIT;
    this->TOTAL=TOTAL;
    this->ID_FOURNISSEUR=ID_FOURNISSEUR;
    this->CODE_EVENNEMENT=CODE_EVENNEMENT;
}

void Facture::set_description(QString DESCRIPTION)
{
    this -> DESCRIPTION= DESCRIPTION;
}

void Facture::set_quantite(QString)
{
   this -> QUANTITE += QUANTITE;
}

void Facture::set_prixunit(QString)
{
   this -> PRIXUNIT += PRIXUNIT;
}

void Facture::set_total(QString)
{
     this -> TOTAL += TOTAL;
}
void Facture::set_ID_FOURNISSEUR(QString)
{
     this -> ID_FOURNISSEUR += ID_FOURNISSEUR;
}
void Facture::set_CODE_EVENNEMENT(int)
    {
         this -> CODE_EVENNEMENT += CODE_EVENNEMENT;
    }
    QString Facture::get_description()
    {
        return DESCRIPTION;
    }

QString Facture::get_ID_FOURNISSEUR()
{
    return ID_FOURNISSEUR;
}

int Facture::get_CODE_EVENNEMENT()
{
    return CODE_EVENNEMENT;
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

    QString du = QString::number(CODE_EVENNEMENT);
          query.prepare("INSERT INTO FACTURE (DESCRIPTION,QUANTITE , PRIXUNIT,TOTAL,ID_FOURNISSEUR,CODE_EVENNEMENT) "
                        "VALUES (:DESCRIPTION, :QUANTITE, :PRIXUNIT ,:TOTAL , :ID_FOURNISSEUR , :CODE_EVENNEMENT)");
          query.bindValue(":DESCRIPTION", DESCRIPTION);
          query.bindValue(":QUANTITE", QUANTITE);
          query.bindValue(":PRIXUNIT", PRIXUNIT);
          query.bindValue(":TOTAL", TOTAL);
          query.bindValue(":ID_FOURNISSEUR", ID_FOURNISSEUR);
          query.bindValue(":CODE_EVENNEMENT", du);


        return  query.exec();

}
QSqlQueryModel* Facture::afficher(){

QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("select * from FACTURE");
model->setHeaderData(0, Qt::Horizontal,QObject::tr("DESCRIPTION"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("QUANTITE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIXUNIT"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("TOTAL"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("CODE_EVENNEMENT"));

return model;
}

bool Facture::modifier_facture(QString DESCRIPTION){

    QSqlQuery query;
    QString du = QString::number(CODE_EVENNEMENT);
   query.prepare("update FACTURE set QUANTITE=:QUANTITE,PRIXUNIT=:PRIXUNIT,TOTAL=:TOTAL ,ID_FOURNISSEUR=:ID_FOURNISSEUR,CODE_EVENNEMENT=:CODE_EVENNEMENT where DESCRIPTION=:DESCRIPTION");
   query.bindValue(":DESCRIPTION",DESCRIPTION);
   query.bindValue(":QUANTITE", QUANTITE);
    query.bindValue(":PRIXUNIT",PRIXUNIT);
    query.bindValue(":TOTAL",TOTAL);
    query.bindValue(":ID_FOURNISSEUR",ID_FOURNISSEUR);
    query.bindValue(":CODE_EVENNEMENT",du);


    return    query.exec();

}
QSqlQueryModel * Facture:: combo_fournisseur(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select ID_FOURNISSEUR from FOURNISSEUR ");


    return  model ;
}
QSqlQueryModel * Facture:: combo_evenement(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select CODE_EVENNEMENT from EVENEMENT ");


    return  model ;
}
