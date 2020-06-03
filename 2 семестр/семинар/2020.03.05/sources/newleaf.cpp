#include "functions.h"
node* btree::newleaf(int key, node* current) {

    node* leaf = new node;
    leaf->key_value=key;
    leaf->left=NULL;
    leaf->right=NULL;
    leaf->parent =current;
    return leaf;

}