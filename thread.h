#ifndef THREAD_H
#define THREAD_H

#include "regulateur_temperature.h"

#include <QThread>

class MonThread : public Qthread
{
 Q_OBJECT
public:

    void run()
    {
      Regulateur_temperature  A;
      A.regul_temp() ;
    }




};





#endif // THREAD_H
