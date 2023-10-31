#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// mat_mul -> normal matrix multiplication
// This function returns a matrix of zeros if the
// condition is not met
Matrix *mat_mul(Matrix *mat1, Matrix *mat2) {
    Matrix *product = new_matrix(mat1->rows, mat2->cols, 0);
    if (mat1->rows != mat2->cols) {
        printf("dimensions of matrices are invalid\n");
        return product;
    }

    for (int row = 0; row < mat1->rows; row++) {
        for (int col = 0; col < mat2->cols; col++) {
            product->data[row][col] = 0;
            for (int inner = 0; inner < mat1->cols; inner++) {
                product->data[row][col] += mat1->data[row][inner] * mat2->data[inner][col];
            }
        }
    }
    return product;
}


// mat_mul_parallel -> parallel implementation of mat_mul() using OpenMp
Matrix *mat_mul_parallel(Matrix *mat1, Matrix *mat2) {
    if (mat1->rows != mat2->cols) {
        printf("dimensions of matrices are invalid\n");
        exit(1);
    }

    Matrix *product = new_matrix(mat1->rows, mat2->cols, 0);
    return product;
}
