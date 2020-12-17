#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#define n 10
#define dim 3
using namespace std;
class input;
class output;
void buildoutput (output* out);
void printinput(input*in);
void printoutput(output*out);
void write (output*out, const char* path);
void read(input*in, const char* path);
