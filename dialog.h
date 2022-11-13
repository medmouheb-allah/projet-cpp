#ifndef DIALOG_H
#define DIALOG_H
#include"employe.h"
#include <QDialog>
#include<QFileDialog>
#include<QTextStream>
#include<QTextDocument>
#include<Qprinter>
#include<Qpainter>

namespace Ui {
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


        void on_lineEdit_8_textChanged(const QString &arg1);

        void on_pushButton_4_clicked();

private:
    Ui::Dialog *ui;
    employe em ;
};

#endif // DIALOG_H
