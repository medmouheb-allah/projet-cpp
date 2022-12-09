#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

#include <iostream>
#include <QLabel>
#include <QPixmap>
#include <QMovie>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     QLabel label;
    QMovie *user = new QMovie("C:/Users/user/Desktop/tttt/ha.gif");
    ui->user->setMovie(user);
    user->start();
    QMovie *userr = new QMovie("C:/Users/user/Desktop/tttt/ha.gif");
    ui->userr->setMovie(userr);
    userr->start();
    QMovie *us = new QMovie("C:/Users/user/Desktop/tttt/bo.gif");
    ui->us->setMovie(us);
    us->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
            QSqlQuery qry;
                QString  LOGIN=ui->lineEdit->text();
                QString  MDP=ui->lineEdit_2->text();
qry.prepare("SELECT GESTION FROM SMART_EVENT_PLANNER WHERE LOGIN= :LOGIN AND MDP= :MDP");
 qry.bindValue(":MDP",MDP);
 qry.bindValue(":LOGIN",LOGIN);
 qry.exec();
                   if(qry.next())
                   {
                       ui->lineEdit->clear();
                       ui->lineEdit_2->clear();

                       if(qry.value(0).toString()=="employe")
                       {
                           Dialog *MainWindow=new Dialog(this);
                           MainWindow->show();
                           QMessageBox::information(this, "Success","LOG In to employe Successfully");
                       }
                       else if (qry.value(0).toString()=="evenement"){
                           event_workspace *MainWindow=new event_workspace(this);
                           MainWindow->show();
                           QMessageBox::information(this, "Success","LOG In to event Successfully");
                       }
                       else if (qry.value(0).toString()=="client"){
                           client_workspace *MainWindow=new client_workspace(this);
                           MainWindow->show();
                           QMessageBox::information(this, "Success","LOG In to client Successfully");
                       }
                       else if (qry.value(0).toString()=="salle"){
                           salle_workspace *MainWindow=new salle_workspace(this);
                           MainWindow->show();
                           QMessageBox::information(this, "Success","LOG In to salle Successfully");
                       }
                       else if (qry.value(0).toString()=="fournisseur"){
                          Interface *MainWindow=new Interface(this);
                           MainWindow->show();
                           QMessageBox::information(this, "Success","LOG In to fournisseur Successfully");
                       }

                       }
                   else  QMessageBox::information(this, "Failed","Log In Failed\n unvalid username or password");


}

void MainWindow::on_pushButton_2_clicked()
{
    QString login=ui->nom_sign->text();
    QString mail=ui->mail_sign->text();
    QString mdp =ui->mdp_sign->text();
    QString gestion =ui->comboBox_sign->currentText() ;

    QSqlQuery query ;
    QMessageBox messageBox;

    query.prepare("insert into SMART_EVENT_PLANNER (LOGIN,MDP,MAIL,GESTION) values(:LOGIN,:MDP,:MAIL,:GESTION)") ;

    query.bindValue(":LOGIN",login) ;
    query.bindValue(":MDP",mdp) ;
    query.bindValue(":MAIL",mail) ;
    query.bindValue(":GESTION",gestion) ;

    bool test = query.exec();
    if (test)
    {
        messageBox.information(nullptr, messageBox.tr("Succès"), messageBox.tr("Ajout effectué"));
    }
     else
        messageBox.critical(nullptr, messageBox.tr("Echec"), messageBox.tr("Ajout non effectué"));


}
