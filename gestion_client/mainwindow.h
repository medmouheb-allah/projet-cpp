#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"client.h"
#include"statistique.h"
#include"pie.h"
#include "piechartwidget.h"
#include "exportexcelobject.h"
#include <QMainWindow>
#include "arduino.h"


namespace Ui {
class MainWindow;
}
class QMediaPlayer;
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

    void on_pushButton_3_clicked();
    void update_label();




    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_triii_currentIndexChanged(const QString &arg1);

    void on_rechercher_clicked();



    void on_excelll_clicked();



    void addToHistory(QString action,QString type,QString id);
    QSqlQueryModel*afficherHistorique();
    bool historyDelete();

    void on_history_activated(const QString &arg1);

    void on_del_clicked();

    void on_deleteee_activated(const QString &arg1);

    void on_listView_indexesMoved(const QModelIndexList &indexes);

    void on_rech_textChanged(const QString &arg1);






    void on_son_clicked();

    void on_start_clicked();

    void on_stop_clicked();

    void on_mute_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_message_clicked();

    void on_excelll_2_textChanged(const QString &arg1);

    void on_ouvrir_clicked();

    void on_ouvrir_2_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    Client c;
     QMediaPlayer *mMediaPlayer;
      arduino a;

      QByteArray data;
      QByteArray data3;
      QByteArray data2;

};

#endif // MAINWINDOW_H
