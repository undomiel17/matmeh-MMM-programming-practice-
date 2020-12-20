#include <iostream>
#include <new>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

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




template <typename T>
void QueueP<T>::Push(T item, int priority, double worktime, double get)
{
  T* A2;
  int* P2;
  int* Pfin2;
  double*time2;
  double*start2;
  bool*flag2;
  double*gettime2;
  double fractpart, intpart;
  fractpart = modf(get, &intpart);
  get=intpart*60+fractpart*100; //преобразование в минуты
  if (counte==0)
        currenttime=get;//первая задача запускает время
 //если неодновременно
 for (int i=0;i<counte;i++) if ((start[i]<get)&&(!flag[i])) {
        flag[i]=true;
        break;
 }
 for (int i=1; i<counte; i++) if (!flag[i]) P[i]=P[i]+abs(get-currenttime);//каждую минуту приоритет каждой задачи повышается на 1 за исключением первой
  currenttime=get;//обновляется время
  //cout<<gettime<<currenttime; //<<worktime;

  try {
    A2 = (T*)new T[counte + 1];
    P2 = (int*)new int[counte + 1];
    Pfin2 = (int*)new int[counte + 1];
    time2=(double*)new double[counte+1];
    start2=(double*)new double[counte+1];
    flag2=(bool*)new bool[counte+1];
    gettime2=(double*)new double[counte+1];
  }
  catch (bad_alloc e)
  {
    cout <<e.what() << endl;
    return;
  }
  int pos;
  int same=-1;
  for (int i=0;i<counte; i++)//ищет первую в очереди задачу, поступившую одновременно
  if (gettime[i]==get) {
    same=i;
    break;
  }
  if (counte == 0)
    pos = 0;
  else
  {
    if (same!=-1){ //если были параллельные, то сравнивает только их
        pos=same;
        while (pos < counte)
       {
            if (P[pos]<priority) break;
      else pos++;
      }
    }
    if (same==-1){
    pos = 0;
    while (pos < counte) //ищет место после неначатых с большим приоритетом
    {

      if (flag[pos]==true) pos++;
      else {
            if (P[pos]<priority) break;
      else pos++;
      }
    }
   }
  }


  for (int i = 0; i < pos; i++)
  {
    A2[i] = A[i];
    P2[i] = P[i];
    Pfin2[i] = Pfin[i];
    time2[i]=time[i];
    start2[i]=start[i];
    flag2[i]=flag[i];
    gettime2[i]=gettime[i];
  }
  A2[pos] = item;
  P2[pos] = priority;
  Pfin2[pos] = priority;
  time2[pos]=worktime;
  gettime2[pos]=get;
  if (counte==0) {start2[pos]=get;
  flag2[pos]=true;
  } else{ //первая задача запускает время
    if ((start[pos-1]+time[pos-1]) < get) {
            start2[pos]=get;// если предыдущая закончится раньше, то время сохранится
            flag2[pos]=false;}
    else {start2[pos]=start2[pos-1]+time2[pos-1];
    flag2[pos]=false;
    } //иначе запустится сразу после окончания предыдущей
  }
  for (int i = pos + 1; i < counte + 1; i++)
  {
    A2[i] = A[i - 1];
    P2[i] = P[i - 1];
    Pfin2[i] = Pfin[i - 1];
    time2[i]=time[i-1];
    flag2[i]=flag[i-1];
    gettime2[i]=gettime[i-1];
    if ((start2[i-1]+time2[i-1])<start[i-1]) start2[i]=start[i-1]; //если новая прерыдущая заканчивается раньше начала текущей, то начало сохранится
    else start2[i]=start2[i-1]+time2[i-1]; //иначе начало после конца предыдущей
  }
  Clear();
  A = A2;
  P = P2;
  Pfin=Pfin2;
  time=time2;
  start=start2;
  flag=flag2;
  gettime=gettime2;
  counte++;
}

template <typename T>
T QueueP<T>::Pop()
{
  if (counte == 0)
    return 0;

  T* A2;
  int* P2;
  int* Pfin2;
  double*time2;
  double*start2;
  double*gettime2;
  bool*flag2;
  try {
    A2 = new T[counte - 1];
    P2 = new int[counte - 1];
    Pfin2 = new int[counte - 1];
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
    Pfin2[i] = Pfin[i + 1];
    time2[i]=time[i+1];
    start2[i]=start[i+1];
    flag2[i]=flag[i+1];
    gettime2[i]=gettime[i+1];
  }

  Clear();
  counte--;
  A = A2;
  P = P2;
  Pfin=Pfin2;
  time=time2;
  start=start2;
  flag=flag2;
  gettime=gettime2;
  return item;
}

/*template <typename T>
void QueueP<T>::Print(const char* objName)
{
  for (int i = 0; i < counte-1; i++){
    cout <<"Task number: "<< A[i] << " starts in  " << int(start[i]/60) <<".";
    if (fmod(start[i],60)<10) cout<<"0"<<fmod(start[i],60);
    else cout<<fmod(start[i],60)<<" ";
    cout<<"with current priority "<<Pfin[i]<<". ";
    cout<<" Lead time: "<<time[i]<<endl;
  }
  cout << endl;
  cout << "---------------" << endl;
}*/

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
//очередь определена внутри процесса. когда останавливается "старт"
//заканчивается область видимости очереди, вызывается деструктор
//который выводит данные на консоль
void start()
{
   QueueP <int> Q1;
Q1.Push(1, 1, 3, 12.21);
Q1.Push(2, 2, 27, 12.21);
Q1.Push(3, 3, 5, 12.21);
Q1.Push(4, 6, 27, 12.21);
Q1.Push(5, 5, 27, 12.21);
Q1.Push(6, 4, 27, 12.40);
Q1.Push(0, 0, 0, 12.40);
}
//задачи с рандомным временем выполнения и приоритетом
//предполагается, что поступают в хронологическом порядке
//с момента time не реже, чем каждые полчаса (diff)
void START()
{
   int number;
   int priority=0;
   double work=0.0;
   double diff=0.0;
   double time=rand()%24+0.01*(rand()%60);
   double timewrite=0.0;
   cout<<"Write number of tasks: ";
   cin>>number;
   cout<<endl;
  // cout<<"Start time: "<<time<<endl;
   QueueP <int> Q1;
for (int i=0; i<number; i++){
    priority=rand()%10+1;
    work=rand()%30+1.0;
    if (i!=0) {
            diff=0.01*(rand()%30);
//если перескакивает через час (равносильно дробной части больше 60)
            if ((time-int (time)+diff)>0.6 ) time=time+1.0+diff-0.6;
                else
            {if((time-int (time)+diff)==0.6) time=double(int(time)+1.0);

            else time+=diff;
            }
    }

Q1.Push(i+1, priority, work,time);

}
//нулевая задача, чтобы обновился приоритет последней
Q1.Push (0, 0, 0, time);
}
int main()
{
setlocale(LC_ALL, "Russian");
srand(time(0));
cout<<"_______start_______"<<endl;
start();
START();
cout<<"_______end_______"<<endl;
  return 0;
}
