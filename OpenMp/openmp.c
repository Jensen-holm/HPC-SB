#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "../Matrix/matrix.h"
#include <time.h>

int main(void)
{
    int MAX = 100;
    srand(time(NULL));
    omp_set_num_threads(100);
    struct matrix *results_arr[100];

// tell the compiler to create a team of threads
#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();

        int dims = rand() % MAX;
        struct matrix *mat1 = new_rand_matrix(dims, dims, MAX);
        struct matrix *mat2 = new_rand_matrix(dims, dims, MAX);

        struct matrix *product = new_empty_matrix(dims, dims);
        int condition_met = mat_mul(mat1, mat2, product);

        results_arr[thread_id] = product;
        free_matrix(mat1);
        free_matrix(mat2);
    }

    for (int i = 0; i < 100; i++)
    {
        print_matrix(results_arr[i]);
        free_matrix(results_arr[i]);
    }

    return 0;
}
