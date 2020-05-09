#include "functions.h"
template <typename T>
T QueueP<T>::Pop()
{
  if (counte == 0)
    return 0;

  T* A2;
  int* P2;
  double*time2;
  double*start2;
  double*gettime2;
  bool*flag2;
  try {
    A2 = new T[counte - 1];
    P2 = new int[counte - 1];
    time2=new double[counte-1];
    start2=new double[counte-1];
    flag2=new bool[counte-1];
    gettime2=new double[counte-1];
  }
  catch (bad_alloc e)
  {
    cout << e.what() << endl;
    return 0;
  }

  T item;
  item = A[0];

  for (int i = 0; i < counte - 1; i++)
  {
    A2[i] = A[i + 1];
    P2[i] = P[i + 1];
    time2[i]=time[i+1];
    start2[i]=start[i+1];
    flag2[i]=flag[i+1];
    gettime2[i]=gettime[i+1];
  }

  if (counte > 0)
  {
    delete[] A;
    delete[] P;
    delete[] time;
    delete[] start;
    delete[] flag;
    delete[] gettime;
  }
  counte--;
  A = A2;
  P = P2;
  time=time2;
  start=start2;
  flag=flag2;
  gettime=gettime2;
  return item;
}
