#include "functions.h"
void read(input*in, const char* path)
{
    ifstream fin;
    fin.open(path);

    if (fin)
    {
        for (int i = 0; i < dim && !fin.fail(); ++i)
        {
            fin.read(reinterpret_cast<char*> (&in[i]),
                       sizeof(input));
        }
        if (fin.fail())
        {
            fin.clear();
        }
        fin.close();
    }
}