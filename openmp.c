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

    int dims1 = rand() % 500;
    int dims2 = rand() % 500;
    Matrix *mat1 = new_matrix(dims1, dims2, 10000);
    Matrix *mat2 = new_matrix(dims2, dims1, 10000);

    // set up timing
    struct timespec start, end;

    clock_gettime(CLOCK_REALTIME, &start);
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        Matrix *product = mat_mul_parallel(mat1, mat2);
        free_matrix(product);
    }
    clock_gettime(CLOCK_REALTIME, &end);

    // calculate elapsed time
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("%f", elapsed);

    free_matrix(mat1);
    free_matrix(mat2);
    return 0;
}

