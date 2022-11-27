#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include <QDialog>

namespace Ui {
class PieChartWidget;
}

class PieChartWidget : public QDialog
{
    Q_OBJECT

public:
    explicit PieChartWidget(QWidget *parent = 0);
    ~PieChartWidget();
protected:
        void paintEvent(QPaintEvent *);
private:
    Ui::PieChartWidget *ui;
};

#endif // PIECHARTWIDGET_H
