#include <math.h>
#include <omp.h>
#include <iostream>
#include <fstream>
using namespace std;
float form_jacobi_parallel(float **alf, float *xlast, float *xcurrent, float *bet, int n,
                           int core) {
  int i, j;
  float s, maxdiffetence;
#pragma omp parallel for private(i, j, s)
  for (i = 0; i < n; i++) {
    s = 0;
    for (j = 0; j < n; j++) {
      s += alf[i][j] * xlast[j];
    }
    s += bet[i];
    if (i == 0) {
      maxdiffetence = fabs(xlast[i] - s);
    } else if (fabs(xlast[i] - s) > maxdiffetence) {
      maxdiffetence = fabs(xlast[i] - s);
    }
    xcurrent[i] = s;
  }
  return maxdiffetence;
}
int jacobi_parallel(float **a, float *b, float *xlast, int n, float eps, int core) {
  float **f, *h, **alf, *bet, *xcurrent, *xx, maxdiffetence;
  int i, j, IterationCounter;
  f = new float *[n];
  for (i = 0; i < n; i++)
    f[i] = new float[n];
  h = new float[n];
  alf = new float *[n];
  for (i = 0; i < n; i++)
    alf[i] = new float[n];
  bet = new float[n];
  xcurrent = new float[n];
  xx = new float[n];
#pragma omp parallel for
  for (i = 0; i < n; i++) {
#pragma omp parallel for
    for (j = 0; j < n; j++)
      if (i == j)
        alf[i][j] = 0;
      else
        alf[i][j] = -a[i][j] / a[i][i];
    bet[i] = b[i] / a[i][i];
  }
  for (i = 0; i < n; i++)
    xcurrent[i] = bet[i];
  IterationCounter = 0;
  maxdiffetence = 7* eps;
  while (maxdiffetence > eps) {
    for (i = 0; i < n; i++)
      xlast[i] = xcurrent[i];
    maxdiffetence = form_jacobi_parallel(alf, xlast, xcurrent, bet, n, core);
    IterationCounter++;
  }
  delete[] f;
  delete[] h;
  delete[] alf;
  delete[] bet;
  delete[] xcurrent;
  delete[] xx;
  return IterationCounter;
}
int main() {
  omp_set_dynamic(0);
  //ofstream fout;
  //fout.open("res.txt");
  int cores[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int sizes[] = {5, 10, 50, 100, 150, 200, 500,1000,2000};
  int result, i, j;
  float **a;
  float *b;
  float *x;
  float ep;
  ep = 1e-6;
  for (auto size : sizes) {
    cout << "time for N = " << size << ":" << endl;
    for (auto core : cores) {
      omp_set_num_threads(core);
      a = new float *[size];
      for (i = 0; i < size; i++)
        a[i] = new float[size];
      b = new float[size];
      x = new float[size];
      for (i = 0; i < size; a[i][i] = 1, i++)
        for (j = 0; j < size; j++)
          if (i != j)
            a[i][j] = 1.0 / (i + j);
      for (i = 0; i < size; i++)
        b[i] = i^2;
      auto t1 = omp_get_wtime();
      jacobi_parallel(a, b, x, size, ep, core);
      auto t2 = omp_get_wtime();
      cout << t2 - t1 << ' ';
      cout.flush();
      delete[] a;
      delete[] b;
      delete[] x;
    }
    cout << endl;
  }
  //fout.close();
  return 0;
}
