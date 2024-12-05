#include "image_processing.h"
#include "matrix_operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to allocate a matrix of given dimensions
UCH **alloc_matrix(int rows, int cols) {
    UCH **matrix = (UCH **)malloc(rows * sizeof(UCH *));
    if (!matrix) {
        printf("Memory allocation failed for matrix\n");
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (UCH *)malloc(cols * sizeof(UCH));
        if (!matrix[i]) {
            printf("Memory allocation failed for row %d\n", i);
            return NULL;
        }
    }

    return matrix;
}

// Function to free the memory used by the matrix
void clear_matrix(int rows, UCH **matrix) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to rotate a submatrix 90 degrees clockwise
void ascii_90(int *x1, int *y1, int *x2, int *y2, UCH **a) {
    UCH **a3 = alloc_matrix(*y2 - *y1, *x2 - *x1);
    if (!a3) {
        printf("malloc() failed\n");
        return;
    }

    int z, t = 0;
    // Copy the relevant submatrix from the original image into the new matrix
    for (int i = *y1; i < *y2; i++) {
        z = 0;
        for (int j = *x1; j < *x2; j++) {
            a3[t][z] = a[i][j];
            z++;
        }
        t++;
    }

    // Rotate the submatrix 90 degrees by transposing and reversing
    for (int i = 0; i < *y2 - *y1; i++) {
        for (int j = 0; j < *x2 - *x1; j++) {
            a[*y1 + i][*x1 + j] = a3[*y2 - *y1 - 1 - j][i];
        }
    }

    // Clean up memory used for the temporary rotated matrix
    clear_matrix(*y2 - *y1, a3);
}

// Function to rotate the entire image by 90 degrees
void rotate_image(int *x1, int *y1, int *x2, int *y2, UCH **a) {
    // Calls ascii_90 to rotate the specified section of the image by 90 degrees
    // This could be extended for 180 and 270 degrees by modifying the rotation logic
    ascii_90(x1, y1, x2, y2, a);
}
