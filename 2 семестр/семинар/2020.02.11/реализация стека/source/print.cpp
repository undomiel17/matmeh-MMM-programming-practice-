#include <iostream>
#include <new>
#include "functions.h"
using namespace std;
void print (){
int*pr;
pr=steck; //не массив равный стеку, а указатель
cout <<"stack:"<<endl;
if (n==0) {cout <<"is empty"<<endl;}
else {
     for (int i=0; i<n;i++) cout <<pr[i]<<endl;
}
}
