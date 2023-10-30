#include "matrix.h"

int main(void) {
    struct matrix *mat1 = new_rand_matrix(3, 5, 10);
    struct matrix *mat2 = new_rand_matrix(10, 3, 10);
    struct matrix *product = new_empty_matrix(3, 3);

    // ignoring is valid integer because the mat mul
    // condition will always be met in this test
    int invalid = mat_mul(mat1, mat2, product);
    if (invalid) {
        printf("matrix multiplication conditions not met for matrices of dims '%ix%i' & '%ix%i'",
               mat1->rows, mat1->cols, mat2->rows, mat2->cols);
    }

    printf(" --- Matrix Multiplication ---\n");
    print_matrix(mat1);
    printf(" X \n");
    print_matrix(mat2);
    printf(" = \n");
    print_matrix(product);
    printf("\n");

    free_matrix(product);
    free_matrix(mat1);
    free_matrix(mat2);
    return 0;
}
