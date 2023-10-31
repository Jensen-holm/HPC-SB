#!/bin/bash

# compiling naive.c
gcc-12 -Wall ./Matrix/mul.c ./Matrix/matrix.c naive.c -o naive

# compiling openmp.c
gcc-12 -Wall ./Matrix/mul.c ./Matrix/matrix.c openmp.c -o omp
