#include "functions.h"
using namespace std;
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
