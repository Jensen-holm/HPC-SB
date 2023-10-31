#!/bin/bash

# compiling naive.c
gcc-12 -Wall ./Matrix/mul.c ./Matrix/matrix.c naive.c -o naive

# compiling openmp.c
# for some reason when compiling gcc-12, it doesn't recognize the -fopenmp flag
# but the code seems to work. I can compile it straight from the terminal and I get no
# warning but I do when running this script.
gcc-12 -Wall -fopenmp openmp.c -o omp ./Matrix/matrix.c ./Matrix/mul.c
