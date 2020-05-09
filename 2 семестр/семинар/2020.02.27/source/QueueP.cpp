#include "functions.h"
template <typename T>
class QueueP
{
private:
  T* A;               //массив задач
  int* P;             //их приоритеты
  int counte;         //количество задач
  double* time;       //время на их выполнение
  double* start;      //начало выполнения
  double*gettime;     //время поступления
  double currenttime; //текущее время
  bool*flag;          //запуск

public:
  QueueP() { counte = 0; }
  QueueP(const QueueP& _Q)
  {
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
      counte = 0;
      return;
    }
    counte = _Q.counte;

    for (int i = 0; i < counte; i++){
      A[i] = _Q.A[i];
      P[i] = _Q.P[i];
      time[i]=_Q.time[i];
      start[i]=_Q.start[i];
      flag[i]=_Q.flag[i];
      gettime[i]=_Q.gettime;
    }
  }

  ~QueueP()
  {
    if (counte > 0)
    {
      delete[] A;
      delete[] P;
      delete[] time;
      delete[] start;
      delete[] flag;
      delete[] gettime;
    }
  }

  QueueP operator=(const QueueP& _Q);
  void Push(T item, int priority, double worktime, double get);
  T Pop();
  void Clear()
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
  }
  int Count()
  {
    return counte;
  }

  void Print(const char* objName);
};