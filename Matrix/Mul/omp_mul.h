/*
 * =====================================================================================
 *
 *       Filename:  omp_mul.h
 *
 *    Description:  Header file for omp_mul.c 
 *
 *        Version:  1.0
 *        Created:  11/17/2023 16:09:27
 *       Revision:  none
 *       Compiler:  gcc-12
 *
 *         Author:  Jensen Holm 
 *   Organization:  GVSU undergraduate research 
 *
 * =====================================================================================
 */

#ifndef OMP_MUL_H
#define OMP_MUL_H

#include "../matrix.h"

Matrix *mat_mul_omp(Matrix *mat1, Matrix *mat2);

#endif

