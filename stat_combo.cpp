#include "stat_combo.h"
#include "ui_stat_combo.h"

stat_combo::stat_combo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_combo)
{
    ui->setupUi(this);
}

stat_combo::~stat_combo()
{
    delete ui;
}

//pie chart
    void stat_combo::choix_pie()
    {
    QSqlQuery q1,q2,q3;
    qreal tot=0,c1=0,c2=0;

    q1.prepare("SELECT * FROM EMPLOYE");
    q1.exec();

    q2.prepare("SELECT * FROM EMPLOYE WHERE GENRE='Homme'");
    q2.exec();

    q3.prepare("SELECT * FROM EMPLOYE WHERE GENRE='Femme'");
    q3.exec();



    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}


    c1=(c1*100)/tot;
    c2=(c2*100)/tot;

    QString c3= QString::number(c1) ;
  c3= " = "+c3+"%"  ;

 QString c4= QString::number(c2) ;
 c4= " = "+c4+"%"  ;

  QString HOMME="Homme" ;
  HOMME=HOMME+c3 ;

  QString FEMME="Femme" ;
  FEMME=FEMME+c4 ;

    // Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
   // for(auto slice : series->slices())
     //   slice->setLabel(QString("%1%").arg(100*slice->percentage(), 0, 'f', 1));
    series->append(HOMME  ,c1);
    series->append(FEMME,c2);




    QChart *chart = new QChart();

    chart->addSeries(series);
    chart->legend()->show();


    chartView = new QChartView(chart,ui->graphicsView);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400,400);


    chartView->show();
    }
