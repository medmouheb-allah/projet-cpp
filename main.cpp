#include "mainwindow.h"

#include <QApplication>

#include<QDebug>

#include "connection.h"

#include<QMessageBox>

#include <iostream>

using namespace std;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QMessageBox messageBox;
    Connection db;
    bool db_test = db.createConnection();
    if (db_test)
    {
        w.show();
        messageBox.information(nullptr, messageBox.tr("BD ouverte"), messageBox.tr("la connection à la BD a réussie")) ;
    }
     else
        messageBox.critical(nullptr, messageBox.tr("BD non ouverte"), messageBox.tr("la connection à la BD a échouée"));
        //return 0;

    return a.exec();
}
