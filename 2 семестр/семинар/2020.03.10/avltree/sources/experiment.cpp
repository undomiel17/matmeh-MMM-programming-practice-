#include "functions.h"
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