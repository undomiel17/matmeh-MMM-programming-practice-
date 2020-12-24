#include "functions.h"
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
