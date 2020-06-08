#include <iostream>
#include <stack>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
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
void takecard (vector <int> &player, stack <int> &deck){ //вытащить карту из колоды
player.push_back (deck.top());
deck.pop();
}
void yourcards (vector <int> &player, int number){   //карты игрока
cout<<"cards of player "<<number<<" :";
for (int i=0; i<player.size(); i++) {
        if (player.at(i)==8) cout<<"joker"<<" ";
        else cout<<player.at(i)<<" ";
        }
cout<<endl;
}
int points (vector <int> &player){ //очки игрока
int sum=0;
for (int i=0; i<player.size(); i++)
    if (player.at(i)!=8) sum+=player.at(i); //джокер не прибавляет веса
return sum;
}
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

void print (vector <int> &player1,vector <int> &player2, int next ){
if (next==1) {
        yourcards(player1, 1);
        yourcards(player2, 2);
    }
         else {
                yourcards(player2, 1);
                yourcards(player1, 2);
         }
}
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
void mistake (vector <int> &player1, vector <int> &player2,int next, stack <int> deck, string card1){
  string card2;
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
    replacement (player2, card2, deck);
    print (player1, player2, next);
}
else {
if (card2=="skip"){ //если второй пропускает ход, то у первого пропадает его карты взамен на 2 новых из колоды
    replacement (player1, card1, deck);
    takecard(player1, deck);
    print (player1, player2, next);

}
else {
       if ((card2<card1)||(!rightchoice(player2,card2))) { //шанс на ошибку один
       cout<<"you are a looser"<<endl<<"game is over";
                exit(0);
       }//шанс на ошибку один
else   {
    replacement (player1, card1, deck); //иначе у обоих заменяются карты. даже если карты равны
    replacement (player2, card2, deck);
    print (player1, player2, next);

       }
     }
   }
 }
}
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
