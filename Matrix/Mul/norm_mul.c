/*
 * =====================================================================================
 *
 *       Filename:  norm_mul.c
 *
 *    Description:  matrix multiplication without any HPC optimization 
 *
 *        Version:  1.0
 *        Created:  11/17/2023 16:10:30
 *       Revision:  none
 *       Compiler:  gcc-12
 *
 *         Author:  Jensen Holm 
 *   Organization:  GVSU undergraduate research 
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "../matrix.h"


Matrix *mat_mul(Matrix *mat1, Matrix *mat2) {
    Matrix *product = new_matrix(mat1->rows, mat2->cols, 2.0);
    if (mat1->rows != mat2->cols) {
            printf("dimensions of matrices are invalid\n");
            return product;
    };

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


