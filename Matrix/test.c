#include "matrix.h"
#include "mul.h"
#include <stdio.h>
#include <time.h>

int main(void) {
    Matrix *mat1 = new_matrix(2, 3, 100);
    Matrix *mat2 = new_matrix(3, 2, 100);

    clock_t naive_start = clock();
    Matrix *product = mat_mul(mat1, mat2);
    clock_t naive_end = clock();
    double naive_runtime = (double)(naive_end - naive_start) / CLOCKS_PER_SEC;

    clock_t parallel_start = clock();
    Matrix *product_parallel = mat_mul_parallel(mat1, mat2);
    clock_t parallel_end = clock();
    double parallel_runtime = (double)(parallel_end - parallel_start) / CLOCKS_PER_SEC;

    printf(" --- Matrix Multiplication Naive ---\n");
    print_matrix(mat1);
    printf(" X \n");
    print_matrix(mat2);
    printf(" = \n");
    print_matrix(product);
    printf("\n");
    printf("Naive Runtime: %f\n", naive_runtime);

    printf("\n --- Matrix Multiplication Parallel ---\n");
    print_matrix(mat1);
    printf(" X \n");
    print_matrix(mat2);
    printf(" = \n");
    print_matrix(product_parallel);
    printf("\n");
    printf("Parallel Runtime: %f\n", parallel_runtime);

    free_matrix(mat1);
    free_matrix(mat2);
    free_matrix(product);
    free_matrix(product_parallel);
    return 0;
}
