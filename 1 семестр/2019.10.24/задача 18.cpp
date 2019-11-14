#include <iostream>

using namespace std;


   long int qsort(long int* a, int left,int right,int k) {
     long int x = a[(left+right) / 2];
     int y=left,z=right;
     while(y<=z) {
         while(a[y] < x) y++;
         while(a[z] > x) z--;
         if(y<=z) {
             swap(a[y],a[z]);
 y++; z--;
         }
     }
     if(left<=k && k<=z)
     return qsort(a,left,z,k);
     if( y<=k && k<=right)
     return qsort(a,y,right,k);
     return a[k];
}

int main()
{
    int n, left, right, k;
    cin >>n>> left >> right >> k;
    long int *a= new long int[n];
        for (int i = 0; i < n; i++) {
 cin >> a[i];
        }
        cout << qsort (a,left-1, right-1, k-1); // учитывается то, что пользователь не знает, что массив вводится с нулевого индекса 
        delete [] a;
    return 0;
}
