#include <iostream>
#include <new>
using namespace std;
struct STACK
{
private:
  int* steck; int n;
public:
    STACK(){ //конструктор
    n=0;
    }
STACK (const STACK&buildcopy) //конструктор копий
  {
      try {
      steck= new int[buildcopy.n];
      n=buildcopy.n;
      for (int i=0; i<n;i++) steck[i]=buildcopy.steck[i]; }
      catch (bad_alloc e){
      cout<<e.what()<<endl;
      }
  }
~STACK (){ 
    if (n>0) delete [] steck;
}
STACK operator = (const STACK&analog ){ //конструктор эквивалентности
if (n>0) {
    n=0;
    delete [] steck; 
}
try {
steck=new int [analog.n];
n=analog.n;
for (int i=0; i<n; i++)
    steck[i]=analog.steck[i];
}
catch (bad_alloc e){
cout<<e.what()<<endl;
}
return*this;
};
int number(){ 
return n;}
void push (int next){
int*tmp;
try{
tmp=steck;
steck= new int[n+1];
n++;
for (int i=0; i<n-1; i++) steck[i]=tmp[i];
steck[n-1]=next;
if (n>1) delete[]tmp;
}
catch (bad_alloc e) {
cout<<e.what()<<endl;
}
}
int pop (){
if (n==0) return 0;
n--;
return steck[n]; //без верхнего
}
int top (){
if (n==0) return 0;
return steck[n-1];
}
bool isEmpty ()
{if (n==0) return true;
return false;
}
void print (){
int*pr;
pr=steck; //указатель на стек
cout <<"stack:"<<endl;
if (n==0) {cout <<"is empty"<<endl;}
else {
     for (int i=0; i<n;i++) cout <<pr[i]<<endl;
}
}
int multipop (int k){
if (n==0) return 0;
n=n-k;
return steck[n];}

};
    int main()
{
    STACK st1;
    st1.print();
    int k;
    for (int i=0; i<11; i++)
            st1.push(i);

    STACK st2;
    st2=st1;
    st1.print();
    int head;
    head=st1.pop();
    cout <<head<<" is deleted"<<endl;
    cout<< "new top: "<<st1.top()<<endl;
    st2.multipop(5);
    st2.print();
    if (st2.isEmpty()) cout <<"stack is empty"<<endl;
    else cout<<"stack is not empty"<<endl;

    return 0;
}
