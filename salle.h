#ifndef SALLE_H
#define SALLE_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QPixmap>
//#include <QVariant>
#include <QBuffer>

using namespace std;

class Salle
{
    int num_salle;
    int capacite;
    QString localisation, style;
    QPixmap img;

public:
    //Constructuers
    Salle();
    Salle(int, int, QString, QString, QPixmap);

    //Getter
    int getNum_salle() {return num_salle;}
    int getCapacite() {return capacite;}
    QString getLocalisation() {return localisation;}
    QString getStyle() {return style;}
    QPixmap getImg(){return img;}

    //Setter
    void setNum_sallle (int num_salle) {this->num_salle=num_salle;}
    void setCapacitee (int capacite) {this->capacite=capacite;}
    void setLocalisation (QString localisation){this->localisation=localisation;}
    void setStyle (QString style){this->style=style;}
    void setImg (QPixmap img){this->img=img;}

    //CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();

    ///////////////////////
    QSqlQueryModel*  tester();

    ///////////////////////

    QSqlQueryModel * tricroissant_num_salle() ;
    QSqlQueryModel * tricroissant_capacite() ;
    QSqlQueryModel * tricroissant_style() ;
    QSqlQueryModel * tricroissant_localisation();

    QSqlQueryModel * tridecroissant_num_salle() ;
    QSqlQueryModel * tridecroissant_capacite() ;
    QSqlQueryModel * tridecroissant_style() ;
    QSqlQueryModel * tridecroissant_localisation();

    bool supprimerTout();

    QSqlQueryModel * recherchernumsalle(QString num) ;
    QSqlQueryModel * rechercherlocalisation(QString localisation) ;
    QSqlQueryModel * rechercherstyle(QString style) ;
    QSqlQueryModel * recherchercapacite(QString capacite) ;

};

#endif // SALLE_H
