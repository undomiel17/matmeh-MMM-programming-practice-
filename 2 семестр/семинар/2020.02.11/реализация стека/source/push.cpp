#include <iostream>
#include <new>
using namespace std;
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
