#include "../matrix.h"
#include <stdio.h>


Matrix *mat_mul_mpi(Matrix *mat1, Matrix *mat2) {
    if (mat1->cols != mat2->rows) {
        printf("Error: Matrix dimensions do not match\n");
        return NULL;
    }

    Matrix *product = new_matrix(mat1->rows, mat2->cols, 2.0);

    return product;
}

