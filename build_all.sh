#!/bin/bash

# compiling openmp.c
gcc-12 -Wall -fopenmp ./Matrix/mul.c ./Matrix/matrix.c openmp.c -o omp

# compiling mpi.c
