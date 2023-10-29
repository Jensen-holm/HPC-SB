#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "../Matrix/matrix.h"


int main(void) 
{
    // set number of threads
    omp_set_num_threads(4);

    struct matrix* mat1ptr = new_rand_matrix(5, 5, 10);
    print_matrix(mat1ptr);

    // tell the compiler to create a team of threads
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        printf(" --- Thread %i ---\n", thread_id);

        struct matrix* mat2ptr = new_rand_matrix(5, 5, 10);
        struct matrix* resultptr = new_empty_matrix(mat1ptr->rows, mat2ptr->cols);
        int is_valid = mat_mul(mat1ptr, mat2ptr, resultptr);

        if (is_valid == 1) {
            printf("condition not met for matrix multiplication.");
        } else {
        }

        free_matrix(mat2ptr);
        free_matrix(resultptr);
    }

    free_matrix(mat1ptr);
    return 0;
}
