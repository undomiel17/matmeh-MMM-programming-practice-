#include "functions.h"
void avltree::destroy_tree(node *leaf)
{
      if(leaf!=NULL)
      {
          if (leaf->left != NULL) destroy_tree(leaf->left);	//сначала для левого потомка,
          if (leaf->right != NULL) destroy_tree(leaf->right);  	//после для правого потомка.
          delete leaf;
      }
      root=NULL;
}
node* avltree::newleaf(int key, node* current) {

    node* leaf = new node;
    leaf->key=key;
    leaf->left=NULL;
    leaf->right=NULL;
    leaf->parent =current;
    leaf->height =1;
    return leaf;

}
void avltree:: fixheight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl>hr?hl:hr)+1;
}
node* avltree:: rotateright(node* p) // правый поворот вокруг p
{
	if (p!=NULL){
            if (p->left!=NULL){
    node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	++srr;
	return q;
            }
            else return p;
            }
        else return p;
}
node* avltree:: rotateleft(node* q) // левый поворот вокруг q
{
	if (q!=NULL){
            if (q->right!=NULL){
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	++slr;
	return p;
            }
            else return q;
            }
        else return q;
}
node* avltree:: bigrotateright(node* p){
if (p!=NULL){
    if (p->left!=NULL){
       p->left = rotateleft(p->left);
       ++brr;
       --srr;
       --slr;
       return rotateright(p);
    }
    else return p;
}
return p;
}
node* avltree:: bigrotateleft(node* q){
if (q!=NULL){
    if (q->right!=NULL){
       q->right = rotateright(q->right);
       ++blr;
       --srr;
       --slr;
       return rotateleft(q);
    }
    else return q;
}
return q;
}
node* avltree:: balance(node* p) // балансировка узла p
{
	fixheight(p);
	if( bfactor(p)>1 )
	{
		if( bfactor(p->right) > 0 ){
		return rotateleft(p);
	}
	else bigrotateleft(p);
	}
	if( bfactor(p)<-1 )
	{
		if( bfactor(p->left) < 0  ){
		return rotateright(p);
	}
	else bigrotateright(p);
	}
	return p; // балансировка не нужна
}
node* avltree:: insert(node* leaf, int key) // вставка ключа k в дерево с корнем p
{
	if( root==NULL ) {
            root=newleaf(key, NULL);
	}
	else if( key < leaf->key ){
            if (leaf->left!=NULL){
		        insert(leaf->left,key);
		        balance(leaf);
            }
    else
    {
        leaf->left=newleaf(key,leaf);
        //cout<<leaf->left->key;
        balance(leaf);
        return leaf->left;
    }
	}
	else if( key>=leaf->key )
        {
            if (leaf->right!=NULL){
		        insert(leaf->right,key);
		        balance(leaf);
            }
    else
    {
        leaf->right=newleaf(key,leaf);
        //cout<<leaf->right->key;
        balance(leaf);
        return leaf->right;
    }
	}
}