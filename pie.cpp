#include "pie.h"
#include "ui_pie.h"
/*#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>*/
#include"QSqlRecord"
#include"QSqlQuery"
#include <QPainter>

pie::pie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pie)
{
    ui->setupUi(this);
    QPainter painter(this);
    QRectF size =QRectF(10,10,this->width()-10, this->width()-10);
    painter.setBrush(Qt::red);
    painter.drawPie(size, 0,90*16);
    painter.setBrush(Qt::blue);
    painter.drawPie(size,90*16,270*16);

}

pie::~pie()
{
    delete ui;
}
