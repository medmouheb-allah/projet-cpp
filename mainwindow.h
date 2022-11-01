#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>


#include "evenement.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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






private:
    Ui::MainWindow *ui;
    int selected=0,search_col=-1;
    QWidget* widget;

};
#endif // MAINWINDOW_H
