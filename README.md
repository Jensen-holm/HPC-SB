# High Performance Computing Sandbox

This repo is a 'sandbox' for me to get familiar with different HPC patterns and algorithms before beginning an undergraduate research project in the HPC field. <br>

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

it wasn't installed by default on my ubutu sysystem so I had to install it with <br>
this command: <br>

#### Ubutntu: 
`sudo apt install libomp-dev`

#### Mac os

the default installation of gcc on mac os is just an alias to clang and the default installation of clang on mac os does not ship with OpenMp support. Install gcc with homebrew: <br> 

`brew install gcc` <br>

Now you should check what version you just installed and then use that when compiling instead of just gcc. On my machine, I installed gcc-12.

Now to install openmp:
`brew install libomp`

### Compiling

#### Ubuntu
`$ gcc -fopenmp -Wall <filename>.c`

#### Mac os
`$ gcc-12 -fopenmp -Wall <filename>.c`

On my macbook, I set an alias in .zshrc to map "gcc" to "gcc-12"

