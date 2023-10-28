#include <stdlib.h>


struct matrix 
{
    int rows;
    int cols;
    int data_points;
    int* data;
};

struct matrix* new_empty_matrix(int rows, int cols)
{
    struct matrix* mat = (struct matrix*) malloc(sizeof(struct matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data_points = rows * cols;
    mat->data = (int*) malloc(mat->data_points * sizeof(int));

    // fill all values with 0 to avoid garbage values
    for (int i = 0; i < mat->data_points; i++) {
        mat->data[i] = 0;
    }

    return mat;
}

struct matrix* new_rand_matrix(int rows, int cols)
{
    struct matrix* mat = (struct matrix*) malloc(sizeof(struct matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data_points = rows * cols;
    mat->data = (int*) malloc(mat->data_points * sizeof(int));

    // fill all values with 0 to avoid garbage values
    for (int i = 0; i < mat->data_points; i++) {
        mat->data[i] = rand();
    }

    return mat;
}

void print_matrix(struct matrix* mat) 
{
    printf("[\n");
    for (int r = 0; r < mat->rows; r++) {
        printf("[");
        for (int c = 0; c < mat->cols; c++) {
            printf("%i, ", mat->data[r + c]);
        }
        printf("]\n");
    }
    printf("]\n");
}


int mat_mul(struct matrix* m1, struct matrix* m2, struct matrix* result)
{
    // check if matrix multiplication pre reqs are met
    // if not return 1 (error), if it is met, do mat mul
    // and assign result to pointer in parameters

    // number of cols from m2 should be the same as m1 rows
    int cols = m2->cols;
    int rows = m1->rows;
    if (cols != rows) {
        return 1;
    }

    // assign the result matrix the correct dims
    result->rows = rows;
    result->cols = cols;
    result->data = (int*) malloc(rows * cols * sizeof(int));

    return 0;
}


void free_matrix(struct matrix* mat) {
    free(mat);
    free(mat->data);
}
