#include <math.h>
#include <omp.h>
#include <iostream>
#include <fstream>
using namespace std;
float form_jacobi_parallel(float **alf, float *xlast, float *xcurrent, float *bet, int n, int core);
int jacobi_parallel(float **a, float *b, float *xlast, int n, float eps, int core);
