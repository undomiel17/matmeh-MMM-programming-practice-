#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
void poisk (string x, string y, int**a, int m, int n){
for (int i=1; i<m; i++){
    for (int j=1; j<n; j++){
        if (x[i-1]==y[j-1]) a[i][j]=a[i-1][j-1]+1;
        else a[i][j]=max (a[i-1][j],a[i][j-1]);
    }
}
}
void lcs_ ( int**a, int m, int n, string x, string y){
char*lcs=new char [a[m][n]];
int k=0;
int i=m;
int j=n;
while (a[i][j]!=0){
    if (x[i-1]==y[j-1]){
       lcs[k]=x[i-1];
        i--;
        j--;
        k++;
    }
    else {
        if (a[i-1][j]>a[i][j-1]) i--;
        else j--;
    }
}
for (int i=k-1;i>=0 ; i--) cout<<lcs[i];
delete []lcs;
}
int main()
{
    string x;
    string y;
    cin>>x;
    cin>>y;
    int m=x.size()+1;
    int n=y.size()+1;
    int**a=new int*[m];
    for (int i=0; i<m;i++){
        a[i]=new int [n];
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<n; j++) a[i][j]=0;
    }
    poisk (x,y,a,m,n);
    lcs_(a,m-1,n-1,x,y);

    return 0;
}
