#include "functions.h"
template <typename T>
  class raid {
private:
   int number;
   int length;
   T ** buff;
public:
raid(int k, int n){
number=k+1; //доп буфер для контр сумм
length=n;
T**arr=new T*[number];
   for (int i=0; i<number; i++){
    arr[i]=new T[length];
   }
buff=arr;
for (int j=0; j<length;j++)
    buff[number-1][j]=0; //буфер мы считаем, а это сразу заполним, чтобы не попал мусор
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
        i++; //переходим на следующий диск
        j=0;
    }
  }
}
void control(){
for (int j=0; j<length;j++) {
    for (int i=0;i<number-1; i++) //исключающее или равносильно остатку от деления на 2 суммы элементов
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
    buff[mistake][j]=(buff[mistake][j]+1)%2; //восстанавливаем вычтенную единицу
  }
}

};