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

    clock_t naive_begin = clock();
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        Matrix *product = mat_mul(mat1, mat2);
        free_matrix(product);
    }
    clock_t naive_end = clock();

    free_matrix(mat1);
    free_matrix(mat2);
    double naive_run_time = (double) (naive_end - naive_begin) / CLOCKS_PER_SEC;
    printf("%f", naive_run_time);

}
