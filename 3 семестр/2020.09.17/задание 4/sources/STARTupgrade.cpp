#include "functions.h"
//������ � ��������� �������� ���������� � �����������
//��������������, ��� ��������� � ��������������� �������
//� ������� time �� ����, ��� ������ ������� (diff)
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
//���� ������������� ����� ��� (����������� ������� ����� ������ 60)
            if ((time-int (time)+diff)>0.6 ) time=time+1.0+diff-0.6;
                else
            {if((time-int (time)+diff)==0.6) time=double(int(time)+1.0);

            else time+=diff;
            }
    }

Q1.Push(i+1, priority, work,time);

}
//������� ������, ����� ��������� ��������� ���������
Q1.Push (0, 0, 0, time);
}