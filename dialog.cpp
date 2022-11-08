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

  /*  int CIN=ui->lineEdit_3->text().toInt() ;
    int num =ui->lineEdit_5->text().toInt() ;

    if(CIN < 9999999 || ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" || ui->lineEdit_4->text() == "" || num < 99999999)
    {
               ui->lineEdit_3->setStyleSheet("border: 1px solid red;");
               if(CIN > 999999 )
               {
                   ui->lineEdit_3->setStyleSheet("border: 1px solid black;");
               }

               ui->lineEdit->setStyleSheet("border: 1px solid red;") ;

               if( ui->lineEdit->text()!= "" )
                   ui->lineEdit->setStyleSheet("border: 1px solid black;") ;
               }*/



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


void Dialog::on_affichage_employe_doubleClicked()
{
   // selected=ui->affichage_employe->model()
    QModelIndex index = ui->affichage_employe->currentIndex();
             QString ci = index.data(Qt::DisplayRole).toString();
              QString nom = ui->affichage_employe->model()->index(index.row(), 2).data(Qt::DisplayRole).toString();
              ui->lineEdit->setText(nom);
               QString prenom = ui->affichage_employe->model()->index(index.row(), 3).data(Qt::DisplayRole).toString();
                 ui->lineEdit_2->setText(prenom);
                QString email = ui->affichage_employe->model()->index(index.row(), 1).data(Qt::DisplayRole).toString();
                 ui->lineEdit_4->setText(email);
                 QString tel = ui->affichage_employe->model()->index(index.row(), 4).data(Qt::DisplayRole).toString();
                 ui->lineEdit_5->setText(tel) ;
                  QString cin = ui->affichage_employe->model()->index(index.row(), 0).data(Qt::DisplayRole).toString();
                  ui->lineEdit_3->setText(cin);



}


void Dialog::on_pushButton_2_clicked()
{
    employe emp ;
    QString tri= ui->comboBox->currentText() ;

    if(tri=="Nom")
    {

        ui->affichage_employe->setModel(emp.AfficherTrieNom()) ;
    }  else
        if (tri=="CIN")
        {
        ui->affichage_employe->setModel(emp.AfficherTrieCIN()) ;
        }
        else
        {
        ui->affichage_employe->setModel(emp.AfficherTriePrenom()) ;
        }
    }




void Dialog::on_pushButton_8_clicked()
{
    employe emp;
    QString aff= ui->lineEdit_8->text() ;
    ui->affichage_employe->setModel(emp.rechercherafficher(aff)) ;
}