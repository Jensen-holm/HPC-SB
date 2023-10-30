#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

struct matrix {
    int rows;
    int cols;
    int data_points;
    float *data;
};

struct matrix *new_empty_matrix(int rows, int cols) {
    struct matrix *mat = (struct matrix *) malloc(sizeof(struct matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data_points = rows * cols;
    mat->data = (float *) malloc(mat->data_points * sizeof(float));

    for (int i = 0; i < mat->data_points; i++) {
        mat->data[i] = 0.0;
    }
    return mat;
}

struct matrix *new_rand_matrix(int rows, int cols, int max) {
    srand(time(NULL));
    struct matrix *mat = (struct matrix *) malloc(sizeof(struct matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data_points = rows * cols;
    mat->data = (float *) malloc(mat->data_points * sizeof(float));

    for (int i = 0; i < mat->data_points; i++) {
        mat->data[i] = rand() % max;
    }
    return mat;
}

void print_matrix(struct matrix *mat) {
    printf("[\n");
    for (int row = 0; row < mat->rows; row++) {
        printf("[");
        for (int col = 0; col < mat->cols; col++) {
            printf("%f, ", mat->data[row + col]);
        }
        printf("]\n");
    }
    printf("]\n");
}

int mat_mul(struct matrix *mat1, struct matrix *mat2, struct matrix *product) {
    int rows = mat1->rows;
    int cols = mat2->cols;
    if (cols != rows) {
        return 1;
    }

    if (product->rows != rows || product->cols != cols) {
        return 1;
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int sum = 0;
            for (int inner_col = 0; inner_col < mat1->cols; inner_col++) {
                sum += mat1->data[row * cols + inner_col] * mat2->data[inner_col * cols + col];
            }
            product->data[row * cols + col] = sum;
        }
    }
    return 0;
}


int mat_mul_parallel(struct matrix *mat1, struct matrix *mat2, struct matrix *product) {
    int rows = mat1->rows;
    int cols = mat2->cols;
    if (rows != cols) {
        return 1;
    }

    if (product->rows != rows || product->cols != cols) {
        return 1;
    }

    // setting up

}

void free_matrix(struct matrix *mat) {
    free(mat->data);
    free(mat);
}
