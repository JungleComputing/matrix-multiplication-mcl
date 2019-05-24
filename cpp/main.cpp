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


#include "io_data.h"
#include "kernels.h"


int usage(char *appName) {
  printf("USAGE: %s\n", appName);
  return 1;
}



int main(int argc, char **argv) {
  if (argc != 1) {
    return usage(argv[0]);
  }

  turnOnPrintingOutput();

  int n = 1025;
  int m = 1026;
  int p = 1027;

  float *a = createInput<float>(n, p);
  float *b = createInput<float>(p, m);
  float *outputCPU = createInput<float>(n, m);
  cleanArray<float>(outputCPU, n, m);
  float *outputMCL = createInput<float>(n, m);
  cleanArray<float>(outputMCL, n, m);

  matmulCPU(n, m, p, outputCPU, a, b);
  matmulMCL(n, m, p, outputMCL, a, b);
  
  checkOutput(outputCPU, "cpu", n, m);
  checkOutput(outputMCL, "mcl", n, m);

  aligned_delete<float>(a);
  aligned_delete<float>(b);
  aligned_delete<float>(outputCPU);
  aligned_delete<float>(outputMCL);

  return 0;
}
