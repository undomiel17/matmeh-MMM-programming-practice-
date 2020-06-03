#include "functions.h"
void btree::destroy_tree(node *leaf)
{
      if(leaf!=NULL)
      {
          if (leaf->left != NULL) destroy_tree(leaf->left);	//сначала для левого потомка,
          if (leaf->right != NULL) destroy_tree(leaf->right);  	//после для правого потомка.
          delete leaf;
      }
}