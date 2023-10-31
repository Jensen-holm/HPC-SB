#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Matrix/matrix.h"
#include "Matrix/mul.h"

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

    double parallel_begin = omp_get_wtime();
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        Matrix *product = mat_mul_parallel(mat1, mat2);
        free_matrix(product);
    }
    double parallel_end = omp_get_wtime();

    double parallel_run_time = (double) (parallel_end - parallel_begin);
    printf("Execution time for parallelized mat_mul w/ %i operations: %f seconds\n", NUM_OPERATIONS, parallel_run_time);
    return 0;
}
