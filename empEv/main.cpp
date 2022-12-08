#include "mainwindow.h"
#include<QMessageBox>
#include <QApplication>
#include"connection.h"

int main(int argc, char *argv[])
{
    connection c ;
    bool test ;
    test= c.createconnection() ;

    QApplication a(argc, argv);
    MainWindow w;
    if (test)
    {

    w.show();
    QMessageBox::information(nullptr,QObject::tr("database is open"),QObject::tr("connection successful.\n""click cancel to exit"),QMessageBox::Cancel) ;
    }
    else
    {
   QMessageBox::critical(nullptr,QObject::tr("database isn't open"),QObject::tr("connection failed.\n""click cancel to exit"),QMessageBox::Cancel) ;
    }


    return a.exec();

}
