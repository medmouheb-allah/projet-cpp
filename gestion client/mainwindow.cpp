#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QDebug>
#include "client.h"
#include <iostream>
#include<QIntValidator>
#include<QComboBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->le_id->setValidator(new QIntValidator(0,9999999,this)) ;
    ui->le_tel->setValidator(new QIntValidator(0,99999999,this)) ;
    ui->le_tab->setModel(c.afficher());
    ui->comboBox->setModel(c.tester());
    ui->comboBox_2->setModel(c.tester());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{


    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString e_mail=ui->le_email->text();
    QString tel=ui->le_tel->text();


    Client C(id,nom,prenom,e_mail,tel);
    bool test=C.ajouter();

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr(" not ok"),
                    QObject::tr("Ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
ui->le_tab->setModel(c.afficher());
ui->comboBox->setModel(c.tester());
 ui->comboBox_2->setModel(c.tester());
}


void MainWindow::on_bouton_supp_clicked()
{
    Client c;
    c.setid(ui->comboBox->currentText().toInt());
    bool test=c.supprimer(c.getid());
    QMessageBox msgBox;

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("supp effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->le_tab->setModel(c.afficher());
         ui->comboBox->setModel(c.tester());
          ui->comboBox_2->setModel(c.tester());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr(" not ok"),
                    QObject::tr("supp non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_clicked()
{
    int id;
    QString nom,prenom,e_mail,tel;

    id=ui->le_id_2->text().toInt();
    nom=ui->le_nom_2->text();
    prenom=ui->le_prenom_2->text();
    e_mail=ui->le_email_2->text();
     tel=ui->le_tel_2->text();
    c.modifier(id,nom,prenom,e_mail,tel);
    ui->le_tab->setModel(c.afficher());

}

void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    QString name=ui->comboBox_2->currentText();
    QSqlQuery qry;
    qry.prepare("select *from CLIENT_ where id_client='"+name+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
         ui->le_id_2->setText(qry.value(0).toString());
         ui->le_nom_2->setText(qry.value(1).toString());
          ui->le_prenom_2->setText(qry.value(2).toString());
          ui->le_email_2->setText(qry.value(3).toString());
         ui->le_tel_2->setText(qry.value(4).toString());
        }
    }





}
