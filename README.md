# High Performance Computing Sandbox

This repo is a 'sandbox' for me to get familiar with different HPC patterns and algorithms before beginning an undergraduate research project in the HPC field. <br>

## Benchmarking & Running Locally

...

## OpenMP Notes

These notes are for my future reference. Currently exploring parallel programming <br>
using the OpenMP C API leading into HPC undergraduate research project. <br>

### What is it

OpenMP is a compiler-side solution for code that runs on multiple cores / threads <br>
Since it is a compiler side solution, no additional libraries need to be installed <br>
to use it and you import is from the omp.h file just like you include stdio.h. <br> 

```c
#include <stdio.h>
#include <omp.h>
```

### Installation

the default installation of gcc on mac os is just an alias to clang and the default installation of clang on mac os does not ship with OpenMp support. Install gcc with homebrew: <br> 

`brew install gcc` <br>

Now you should check what version you just installed and then use that when compiling instead of just gcc. On my machine, I installed gcc-12.

Now to install openmp:
`brew install libomp`

### Compiling

`$ gcc-12 -fopenmp -Wall <filename>.c`

On my macbook, I set an alias in .zshrc to map "gcc" to "gcc-12"

#### OMP vs. naive matrix multiplication

![](https://github.com/Jensen-holm/HPC-SB/blob/main/demos/omp_vs_naive.gif)

as you can see in the screen recording above, matrix multiplication is a lot faster with the parallel implementation using openmp.
The test in the video timed how long it took both the naive approach to matrix multiplication and openmp version to compute matrix multiplication 50 times with matrices that have large dimensions. next to where I am benchmarking the two implementations, I have htop running so you can see how openmp is working. There is only one cpu being utilized. But once the parallel code is running, all of the cpu's light up at the same time because the computation is being split amongst the cpu's. Cool stuff

## MPI Notes

### Installation

`$ brew install open-mpi`
