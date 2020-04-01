#include <iostream>
#include <stack>
#include <cmath>
#include <cstring>
#include <fstream>
using namespace std;
void skobki(string a, const char*res){
stack <char> sk;
ofstream fout(res);
if ((a[0]=='(')||(a[0]=='[')) sk.push(a[0]); else {
        fout<<"no";
        return;
        }
for (int i=1; i< a.size(); i++){
    if ((a[i]=='(')||(a[i]=='[')) sk.push(a[i]);

    else {if (sk.empty()){
        fout<<"no";
        return;
        }
        if ((!sk.empty())&&(abs(a[i]-sk.top())<3)) sk.pop(); else {
        fout<<"no";
        return;
        }
    }
}
if (sk.empty()) fout<<"yes"; else fout<<"no";
fout.close();
}
int main()
{
char k='0';
for (int i=1; i<11; i++){
char path1[]="0_test_in.txt";
char res1[]="0_test_res.txt";
const char*path;
const char*res;
if (k!='9') { k++;
path1[0]=k;
res1[0]=k;
path=path1;
res=res1;
}
else {
        path="10_test_in.txt";
        res="10_test_res.txt";
}
ifstream fin(path);
string test;
fin>>test;
fin.close();
skobki(test,res);
cout<<endl;
}
    return 0;
}
