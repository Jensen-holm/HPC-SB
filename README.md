# High Performance Computing Sandbox

This repo is a 'sandbox' for me to get familiar with different HPC patterns and algorithms before beginning an undergraduate research project in applied HPC for chemistry simulation. <br>

## Benchmarking & Running Locally

You may need to reconfigure the pound bang path to your bash interpreter as it points
to where my bash interpreter is and if you are not on mac os, it is likley different than
what it is on my machine. You also need to have make installed.

1. `$ git clone https://github.com/Jensen-holm/HPC-SB && cd HPC-SB` <br>
2. `$ make` <br>
3. `$ chmod u+x benchmark.sh` <br>
4. `$ ./benchmark <NUM_OPERATIONS>` <br>

## OpenMP Notes

These notes are for my future reference. Currently exploring parallel programming <br>
using the OpenMP C API leading into HPC undergraduate research project. <br>

### What is it

OpenMP is a compiler-side solution for code that runs on multiple cores / threads <br>
Since it is a compiler side solution, no additional libraries need to be installed <br>
to use it and you import is from the omp.h file just like you include stdio.h. <br> 

```c
#include <omp.h>
```

### Installation

the default installation of gcc on mac os is just an alias to clang and the default installation of clang on mac os does not ship with OpenMp support. Install gcc with homebrew: <br> 

`brew install gcc` <br>

Now you should check what version you just installed and then use that when compiling instead of just gcc. On my machine, I installed gcc-12.

Now to install openmp:
`brew install libomp`

### Compiling

##### Without MakeFile
`$ gcc-12 -fopenmp -Wall <filename>.c`

##### With MakeFile
`$ make all` <br>

On my macbook, I set an alias in .zshrc to map "gcc" to "gcc-12" since the default gcc on Mac is an alias to clang

#### OMP vs. naive matrix multiplication

![](https://github.com/Jensen-holm/HPC-SB/blob/main/demos/benchmark_demo.gif)

as you can see in the screen recording above, matrix multiplication is a lot faster with the parallel implementation using openmp.
The test in the video timed how long it took both the naive approach to matrix multiplication and openmp version to compute matrix multiplication 15 times with matrices that have large dimensions. next to where I am benchmarking the two implementations, I have htop running so you can see how openmp is working. There is only one cpu being utilized. But once the parallel code is running, all of the cpu's light up at the same time because the computation is being split amongst the cpu's. Cool stuff

## MPI Notes

Documentation link: https://curc.readthedocs.io/en/latest/programming/MPI-C.html



## Running on clipper

I ran 10,000 iterations of the openmp implementation and it took 17 seconds <br>
on clipper and 404 seconds on my local machine (M1 macbook air) ...

