#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "salle.h"
#include<QMessageBox>

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




void MainWindow::on_pushButton_ajouter_clicked()
{

    int num_salle;
    int capacite;
    QString localisation, style;
    QMessageBox messageBox;

    num_salle=ui->lineEdit_num_salle->text().toInt();
    capacite=ui->spinBox_capacite->text().toInt();
    localisation=ui->lineEdit_localisation->text();
    style=ui->lineEdit_style->text();


    Salle s(num_salle, capacite, localisation, style);
    bool test=s.ajouter();
    if (test)
    {
        messageBox.information(nullptr, messageBox.tr("Succès"), messageBox.tr("Ajout effectué"));
    }
     else
        messageBox.critical(nullptr, messageBox.tr("Echec"), messageBox.tr("Ajout non effectué"));

    ui->lineEdit_num_salle->clear();
    ui->spinBox_capacite->clear();
    ui->lineEdit_localisation->clear();
    ui->lineEdit_style->clear();
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int num_salle;
    QMessageBox messageBox;

    num_salle=ui->lineEdit_num_salle2->text().toInt();
    bool test=Stmp.supprimer(num_salle);

    if (test)
    {
        messageBox.information(nullptr, messageBox.tr("Succès"), messageBox.tr("Suppression effectuée"));
    }
     else
        messageBox.critical(nullptr, messageBox.tr("Echec"), messageBox.tr("Suppression non effectuée"));

    ui->lineEdit_num_salle2->clear();

}


void MainWindow::on_pushButton_afficher_clicked()
{

    ui->tableView_salle->setModel(Stmp.afficher());

}

void MainWindow::on_pushButton_modifier_clicked()
{
    int num_salle;
    int capacite;
    QString localisation, style;
    QMessageBox messageBox;

    num_salle=ui->lineEdit_num_salle->text().toInt();
    capacite=ui->spinBox_capacite->text().toInt();
    localisation=ui->lineEdit_localisation->text();
    style=ui->lineEdit_style->text();



    Salle s(num_salle, capacite, localisation, style);

    bool test=s.modifier();
    if (test)
    {
        messageBox.information(nullptr, messageBox.tr("Succès"), messageBox.tr("modification effectuée"));
    }
     else
        messageBox.critical(nullptr, messageBox.tr("Echec"), messageBox.tr("modification non effectuée"));

    ui->lineEdit_num_salle->clear();
    ui->spinBox_capacite->clear();
    ui->lineEdit_localisation->clear();
    ui->lineEdit_style->clear();

}


