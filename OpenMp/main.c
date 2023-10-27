#include <stdio.h>
#include <omp.h>
#include <matrix.h>


int main(void) 
{

    struct matrix m1;
    m1.width = 10;
    m1.height = 10;

    struct matrix m2;
    m2.width = 10;
    m2.height = 10;

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
