#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
            QSqlQuery qry;
                QString  USERNAME=ui->lineEdit->text();
                QString  MDP=ui->lineEdit_2->text();
qry.prepare("SELECT ROLE FROM EMPLOYE WHERE PRENOM_EMP= :usr AND ID_EMP= :mdp");
 qry.bindValue(":mdp",MDP);
 qry.bindValue(":usr",USERNAME);
 qry.exec();
                   if(qry.next())
                   {
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


                       }
                   else  QMessageBox::information(this, "Failed","Log In Failed\n unvalid username or password");


}
