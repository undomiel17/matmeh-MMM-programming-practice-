#include <iostream>
#include <stack>
#include <cmath>
#include <cstring>
using namespace std;
void skobki(string a){
    stack <char> sk;
if ((a[0]=='(')||(a[0]=='[')) sk.push(a[0]); else {
        cout<<"no";
        return;
        }
for (int i=1; i< a.size(); i++){
    if ((a[i]=='(')||(a[i]=='[')) sk.push(a[i]);

    else {if (sk.empty()){
        cout<<"no";
        return;
        }
        if ((!sk.empty())&&(abs(a[i]-sk.top())<3)) sk.pop(); else {
        cout<<"no";
        return;
        }
    }
}
if (sk.empty()) cout<<"yes"; else cout<<"no";
}