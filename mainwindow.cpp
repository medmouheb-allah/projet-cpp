#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"interface.h"
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


void MainWindow::on_pb_fournisseur_clicked()

    {
        Interface inter;
        inter.setModal(true);
        inter.exec();

    }

