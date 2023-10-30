#include "../Matrix/matrix.h"
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (!argv[1]) {
        printf("Please specify an argument for num operations.");
        return 1;
    }

    int NUM_OPERATIONS = atoi(argv[1]);
    if (NUM_OPERATIONS == 0 && *argv[1] != '0') {
        printf("Invalid argument for num operations '%s'\n", argv[1]);
        return 1;
    }

    int dims1 = rand() % 100;
    int dims2 = rand() % 100;
    struct matrix *mat1 = new_rand_matrix(dims1, dims2, 1000);
    struct matrix *mat2 = new_rand_matrix(dims2, dims1, 1000);

    double begin = omp_get_wtime();
#pragma omp parallel for
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        struct matrix *product = new_empty_matrix(dims1, dims1);
        int invalid = mat_mul(mat1, mat2, product);
        if (invalid) {
            printf("matrices did not meet condition for matrix multiplication");
            continue;
        }
        free_matrix(product);
    }
    double end = omp_get_wtime();

    free_matrix(mat1);
    free_matrix(mat2);
    double run_time = (double) (end - begin);
    printf("Execution time for OpenMp w/ %i operations: %f seconds\n", NUM_OPERATIONS, run_time);
    return 0;
}
