// matrix.h
#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int cols;
    float **data;
} Matrix;

Matrix *new_matrix(int rows, int cols, int max);

void print_matrix(Matrix *mat);

void free_matrix(Matrix *mat);

#endif
