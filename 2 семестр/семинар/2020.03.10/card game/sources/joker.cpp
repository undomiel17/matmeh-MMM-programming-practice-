#include "functions.h"
void joker(vector <int> &player1, vector <int> &player2, stack <int> &deck, int next){
if (next==1) cout<<"player 2, give a card to player 1"<<endl;
else cout<<"player 1, give a card to player 2"<<endl;
int card;
cin>>card;
player1.pop_back();
player1.push_back(card);
int poisk;
for (int i=0; i<player2.size(); i++)
    if (player2.at(i)==card){    //ищет карту для замены
        poisk=i;
        break;
    }
    for (int i=poisk; i<player2.size()-1; i++ ) player2.at(i)=player2.at(i+1); //карта удаляется у игрока
    player2.pop_back();
 print (player1, player2, next);
}