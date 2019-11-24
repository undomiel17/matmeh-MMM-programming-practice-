#include <iostream>
#include <cmath>
using namespace std;
struct lines{
int x;
int y;
int lenght;
};
void quicksort (  struct lines*  ls, int left, int right){
int l=left; int r= right;
int X=ls[(left+right)/2].y;
while (l<=r){
    while (ls[l].y<X) l++;
    while (ls[r].y>X) r--;
    if (l<=r){
        struct lines t=ls[l];
        ls[l]=ls[r];
        ls[r]=t;
        l++;
        r--;
    }
    if (right>l) quicksort(ls,l,right);
    if (r>left)  quicksort (ls, left, r);
}
}
int main()
{
    int n;
    cin>>n;
  lines *ls= new lines[n];
    for (int i=0; i<n; i++){
        cin>>ls[i].x;
        cin>>ls[i].y;
        if (ls[i].x>ls[i].y) swap (ls[i].x, ls[i].y);
        ls[i].lenght = abs(ls[i].y-ls[i].x);
    }
    quicksort(ls, 0, n-1);
    int s=0;
    for (int i=1,z; i<n;i++,z=0){
        for (int j=0; j<i; j++){
            if (ls[i].x>ls[j].y) z=1;
            else z=0;
    }
    if (z==1) s++;
    }
    cout<<s;
    delete []ls;

    return 0;
}
