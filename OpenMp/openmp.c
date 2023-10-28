#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include "../Matrix/matrix.h"


int main(void) 
{
    // set the seed for random numbers in matrix
    srand(time(NULL));

    // create two matrices with random values
    struct matrix* mat1ptr = new_matrix(3, 3);
    struct matrix* mat2ptr = new_matrix(3, 3);

    // set number of threads
    omp_set_num_threads(4);

    // tell the compiler to create a team of threads
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        printf(" --- Thread %i ---\n", thread_id);

        struct matrix* result;
        int condition_met = mat_mul(mat1ptr, mat2ptr, result);

        if (condition_met == 0) {
            printf("Matrix multiplication successul. Result: %i\n", *result->data);
        } else {
            printf("Matrix multiplication failed. Condition not met.\n");
        }
        
        free(result);
    }

    // the matrices are stored in the heap when initialized
    // with malloc so we must free them
    free(mat1ptr);
    free(mat2ptr);

    return 0;
}
