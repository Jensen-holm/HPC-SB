/*
 * =====================================================================================
 *
 *       Filename:  matrix.c
 *
 *    Description:  Matrix structure and simple operations 
 *
 *        Version:  1.0
 *        Created:  11/17/2023 15:54:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jensen Holm 
 *   Organization:  GVSU undergraduate research 
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    float *data;
    int total_elems;
} Matrix;


Matrix *new_matrix(int rows, int cols, int max) {
    Matrix *mat = (Matrix *) malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->total_elems = rows * cols;
    mat->data = (float *) malloc(mat->total_elems * sizeof(float));

    // Initialize matrix with random values
    for (int i = 0; i < mat->total_elems; i++) {
        mat->data[i] = (float) rand() / RAND_MAX * max;
    }

    return mat;
}


float index_matrix(Matrix *mat, int row, int col) {
    return mat->data[row * mat->cols + col];
}

void set_matrix_index(Matrix *mat, int row, int col, float val) {
    mat->data[row * mat->cols + col] = val;
}


void print_matrix(Matrix *mat) {
    printf("[");
    for (int row = 0; row < mat->rows; row++) {
        printf("[");

        for (int col = 0; col < mat->cols; col++) {
            printf("%f", index_matrix(mat, row, col));
            if (col != mat->cols - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (row != mat->rows - 1) {
            printf("\n");
        }
    }
    printf("]\n");
}


// Matrices are stored in the heap, so we need to free them
void free_matrix(Matrix *mat) {
    free(mat->data);
    free(mat);
}

