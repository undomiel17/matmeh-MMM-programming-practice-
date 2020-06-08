#include "functions.h"
void mixdeck (stack <int> &deck){  //смешать колоду
int*cards=new int [8];
bool flag;
int attempt;
for (int i=0; i<8; i++) cards[i]=4;
for (int i=0; i<32; i++){
    flag=false;
    while (!flag){
        attempt=rand()%8;
        if (cards[attempt]>0){
            deck.push(attempt+1);
            cards[attempt]--;
            flag=true;
        }
    }
    cout<<deck.top()<<" ";
  }
  delete [] cards;
  cout<<endl;
}