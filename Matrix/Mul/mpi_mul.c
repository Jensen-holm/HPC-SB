/*
 * =====================================================================================
 *
 *       Filename:  mpi_mul.c
 *
 *    Description:  Matrix multiplication using MPI 
 *
 *        Version:  1.0
 *        Created:  11/17/2023 15:51:47
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
#include <mpi.h>
#include "../matrix.h"


Matrix *mat_mul_mpi(Matrix *mat1, Matrix *mat2, int size, int rank) {
    if (mat1->cols != mat2->rows) {
        printf("Error: Matrix dimensions do not match\n");
        return NULL;
    }

    Matrix *product = new_matrix(mat1->rows, mat2->cols, 2.0);

    return product;
}


