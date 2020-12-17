#include "functions.h"
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
