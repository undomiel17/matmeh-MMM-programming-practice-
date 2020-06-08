#include "functions.h"
bool rightchoice (vector <int> &player, string &xcard){
    int poisk=-1;
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
if (poisk==-1) return false;
else return true;
}