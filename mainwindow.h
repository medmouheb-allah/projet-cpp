#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "salle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_modifier_clicked();

private:
    Ui::MainWindow *ui;

    Salle Stmp;
};
#endif // MAINWINDOW_H
