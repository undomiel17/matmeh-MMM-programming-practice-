#include "functions.h"
int points (vector <int> &player){ //очки игрока
int sum=0;
for (int i=0; i<player.size(); i++)
    if (player.at(i)!=8) sum+=player.at(i); //джокер не прибавляет веса
return sum;
}