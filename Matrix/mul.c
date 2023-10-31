#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// mat_mul -> normal matrix multiplication
Matrix *mat_mul(Matrix *mat1, Matrix *mat2) {
    if (mat1->rows != mat2->cols) {
        printf("dimensions of matrices are invalid\n");
        exit(1);
    }

    Matrix *product = new_matrix(mat1->rows, mat2->cols, 0);
    for (int row = 0; row < mat1->rows; row++) {
        for (int col = 0; col < mat2->cols; col++) {
            for (int inner = 0; inner < mat1->cols; inner++) {
                product->data[row][col] = mat1->data[row][inner] * mat2->data[inner][col];
            }
        }
    }
    return product;
}
