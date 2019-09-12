#include <iostream>

using namespace std;

int main()
{ int n,m=0;
 cin >>n;
 for (int i=1; i<=n; i++) if (n%i==0) m=m+1;
   cout << m<<endl;
    if (m!=2) cout <<"not ";
    cout << "prime number";
    return 0;
}
