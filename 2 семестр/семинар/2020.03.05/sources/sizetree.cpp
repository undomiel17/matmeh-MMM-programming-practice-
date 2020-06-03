#include "functions.h"
int btree::sizetree(node*current){
int number=0,leftnumber=0, rightnumber=0;
if (current!=NULL){
  if ((current->left == NULL)&&(current->right == NULL)) number++;
  else{
        if (current->left!=NULL) leftnumber=sizetree(current->left);
  number+=leftnumber;
  if (current->right!=NULL) rightnumber=sizetree(current->right);
  number+=rightnumber;

}

}
return number;
}