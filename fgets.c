// Filename: fgets.c
// Author: Faris Hawamdeh
// Date Created: January 24th 2024

# include <stdio.h> // Import the Standard I/O Library

int main(void) {
    FILE *my_file; // Create a FILE pointer
    char file_input[30]; // Create buffers to store file input
    char *result; // Create variables to store return values

    my_file = fopen("demo.txt", "r"); // Open the file for reading
    result = fgets(file_input, 30, my_file); // Read a single line from the file

    // Check to see if it was successfull
    if (result != NULL) {
        // Print the output
        printf("%s\n", file_input);
    }

    // close the file
    fclose(my_file);

    return 0;
}