#include "functions.h"
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