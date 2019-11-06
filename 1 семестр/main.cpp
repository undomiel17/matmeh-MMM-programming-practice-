#include <iostream>

using namespace std;

int main()
{
    int k,n;
    cin>>k>>n;
   int**A=new int*[k];
   for (int i=0;i<k;i++) A[i]=new int[n];
    int*B=new int [n];
    for (int i=0;i<n;i++) B[i]=-1;
    for (int i=0; i<k; i++)
        for (int j=0;j<n;j++) cin>>A[i][j];

    for (int i=0,j=0,g=0;(i<n)&&(j<n);){
    if (A[0][i]==A[1][j]){
        B[g]=A[1][j];
        g++; i++; j++;
         }
    if (A[0][i]<A[1][j]) i++;
        else j++;
    }
    bool flag;
    for (int i=2;i<k;i++){
        for (int g=0;g<n;g++){
                flag=false;

            for (int j=0;j<n;j++)
            {if ((B[g]==A[i][j])&&(B[g]!=-1)) flag=true;}
            if (flag!=true)B[g]=-1;
        }
        }
        for (int i=0;i<n;i++)
            if (B[i]!=-1)cout<<B[i]<<" ";
        delete []B;
        for (int i=0;i<k;i++) delete[]A[i];
    return 0;
}
