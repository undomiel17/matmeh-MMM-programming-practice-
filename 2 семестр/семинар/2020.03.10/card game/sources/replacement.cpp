#include "functions.h"
void replacement (vector <int> &player, string xcard, stack <int> &deck){
int poisk;
if (xcard=="joker"){
  for (int i=0; i<player.size(); i++)
    if (player.at(i)==8){    //ищет карту для замены
        poisk=i;
        break;
    }
}
else {
xcard=xcard.substr(0,1);
int card=atoi(xcard.c_str());
    for (int i=0; i<player.size(); i++)
    if (player.at(i)==card){    //ищет карту для замены
        poisk=i;
        break;
    }
}
    player.at(poisk)=deck.top(); //заменяет на верхнюю из колоды
    deck.pop();
}
