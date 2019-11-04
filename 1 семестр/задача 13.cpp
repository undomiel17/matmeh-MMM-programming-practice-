#include <iostream>
#include <cmath>
using namespace std;
bool prostoe(int N){
 for (int i=2;i<=sqrt(N);i++) if (N%i==0) return false;
return true;}
void mersenne (int N){
if (N!=2) {N=N+1;
while (N%2==0) N=N/2;
if (N==1)  cout<<"mersenne";else cout<<"not mersenne";
cout<<endl;}
}
void ferma(int N){
N=N-1;
int k=0;
while(N%2==0){
    N=N/2;
    k=k+1;
}
if (N==1)
    while(k%2==0)k=k/2;
if((N==1)&&(k==1))cout<<"ferma";else cout<<"not ferma";
cout<<endl;
}
void wilson(int N){

if (prostoe(N)) {
    long int p=1;
    for(int i=1; i<=N-1;i++)p=(p*i)%(N*N);
    if ((p+1)%(N*N)==0)cout<<"wilson"; else cout<<"not wilson";
}
else cout<<"not wilson";
cout<<endl;
}
void wagstaff(int N){

if (prostoe(N)){
    int k=4;int s=2;
    for (int i=2; k+1<3*N;i++) {
            s++;
            k*=2;
    }

    if ((prostoe(s))&&(3*N==(k+1))) cout<<"wagstaff";else cout<<"not wagstaff";
    }
    else cout<<"not wagstaff";
    cout<<endl;

}
void wieferich (int N){
if (prostoe(N)){
        long int k=1;
for (int i=1;i<=N-1;i++) k=(k*2)%(N*N);
if ((k-1)%(N*N)==0) cout<<"wieferich"; else cout<<"not wieferich";
}
else cout<<"wieferich";
cout<<endl;
 }
 void sophie (int N){
 if ((prostoe(N))&&(prostoe(2*N+1))) cout <<"Sophie Germain";
 else cout<<"not Sophie Germain";
 cout<<endl;}
bool higgs (int N){
if (prostoe(N)){
long int k=1;
for (int i=2; i<=N;i++) {
        int s=1;
   if (prostoe(i)) for (int j=1;j<i;j++)
    {
       if(prostoe(j)) s=(s*j*j)%(i-1);
    }
if (s==0) {k=(k*i*i)%(N-1);}
};
if (k==0) return true;}
return false;

}

int main()
{
    int N;
    cin>>N;
    if (N==2) cout<<"not mersenne"<<endl<<"not ferma"<<endl<<"not wilson"<<endl<<"not wagstaff"<<endl<<"not wieferich"<<endl<<"Sophie Germain"<<endl<<"higgs";
    else mersenne(N);
    ferma(N);
    wilson(N);
    wagstaff(N);
    wieferich (N);
    sophie(N);
    if (higgs(N)==true)cout<<"higgs";
    else cout<<"not higgs";
    return 0;
}

