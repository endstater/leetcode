#include <stdio.h>
#include <stdlib.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    for (int m = 1; m < *matrixColSize; ++m) {
        int needed = matrix[0][m];
        for (int i = 0, j = m; i < matrixSize && j < *matrixColSize ; ++i, ++j) {
            if (needed != matrix[i][j]) {
                return false;
            }
        }
    }
    for (int m = 0; m < matrixSize; ++m) {
        int needed = matrix[m][0];
        for (int i = m, j = 0; i < matrixSize && j < *matrixColSize ; ++i, ++j) {
            if (needed != matrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int rows = 3, cols = 4;

    int **matrix = (int **)malloc(rows * sizeof(int *));

    for(int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3; matrix[0][3] = 4;
    matrix[1][0] = 5; matrix[1][1] = 1; matrix[1][2] = 2; matrix[1][3] = 3;
    matrix[2][0] = 9; matrix[2][1] = 5; matrix[2][2] = 1; matrix[2][3] = 2;

    bool isToeplitz = isToeplitzMatrix(matrix, rows, &cols);

    printf("%b\n", isToeplitz);

    return 0;
}