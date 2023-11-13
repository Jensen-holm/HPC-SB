#include "matrix.h"
#include "mul.h"
#include <stdio.h>

// This is a test file for the matrix multiplication functions
// compile and run it to see the results of the matrix multiplication
int main(void) {
    Matrix *mat1 = new_matrix(2, 3, 100);
    Matrix *mat2 = new_matrix(3, 2, 100);

    Matrix *product = mat_mul(mat1, mat2);

    Matrix *product_parallel = mat_mul_parallel(mat1, mat2);

    printf(" --- Matrix Multiplication Naive ---\n");
    print_matrix(mat1);
    printf(" X \n");
    print_matrix(mat2);
    printf(" = \n");
    print_matrix(product);
    printf("\n");

    printf("\n --- Matrix Multiplication Parallel ---\n");
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
