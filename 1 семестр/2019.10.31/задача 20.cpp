#include <iostream>

using namespace std;
    void quicksort(double *w, double*s, int first, int last)
{
double x;
double*u=new double [last+1];
for (int i=0;i<last+1;i++){
    u[i]=s[i]/w[i];
}
int f=first, l=last;
x=u[(f+l) / 2];
do
{
while (u[f]>x) {
        f++;
}
while (u[l]<x){
        l--;
}
if (f<=l)
{
swap (u[f],u[l]);
swap (s[f],s[l]);
swap (w[f],w[l]);
f++;
l--;
}
} while (f<l);
if (first<l) quicksort(w, s, first, l);
if (f<last) quicksort(w, s,f, last);
delete []u;
}
 void knapsack (double*w, double*s,int*a,int n, double&W){
 double sum=0;
 quicksort(w,s,0,n-1);
 int lastsubject=-1;
 for (int i=0;i<n; i++){
  if (W > w[i]){
    sum += s[i];
    W -= w[i];
    a[i]=1;
  }
  else
  {
    sum += W / w[i] * s[i] ;
    lastsubject=i;
    a[i]=1;
    break;
  }
 }
 cout<<sum<<endl;
 for (int i=0; i<n; i++){
    if (a[i]==1)
    cout<<w[i]<<" "<<s[i];
    if (i==lastsubject) cout<<" "<<W/w[i]*s[i];
    cout<<endl;

 }
 }
   int main()
{
    int n; double W;
    cin>>W>>n;
    double*s= new double [n];
    double*w=new double [n];
    int*a= new int[n];
    for (int i=0;i<n; i++){
        cin>>w[i]>>s[i];
        a[i]=0;
    };
    knapsack (w,s,a,n,W);
    delete []s;
    delete []w;
    delete[]a;
     return 0;
}
