int main()
#include "functions.h"
using namespace std;
{
    Queue <int> Q1;
    Queue <int> Q2;

    if (!Q1.IsEmpty())
          Q1.print("Q1");
        else cout<< "Empty"<<endl;

    for (int i=0; i<10; i++)
        Q1.push (i+1);
    Q1.print ("Q1");
    Q2=Q1;
    Q1.clear();
    cout<<"Count of Q1: "<<Q1.GetCount()<<endl;
    Q1.print("Q1");
    cout<<"First element of Q1: "<<Q1.GetFirst()<<endl;

    cout << "---------------------" << endl;

    cout<<"Count of Q2: "<<Q2.GetCount()<<endl;
    Q2.print("Q2");
    cout<<"First element of Q2: "<<Q2.GetFirst()<<endl;

    Queue <char> Q3;
    Q3.push ('a');
    Q3.push ('b');
    Q3.push ('c');
    Q3.print("Q3");
    return 0;
}
