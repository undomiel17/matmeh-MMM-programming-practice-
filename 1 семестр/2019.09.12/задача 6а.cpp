#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int s=0; int a[1000];
    for (int i=0; i<1000;a[i++]=rand());
    for (int i=0;i<1000;i++){
    s+=a[i];}
    cout << s;
    return 0;
}
