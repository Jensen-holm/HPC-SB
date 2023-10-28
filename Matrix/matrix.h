struct matrix 
{
    int rows;
    int cols;
    int* data;
};

struct matrix* new_matrix(int rows, int cols)
{
    struct matrix* mat;
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int*) malloc(rows * cols * sizeof(int));
    return mat;
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
