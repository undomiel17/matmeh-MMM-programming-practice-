#include <iostream>

using namespace std;
void eratosthenes (bool E[],int N){
int i,p;
for (p=2;p<=N;p++) E[p]=true;
p=2;
while (p*p<=N){
    i=p*p;
    if(E[p])
    while (i<=N){
        E[i]=false;
        i=i+p;
    }
    p=p+1;
    }
    for(p=2;p<=N;p++){
        if(E[p]==true)cout<<p<<" ";}
}
int main()
{
    int N;
    cin>>N;
    bool*E=new bool[N];
    eratosthenes (E,N);
    return 0;
}
