#include <iostream>
#include <cmath>
using namespace std;
class ex{
private:
    double a;
    unsigned short int b;
    int c;
    char d;
    char*e;
    long int f;
    float g;
    bool h;
public:
    ex(double a, unsigned short int b,  int c, char d, char*e, long int f, float g, bool h ) //êîíñòðóêòîð
    {
        setEx (a, b, c, d, e, f, g, h);
    }
    void setEx (double a1, unsigned short int b1,  int c1, char d1, char*e1, long int f1, float g1, bool h1){
    a=a1;
    b=b1;
    c=c1;
    d=d1;
    e=e1;
    f=f1;
    g=g1;
    h=h1;
    }
    void write (){
    int n= sizeof(e);
    for (int i=0; i<n; i++) cout<<e[i];
    cout<<endl<<d<<endl;
    }
    void proverka(){
    if (h==true) cout<<"successful"<<endl;
    else cout<<"failed"<<endl;
    }
    void sum1(){
    g=g+a;
    cout<<"sum1: "<<g<<endl;
    }
    void sum2(){
    b=b+c+f;
    cout<<"sum2: "<<b<<endl;
    }
};


int main()
{
    ex Example (1.2, 2,-10, 't', "pmml", 218724, 3456.5, true);
    Example.write();
    Example.proverka();
    Example.sum1();
    Example.sum2();
    return 0;
}
