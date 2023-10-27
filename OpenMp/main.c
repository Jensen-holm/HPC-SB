#include <stdio.h>
#include <omp.h>


int main(void) 
{
    // set number of threads
    omp_set_num_threads(4);

    // tell the compiler to create a 
    // team of threads
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        printf("Hello from thread %d\n", thread_id);
    }

    return 0;
}
