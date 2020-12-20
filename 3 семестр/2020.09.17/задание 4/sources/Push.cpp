#include "functions.h"
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
  get=intpart*60+fractpart*100; //�������������� � ������
  if (counte==0)
        currenttime=get;//������ ������ ��������� �����
 //���� ��������������
 for (int i=0;i<counte;i++) if ((start[i]<get)&&(!flag[i])) {
        flag[i]=true;
        break;
 }
 for (int i=1; i<counte; i++) if (!flag[i]) P[i]=P[i]+abs(get-currenttime);//������ ������ ��������� ������ ������ ���������� �� 1 �� ����������� ������
  currenttime=get;//����������� �����
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
  for (int i=0;i<counte; i++)//���� ������ � ������� ������, ����������� ������������
  if (gettime[i]==get) {
    same=i;
    break;
  }
  if (counte == 0)
    pos = 0;
  else
  {
    if (same!=-1){ //���� ���� ������������, �� ���������� ������ ��
        pos=same;
        while (pos < counte)
       {
            if (P[pos]<priority) break;
      else pos++;
      }
    }
    if (same==-1){
    pos = 0;
    while (pos < counte) //���� ����� ����� ��������� � ������� �����������
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
  } else{ //������ ������ ��������� �����
    if ((start[pos-1]+time[pos-1]) < get) {
            start2[pos]=get;// ���� ���������� ���������� ������, �� ����� ����������
            flag2[pos]=false;}
    else {start2[pos]=start2[pos-1]+time2[pos-1];
    flag2[pos]=false;
    } //����� ���������� ����� ����� ��������� ����������
  }
  for (int i = pos + 1; i < counte + 1; i++)
  {
    A2[i] = A[i - 1];
    P2[i] = P[i - 1];
    Pfin2[i] = Pfin[i - 1];
    time2[i]=time[i-1];
    flag2[i]=flag[i-1];
    gettime2[i]=gettime[i-1];
    if ((start2[i-1]+time2[i-1])<start[i-1]) start2[i]=start[i-1]; //���� ����� ���������� ������������� ������ ������ �������, �� ������ ����������
    else start2[i]=start2[i-1]+time2[i-1]; //����� ������ ����� ����� ����������
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

