#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
struct node
{
    int key_value; //���� � �������� ����, ���� int
    node* left;    //��������� �� ������ �������
    node* right;   //��������� �� ������� �������
    node* parent;   //��������� �� ��������
};
class btree
{
public:
btree()
{
 		      root = NULL;	       // �������� ���� ��� �������� ���������
}
~btree()
{
destroy_tree(root); 	//��� �������� ������, ���������� ������� ��� //��������
}
    node*insert(int key)
{
    return insert(key, root);
}
    node* search(int key);
    void destroy_tree();
    void  print(){
     printcurrent(root);
    }
    int height(node*current);
    int  depth(node*current){
    return depthcurrent(current);
    }
    node* root;
    int sizetree(node*current);

private:
void destroy_tree(node* leaf);		//����������� ������� ��������
node* insert(int key, node* leaf);	//����������� ������� ���������� ���� � ������
node* search(int key, node* leaf);	//����������� ������� ������ ����
void printcurrent (node* current);
//int heightcurrent(node* current);
int depthcurrent(node* current);
node*newleaf(int key, node*current);

};
node* btree::newleaf(int key, node* current) {

    node* leaf = new node;
    leaf->key_value=key;
    leaf->left=NULL;
    leaf->right=NULL;
    leaf->parent =current;
    return leaf;

}

void btree::destroy_tree(node *leaf)
{
      if(leaf!=NULL)
      {
          if (leaf->left != NULL) destroy_tree(leaf->left);	//������� ��� ������ �������,
          if (leaf->right != NULL) destroy_tree(leaf->right);  	//����� ��� ������� �������.
          delete leaf;
      }
}

node* btree::insert(int key, node* leaf)
{
    if (root==NULL){

        root=newleaf(key, NULL);
    }
else if (key < leaf->key_value)
    {
        if (leaf->left != NULL)		//� ���� ����� ��������� ���� ���������������
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

node* btree::search(int key, node* leaf)
{
if (leaf != NULL)
    {
        if (key == leaf->key_value)
return leaf;	//������������ ��������� �� ��������� �������.
if (key < leaf->key_value)
return search(key, leaf->left);
        else
            return search(key, leaf->right);
    }
    else return NULL;
}

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
int btree:: depthcurrent(node* current)
{
if (current->parent == NULL)
    {
        return 0;
    }
    else {
        return (1+depthcurrent(current->parent));
    }
}
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
int main()
{
    btree Tree;
    int n=10;
    int keys[10]={21, 34, 3, 89, 6, 32, 68, 54, 1, 99};
    cout<<"process of adding: "<<endl;
    Tree.print();
    for (int i=0; i<n; i++){
        cout<<"the depth of "<<keys[i]<<" is "<<Tree.depth(Tree.insert(keys[i]))<<endl;
    }
    Tree.print();
    cout<<endl;
 cout<<"the height is "<<Tree.height(Tree.root)<<endl;
 cout<<"the size is "<<n-Tree.sizetree(Tree.root);
    return 0;
}
