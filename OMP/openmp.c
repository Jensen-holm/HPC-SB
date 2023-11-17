/*
 * =====================================================================================
 *
 *       Filename:  openmp.c
 *
 *    Description:  For testing the performance of matrix multiplication using OpenMP 
 *
 *        Version:  1.0
 *        Created:  11/17/2023 15:56:58
 *       Revision:  none
 *       Compiler:  gcc-12
 *
 *         Author:  Jensen Holm 
 *   Organization:  GVSU undergraduate research 
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Matrix/matrix.h"
#include "../Matrix/Mul/omp_mul.h"


#define DIMSX 500
#define DIMSY 500
#define MAX_VAL 10000


int main(int argc, char *argv[]) {
    if (!argv[1]) {
        printf("Please specify an argument for num operations.\n");
        return 1;
    }

    int NUM_OPERATIONS = atoi(argv[1]);
    if (NUM_OPERATIONS == 0 && *argv[1] != '0') {
        printf("Invalid argument for num operations '%s'\n", argv[1]);
        return 1;
    }

    Matrix *mat1 = new_matrix(DIMSX, DIMSY, MAX_VAL);
    Matrix *mat2 = new_matrix(DIMSY, DIMSX, MAX_VAL);

    // set up wall clock timing
    struct timespec start, end;

    clock_gettime(CLOCK_REALTIME, &start);
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        Matrix *product = mat_mul_omp(mat1, mat2);
        free_matrix(product);
    }
    clock_gettime(CLOCK_REALTIME, &end);

    // calculate elapsed wall clock time
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("%f", elapsed);

    free_matrix(mat1);
    free_matrix(mat2);
    return 0;
}

