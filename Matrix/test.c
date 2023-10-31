#include "matrix.h"
#include "mul.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    Matrix *mat1 = new_matrix(3, 3, 10);
    Matrix *mat2 = new_matrix(3, 3, 10);

    clock_t begin = clock();
    Matrix *product = mat_mul(mat1, mat2);
    clock_t end = clock();

    double compute_time = (double) (begin - end) / CLOCKS_PER_SEC;
    printf("compute time: %f", compute_time);

    printf(" --- Matrix Multiplication ---\n");
    print_matrix(mat1);
    printf(" X \n");
    print_matrix(mat2);
    printf(" = \n");
    print_matrix(product);
    printf("\n");

    free_matrix(mat1);
    free_matrix(mat2);
    free_matrix(product);
    return 0;
}
