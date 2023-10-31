#include "matrix.h"
#include "mul.h"
#include <stdio.h>

int main(void) {
    Matrix *mat1 = new_matrix(3, 3, 10);
    Matrix *mat2 = new_matrix(3, 3, 10);
    Matrix *product = mat_mul(mat1, mat2);
    Matrix *product_parallel = mat_mul_parallel(mat1, mat2);

    printf(" --- Matrix Multiplication Naive ---\n");
    print_matrix(mat1);
    printf(" X \n");
    print_matrix(mat2);
    printf(" = \n");
    print_matrix(product);
    printf("\n");

    printf(" --- Matrix Multiplication Parallel ---\n");
    print_matrix(mat1);
    printf(" X \n");
    print_matrix(mat2);
    printf(" = \n");
    print_matrix(product_parallel);
    printf("\n");

    free_matrix(mat1);
    free_matrix(mat2);
    free_matrix(product);
    free_matrix(product_parallel);
    return 0;
}
