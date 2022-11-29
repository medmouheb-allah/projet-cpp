#ifndef DIALOG_H
#define DIALOG_H
#include"employe.h"
#include <QDialog>
#include<QFileDialog>
#include<QTextStream>
#include<QTextDocument>
#include<QPrinter>
#include<QPainter>
#include <QTcpSocket>
#include<arduino.h>

namespace Ui
{
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void fill_form(int);

private slots :


        void on_bouton1_clicked();

        void on_pushButton_3_clicked();

        void on_b2_clicked();



        void on_affichage_employe_doubleClicked();


        void on_pushButton_2_clicked();


      //  void on_pushButton_8_clicked();

        void on_pushButton_5_clicked();


       // void on_lineEdit_8_textChanged(const QString &arg1);

        void on_pushButton_4_clicked();

       // void on_pushButton_7_clicked();

        void on_lineEdit_8_textChanged(const QString &arg1);

        void onSendButtonPressed();

       void onReadyRead() ;

        void on_pushButton_6_clicked();

        //void on_pushButton_9_clicked();

      //  void on_bouton1_3_clicked();

        void update_label() ;

    //    void on_bouton1_4_clicked();

        void on_pushButton_signal_clicked();

     //   void on_refreshButton_clicked() ;


private:
    Ui::Dialog *ui;
    employe em ;
    QTcpSocket socket;
    QByteArray data;
    Arduino A;
     QByteArray data2;
};

#endif // DIALOG_H
