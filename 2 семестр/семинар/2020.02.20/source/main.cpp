#include "functions.h"
using namespace std;
int main()
{
    setlocale (LC_ALL,"rus");
    int n,m;
    cout<<"количество элементов:";
    cin>>n;
    cout<<"количество повторов:";
    cin>>m;
    double t=0; //время на операции

     //int nomer;
    for (int p=0; p<m; p++){
    int *a=new int[n];
     for (int i=0;i<n; i++) a[i]=i;
    int*b=new int[n];
    cout<<"введите перестановку:"<<endl;
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
     //cout<<nomer<<endl; номер текущей перестановки
     cout<<t<<endl; //текущее время поиска

        delete [] b;
        delete []a;
     }
     t=t/m;
     cout<<t;
     cin.get(); cin.get();
    return 0;
}
