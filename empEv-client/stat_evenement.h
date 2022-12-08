#ifndef STAT_EVENEMENT_H
#define STAT_EVENEMENT_H

#include <QDialog>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

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

QT_CHARTS_USE_NAMESPACE


namespace Ui {
class stat_evenement;
}

class stat_evenement : public QDialog
{
    Q_OBJECT

public:
    explicit stat_evenement(QWidget *parent = nullptr);
    ~stat_evenement();

    QChartView *chartView ;
    void choix_pie();

private:
    Ui::stat_evenement *ui;
};

#endif // STAT_EVENEMENT_H
