#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Declare variables for the coordinates and the command input
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    char command[100];  // Command buffer to store user input
    strcpy(command, "NULL");  // Initialize the command to avoid undefined behavior
    int loaded = 0;  // Flag to check if an image has been loaded
    UCH **mat = NULL;  // Pointer to the image matrix
    image v[2] = {0};  // Array to hold the image data (2 elements for two different states)

    // Start the command loop
    while (strcmp("EXIT", strtok(command, " "))) {
        scanf("%s", command);  // Get the command from the user

        // Handle the "LOAD" command
        if (strcmp("LOAD", command) == 0) {
            if (loaded) {
                clear_matrix(v[0].h, mat);  // Clear the previous image if it's loaded
            }
            char file[NMAX];  // File name buffer
            scanf("%s", file);  // Get the file name from user
            mat = load_matrix(mat, v, &loaded, file);  // Load the image matrix
            x1 = 0; y1 = 0; x2 = v[0].w; y2 = v[0].h;  // Update image dimensions
            continue;  // Skip to the next iteration
        }

        // Handle the "SELECT" command
        if (strcmp("SELECT", command) == 0) {
            if (loaded == 1) {
                select_file(&x1, &y1, &x2, &y2, v);  // Select a region in the image
            } else {
                printf("No image loaded\n");
                free_the_space();  // Free allocated memory
            }
            continue;
        }

        // Handle the "CROP" command
        if (strcmp("CROP", command) == 0) {
            if (loaded == 1) {
                mat = crop_image(&x1, &y1, &x2, &y2, v, mat);  // Crop the selected region
            } else {
                printf("No image loaded\n");
            }
            continue;
        }

        // Handle the "ROTATE" command
        if (strcmp("ROTATE", command) == 0) {
            if (loaded == 1) {
                mat = rotate(&x1, &y1, &x2, &y2, v, mat);  // Rotate the image
            } else {
                printf("No image loaded\n");
                free_the_space();  // Free allocated memory
            }
            continue;
        }

        // Handle the "SAVE" command
        if (strcmp("SAVE", command) == 0) {
            if (loaded == 1) {
                save_file(mat, v);  // Save the current image
            } else {
                printf("No image loaded\n");
                free_the_space();  // Free allocated memory
            }
            continue;
        }

        // Handle the "EXIT" command
        if (strcmp("EXIT", command) == 0) {
            if (loaded == 1) {
                clear_matrix(v[0].h, mat);  // Clear the loaded image
            } else {
                printf("No image loaded\n");
            }
            continue;
        }

        // Handle the "APPLY" command
        if (strcmp("APPLY", strtok(command, " ")) == 0) {
            if (loaded == 1) {
                apply_filter(x1, y1, x2, y2, v, mat);  // Apply a filter to the image
            } else {
                printf("No image loaded\n");
                free_the_space();  // Free allocated memory
            }
            continue;
        }

        // Invalid command handling
        printf("Invalid command\n");
        free_the_space();  // Free allocated memory in case of invalid input
    }

    return 0;
}
