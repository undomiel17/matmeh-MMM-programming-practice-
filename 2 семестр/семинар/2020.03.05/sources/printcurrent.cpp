#include "functions.h"
void btree:: printcurrent(node*current){
if (root!=NULL)
    {
        if (current->left!=NULL){
            printcurrent(current->left);
        }
        cout<< current->key_value<<" ";
        if (current->right!=NULL){
            printcurrent(current->right);
        }
    }
    else
        cout<<"the btree is empty"<<endl;
}
