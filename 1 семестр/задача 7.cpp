#include <iostream>

using namespace std;
    struct R {
    int n; int m;
    R (int x=0, int y=1){
    n=x/gcd(x,y);
    m=y/gcd(x,y);}
    int gcd (int n, int m){
    if (m==0) return n;
    return gcd (m, n%m);}
    R& operator *= (R z){
    n*=z.n;
    m*=z.m;
    int g=gcd (n,m);
    m/=g;
    n/=g;
    return *this;
    };
    R& operator *=(int n){
    return *this*=R(n);};
     };
    R operator * (R r1, R r2){
    R t(r1);
    return t*=r2;}

    bool operator == (R r1, R r2){
    return (r1.n==r2.n)&&(r1.m==r2.m);}
    bool operator != (R r1, R r2){
    return!(r1==r2);
    }

    int main (){
    int n=2;
    R r1(10,6), r2(30,18), r3(5,6);
    cout<<r1.n<<'/'<<r1.m<<endl;
    cout<<r2.n<<'/'<<r2.m<<endl;
    if (r1==r2) cout<<'e'<<endl;
    if (r1!=r3) {
        if (r1==r3*n)cout<<'c'; else cout<<'nc';
    }
    return 0;
}
