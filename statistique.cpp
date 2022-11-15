#include "statistique.h"
#include "ui_statistique.h"

#include <iostream>

using namespace std;

statistique::statistique(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}


int statistique::Stat_partie1()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from SALLE_EVENEMENT where capacite BETWEEN '1' AND '30'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}

int statistique::Stat_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from SALLE_EVENEMENT where capacite BETWEEN '31' AND '50'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}

int statistique::Stat_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from SALLE_EVENEMENT where capacite BETWEEN '51' AND '100'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}



void statistique::paintEvent(QPaintEvent *)
{

    int a=Stat_partie1();
    int b=Stat_partie2();
    int c=Stat_partie3();

        float s1= a*100 ;
        float s2=b*100;
        float nb = a+b+c ;

        float q1 = s1/nb ;
        float q2 =s2/nb;

        float x = (q1*360)/100 ;

        float y = (q2*360)/100;

        float z =360-(x+y) ;


    QPainter painter(this);
    QRectF size=QRectF(100,100,this->width()-500,this->width()-500);

    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,16*x);
    ui->label_1->setText("blue: Capacite Salle 1-30") ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,16*x,16*y);
    ui->label_2->setText("green: Capacite Salle 31-50") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*(y+x),16*z);
    ui->label_3->setText("red: Capacite Salle 51-100") ;

    ui->stat1->setNum(q1) ;
    ui->stat2->setNum(q2) ;
    ui->stat3->setNum(100-q1-q2) ;

}

