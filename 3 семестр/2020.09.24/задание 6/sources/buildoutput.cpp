#include "functions.h"
void buildoutput (output* out)
{
    if (dim!=0 && out!=0)
    {
        for (int i=0; i<dim; ++i){
        int* array= new int[n];
        for (int j=0;j<n; j++)
            array[j]=j+i;
        out[i].build('a'+i%24,i, array );
        delete []array;
        }
    }
}