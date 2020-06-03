#include <iostream>
#include <cstdlib>
#include <cmath>
struct node;
class btree;
int height(node*current);
void destroy_tree(node* leaf);
int sizetree(node*current);		
node* insert(int key, node* leaf);	
node* search(int key, node* leaf);	
void printcurrent (node* current);
int depthcurrent(node* current);
node*newleaf(int key, node*current);