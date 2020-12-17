#include "functions.h"
class input
{
    private:
    char c1;
    double d1;
    int* arr1;

    public:
//constructors

    input()
    {
        c1=0;
        d1=0;
        arr1=new int[n];
        for (int i=0;i<n;i++)
            arr1[i]=0;
    }
    void build(char arg1, double arg2, int* arg3)
     {
         c1=arg1;
         d1=arg2;
         arr1=new int[n];
         for (int i=0; i<n; i++)
            arr1[i]=arg3[i];

     }
     input(char arg1, double arg2, int* arg3)
     {
         build(arg1, arg2, arg3);

     }

//copy
    input(const input& inputx)
    {
        c1=inputx.c1;
        d1=inputx.d1;
        for (int i=0;i<n; i++)
            arr1[i]=inputx.arr1[i];
    }
//operator =
    input operator=(const input& inputx)
    {
            c1=inputx.c1;
            d1=inputx.d1;
            for (int i=0;i<n; i++)
                arr1[i]=inputx.arr1[i];

        return *this;
    }
//print
    print() const
    {
       // cout<<"input: "<<endl;
        cout<<c1<<endl;
        cout<<d1<<endl;
        for (int i=0; i<n; i++)
            cout<<arr1[i]<<" ";
        cout<<endl;
        cout<<endl;
    }
//destructor
    clear()
    {
        c1=0;
        d1=0;
        delete[] arr1;
    }
    ~input()
    {
        clear();
    }
};