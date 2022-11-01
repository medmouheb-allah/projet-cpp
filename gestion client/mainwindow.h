#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"client.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();



    void on_bouton_supp_clicked();

    void on_pushButton_clicked();

    //void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Client c;
};

#endif // MAINWINDOW_H
