#include "file_operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to load an image from a file (example for BMP format)
UCH** load_image(const char* filename, int* x1, int* y1, int* x2, int* y2) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Failed to open file: %s\n", filename);
        return NULL;
    }

    // Assuming the image is in a simple format where width and height are provided
    // Normally, more parsing is needed for a real image format (e.g., BMP, PNG)
    fseek(file, 18, SEEK_SET);  // Skip the header (example: BMP header)

    // Read image dimensions (for example, BMP files store width and height at certain positions)
    fread(x2, sizeof(int), 1, file);
    fread(y2, sizeof(int), 1, file);

    // Allocate memory for the image matrix (width x height)
    UCH **a = alloc_matrix(*y2, *x2);
    if (!a) {
        fclose(file);
        return NULL;
    }

    // Move the file pointer to the start of pixel data
    fseek(file, 54, SEEK_SET);  // Skip the header (example: BMP header)

    // Read pixel data into the matrix
    for (int i = 0; i < *y2; i++) {
        for (int j = 0; j < *x2; j++) {
            fread(&a[i][j], sizeof(UCH), 1, file);
        }
    }

    fclose(file);
    return a;
}

// Function to save an image to a file (example for BMP format)
void save_image(const char* filename, UCH **a, int x1, int y1, int x2, int y2) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Failed to open file for writing: %s\n", filename);
        return;
    }

    // Write a basic BMP header (for simplicity, skipping detailed header fields)
    unsigned char header[54] = {0x42, 0x4D, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00};
    fwrite(header, sizeof(unsigned char), 54, file); // Basic header for a BMP file

    // Write image dimensions (for example, BMP files store width and height at certain positions)
    fwrite(&x2, sizeof(int), 1, file);
    fwrite(&y2, sizeof(int), 1, file);

    // Write pixel data from the matrix
    for (int i = 0; i < y2; i++) {
        for (int j = 0; j < x2; j++) {
            fwrite(&a[i][j], sizeof(UCH), 1, file);
        }
    }

    fclose(file);
}
