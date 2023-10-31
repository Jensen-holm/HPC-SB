// mul.h
#ifndef MUL_H
#define MUL_H

#include "matrix.h"

Matrix *mat_mul(Matrix *mat1, Matrix *mat2);

Matrix *mat_mul_parallel(Matrix *mat1, Matrix *mat2);

#endif
