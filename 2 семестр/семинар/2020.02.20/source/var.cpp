#include <functions.h>
bool var (int *a, int n, int t){
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