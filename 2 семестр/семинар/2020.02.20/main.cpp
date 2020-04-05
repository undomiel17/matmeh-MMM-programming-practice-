#include <iostream>
#include <cmath>
#include <locale>
using namespace std;


    void swap (int *a, int i, int j){
    int s=a[i];
        a[i]=a[j];
        a[j]=s;
    }
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
    void print (int *a, int n){
    for (int i=0;i<n;i++)
        cout <<a[i];
        cout<<endl;
    }
bool poisk (int*a, int*b,int n){
for (int i=0; i<n; i++)
    if (a[i]!=b[i]) return false;
    return true;

}
 int main()
{
    setlocale (LC_ALL,"rus");
    int n,m;
    cout<<"êîëè÷åñòâî ýëåìåíòîâ:";
    cin>>n;
    cout<<"êîëè÷åñòâî ïîâòîðîâ:";
    cin>>m;
    double t=0; //âðåìÿ íà îïåðàöèè

     //int nomer;
    for (int p=0; p<m; p++){
    int *a=new int[n];
     for (int i=0;i<n; i++) a[i]=i;
    int*b=new int[n];
    cout<<"ââåäèòå ïåðåñòàíîâêó:"<<endl;
    for (int i=0; i<n; i++) cin>>b[i];
    //nomer=1;
    t++;
    if  (poisk(a,b,n))
         continue;
     while(var(a,n,t)){
            t++;
            if (poisk(a,b,n)) break;
            //nomer++;
     }
     //cout<<nomer<<endl; íîìåð òåêóùåé ïåðåñòàíîâêè
     cout<<t<<endl; //òåêóùåå âðåìÿ ïîèñêà

        delete [] b;
        delete []a;
     }
     t=t/m;
     cout<<t;
     cin.get(); cin.get();
    return 0;
}
