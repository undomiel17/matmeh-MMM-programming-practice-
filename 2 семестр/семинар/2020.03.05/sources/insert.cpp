#include "functions.h"
node* btree::insert(int key, node* leaf)
{
    if (root==NULL){

        root=newleaf(key, NULL);
    }
else if (key < leaf->key_value)
    {
        if (leaf->left != NULL)		//И если левый указатель узла инициализирован
            insert(key, leaf->left);
else
        {
            leaf->left = newleaf(key, leaf);
            return leaf->left;
        }
    }
    else if (key >= leaf->key_value)
    {
        if (leaf->right != NULL)
            insert(key, leaf->right);
            else
        {
            leaf->right = newleaf(key, leaf);
            return leaf->right;

        }
    }
}