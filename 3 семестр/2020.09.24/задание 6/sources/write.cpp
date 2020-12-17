#include "functions.h"
void write (output*out, const char* path)
{
    ofstream fout;
    fout.open(path, ios::binary);
    if (fout)
    {
         for (int i = 0; i < dim && !fout.fail(); ++i)
        {
            fout.write(reinterpret_cast<char*> (&out[i]),
                       sizeof(output));
        }
        if (fout.fail())
        {
            fout.clear();
        }
        fout.close();
    }
}
