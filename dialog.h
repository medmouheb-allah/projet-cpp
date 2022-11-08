#ifndef DIALOG_H
#define DIALOG_H
#include"employe.h"
#include <QDialog>

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


        void on_pushButton_8_clicked();

private:
    Ui::Dialog *ui;
    employe em ;
};

#endif // DIALOG_H
