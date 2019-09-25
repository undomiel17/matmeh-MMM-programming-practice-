#include <iostream>

using namespace std;

int main()
{
    int N,a,x;
    float s=0;
cin>>N;
for (int i=0; i<N; i++) {
    cin>>x;
   a=1;
   for (int k=1; k<=x; k++)
    a=a*k;
 s=s+a;
}
cout << s/N;
return 0;
}
