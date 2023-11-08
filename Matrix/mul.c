#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <omp.h>
//#include <mpi.h>


// mat_mul -> normal matrix multiplication
// This function returns a matrix of zeros if the
// condition is not met
Matrix *mat_mul(Matrix *mat1, Matrix *mat2) {
    Matrix *product = new_matrix(mat1->rows, mat2->cols, 2.0);
    if (mat1->rows != mat2->cols) {
        printf("dimensions of matrices are invalid\n");
        return product;
    }

    for (int row = 0; row < mat1->rows; row++) {
        for (int col = 0; col < mat2->cols; col++) {
            float local_sum = 0;
            for (int inner = 0; inner < mat1->cols; inner++) {
                local_sum += mat1->data[row][inner] * mat2->data[inner][col];
            }
            product->data[row][col] = local_sum;
        }
    }
    return product;
}

// mat_mul_parallel -> parallel implementation of mat_mul() using OpenMp
Matrix *mat_mul_parallel(Matrix *mat1, Matrix *mat2) {
    Matrix *product = new_matrix(mat1->rows, mat2->cols, 2.0);
    if (mat1->rows != mat2->cols) {
        printf("dimensions of matrices are invalid\n");
        return product;
    }

#pragma omp parallel for
    for (int row = 0; row < mat1->rows; row++) {
        // I noticed that the parallelization of the inner loop
        // actually slowed down the program, so I commented it out
//#pragma omp parallel for
        for (int col = 0; col < mat2->cols; col++) {
            float local_sum = 0;
            for (int inner = 0; inner < mat1->cols; inner++) {
                local_sum += mat1->data[row][inner] * mat2->data[inner][col];
            }
            product->data[row][col] = local_sum;
        }
    }

    return product;
}

//Matrix *mat_mul_mpi(Matrix *mat1, Matrix *mat2) {
//    Matrix *product = new_matrix(mat1->rows, mat2->cols, 2.0);
//    if (mat1->rows != mat2->cols) {
//        printf("dimensions of matrices are invalid\n");
//        return product;
//    }
//
//    int num_processes, rank;
//    MPI_Comm_size(MPI_COMM_WORLD, &num_processes);
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//    int rows_per_process = mat1->rows / num_processes;
//    int remaining_rows = mat1->rows % num_processes;
//
//    // calculate the start and end rows for each process
//    int start_row = rank * rows_per_process;
//    int end_row = start_row + rows_per_process;
//    if (rank == num_processes - 1) {
//        end_row += remaining_rows;
//    }
//
//    for (int row = start_row; row < end_row; row++) {
//        for (int col = 0; col < mat2->cols; col++) {
//            float local_sum = 0;
//            for (int inner = 0; inner < mat1->cols; inner++) {
//                local_sum += mat1->data[row][inner] * mat2->data[inner][col];
//            }
//            product->data[row][col] = local_sum;
//        }
//    }
//
//    // if there are multiple mpi processes let's join the results
//    if (num_processes > 1) {
//        MPI_Gather(product->data[start_row], rows_per_process * mat2->cols, MPI_FLOAT, product->data[0],
//                   rows_per_process * mat2->cols, MPI_FLOAT, 0, MPI_COMM_WORLD
//    }
//
//    return product;
//}
