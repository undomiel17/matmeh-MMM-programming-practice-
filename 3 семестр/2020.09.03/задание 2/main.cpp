// Решить задачу с помощью STL.  Эффективно смоделировать RAID 5, для k буферов размера n кБайт. 
//Технология использует контрольные суммы для восстановления данных в случае выхода из строя одного жёсткого диска.
//Нужно проделать тоже самое, только на буферах(массивах фиксированной длины).
//В моделировании нужно заполнить несколько буферов данных, по ним построить буфер контрольных сумм. 
//Затем выбрать случайным образом один из буферов, как исчезнувший. После восстановить исчезнувшие данные и сравнить восстановленные данные с настоящими.

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
template <typename T>
  class raid {
private:
   int number;
   int length;
   T ** buff;
public:
raid(int k, int n){
number=k+1; //äîï áóôåð äëÿ êîíòð ñóìì
length=n;
T**arr=new T*[number];
   for (int i=0; i<number; i++){
    arr[i]=new T[length];
   }
buff=arr;
for (int j=0; j<length;j++)
    buff[number-1][j]=0; //áóôåð ìû ñ÷èòàåì, à ýòî ñðàçó çàïîëíèì, ÷òîáû íå ïîïàë ìóñîð
}
~raid(){
for (int i=0; i<number; i++){
    delete [] buff[i];
}
delete [] buff;
    }
 void print (){
if (number==0) {
        cout<<"no data";
}
else
for (int i=0; i<number; i++){
    if (i!=number-1) cout<<"disk"<<i+1<<":"<<endl;
    else cout<<"control sum:"<<endl;
  for (int j=0; j<length; j++){
    cout<<"  "<<buff[i][j]<<" ";
  }
  cout<<endl;
 }
}
void read (){
    T x;
    int i=0;
    int j=0;
cout<<"data:"<<endl;
for (int step=0; step< (number-1)*length; step++ ){
    cin>>x;
    buff[i][j]=x;
    j++;
    if ((step+1)%length==0){
        i++; //ïåðåõîäèì íà ñëåäóþùèé äèñê
        j=0;
    }
  }
}
void control(){
for (int j=0; j<length;j++) {
    for (int i=0;i<number-1; i++) //èñêëþ÷àþùåå èëè ðàâíîñèëüíî îñòàòêó îò äåëåíèÿ íà 2 ñóììû ýëåìåíòîâ
      buff[number-1][j]+=buff[i][j];
    buff[number-1][j]=buff[number-1][j]%2;
    }
 }
void loss (int mistake ){
for (int i=0; i<length;i++)
    buff[mistake][i]=-1;
}
void recovery (int mistake){
    for (int j=0; j<length;j++) {
    for (int i=0;i<number; i++){
      if (i!=mistake) buff[mistake][j]+=buff[i][j];
    }
    buff[mistake][j]=(buff[mistake][j]+1)%2; //âîññòàíàâëèâàåì âû÷òåííóþ åäèíèöó
  }
}

};
int main()
{
     srand(time(0));
    int k,n;
    cout<<"number of buffers:"<<endl;
    cin>>k;
    cout<<"length of buffers:"<<endl;
    cin>>n;
    raid <int> raid5(k,n);
    raid5.read();
    //raid5.print();
    raid5.control();
    raid5.print();
    int mistake= rand()%n;
    raid5.loss(mistake);
    cout<<"data of disk "<<mistake+1<<" are lost"<<endl;
    raid5.print();
    raid5.recovery(mistake);
    raid5.print();
    return 0;
}
