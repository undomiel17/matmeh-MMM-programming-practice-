#include "functions.h"
void takecard (vector <int> &player, stack <int> &deck){ //вытащить карту из колоды
player.push_back (deck.top());
deck.pop();
}