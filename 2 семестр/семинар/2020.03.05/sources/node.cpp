#include "functions.h"
struct node
{
    int key_value; //ключ – значение узла, типа int
    node* left;    //указатель на левого потомка
    node* right;   //указатель на правого потомка
    node* parent;   //указатель на родителя
};