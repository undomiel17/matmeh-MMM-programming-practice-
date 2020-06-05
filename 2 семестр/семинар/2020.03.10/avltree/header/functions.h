#include <iostream>
#include <cstdlib>
#include <ctime>
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
void transposition (int*array, const int& number);
void newtree(const int&number, avltree& tree);
void experiment (const int&number, const int& repeat);
