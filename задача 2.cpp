#include <iostream>

using namespace std;
    int a (int,int);
int main() {
    int n,m;
    cin >> n >> m;
    cout << a(n,m);
    return 0;
}
int a (int n,int m) {
if ((n==0) && (m!=0)) return m+1;
if ((n!=0) && (m==0)) return a(n-1,1);
if ((n!=0) && (m!=0)) return a(n-1, a(n,m-1));
}

