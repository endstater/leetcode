#include <stdio.h>
#include <stdlib.h>

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int counter = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 0) continue;
            if (i == 0 || grid[i - 1][j] == 0) counter++;
            if (j == 0 || grid[i][j - 1] == 0) counter++;
            if (i == gridSize - 1 || grid[i + 1][j] == 0) counter++;
            if (j == gridColSize[0] - 1 || grid[i][j + 1] == 0) counter++;
        }
    }
    return counter;
}

int main() {
    int rows = 4, cols = 4;

    int **matrix = (int **)malloc(rows * sizeof(int *));

    for(int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    matrix[0][0] = 0; matrix[0][1] = 1; matrix[0][2] = 0; matrix[0][3] = 0;
    matrix[1][0] = 1; matrix[1][1] = 1; matrix[1][2] = 1; matrix[1][3] = 0;
    matrix[2][0] = 0; matrix[2][1] = 1; matrix[2][2] = 0; matrix[2][3] = 0;
    matrix[3][0] = 1; matrix[3][1] = 1; matrix[3][2] = 0; matrix[3][3] = 0;

    int perimeter = islandPerimeter(matrix, rows, &cols);

    printf("%d\n", perimeter);

    return 0;
}