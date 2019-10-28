#include <iostream>

using namespace std;
long int p;
int L;
void xxx(long int p,int L);
int main()
{
    cin >> L;
    for (int i=1; i<10; i++){
        xxx(i, (L-2)/2);
    }

    return 0;
}
void xxx(long int p, int l){
    if (l==0){
        long int P=p; int m=0;
        int k=1;
        for (int i=0;i<L/2;i++){
            m=m*10+((P/k)%10);
            k*=10;
        }
        if (P%10!=0) {
                 if (L%2==0){cout<<p<<m<<endl;}
            else for (int j=0;j<10; j++){cout<<p<<j<<m<<endl;}
        }


        else {
                if (L%2==0) {cout<<p<<"0"<<m<<endl;}
            else for (int j=0;j<10;j++){
                cout<<p<<j<<"0"<<m<<endl;
            }
        }
    }
        else {
            for (int t=0;t<10;t++){
                xxx (p*10+t,l-1);

            }
        }

}
