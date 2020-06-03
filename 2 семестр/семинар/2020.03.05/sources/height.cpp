#include "functions.h"
int btree:: height(node*current){
int h=0, leftheight=0, rightheight=0;
if (current!=NULL){
if (current->left != NULL) {leftheight=height(current->left);
}
if (current->right !=NULL) {rightheight=height(current->right);
}
h=max(leftheight,rightheight)+1;
}
return h;
}