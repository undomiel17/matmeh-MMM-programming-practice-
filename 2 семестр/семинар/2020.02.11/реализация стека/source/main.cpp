#include "functions.h"
using namespace std;

    int main()
{
    STACK st1;
    st1.print();
    int k;
    for (int i=0; i<11; i++)
            st1.push(i);

    STACK st2;
    st2=st1;
    st1.print();
    int head;
    head=st1.pop();
    cout <<head<<" is deleted"<<endl;
    cout<< "new top: "<<st1.top()<<endl;
    st2.multipop(5);
    st2.print();
    if (st2.isEmpty()) cout <<"stack is empty"<<endl;
    else cout<<"stack is not empty"<<endl;

    return 0;
}
