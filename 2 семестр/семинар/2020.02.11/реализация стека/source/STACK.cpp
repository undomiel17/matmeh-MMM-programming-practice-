#include "functions.h"
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
~STACK (){ //удаление
    if (n>0) delete [] steck;
}
STACK operator = (const STACK&analog ){
if (n>0) {
    n=0;
    delete [] steck; //освободить стек
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
