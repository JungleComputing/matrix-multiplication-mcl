#include "matrixmultiplication/matrixmultiplication.h"
#include "timer.h"



void matmulCPUKernel(const int n, const int m, const int p, float *c, 
	float *a, float *b) {
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	    float sum = 0.0;
	    for (int k = 0; k < p; k++) {
		float aa = a[i * p + k];
		float bb = b[k * m + j];
		sum += aa * bb;
	    }
	    c[i * m + j] = sum;
	}
    }
}


void matmulCPU(int n, int m, int p, float *c, float *a, float *b) {
    timer t("cpu");

    t.start();
    matmulCPUKernel(n, m, p, c, a, b);
    t.stop();

    std::cerr << t << std::endl;
}


void matmulMCL(int n, int m, int p, float *c, float *a, float *b) {
  timer t("mcl");

  t.start();
  matmul(n, m, p, c, a, b);
  t.stop();
  
  std::cerr << t << std::endl;
}
