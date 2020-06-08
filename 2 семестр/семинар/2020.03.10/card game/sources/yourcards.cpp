#include "functions.h"
void yourcards (vector <int> &player, int number){   //карты игрока
cout<<"cards of player "<<number<<" :";
for (int i=0; i<player.size(); i++) {
        if (player.at(i)==8) cout<<"joker"<<" ";
        else cout<<player.at(i)<<" ";
        }
cout<<endl;
}