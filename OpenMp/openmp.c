#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Matrix/matrix.h"
#include "../Matrix/mul.h"

int main(int argc, char *argv[]) {
    if (!argv[1]) {
        printf("Please specify an argument for num operations.\n");
        return 1;
    }

    int NUM_OPERATIONS = atoi(argv[1]);
    if (NUM_OPERATIONS == 0 && *argv[1] != '0') {
        printf("Invalid argument for num operations '%s'\n", argv[1]);
        return 1;
    }

    int dims1 = rand() % 1000;
    int dims2 = rand() % 1000;
    Matrix *mat1 = new_matrix(dims1, dims2, 1000);
    Matrix *mat2 = new_matrix(dims2, dims1, 1000);

    double naive_begin = omp_get_wtime();
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        Matrix *product = new_empty_matrix(dims1, dims1);
        int _ = mat_mul(mat1, mat2, product);
        free_matrix(product);
    }
    double naive_end = omp_get_wtime();

    free_matrix(mat1);
    free_matrix(mat2);
    double naive_run_time = (double) (naive_end - naive_begin);
    printf("Execution time for naive mat_mul w/ %i operations: %f seconds\n", NUM_OPERATIONS, naive_run_time);

    // now benchmark the mat_mul_parallel function
    double parallel_begin = omp_get_wtime();
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        Matrix *product = new_empty_matrix(dims1, dims1);
        int _ = mat_mul(mat1, mat2, product);
        free_matrix(product);
    }
    double parallel_end = omp_get_wtime();

    double parallel_run_time = (double) (naive_end - naive_begin);
    printf("Execution time for parallelized mat_mul w/ %i operations: %f seconds\n", NUM_OPERATIONS, parallel_run_time);
    return 0;
}
