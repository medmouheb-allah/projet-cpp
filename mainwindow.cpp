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
    //int id=ui->lin->text().toInt() ;
    //QString





            QSqlQuery qry;
                QString  USERNAME=ui->lineEdit->text();
                QString  MDP=ui->lineEdit_2->text();

                   if(qry.exec("SELECT PRENOM_EMP, ID_EMP FROM EMPLOYE WHERE PRENOM_EMP=\'"+ USERNAME +"\' AND ID_EMP=\'" + MDP + "\'"))
                   {
                       if(qry.next())
                       {
                           Dialog *MainWindow=new Dialog(this);
                           MainWindow->show();
                           QMessageBox::information(this, "Success","LOG In Success");
                           qry.exec();



                       }else
                       {

                           QMessageBox::information(this, "Failed","Log In Failed\n unvalid username or password");

                                   }

                       }
}
