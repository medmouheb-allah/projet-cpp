#include "stat_evenement.h"
#include "ui_stat_evenement.h"

stat_evenement::stat_evenement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_evenement)
{
    ui->setupUi(this);
}

stat_evenement::~stat_evenement()
{
    delete ui;
}

void stat_evenement::choix_pie()
{
QSqlQuery q1,q2,q3,q4,q5;
qreal tot=0,c1=0,c2=0,c3=0,c4=0;

q1.prepare("SELECT * FROM EVENEMENT");
q1.exec();

q2.prepare("SELECT * FROM EVENEMENT WHERE TYPE='sportif'");
q2.exec();

q3.prepare("SELECT * FROM EVENEMENT WHERE TYPE='culturel'");
q3.exec();

q4.prepare("SELECT * FROM EVENEMENT WHERE TYPE='marriage' ");
q4.exec();

q5.prepare("SELECT * FROM EVENEMENT WHERE TYPE='congre' ");
q5.exec();

while (q1.next()){tot++;}
while (q2.next()){c1++;}
while (q3.next()){c2++;}
while (q4.next()){c3++;}
while (q5.next()){c4++;}

c1=(c1*100)/tot;
c2=(c2*100)/tot;
c3=(c3*100)/tot;
c4=(c4*100)/tot;


QString s1= QString::number(c1) ;
  s1= " = "+s1+"%"  ;

 QString s2= QString::number(c2) ;
 s2= " = "+s2+"%"  ;

 QString s3= QString::number(c3) ;
   s3= " = "+s3+"%"  ;

  QString s4= QString::number(c4) ;
  s4= " = "+s4+"%"  ;


  QString sportif="sportif" ;
  sportif=sportif+s1 ;
  QString culturel="culturel" ;
  culturel=culturel+s2 ;
  QString mariage="mariage" ;
  mariage=mariage+s3 ;
  QString congre="congre" ;
  congre=congre+s4;







QPieSeries *series = new QPieSeries();
series->append(sportif,c1);
series->append(culturel,c2);
series->append(mariage,c3);
series->append(congre,c4);



QChart *chart = new QChart();


chart->addSeries(series);
chart->legend()->show();



chartView = new QChartView(chart,ui->label_stat);
chartView->setRenderHint(QPainter::Antialiasing);
chartView->setMinimumSize(500,500);

chartView->show();
}

