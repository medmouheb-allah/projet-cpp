#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"dialog.h"
#include"authentification.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "interface.h"
#include "ui_interface.h"
#include "event_workspace.h"
#include "client_workspace.h"
#include "salle_workspace.h"
#include "fournisseur_workspace.h"

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase database;
      login L;

};
#endif // MAINWINDOW_H
