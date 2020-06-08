#include "functions.h"
void step (vector <int> &player1, vector <int> &player2, stack <int> &deck, int next){
string card1, card2;
if (next==1) cout << "player 1, your step"<<endl;
else cout << "player 2, your step"<<endl;
cin>>card1; //cчитывает значение карты
if (!rightchoice(player1,card1)) {
        cout<<"try again:"<<endl;
        cin>>card1;
        if (!rightchoice(player1, card1))
        {
                cout<<"you are a looser"<<endl<<"game is over"; //если ошибка во второй раз
                exit(0);
        }
}
if (card1=="joker") {
        if (next!=1) cout << "player 1, your step"<<endl;
else cout << "player 2, your step"<<endl;
        cin>>card2;
if (card2=="joker"){ //джокер джокера кроет
    replacement(player1,"joker", deck);
    replacement(player2,"joker", deck);
    print (player1,player2,next);
}
        else joker(player1, player2, deck, next);
}
if (card1!="joker"){
card1=card1.substr(0,1);
int Xcard1=atoi(card1.c_str());
if (next==1) cout << "player 2, your answer"<<endl;
else cout << "player 1, your answer"<<endl;
cin>>card2;
if (card2=="joker"){
    replacement (player1, card1, deck);
    replacement (player2, "joker", deck);
    print (player1, player2, next);
}
else {
if (card2=="skip"){ //если второй пропускает ход, то у первого пропадает его карты взамен на 2 новых из колоды
    replacement (player1, card1, deck);
    takecard(player1, deck);
    print (player1, player2, next);

}
else {
       if ((card2<card1)||(!rightchoice(player2, card2))) {
             cout<<"try again"<<endl;
             mistake (player1, player2, next, deck, card1);
       }
else   {
    replacement (player1, card1, deck); //иначе у обоих заменяются карты. даже если карты равны
    replacement (player2, card2, deck);
    print (player1, player2, next);

       }
     }
   }
 }
}