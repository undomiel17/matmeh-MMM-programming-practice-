#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct node // структура для представления узлов дерева
{
	int key;
	unsigned char height;
	node* left;
	node* right;
	node* parent;
};
struct avltree
{
public:
    avltree(){
    root=NULL;
    srr=0;
    slr=0;
    brr=0;
    blr=0;
    }
    ~avltree(){
    destroy_tree(root);
    }
    void destroy_tree(){
        destroy_tree(root);
    }
    node* insert(int key){
    return insert(root,key);
    }
    int srr_count(){
    return srr;
    }
    int slr_count(){
    return slr;
    }
    int brr_count(){
    return brr;
    }
    int blr_count(){
    return blr;
    }
private:
    int srr;
    int slr;
    int brr;
    int blr;
    void destroy_tree(node* leaf);
    unsigned char height(node* p)
{
	return p?p->height:0;
}
int bfactor(node* p)
{
	return height(p->right)-height(p->left);
}
void fixheight(node* p);
node* rotateright(node* p);
node* rotateleft(node* q);
node* bigrotateright(node* p);
node* bigrotateleft(node* q);
node* balance(node* p);
node* insert(node* leaf, int key);
node* root;
node* newleaf(int key, node* current);

};
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

void transposition (int*array, const int& number)
{
    int*flag=new int[number];
 for (int i=0; i<number; i++){
    flag[i]=-1;
    array[i]=-1;
 }
 int attempt;
 for (int i=0; i<number; i++){
    while (array[i]==-1){
    attempt=rand()%number;
    if (flag[attempt]==-1) {
            array[i]=attempt+1;
            flag[attempt]=1;
            }
    }
 }
    delete[]flag;
    for (int i=0; i<number; i++) cout<<array[i]<<" ";
    cout<<endl;
}
void newtree(const int&number, avltree& tree){
int*keys=new int[number];
transposition(keys, (int&)number);
for (int i=0; i<number; i++){
    tree.insert(keys[i]);
}
delete [] keys;
}
void experiment (const int&number, const int& repeat){
avltree tree;
float srr=0, slr=0, brr=0, blr=0;
for (int i=0; i<repeat; i++){
    tree.destroy_tree();
    newtree(number,tree);
    srr+=tree.srr_count();
    slr+=tree.slr_count();
    brr+=tree.brr_count();
    blr+=tree.blr_count();
}
cout<<"small right rotation amount: "<<srr/repeat<<endl;
cout<<"small left rotation amount: "<<slr/repeat<<endl;
cout<<"big right rotation amount: "<<brr/repeat<<endl;
cout<<"big left rotation amount: "<<blr/repeat<<endl;

}
int main()
{
    srand(time(NULL));
    int number, repeat;
    cout << "size of transposition: " << endl;
    cin >> number;
    cout << "experiment accuracy: " << endl;
    cin >> repeat;
    experiment (number, repeat);
    return 0;
}
