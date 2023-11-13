#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <omp.h>


// mat_mul -> normal matrix multiplication
// This function returns a matrix of zeros if the
// condition is not met
Matrix *mat_mul(Matrix *mat1, Matrix *mat2) {
    Matrix *product = new_matrix(mat1->rows, mat2->cols, 2.0);
    if (mat1->rows != mat2->cols) {
        printf("dimensions of matrices are invalid\n");
        return product;
    }

    for (int row = 0; row < mat1->rows; row++) {
        for (int col = 0; col < mat2->cols; col++) {
            float local_sum = 0;
            for (int inner = 0; inner < mat1->cols; inner++) {
                local_sum += index_matrix(mat1, row, inner) * index_matrix(mat2, inner, col);
            }

            set_matrix_index(product, row, col, local_sum);
        }
    }
    return product;
}

// mat_mul_parallel -> parallel implementation of mat_mul() using OpenMp
Matrix *mat_mul_parallel(Matrix *mat1, Matrix *mat2) {
    Matrix *product = new_matrix(mat1->rows, mat2->cols, 2.0);
    if (mat1->rows != mat2->cols) {
        printf("dimensions of matrices are invalid\n");
        return product;
    }

#pragma omp parallel for
    for (int row = 0; row < mat1->rows; row++) {
        // I noticed that the parallelization of the inner loop
        // actually slowed down the program in some instances but
        // I am leaving it here for now
        for (int col = 0; col < mat2->cols; col++) {
            float local_sum = 0;
            for (int inner = 0; inner < mat1->cols; inner++) {
                local_sum += index_matrix(mat1, row, inner) * index_matrix(mat2, inner, col);
            }

            set_matrix_index(product, row, col, local_sum);
        }
    }
    return product;
}

