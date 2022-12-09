#ifndef EVENT_H
#define EVENT_H

#include <QString>
class Event
{
public:
    Event();
    Event (int , QString,QString,QString,QString);
    int getcod();
    QString getnom();
    QString getdescrp();
    QString gettyp();
    QString getdate();
    void setcod(int);
    void setnom(QString);
    void setdescrp(QString);
    void settyp(QString);
    void setdate(QString);
    
       
private:
    int cod;
    QString nom , descrp , typ, date; 
};

#endif // EVENT_H
