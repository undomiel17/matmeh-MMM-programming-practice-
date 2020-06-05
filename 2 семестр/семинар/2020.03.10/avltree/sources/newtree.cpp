#include "functions.h"
void newtree(const int&number, avltree& tree){
int*keys=new int[number];
transposition(keys, (int&)number);
for (int i=0; i<number; i++){
    tree.insert(keys[i]);
}
delete [] keys;
}