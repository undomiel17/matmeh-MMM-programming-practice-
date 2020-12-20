#include "functions.h"
//считает окончательные приоритеты
template <typename T>
   void QueueP<T>::Priority()
{
    double diff, fractpart, intpart;
    for (int i=0; i<counte-1; i++){
  fractpart=0;
  intpart=0;
  fractpart = modf(start[i], &intpart);
  diff=start[i]-gettime[i];
 //теперь Р хранит начальный приоритет. Pfin приоритет на момент запуска
  P[i]=Pfin[i];
  Pfin[i]+=diff;
    }
}