#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

struct matrix {
    int rows;
    int cols;
    int data_points;
    int *data;
};

struct matrix *new_empty_matrix(int rows, int cols) {
    struct matrix *mat = (struct matrix *) malloc(sizeof(struct matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data_points = rows * cols;
    mat->data = (int*) malloc(mat->data_points * sizeof(float));

    for (int i = 0; i < mat->data_points; i++) {
        mat->data[i] = 0;
    }
    return mat;
}

struct matrix *new_rand_matrix(int rows, int cols, int max) {
    srand(time(NULL));
    struct matrix *mat = (struct matrix *) malloc(sizeof(struct matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data_points = rows * cols;
    mat->data = (int *) malloc(mat->data_points * sizeof(float));

    for (int i = 0; i < mat->data_points; i++) {
        mat->data[i] = rand() % max;
    }
    return mat;
}

void print_matrix(struct matrix *mat) {
    printf("[");
    for (int row = 0; row < mat->rows; row++) {
        printf("[");
        for (int col = 0; col < mat->cols; col++) {
            int index = row * mat->cols + col;
            printf("%i, ", mat->data[index]);
        }
        if (row != mat->rows - 1) {
            printf("]\n");
        } else {
            printf("]]\n");
        }
    }
}

void free_matrix(struct matrix *mat) {
    free(mat->data);
    free(mat);
}

int mat_mul_check_condition(int rows, int cols, struct matrix *product) {
    if (rows != cols) {
        return 1;
    }
    if (product->rows != rows || product->cols != cols) {
        return 1;
    }
    return 0;
}

// naive matrix multiplication
int mat_mul(struct matrix *mat1, struct matrix *mat2, struct matrix *product) {
    int rows = mat1->rows;
    int cols = mat2->cols;
    int invalid = mat_mul_check_condition(rows, cols, product);
    if (invalid) {
        return 1;
    }

    int inner_dim = mat1->cols;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int product_index = row * cols + col;
            product->data[product_index] = 0;
            for (int inner_col = 0; inner_col < inner_dim; inner_col++) {
                int mat1_index = row * inner_dim + inner_col;
                int mat2_index = inner_col * cols + col;
                product->data[product_index] += (mat1->data[mat1_index] * mat2->data[mat2_index]);
            }
        }
    }
    return 0;
}

// parallel version of matrix multiplication
int mat_mul_parallel(struct matrix *mat1, struct matrix *mat2, struct matrix *product) {
    int rows = mat1->rows;
    int cols = mat2->cols;
    int invalid = mat_mul_check_condition(rows, cols, product);
    if (invalid) {
        return 1;
    }
    return 0;
}
