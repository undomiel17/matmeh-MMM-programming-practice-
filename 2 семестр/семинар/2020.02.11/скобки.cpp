#include <iostream>
#include <stack>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
stack <char> sk;
string a;
cin>>a;
if ((a[0]=='(')||(a[0]=='[')) sk.push(a[0]); else { //если начинается с закрывающейся
        cout<<"no";
        return 0;
        }
for (int i=1; i< a.size(); i++){
    if ((a[i]=='(')||(a[i]=='[')) sk.push(a[i]);

    else {if (sk.empty()){ //если закрывающихся больше
        cout<<"no";
        return 0;
        }
        if ((!sk.empty())&&(abs(a[i]-sk.top())<3)) sk.pop(); else { //если не совпадают
        cout<<"no";
        return 0;
        }
    }
}
if (sk.empty()) cout<<"yes"; else cout<<"no"; //если в стеке ещё что-то осталось

    return 0;
}
