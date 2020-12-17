#include "functions.h"
class object2
{
    private:

    char c2;
    double d2;
    int* arr2;
    public:
//constructors
    object2()
    {
        c2=0;
        d2=0;
        arr2=0;
    }
     object2(char arg1, double arg2, int*arg3)
     {
         c2=arg1;
         d2=arg2;
         arr2=new int[n];
         for (int i=0; i<n; i++)
            arr2[i]=arg3[i];
     }

//copy
    object2(const object2& object)
    {
        c2=object.c2;
        d2=object.d2;
        arr2=new int[n];
        for (int i=0; i<n; i++)
            arr2[i]=object.arr2[i];
    }

//operator =
    object2 operator=(const object2& object)
    {
            c2=object.c2;
            d2=object.d2;
            arr2=new int[n];
            for (int i=0; i<n; i++)
                arr2[i]=object.arr2[i];
        return *this;
    }
//print
    print() const
    {
        cout<<"object2: "<<endl;
        cout<<c2<<endl;
        cout<<d2<<endl;
        for (int i=0; i<n; i++)
            cout<<arr2[i]<<" ";
        cout<<endl;
        cout<<endl;
    }
    //destructor
    clear()
    {
        c2=0;
        d2=0;
        delete[]arr2;
    }
    ~object2()
    {
        clear();
    }
};
