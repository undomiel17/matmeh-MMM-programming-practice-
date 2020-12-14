#include "functions.h"

using namespace std;

int main()
{
    STACK<bool> st1;
    st1.Print();
    st1.push(false);
    cout<<std::boolalpha<<st1.Head()<<endl;
    st1.push(true);
    st1.push(false);
    cout<<st1.Count()<<endl;
    st1.Print();
    st1.pop();
    cout<<st1.Count()<<endl;
    st1.Print();
    return 0;
}
