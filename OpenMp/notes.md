# OpenMP Notes

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

`sudo apt install libomp-dev`

### Compiling

`$ gcc -fopenmp -Wall <filename>.c`
