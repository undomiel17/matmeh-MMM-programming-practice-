#include "functions.h"
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