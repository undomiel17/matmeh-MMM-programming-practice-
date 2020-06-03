#include "functions.h"
node* btree::search(int key, node* leaf)
{
if (leaf != NULL)
    {
        if (key == leaf->key_value)
return leaf;	//Возвращается указатель на найденный элемент.
if (key < leaf->key_value)
return search(key, leaf->left);
        else
            return search(key, leaf->right);
    }
    else return NULL;
}
