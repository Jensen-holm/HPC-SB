#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

typedef struct {
    int rows;
    int cols;
    float **data;
} Matrix;


Matrix *new_matrix(int rows, int cols, int max) {
    Matrix *mat = (Matrix *) malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;

    mat->data = (float **) malloc(rows * sizeof(float *));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (float *) malloc(cols * sizeof(float));
        for (int j = 0; j < cols; j++) {
            float rand_num = rand() % max;
            mat->data[i][j] = rand_num;
        }
    }

    return mat;
}


void print_matrix(Matrix *mat) {
    printf("[");
    for (int row = 0; row < mat->rows; row++) {
        printf("[");

        for (int col = 0; col < mat->cols; col++) {
            printf("%f", mat->data[row][col]);
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


void free_matrix(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
}
