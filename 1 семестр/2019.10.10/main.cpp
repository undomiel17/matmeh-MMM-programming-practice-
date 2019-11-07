#include <iostream>

using namespace std;

   int GetMinrun(int n)
   {
       int r = 0;
       while (n >= 64) {
           r |= n & 1;
           n >>= 1;
       }
       return n + r;
   }
   void mergesort (int*a1, int*b1, int*a2, int*b2 ){
   int x=0;
   do{
        if (*a1>*a2){
            x=*a2;
            for (int* i=a2; i!=a1;i--){
                *i=*(i-1);
            }
            *a1=x;
            a1++;b1++;a2++;
        }
        a1++;
   }
   while ((a1!=a2)&&(b1!=b2));
   }
   void insertionsort (int*a,int n){
   int i=0; int x; int j;
   while (i<n-1){
    x=a[i+1];
    j=0;
    while (x>a[j]){
        j++;
    }
    for (int g=i+1;g>j;g--){
        a[g]=a[g-1];
    }
    a[j]=x;
    i++;
   }
   }
   void timsort (int*a, int n, int minrun){
   if (n>minrun){
        int d1, d2;
   if (n%2==0){
        d1=d2=n/2;
   }
   else {
    d1=n/2;
    d2=n/2+1;
   }
   timsort (a,d1,minrun);
   timsort (a+d1,d2,minrun);
   mergesort (a,a+d1-1,a+d1,a+n-1);
   }
   else insertionsort(a,n);
   }

int main()
{ int n;
cin>>n;
if (n>0){
int*a=new int [n];
for (int i=0;i<n;cin>>a[i++]){};
timsort(a,n,GetMinrun(n));
for (int i=0;i<n;cout<<a[i++]<<" "){};
delete []a;
}
 else cout<<"error";
    return 0;
}
