#include "functions.h"
template <typename T>
QueueP<T> QueueP<T>::operator=(const QueueP& _Q)
{
  if (counte > 0)
  {
    delete[] A;
    delete[] P;
    delete[] time;
    delete[] start;
    delete[] flag;
    delete[] gettime;
    counte = 0;
  }

  try {
    A = new T[_Q.counte];
    P = new int[_Q.counte];
    time=new double[_Q.counte];
    start=new double[_Q.counte];
    flag=new bool[_Q.counte];
    gettime=new double[_Q.counte];
  }
  catch (bad_alloc e)
  {
    cout << e.what() << endl;
    return *this;
  }
  counte = _Q.counte;
  for (int i = 0; i < counte; i++)
  {
    A[i] = _Q.A[i];
    P[i] = _Q.P[i];
    time[i]=_Q.time[i];
    start[i]=_Q.start[i];
    flag[i]=_Q.flag[i];
    gettime[i]=_Q.gettime[i];
  }
  return *this;
}
