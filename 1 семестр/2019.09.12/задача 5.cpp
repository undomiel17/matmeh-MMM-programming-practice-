#include <iostream>
using namespace std;
void def_odd (int *&a, int&n){
    int k=n,ia=0;
    n=0;
    int*b=new int[k];
    for (int i=0;i<k;i++){
        *(b+i)=*(a+i);
        if (*(a+i)%2!=0){
            n++;
        }
    }
    delete [] a;
    a= new int[n];
    for (int i=0; i<k; i++){
        if (*(b+i)%2!=0){
                *(a+ia)=*(b+i);
        ia++;

        }
    }
    delete [] b;
 }
int main(){
int n;
cin >> n;
int*a= new int [n];
for (int i=0; i<n; cin >> a[i++]);
def_odd (a,n);
for (int i=0;i<n; cout << a[i++]);
delete [] a;


    return 0;
}
