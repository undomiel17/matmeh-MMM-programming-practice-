#include <iostream>
#include <cstdlib>
#define Time_swap 0.1
#define Time_compare 0.001
using namespace std;
void quicksort(int *a, int first, int last, double&st1, double&ct1, double time_swap, double time_compare)
{
int x;
int f=first, l=last;
x=a[(f+l) / 2];
do
{
while (a[f]<x) {
        f++;
 ct1+=time_compare;
}
while (a[l]>x){
        l--;
 ct1+=time_compare;
}
if (f<=l)
{
swap (a[f],a[l]);
st1+=time_swap;
f++;
l--;
}
} while (f<l);
if (first<l) quicksort(a, first, l,st1,ct1,time_swap,time_compare);
if (f<last) quicksort(a, f, last,st1,ct1,time_swap,time_compare);
}
void selection(int *a,int n,double& st2, double& ct2,double time_swap,double time_compare){
    int min;
    for(int i = 0; i < n-1; i++){
        min=i;
        for(int j = i+1; j < n; j++){
            ct2+=time_compare;
            if(a[j]<a[min]){
                min=j;

            }

        }
        if(min!=i){
            swap(a[i],a[min]);
           st2+=time_swap;

        }
    }
}

int main()
{
    int n;
    cin>>n;
    int *a= new int[n];
    int *b=new int[n];
    for (int i=0; i<n; i++){
      a[i]=rand()%1000;
      b[i]=a[i];
    }
    double time_swap, time_compare;
    time_swap=Time_swap; time_compare=Time_compare;
    double st1=0, st2=0, ct1=0, ct2=0;
    quicksort (a, 0, n-1, st1, ct1, time_swap, time_compare);
    selection (a, n, st2, ct2, time_swap, time_compare);
    double v;
    v=(st1+ct1)/(st2+ct2);
    cout<<v;
    delete []a;
    delete[] b;
    return 0;
}
