#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
struct str {
   private: unsigned int dl; char* s;
   public:
   str (char*st){
   dl=strlen(st);
   s=new char[dl+1];
   for (unsigned int i=0;i<dl;i++){s[i]=st[i];}
   s[dl]='\0';
  }
  str (){
       dl=5;
       s= new char [dl+1];
      strcpy(s,"error");
   }
   ~str (){ delete[]s;}
    unsigned int getd(){
   return dl;
   }
   str& operator=(const str& a){
       if (this==&a) return *this;
   char* t= new char[a.dl+1];
   strcpy (t,a.s);
   t[a.dl]='\0';
   delete []s;
   dl=a.dl;
   s=t;
   return *this;
   }

   bool p (str pst){
  int i,j;
   for (i=0; i<dl;i++){
    for (j=i;j<pst.dl+i;j++){
        if (s[j]!=pst.s[j-i]) break;
        else if (s[j]==pst.s[j-i]&&j-i+1==pst.dl){
                    cout<<"done"<<endl;
                    return true;
                    }

        }
    }

  cout<<"failed"<<endl;
  return false;
   }

str operator+(const str &dop){
char *ns =new char[this->dl+dop.dl+1];
for(int i=0;i<this->dl;i++) {ns[i]=this->s[i];}
for(int j=0, i=this->dl;j<dop.dl;i++,j++) {ns[i]=dop.s[j];}
ns[dl+dop.dl]='\0';
return str(ns);
}
friend ostream&operator << (ostream&out, str&str){
for(unsigned int i=0; i<str.getd();i++)
    out<<str.s[i];
    return out;
}
};
int main()
{ setlocale(LC_ALL, "ru");
char s1[8]="abcdefg";
str a(s1);
char s2[4]="abc";
str b(s2);
str c=a+b;
cout<<c<<endl;
cout<<c.getd()<<endl;
a.p(b);
return 0;
}
