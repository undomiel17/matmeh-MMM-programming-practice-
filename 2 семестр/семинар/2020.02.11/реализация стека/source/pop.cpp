#include "functions.h"
using namespace std;
int pop (){
if (n==0) return 0;
n--;
return steck[n]; //возвращает без верхнего элемента
}
