int new_matrix(int rows, int cols) {

    int matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand();
        }
    }

    return matrix;
}
