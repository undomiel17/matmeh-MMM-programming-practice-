#include <iostream>
#include <cstdio>
#include <cstdlib>
#define n 10
using namespace std;
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

template <typename T1, typename T2>

    void swap(const T1& obj1, const T2& obj2)
    {
//запоминает
        T1 tmp = obj1;
//снимает константное значение, после этого приводит типы
        const_cast<T1&> (obj1) = reinterpret_cast<T1&> (
                                    const_cast<T2&> (obj2));
        const_cast<T2&> (obj2) = reinterpret_cast<T2&> (
                                    const_cast<T1&> (tmp));
    }
int main()
{
    int*array1=new int[n];
    int*array2=new int[n];
    for (int i=0;i<n; i++){
        array1[i]=i+1;
        array2[i]=i+101;
    }
    const object1 obj1('a', 24.00, array1);
    const object2 obj2('b',  20.21, array2);
    obj1.print();

    obj2.print();

    swap(obj1, obj2);

    obj1.print();
    obj2.print();
    return 0;
}
