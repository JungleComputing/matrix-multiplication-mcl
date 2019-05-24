/*
 * Copyright 2019 Vrije Universiteit Amsterdam, The Netherlands
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


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
