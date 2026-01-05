#include <stdio.h>
#include <stdlib.h>

int mabs(int n) {
    if (n < 0) return -n;
    return n;
}

long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    long long sum = 0;
    int even = 0;
    int min = 1000000;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] < 0) even++;
            int elem = mabs(matrix[i][j]);
            sum += elem;
            if (elem < min) min = elem;
        }
    }
    if (even % 2 != 0) {
        sum-=2*min;
    }
    return sum;
}

int main() {
    int rows = 3, cols = 3;

    int **matrix = (int **)malloc(rows * sizeof(int *));

    for(int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
    matrix[1][0] = -1; matrix[1][1] = -2; matrix[1][2] = -3;
    matrix[2][0] = 1; matrix[2][1] = 2; matrix[2][2] = 3;

    long long sum = maxMatrixSum(matrix, rows, &cols);

    printf("%d\n", sum);

    return 0;
}
