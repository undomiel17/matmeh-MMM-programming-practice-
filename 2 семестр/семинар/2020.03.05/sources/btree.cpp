#include "functions.h"
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
    node* search(int key){
return node* search(int key, node* leaf);
}
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
