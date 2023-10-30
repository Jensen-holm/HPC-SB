#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct matrix
{
    int rows;
    int cols;
    int data_points;
    float *data;
};

struct matrix *new_empty_matrix(int rows, int cols)
{
    struct matrix *mat = (struct matrix *)malloc(sizeof(struct matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data_points = rows * cols;
    mat->data = (float *)malloc(mat->data_points * sizeof(float));

    // fill all values with 0 to avoid garbage values
    for (int i = 0; i < mat->data_points; i++)
    {
        mat->data[i] = 0.0;
    }

    return mat;
}

struct matrix *new_rand_matrix(int rows, int cols, int max)
{
    srand(time(NULL));
    struct matrix *mat = (struct matrix *)malloc(sizeof(struct matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data_points = rows * cols;
    mat->data = (float *)malloc(mat->data_points * sizeof(float));

    // fill all values with 0 to avoid garbage values
    for (int i = 0; i < mat->data_points; i++)
    {
        mat->data[i] = rand() % max;
    }

    return mat;
}

void print_matrix(struct matrix *mat)
{
    printf("[\n");
    for (int r = 0; r < mat->rows; r++)
    {
        printf("[");
        for (int c = 0; c < mat->cols; c++)
        {
            printf("%f, ", mat->data[r + c]);
        }
        printf("]\n");
    }
    printf("]\n");
}

int mat_mul(struct matrix *m1, struct matrix *m2, struct matrix *product)
{
    // check if matrix multiplication pre reqs are met
    // if not return 1 (error), if it is met, do mat mul
    // and assign result to pointer in parameters

    // number of cols from m2 should be the same as m1 rows
    int cols = m2->cols;
    int rows = m1->rows;
    if (cols != rows)
    {
        return 1;
    }

    int cols1 = m1->cols;
    int cols2 = m2->cols;
    int rows1 = m1->rows;
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            float sum = 0.0;
            for (int k = 0; k < cols1; k++)
            {
                sum += m1->data[i * cols1 + k] * m2->data[k * cols2 + j];
            }
            product->data[i * cols2 + j] = sum;
        }
    }
    return 0;
}

void free_matrix(struct matrix *mat)
{
    free(mat->data);
    free(mat);
}
