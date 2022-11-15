#include "event.h"

Event::Event()
{
cod=0;
nom="";
descrp="";
typ="";
date="" ;

}
Event::Event (int cod , QString nom , QString descrp , QString typ , QString date )
{
   this->cod=cod ;
    this->nom=nom;
    this->descrp=descrp;
    this->typ=typ;
    this->date=date;
}
int Event::getcod(){return cod;}
QString Event::getnom(){return nom ;}
QString Event::getdescrp(){return descrp;}
QString Event::gettyp(){return typ;}
QString Event::getdate(){return date;}
void Event::setcod(int cod ){this->cod=cod;}
void Event::setnom(QString nom){this->nom=nom;}
void Event::setdescrp(QString descrp){this->descrp=descrp ;}
void Event::settyp(QString typ){this->typ=typ;}
void Event::setdate(QString date){this->date=date;}
