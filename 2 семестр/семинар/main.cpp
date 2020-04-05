#include <iostream>
#include <locale>
#include <cmath>
using namespace std;
struct ex1{ //28
double a; //8
unsigned short int b; //2
int c; //4
char d; //1
char*e; //4
long int f; //4
float g; //4
bool h; //1
};
int cash (unsigned int a,unsigned int b){
return (b-a%b)%b;
}
void memory (struct ex1 str){
    unsigned int s= sizeof(str);
    cout<<"структура занимает в памяти: "<<s<<endl;
    //char*t=(char*)&str; //выравнивание по размеру указателя
    //unsigned int m= sizeof(t);
    unsigned int m=sizeof(str.a);
    int*flag=new int[8];
    for (int i=0; i<8;i++) flag[i]=0;
    if ((sizeof(str.a)+sizeof(str.b))<=m)
    {
      cout<<"a: "<<sizeof(str.a)<<endl; flag[0]=1;
      cout<<"мусор: "<<(m-sizeof(str.a)-sizeof(str.b))<<endl;
      cout<<"b: "<<sizeof(str.b)<<endl; flag[1]=1;
      cout<<"мусор: "<<0<<endl;
    }
    else {
    cout<<"a: "<<sizeof(str.a)<<endl; flag[0]=1;
    cout<<"мусор: "<<cash(sizeof(str.a),m)<<endl;
    }

    if (flag[1]!=1)
    {
        if ((sizeof(str.b)+sizeof(str.c))<=m)
    {
      cout<<"b: "<<sizeof(str.b)<<endl; flag[1]=1;
      cout<<"мусор: "<<(m-sizeof(str.b)-sizeof(str.c))<<endl;
      cout<<"c: "<<sizeof(str.c)<<endl; flag[2]=1;
      cout<<"мусор: "<<0<<endl;
    }
    else {
    cout<<"b: "<<sizeof(str.b)<<endl; flag[1]=1;
    cout<<"мусор: "<<cash(sizeof(str.b),m)<<endl;
    }
    }
if (flag[2]!=1)
    {
        if ((sizeof(str.c)+sizeof(str.d))<=m)
    {
      cout<<"c: "<<sizeof(str.c)<<endl; flag[2]=1;
      cout<<"мусор: "<<(m-sizeof(str.c)-sizeof(str.d))<<endl;
      cout<<"d: "<<sizeof(str.d)<<endl; flag[3]=1;
      cout<<"мусор: "<<0<<endl;
    }
    else {
    cout<<"c: "<<sizeof(str.c)<<endl; flag[2]=1;
    cout<<"мусор: "<<cash(sizeof(str.c),m)<<endl;
    }
    }
    if (flag[3]!=1)
    {
        if ((sizeof(str.d)+sizeof(str.e))<=m)
    {
      cout<<"d: "<<sizeof(str.d)<<endl; flag[3]=1;
      cout<<"мусор: "<<(m-sizeof(str.d)-sizeof(str.e))<<endl;
      cout<<"e: "<<sizeof(str.e)<<endl; flag[4]=1;
      cout<<"мусор: "<<0<<endl;
    }
    else {
    cout<<"d: "<<sizeof(str.d)<<endl; flag[3]=1;
    cout<<"мусор: "<<cash(sizeof(str.d),m)<<endl;
    }
    }
    if (flag[4]!=1)
    {
        if ((sizeof(str.e)+sizeof(str.f))<=m)
    {
      cout<<"e: "<<sizeof(str.e)<<endl; flag[4]=1;
      cout<<"мусор: "<<(m-sizeof(str.e)-sizeof(str.f))<<endl;
      cout<<"f: "<<sizeof(str.f)<<endl; flag[5]=1;
      cout<<"мусор: "<<0<<endl;
    }
    else {
    cout<<"e: "<<sizeof(str.e)<<endl; flag[4]=1;
    cout<<"мусор: "<<cash(sizeof(str.e),m)<<endl;
    }
    }
    if (flag[5]!=1)
    {
        if ((sizeof(str.f)+sizeof(str.g))<=m)
    {
      cout<<"f: "<<sizeof(str.f)<<endl; flag[5]=1;
      cout<<"мусор: "<<(m-sizeof(str.f)-sizeof(str.g))<<endl;
      cout<<"g: "<<sizeof(str.g)<<endl; flag[6]=1;
      cout<<"мусор: "<<0<<endl;
    }
    else {
    cout<<"f: "<<sizeof(str.f)<<endl; flag[5]=1;
    cout<<"мусор: "<<cash(sizeof(str.f),m)<<endl;
    }
    }
    if (flag[6]!=1)
    {
        if ((sizeof(str.g)+sizeof(str.h))<=m)
    {
      cout<<"g: "<<sizeof(str.g)<<endl; flag[6]=1;
      cout<<"мусор: "<<(m-sizeof(str.g)-sizeof(str.h))<<endl;
      cout<<"h: "<<sizeof(str.h)<<endl; flag[7]=1;
      cout<<"мусор: "<<0<<endl;
    }
    else {
    cout<<"g: "<<sizeof(str.g)<<endl; flag[6]=1;
    cout<<"мусор: "<<cash(sizeof(str.g),m)<<endl;
    }
    }
    if (flag[7]!=1){
     cout<<"h: "<<sizeof(str.h)<<endl; flag[7]=1;
    cout<<"мусор: "<<cash(sizeof(str.h),m)<<endl;
    }
    delete[]flag;

}
int main()
{
    setlocale (LC_ALL, "rus");
    struct ex1 str;
    memory (str);
    return 0;
}
