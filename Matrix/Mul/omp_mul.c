/*
 * =====================================================================================
 *
 *       Filename:  omp_mul.c
 *
 *    Description:  OpenMP matrix multiplication 
 *
 *        Version:  1.0
 *        Created:  11/17/2023 15:53:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jensen Holm 
 *   Organization:  GVSU undergraduate research
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <omp.h>
#include "../matrix.h"


Matrix *mat_mul_omp(Matrix *mat1, Matrix *mat2) {
    if (mat1->rows != mat2->cols) {
        printf("dimensions of matrices are invalid\n");
        return NULL;
    }

    Matrix *product = new_matrix(mat1->rows, mat2->cols, 2.0);
#pragma omp parallel for
    for (int row = 0; row < mat1->rows; row++) {
        // I noticed that the parallelization of the inner loop
        // actually slowed down the program in some instances but
        // I am leaving it here for now
// #pragma omp parallel for
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



