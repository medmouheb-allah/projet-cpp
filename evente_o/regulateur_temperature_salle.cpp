#include "Regulateur_temperature_salle.h"
#include "ui_Regulateur_temperature_salle.h"

#include <QTimer>



Regulateur_temperature_salle::Regulateur_temperature_salle(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Regulateur_temperature_salle)
{
    ui->setupUi(this);

    int ret=A.connect_arduino(); //lancer la connexion arduino
    switch(ret)
    {
    case(0):qDebug()<<"arduino is avaible and connected to :"<<A.getarduino_port_name();
        break ;
    case(1):qDebug()<<"arduino is avaible and connected to :"<<A.getarduino_port_name();
        break ;
    case(-1):qDebug()<<"arduino is not avaible";
    }

    ui->lcdNumber_2->display(20.5) ;

    ui->tableView_date->setModel(afficher());

}




Regulateur_temperature_salle::~Regulateur_temperature_salle()
{
    delete ui;
}



float Regulateur_temperature_salle::lire_temperature()
{   float data1 ;

    A.write_to_arduino("1") ;

    do
    {
        A.serial->waitForReadyRead() ;
    }
    while(A.serial->bytesAvailable()!=2) ;

         data = A.read_from_arduino();


    if ( data != "0" )
    {
    data1 = data.toFloat() ;
    ui->lcdNumber->display(data1) ;

    }
    else
        cout<<"data vide"<<endl ;

   return data1 ;

}


void Regulateur_temperature_salle::regul_temp()
{

{   float  temp_actuelle = lire_temperature();
   float temp_ideale = ui->lcdNumber_2 ->value() ;

   if (( temp_actuelle > temp_ideale ) && (test==0) )
    {
       A.write_to_arduino("2") ;

       QTime Time =QTime::currentTime() ;
       Date1 = Time.toString("H:m:s a") ;

       test=1 ;
    }

   else if ((temp_actuelle <= temp_ideale -0.5 ) && (test==1) )
    {
       A.write_to_arduino("3") ;
       QTime Time  =QTime::currentTime() ;
       Date2 = Time.toString("H:m:s a") ;

       ajouter() ;
       ui->tableView_date->setModel(afficher());


       test=0 ;

    }
}
}


void Regulateur_temperature_salle::on_commencer_clicked()
{

    QTimer *timer = new QTimer(this) ;
    connect(timer,SIGNAL(timeout()),this,SLOT(regul_temp()) ) ;
    timer->start(500);


}


void Regulateur_temperature_salle::on_moins_clicked()
{
    float temp = ui->lcdNumber_2 ->value()  ;
    temp -- ;
    ui->lcdNumber_2->display(temp) ;

}

void Regulateur_temperature_salle::on_plus_clicked()
{
    float temp = ui->lcdNumber_2 ->value()  ;
    temp ++ ;
    ui->lcdNumber_2->display(temp) ;
}






bool Regulateur_temperature_salle::ajouter()
{

    QSqlQuery query;

    query.prepare("insert into Regulateur_temperature_salle (DATE_ACTIVATION, DATE_ARRET ) values (:DATE_ACTIVATION, :DATE_ARRET)" );
    query.bindValue(":DATE_ACTIVATION", Date1);
    query.bindValue(":DATE_ARRET", Date2);

    return query.exec();

};

QSqlQueryModel * Regulateur_temperature_salle:: afficher()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Regulateur_temperature_salle" );
    return model;
};



bool Regulateur_temperature_salle::supprimerTout()
{
    QSqlQuery query;

    query.prepare("delete from Regulateur_temperature_salle ");

    return query.exec();

}




void Regulateur_temperature_salle::on_supprimer_date_clicked()
{
    supprimerTout() ;
    ui->tableView_date->setModel(afficher());
}
