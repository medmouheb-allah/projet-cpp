#ifndef statistique_salle_salle_H
#define statistique_salle_salle_H

#include <QDialog>
#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>

#include <QDialog>
#include <QWidget>


namespace Ui {
class statistique_salle;
}

class statistique_salle : public QDialog
{
    Q_OBJECT

public:
    explicit statistique_salle(QDialog *parent = nullptr);
    ~statistique_salle();

    int Stat_partie1() ;
    int Stat_partie2() ;
    int Stat_partie3() ;

    void paintEvent(QPaintEvent *) ;


private:
    Ui::statistique_salle *ui;
};

#endif // statistique_salle_salle_H
