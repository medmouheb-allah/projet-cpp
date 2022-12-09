#ifndef REGULATEUR_TEMPERATURE_SALLE_H
#define REGULATEUR_TEMPERATURE_SALLE_H
#include <iostream>
#include <string>

#include <QDialog>
#include "arduino_salle.h"

#include<QTime>
#include <iostream>
#include <QThread>
#include"arduino_salle.h"
#include <QSerialPort>
#include<QTime>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QThread>

using namespace std;


namespace Ui {
class Regulateur_temperature_salle;
}

class Regulateur_temperature_salle : public QDialog
{
    Q_OBJECT

public:

    explicit Regulateur_temperature_salle(QDialog *parent = nullptr);
    ~Regulateur_temperature_salle();



private slots:


    float lire_temperature();

    void regul_temp();

    void on_moins_clicked();

    void on_plus_clicked();

    void on_commencer_clicked();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimerTout() ;

    void on_supprimer_date_clicked();


private:

    Ui::Regulateur_temperature_salle *ui;

    QByteArray data ;

    int test=0 ;

    QString Date1 ;
    QString Date2 ;

    arduino A ;

    int arret = 1 ;

};







#endif // REGULATEUR_TEMPERATURE_SALLE_H







