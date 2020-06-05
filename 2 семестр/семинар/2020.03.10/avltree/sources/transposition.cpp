#include "functions.h"
void transposition (int*array, const int& number)
{
    int*flag=new int[number];
 for (int i=0; i<number; i++){
    flag[i]=-1;
    array[i]=-1;
 }
 int attempt;
 for (int i=0; i<number; i++){
    while (array[i]==-1){
    attempt=rand()%number;
    if (flag[attempt]==-1) {
            array[i]=attempt+1;
            flag[attempt]=1;
            }
    }
 }
    delete[]flag;
    for (int i=0; i<number; i++) cout<<array[i]<<" ";
    cout<<endl;
}