#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include<QDebug>
#include "connection.h"
#include<QMessageBox>
#include <iostream>

#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QTextDocument>

#include <QMainWindow>
#include "salle.h"
#include "image.h"
#include "qrcodegen.h"
#include <QGraphicsSvgItem>
#include <QFileDialog>
#include <QStandardPaths>

#include "statistique.h"
#include "ui_statistique.h"

#include "regulateur_temperature.h"
#include "ui_regulateur_temperature.h"

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

    void on_comboBox_modifier_currentIndexChanged(const QString &arg1);

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_qr_code_clicked() ;

    void on_trier_clicked();

    void on_reset_clicked() ;

    void on_rechercher_bouton_clicked();


    void on_load_ajouter_clicked();


    void on_load_modifier_clicked();


    void on_consulter_clicked();

    void on_statistique_clicked();

    void on_PDF_clicked();


    void on_comboBox_supprimer_currentIndexChanged(const QString &arg1);





    void on_Regulateur_temp_clicked() ;

private:
    Ui::MainWindow *ui;

    Salle Stmp , S;

};


#endif // MAINWINDOW_H
