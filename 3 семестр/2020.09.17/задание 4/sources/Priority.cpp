#include "functions.h"
//������� ������������� ����������
template <typename T>
   void QueueP<T>::Priority()
{
    double diff, fractpart, intpart;
    for (int i=0; i<counte-1; i++){
  fractpart=0;
  intpart=0;
  fractpart = modf(start[i], &intpart);
  diff=start[i]-gettime[i];
 //������ � ������ ��������� ���������. Pfin ��������� �� ������ �������
  P[i]=Pfin[i];
  Pfin[i]+=diff;
    }
}