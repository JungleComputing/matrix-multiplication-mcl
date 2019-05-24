#ifndef KERNELS_H
#define KERNELS_H



void matmulCPU(int n, int m, int p, float *c, float *a, float *b);
void matmulMCL(int n, int m, int p, float *c, float *a, float *b);



#endif
