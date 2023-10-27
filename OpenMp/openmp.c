#include <stdio.h>
#include <omp.h>
#include <matrix.h>


int main(void) 
{
    // set the seed for random numbers in matrix
    srand(time(0));

    // create two matrices with random values
    int mat1 = init_matrix(3, 3);
    int mat2 = init_matrix(3, 3);

    // set number of threads
    omp_set_num_threads(4);

    // tell the compiler to create a team of threads
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        printf("Hello from thread %d\n", thread_id);
    }

    return 0;
}
