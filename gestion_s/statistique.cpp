#include "statistique.h"
#include "ui_statistique.h"
#include "qcustomplot.h"
#include"QSqlRecord"
#include"QSqlQuery"
#include <QPainter>


statistique::statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
    QSqlQuery q2;


    q2.prepare("select count(ID_CLIENT)from CLIENT_")  ;
    if(q2.exec())
    {
        while(q2.next())
        {
        ui->nb->setText(q2.value(0).toString());
        }
    }


            // set dark background gradient:
            QLinearGradient gradient(0, 0, 0, 400);
            gradient.setColorAt(0, QColor(133, 79, 8));
            gradient.setColorAt(0.38, QColor(115, 67, 5));
            gradient.setColorAt(1, QColor(130, 85, 26));
            ui->customPlot->setBackground(QBrush(gradient));

            // create empty bar chart objects:
            QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);

            regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders


            // set names and colors:

            regen->setName("Nombre de clients par tranche d'âge");
            regen->setPen(QPen(QColor(234, 210, 191).lighter(130)));
            regen->setBrush(QColor(234, 210, 191));



            // prepare x axis with country labels:
            QVector<double> ticks;
            QVector<QString> labels;
            QVector<double> regenData;


            ticks << 1 << 2 << 3 << 4 << 5 ;
            QSqlQuery q;
            q.prepare("select count(ID_CLIENT), age from CLIENT_ group by age order by count(ID_CLIENT)  DESC")  ;

            if(q.exec()){
            while (q.next()) {
            labels << q.value(1).toString();
            regenData   << q.value(0).toInt();;
            }}
            QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
            textTicker->addTicks(ticks, labels);
            ui->customPlot->xAxis->setTicker(textTicker);

            ui->customPlot->xAxis->setTickLabelRotation(60);

            ui->customPlot->xAxis->setTickLength(0, 4);
            ui->customPlot->xAxis->setRange(0, 5);
            ui->customPlot->xAxis->setLabel("Age");

            ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
            ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
            ui->customPlot->xAxis->grid()->setVisible(true);
            ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
            ui->customPlot->xAxis->setTickLabelColor(Qt::white);
            ui->customPlot->xAxis->setLabelColor(Qt::white);

            // prepare y axis:
            ui->customPlot->yAxis->setRange(0, 8);
            ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
            ui->customPlot->yAxis->setLabel("Nombre clients");
            ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
            ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
            ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
            ui->customPlot->yAxis->grid()->setSubGridVisible(true);
            ui->customPlot->yAxis->setTickLabelColor(Qt::white);
            ui->customPlot->yAxis->setLabelColor(Qt::white);
            ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
            ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

            // Add data:


            regen->setData(ticks, regenData);

            // setup legend:
            ui->customPlot->legend->setVisible(true);
            ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
            ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
            ui->customPlot->legend->setBorderPen(Qt::NoPen);
            QFont legendFont = font();
            legendFont.setPointSize(10);
            ui->customPlot->legend->setFont(legendFont);
            ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}

statistique::~statistique()
{
    delete ui;
}

void statistique::makePolt()
{
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));

    QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    regen->setAntialiased(false);
    regen->setStackingGap(1);
    regen->setName("Nombre de clients par genre");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));


    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 ;
    labels << "Tunisie" << "Autres Pays" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->setRange(0, 8);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0,50);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> regenData;

    QSqlQuery query1("select count(ID_CLIENT)  from CLIENT_ where genre='Femme' ");
    while (query1.next()) {
        int  nbr_faute=0;
                           int  nbr_fautee = query1.value(0).toInt();
                           QSqlQuery query2("select count(ID_CLIENT)  from CLIENT_ where genre!='Femme' ");
                           while (query2.next()) {
                                                  nbr_faute = query2.value(0).toInt();
                                                  break;
                                                    }
                           regenData<< nbr_fautee<< nbr_faute;
                           break;
                             }
    regen->setData(ticks, regenData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


}
