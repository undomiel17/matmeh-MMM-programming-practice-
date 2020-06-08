#include <iostream>
#include <stack>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstring>
void mixdeck (stack <int> &deck);
void takecard (vector <int> &player, stack <int> &deck);
void yourcards (vector <int> &player, int number);
int points (vector <int> &player);
void replacement (vector <int> &player, string xcard, stack <int> &deck);
void print (vector <int> &player1,vector <int> &player2, int next);
void joker(vector <int> &player1, vector <int> &player2, stack <int> &deck, int next);
bool rightchoice (vector <int> &player, string xcard);
void mistake (vector <int> &player1, vector <int> &player2,int next, stack <int> deck, string card1);
void step (vector <int> &player1, vector <int> &player2, stack <int> &deck, int next);