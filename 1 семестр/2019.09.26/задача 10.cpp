#include <iostream>

using namespace std;


    void swap (char*a, int i, int j){
    int s=a[i];
        a[i]=a[j];
        a[j]=s;
    }
    bool var (char*a, int n){
    int j=n-2;
    while (j!=-1&&a[j]>=a[j+1]) j--;
    if (j==-1) return false;
    int k=n-1;
    while (a[j]>=a[k])k--;
    swap(a,j,k);
    int q=j+1; int r=n-1;
    while (q<r)
        swap(a,q++,r--);
    return true;
    }
    void print (char*a, int n){
    for (int i=0;i<n;i++)
        cout <<a[i];
        cout<<endl;
    }
 int main()
{
    int n;
    cin>>n;
     char *a=new char [n];
     for (int i=0;i<n; i++) a[i]='a'+i;
     print (a,n);
     while(var(a,n))print (a,n);
     cin.get(); cin.get();
    return 0;
}
