#! /bin/bash

gcc-12 -Wall -fopenmp ./Matrix/mul.c ./Matrix/matrix.c naive.c -o naive

gcc-12 -Wall -fopenmp ./Matrix/mul.c ./Matrix/matrix.c naive_parallel.c -o naive_parallel

gcc-12 -Wall -fopenmp openmp.c -o omp ./Matrix/matrix.c ./Matrix/mul.c
