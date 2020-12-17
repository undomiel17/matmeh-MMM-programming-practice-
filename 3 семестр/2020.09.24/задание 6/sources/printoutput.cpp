#include "functions.h"
void printoutput(output*out)
{
    cout<<"output: "<<endl;
    for (int i=0; i<dim&& out+i!=0; i++)
    {
      cout<<i+1<<": ";
      out[i].print();
      cout<<endl;
    }
}