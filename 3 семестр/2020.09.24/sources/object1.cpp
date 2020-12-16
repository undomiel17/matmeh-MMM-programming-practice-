#include "functions.h"
class object1
{
    private:

    char c1;
    double d1;
    int* arr1;

    public:
//constructors
    object1()
    {
        c1=0;
        d1=0;
        arr1=0;
    }
     object1(char arg1, double arg2, int* arg3)
     {
         c1=arg1;
         d1=arg2;
         arr1=new int[n];
         for (int i=0; i<n; i++)
            arr1[i]=arg3[i];

     }

//copy
    object1(const object1& object)
    {
        c1=object.c1;
        d1=object.d1;
        arr1=new int[n];
        for (int i=0;i<n; i++)
            arr1[i]=object.arr1[i];
    }
//operator =
    object1 operator=(const object1& object)
    {
            c1=object.c1;
            d1=object.d1;
            arr1=new int[n];
            for (int i=0;i<n; i++)
                arr1[i]=object.arr1[i];

        return *this;
    }
//print
    print() const
    {
        cout<<"object1: "<<endl;
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
        delete []arr1;
    }
    ~object1()
    {
        clear();
    }
};