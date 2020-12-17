#include "functions.h"
int main()
{
    output* out= new output[dim];
    input* in= new input[dim];
    printoutput(out);
    buildoutput(out);
    printoutput(out);
    write(out, "./file.txt");
    read(in,"./file.txt");
    printinput(in);
    delete[]out;
    delete[]in;
    return 0;
}
