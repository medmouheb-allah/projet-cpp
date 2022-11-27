#include "piechartwidget.h"
#include "ui_piechartwidget.h"
#include <QPainter>
#include"QSqlQuery"
#include <QString>

PieChartWidget::PieChartWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PieChartWidget)
{
    ui->setupUi(this);
}

PieChartWidget::~PieChartWidget()
{
    delete ui;
}

void PieChartWidget::paintEvent(QPaintEvent *)
{
    QSqlQuery q1,q2,q3;
    int total,f,h,totalf,totalh;

    q1.prepare("select count(ID_CLIENT)from CLIENT_")  ;
    if(q1.exec())
    {
        while(q1.next())
        {
         total = q1.value(0).toInt();
        }
    }
    q2.prepare("select count(ID_CLIENT)from CLIENT_ where genre = 'Femme' ")  ;
    if(q2.exec())
    {
        while(q2.next())
        {
         f =q2.value(0).toInt() ;
         ui->femme->setText(q2.value(0).toString());
        }
    }
    q3.prepare("select count(ID_CLIENT)from CLIENT_ where genre = 'Homme' ")  ;
    if(q3.exec())
    {
        while(q3.next())
        {
         h = q3.value(0).toInt();
          ui->homme->setText(q3.value(0).toString());

        }
    }


    QPainter painter(this);
    QRectF size =QRectF(210.0, 90.0, 421.0, 421.0);
    totalf=(f*360/total);
    totalh=(h*360/total);
    painter.setBrush(QColor(133, 79, 8));
    painter.drawPie(size, 0 ,totalf*16);
    painter.setBrush(QColor(234, 210, 191));
    painter.drawPie(size,totalf*16,totalh*16);
}
