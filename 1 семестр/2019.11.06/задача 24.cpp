#include <iostream>
#include <cmath>
using namespace std;
void poisk(int*step, int*slag, int n){
slag[0]=0;
for (int i=1; i<=n; i++){
    for (int j=1; j*j<=i; j++){
        slag[i]=min(slag[i],slag[i-j*j]+1);
        if (slag[i]==slag[i-j*j]+1) step[i]=j;
    }
}
}
void decomposition (int*, int);
int main()
{
    int n;
    cin>>n;
    int*step=new int [n+1];
    int* slag=new int [n+1];
    for (int i=0; i<n+1; i++){
        step[i]=-1;
        slag [i]=n;
    };
    poisk(step,slag,n);
    decomposition (step, n);
    delete [] step;
    delete [] slag;
    return 0;
}
void decomposition (int*step,  int n){
if (step[n]!=-1) cout<<step[n]<<"^2";
n=n-step[n]*step[n];
if (n!=0){
cout<<"+";
decomposition (step, n);
}
}

