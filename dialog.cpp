#include "dialog.h"
#include "ui_dialog.h"
#include"employe.h"
#include<QMessageBox>
#include "connection.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    //connection c ;
    //bool test ;
    //test= c.createconnection() ;
    ui->setupUi(this);

    ui->lineEdit_3->setValidator(new QIntValidator(0,9999999,this) ) ;
    ui->lineEdit_5->setValidator(new QIntValidator(0,99999999,this)) ;
    ui->comboBox->addItem("CIN");
        ui->comboBox->addItem("Nom");
         ui->comboBox->addItem("Prenom");
         ui->affichage_employe->setModel(em.afficher()) ;



}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_bouton1_clicked()
{
    QString nom =ui->lineEdit->text() ;
    QString prenom =ui->lineEdit_2->text() ;
    QString email = ui->lineEdit_4->text() ;
    int id=ui->lineEdit_3->text().toInt() ;
    int num =ui->lineEdit_5->text().toInt() ;
    employe em(id,nom,prenom,email,num) ;

    bool test=em.ajouter() ;
    if (test)
       {
    QMessageBox :: information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectue.\n""click cancel to exit"),QMessageBox::Cancel) ;
    }
    else
    {
         QMessageBox :: critical(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectue.\n""click cancel to exit"),QMessageBox::Cancel) ;
    }

    ui->affichage_employe->setModel(em.afficher()) ;

}


void Dialog::on_pushButton_3_clicked()
{
    int id=ui->lineEdit_6->text().toInt() ;



    bool test=em.supprimer(id) ;
    if (test)
    {
    QMessageBox :: information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectue.\n""click cancel to exit"),QMessageBox::Cancel) ;
    }
    else
    {
         QMessageBox :: critical(nullptr,QObject::tr("not ok"),QObject::tr("suppression non effectue.\n""click cancel to exit"),QMessageBox::Cancel) ;
    }
    ui->affichage_employe->setModel(em.afficher()) ;

}

void Dialog::on_b2_clicked()
{
    employe em ;

     int id,tel;
     QString nom,prenom,e_mail;

        id=ui->lineEdit_3->text().toInt();
        nom=ui->lineEdit->text();
        prenom=ui->lineEdit_2->text();
        e_mail=ui->lineEdit_4->text();
        tel=ui->lineEdit_5->text().toInt();
        bool test= em.modifier(id,nom,prenom,e_mail,tel);
      if (test)
       {
       QMessageBox :: information(nullptr,QObject::tr("ok"),QObject::tr("modification effectue.\n""click cancel to exit"),QMessageBox::Cancel) ;
       }
       else
       {
            QMessageBox :: critical(nullptr,QObject::tr("not ok"),QObject::tr("modification non effectue.\n""click cancel to exit"),QMessageBox::Cancel) ;
       }
        ui->affichage_employe->setModel(em.afficher());

}

