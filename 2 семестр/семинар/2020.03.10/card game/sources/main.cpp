#include "functions.h"
using namespace std;
int main()
{
    srand(time(NULL));
    char etrance;
    cout << "Hello! This is my game." << endl<<"press 'y' to continue or 'n' to exit"<<endl;
    cin>>etrance;
    if (etrance=='n') {
            cout<<"Goodbye";
            return 0;
    }
    vector <int> player1;
    vector <int> player2;
    stack <int> deck;
    mixdeck (deck);

    for (int i=0; i<5; i++){

        takecard (player1, deck);
        takecard (player2, deck);
    }
    yourcards (player1, 1);
    yourcards (player2, 2);
    //cout<<points(player1)<<endl<<points(player2);
    int next=1; //отслеживает очередь
    while ((points(player1)<50)&&(points(player2)<50)&&(points(player1)!=33)&&(points(player2)!=33)&&(!deck.empty())&&(!player1.empty())&&(!player2.empty())){
        if (next==1) step(player1, player2, deck, next); else step (player2, player1, deck, next);
        next=(next+1)%2;
    }
    if (deck.empty()){ //если колода кончилась, смотрим на текущие очки
        if (points(player1)==points(player2)) cout<<"drawn game"<<endl;
        else {
            if (points(player1)>points(player2)) cout<<"player 1 is a winner!"<<endl;
            else cout<<"player 2 is a winner!"<<endl;
        }
    }
    if (!deck.empty())
    {
       if (player1.empty()) cout<<"player 2 is a winner!"<<endl; //проверка на наличие карт
       if (player2.empty()) cout<<"player 1 is a winner!"<<endl;
    if ((!player1.empty())&&(!player2.empty())) {
            if (((points(player1)>=50)&&(points(player2)>=50))||((points(player1)==33)&&(points(player2)==33))) cout<<"drawn game"<<endl; //если оба наюрали нужное коичество очков, то ничья
    else {
        if ((points(player1)>=50)||(points(player2)==33)) cout<<"player 1 is a winner!"<<endl;
        else cout<<"player 2 is a winner!"<<endl;
         }
    }
    }
cout<<"Game is over"<<endl<<"Goodbye";
    return 0;
}
