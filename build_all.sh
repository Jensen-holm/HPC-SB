#!/bin/bash

# compiling naive.c
gcc-12 -Wall ./Matrix/mul.c ./Matrix/matrix.c naive.c -o naive

# compiling openmp.c
gcc-12 -Wall -fopenmp openmp.c -o omp ./Matrix/matrix.c ./Matrix/mul.c
