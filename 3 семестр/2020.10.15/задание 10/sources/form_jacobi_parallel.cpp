#include "functions.h"
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