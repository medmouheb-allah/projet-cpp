#ifndef EVENT_WORKSPACE_H
#define EVENT_WORKSPACE_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include<QFileDialog>

#include "evenement.h"
#include "stat_combo.h"
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QProcess>
#include "arduino_parking.h"

namespace Ui {
class event_workspace;
}

class event_workspace : public QMainWindow
{
    Q_OBJECT

public:
    explicit event_workspace(QWidget *parent = nullptr);
    ~event_workspace();
    evenement tmp;
    QSortFilterProxyModel *proxy;

    void show_table();

    QString get_date() const ;
    QString nom() const ;
    QString type() const;
    QString emp() const ;
    QString client() const ;
    QString salle() const;
    QString description() const ;
    int code() const;

    void fill_form(int);

private slots:
    void on_add_clicked();

    void on_update_clicked();

    void on_delete_2_clicked();

    void on_tableau_doubleClicked(const QModelIndex &index);

    void on_recherche_textChanged(const QString &arg1);


    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);


    void on_pushButton_2_clicked();

    void update_label();

    void on_calander_clicked();

    void on_pushButton_3_clicked();

    void on_ouvrir_clicked();

    void on_ouvrir_2_clicked();

    void on_pushButton_6_clicked();

private:
    QByteArray data;
    QByteArray data2;
    Ui::event_workspace *ui;
    int selected=0,search_col=-1;
    QString proj_path="C:/Users/user/Desktop/evenement_oumaima";
    stat_combo *s;
    QWidget* widget;
    arduino_parking a;
     evenement ev;
};

#endif // EVENT_WORKSPACE_H
