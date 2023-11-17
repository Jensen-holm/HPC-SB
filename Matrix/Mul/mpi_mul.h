/*
 * =====================================================================================
 *
 *       Filename:  mpi_mul.h
 *
 *    Description:  Header file for MPI matrix multiplication (mpi_mul.c) 
 *
 *        Version:  1.0
 *        Created:  11/17/2023 16:08:23
 *       Revision:  none
 *       Compiler:  mpicc
 *
 *         Author:  Jensen Holm 
 *   Organization:  GVSU undergraduate research 
 *
 * =====================================================================================
 */

#ifndef MPI_MUL_H
#define MPI_MUL_H

#include "../matrix.h"

Matrix *mat_mul_mpi(Matrix *mat1, Matrix *mat2);

#endif

