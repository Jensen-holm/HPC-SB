#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include "../Matrix/matrix.h"


int main(void) 
{
    // set the seed for random numbers in matrix
    srand(time(0));

    // create two matrices with random values
    int* mat1ptr = new_matrix(3, 3);
    int* mat2ptr = new_matrix(3, 3);

    // set number of threads
    omp_set_num_threads(4);

    // tell the compiler to create a team of threads
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        printf("Hello from thread %d\n", thread_id);
    }

    // the matrices are stored in the heap when initialized
    // with malloc so we must free them
    free(mat1ptr);
    free(mat2ptr);

    return 0;
}
