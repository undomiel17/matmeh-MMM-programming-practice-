#include "functions.h"
template <typename T>
class QueueP
{
private:
  T* A;               //массив задач
  int* P;             //их приоритеты для построения очереди
  int*Pfin;           //обновляется к старту работы
  int counte;         //количество задач
  double* time;       //время на их выполнение
  double* start;      //начало выполнения
  double*gettime;     //время поступления
  double currenttime; //текущее время
  bool*flag;          //запуск
  void print()
  {
      // cout << "start time: " << objName << endl;
      cout<<endl;
  for (int i = 0; i < counte-1; i++){
//1440=24*60. перекидывает на следующий день
    gettime[i]=gettime[i]-24*60*(int(gettime[i])/1440);
    start[i]=start[i]-24*60*(int(start[i])/1440);
    cout <<"Task number: "<<A[i]<<" was received in ";
    cout << (int(gettime[i]/60)) <<".";
    if (fmod(gettime[i],60)<10) cout<<"0"<<int(fmod(gettime[i],60)); //на случай очень маленьких чисел
    else cout<<fmod(gettime[i],60);
    cout <<" with priority: "<< P[i] << " started in  ";
    //start[i]-=24.00*int(start[i]/24);
    //cout<<" and started in ";
    cout << int(start[i]/60) <<".";
    if (fmod(start[i],60)<10) cout<<"0"<<int(fmod(start[i],60)); //на случай очень маленьких чисел6
    else cout<<fmod(start[i],60);
    cout<<" with current priority "<<Pfin[i]<<". ";
    cout<<" Lead time: "<<time[i]<<endl;
  }
  cout << endl;
  }

  QueueP(const QueueP& _Q)
  {
    try {
      A = new T[_Q.counte];
      P = new int[_Q.counte];
      Pfin = new int[_Q.counte];
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
      Pfin[i] = _Q.Pfin[i];
      time[i]=_Q.time[i];
      start[i]=_Q.start[i];
      flag[i]=_Q.flag[i];
      gettime[i]=_Q.gettime;
    }
  }
  QueueP operator=(const QueueP& _Q)
{
  Clear();
  try {
    A = new T[_Q.counte];
    P = new int[_Q.counte];
    Pfin = new int[_Q.counte];
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
    Pfin[i] = _Q.Pfin[i];
    time[i]=_Q.time[i];
    start[i]=_Q.start[i];
    flag[i]=_Q.flag[i];
    gettime[i]=_Q.gettime[i];
  }
  return *this;
}
public:

   QueueP() { counte = 0; }

  ~QueueP()
  {

   Priority();
   print();
   Clear();
   counte=0;
  }
 // QueueP operator=(const QueueP& _Q);
  void Push(T item, int priority, double worktime, double get);
  T Pop();
  void Clear()
  {
    if (counte > 0)
    {
      delete[] A;
      delete[] P;
      delete[] Pfin;
      delete[] time;
      delete[] start;
      delete[] flag;
      delete[] gettime;
    }
  }
  void Priority();
  int Count()
  {
    return counte;
  }

  //void Print(const char* objName);
};
