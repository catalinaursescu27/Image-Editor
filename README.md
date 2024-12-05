# Image-Editor

Copyright 2021-2022 314CA Ursescu Elena-Catalina

Assignment 3 - Computer Programming
...............................................................................

*It will use a structure consisting of 4 fields, representing the height, width, maximum value, and the type of image.

<LOAD>
    - This function will depend on 4 other functions:
    - The memory allocation function for a matrix.
    - The function for reading a matrix from a text file.
    - The function for reading a matrix from a binary file.
    - The function for checking the existence of comments, recognizable by the # character.
    - Each time an image is loaded, its characteristics will be read using the fields of the structure.

<SELECT>
    - This function will also include the <SELECT ALL> function by checking for the presence of the string "ALL" in the command.
    - The function includes several checks for parameters (whether they follow the order from the description, are positive numbers, fit within the image dimensions, or consist of a sequence of letters or other non-numeric characters).

<ROTATE>
    - This function depends on other functions:
    - The function to rotate a square matrix from a black-and-white image by 90 degrees.
    - The function to rotate the entire black-and-white image by 90 degrees.
    - The function to rotate a square matrix from a color image by 90 degrees, using the transpose for each RGB channel stored in a matrix.
    - The function to rotate the entire color image by 90 degrees, following the same method as for the square selection.
    - In the actual rotate function, the angle value will be checked, and the rotation will be performed using the functions designed for 90 degrees, calling them as needed, because this applies to angles that are multiples of 90.

<CROP>
    - This function will be implemented using a dynamically allocated auxiliary matrix, where the selected part of the original image will be stored and returned.

<APPLY>
    - This function will initially check the filter that should be applied.
    - For each filter, the corresponding kernel matrix will be initialized with the specified values.
    - Using an auxiliary matrix, the filter will be applied, utilizing the kernel and the original matrix, respecting the pixel values for each color channel.
    - This auxiliary matrix will be copied back into the original matrix at the end to prevent errors and modifications.

<SAVE>
    - For this function, two additional functions will be used:
    - A function to print the matrix to a text file.
    - A function to print the matrix to a binary file.
    - The characteristics of the image will also be printed using the structure.

<EXIT>
    - For the exit function, resources will be deallocated using a memory release function for a matrix.

<MAIN>
    - In main, depending on the command given from stdin, the previous functions will be called, or the corresponding message will
