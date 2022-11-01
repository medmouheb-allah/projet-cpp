#ifndef SALLE_H
#define SALLE_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
//#include <iostream>

using namespace std;

class Salle
{
    int num_salle;
    int capacite;
    QString localisation, style;

public:
    //Constructuers
    Salle();
    Salle(int, int, QString, QString);

    //Getter
    int getNum_salle() {return num_salle;}
    int getCapacite() {return capacite;}
    QString getLocalisation() {return localisation;}
    QString getStyle() {return style;}

    //Setter
    void setNum_sallle (int num_salle) {this->num_salle=num_salle;}
    void setCapacitee (int capacite) {this->capacite=capacite;}
    void setLocalisation (QString localisation){this->localisation=localisation;}
    void setStyle (QString style){this->style=style;}

    //CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();

};

#endif // SALLE_H
