#ifndef SALLE_WORKSPACE_H
#define SALLE_WORKSPACE_H

#include <QApplication>
#include<QDebug>
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
#include "image_salle.h"
#include "qrcodegen_salle.h"
#include <QGraphicsSvgItem>
#include <QFileDialog>
#include <QStandardPaths>

#include "statistique_salle.h"
#include "ui_statistique_salle.h"

#include "regulateur_temperature_salle.h"
#include "ui_regulateur_temperature_salle.h"

QT_BEGIN_NAMESPACE
namespace Ui
{ class salle_workspace;
}
QT_END_NAMESPACE

class salle_workspace : public QMainWindow
{
    Q_OBJECT

public:
    salle_workspace(QWidget *parent = nullptr);
    ~salle_workspace();

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

    void on_pushButton_6_clicked();

private:

    Ui::salle_workspace *ui;

    Salle Stmp , S;

};


#endif // SALLE_WORKSPACE_H
