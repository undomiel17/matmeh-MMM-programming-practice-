#include "functions.h"
void printinput(input*in)
{
    cout<<"input: "<<endl;
    for (int i=0; i<dim&& in+i!=0; i++)
    {
      cout<<i+1 <<": ";
      in[i].print();
      cout<<endl;
    }
}