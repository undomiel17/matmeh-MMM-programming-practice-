//Функции записи чтения массива объектов в файл. 

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#define n 10
#define dim 3
using namespace std;

class input
{
    private:
    char c1;
    double d1;
    int* arr1;

    public:
//constructors

    input()
    {
        c1=0;
        d1=0;
        arr1=new int[n];
        for (int i=0;i<n;i++)
            arr1[i]=0;
    }
    void build(char arg1, double arg2, int* arg3)
     {
         c1=arg1;
         d1=arg2;
         arr1=new int[n];
         for (int i=0; i<n; i++)
            arr1[i]=arg3[i];

     }
     input(char arg1, double arg2, int* arg3)
     {
         build(arg1, arg2, arg3);

     }

//copy
    input(const input& inputx)
    {
        c1=inputx.c1;
        d1=inputx.d1;
        for (int i=0;i<n; i++)
            arr1[i]=inputx.arr1[i];
    }
//operator =
    input operator=(const input& inputx)
    {
            c1=inputx.c1;
            d1=inputx.d1;
            for (int i=0;i<n; i++)
                arr1[i]=inputx.arr1[i];

        return *this;
    }
//print
    print() const
    {
       // cout<<"input: "<<endl;
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
        delete[] arr1;
    }
    ~input()
    {
        clear();
    }
};

class output
{
    private:

    char c1;
    double d1;
    int* arr1;

    public:
//constructors
    output()
    {
        c1=0;
        d1=0;
        arr1=new int[n];
        for (int i=0;i<n;i++)
            arr1[i]=0;
    }
    void build(char arg1, double arg2, int* arg3)
     {
         c1=arg1;
         d1=arg2;
         for (int i=0; i<n; i++)
            arr1[i]=arg3[i];

     }
     output(char arg1, double arg2, int* arg3)
     {
         build(arg1, arg2, arg3);

     }

//copy
    output(const output& outputx)
    {
        c1=outputx.c1;
        d1=outputx.d1;
        arr1=new int[n];
        for (int i=0;i<n; i++)
            arr1[i]=outputx.arr1[i];
    }
//operator =
    output operator=(const output& outputx)
    {
            c1=outputx.c1;
            d1=outputx.d1;
            for (int i=0;i<n; i++)
                arr1[i]=outputx.arr1[i];

        return *this;
    }
//print
    print() const
    {
        //cout<<"output: "<<endl;
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
        delete[] arr1;
    }
    ~output()
    {
        clear();
    }
};

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

void read(input*in, const char* path)
{
    ifstream fin;
    fin.open(path, ios::binary);

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
