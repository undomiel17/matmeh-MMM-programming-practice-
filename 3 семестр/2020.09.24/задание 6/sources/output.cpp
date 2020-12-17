#include "functions.h"
class output
{
    private:

    char c1;
    double d1;
    int* arr1;

    public:
//constructors
    output()
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
         for (int i=0; i<n; i++)
            arr1[i]=arg3[i];

     }
     output(char arg1, double arg2, int* arg3)
     {
         build(arg1, arg2, arg3);

     }

//copy
    output(const output& outputx)
    {
        c1=outputx.c1;
        d1=outputx.d1;
        arr1=new int[n];
        for (int i=0;i<n; i++)
            arr1[i]=outputx.arr1[i];
    }
//operator =
    output operator=(const output& outputx)
    {
            c1=outputx.c1;
            d1=outputx.d1;
            for (int i=0;i<n; i++)
                arr1[i]=outputx.arr1[i];

        return *this;
    }
//print
    print() const
    {
        //cout<<"output: "<<endl;
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
    ~output()
    {
        clear();
    }
};
