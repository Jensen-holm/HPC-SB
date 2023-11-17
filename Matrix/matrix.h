/*
 * =====================================================================================
 *
 *       Filename:  matrix.h
 *
 *    Description:  header file for matrix.c 
 *
 *        Version:  1.0
 *        Created:  11/17/2023 15:55:55
 *       Revision:  none
 *       Compiler:  gcc-12
 *
 *         Author:  Jensen Holm 
 *   Organization:  GVSU undergraduate research 
 *
 * =====================================================================================
 */

#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;
    int cols;
    float **data;
} Matrix;

Matrix *new_matrix(int rows, int cols, int max);

float index_matrix(Matrix *mat, int row, int col);

void set_matrix_index(Matrix *mat, int row, int col, float val);

void print_matrix(Matrix *mat);

void free_matrix(Matrix *mat);

#endif

