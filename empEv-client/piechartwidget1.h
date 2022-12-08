#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include <QDialog>
#include <QPainter>
#include"QSqlQuery"
#include <QString>

namespace Ui {
class PieChartWidget;
}

class PieChartWidget : public QDialog
{
    Q_OBJECT

public:
    explicit PieChartWidget(QWidget *parent = nullptr);
    ~PieChartWidget();
void paintEvent(QPaintEvent *);
private:
    Ui::PieChartWidget *ui;
};

#endif // PIECHARTWIDGET_H
