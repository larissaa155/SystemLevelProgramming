nnnmm                                                                                                                     // Filename: fprintf.c
// Author: Faris Hawamdeh
// Date Created: January 24th 2024

# include <stdio.h> // Import the Standard I/O Library

int main(void) {
    FILE* my_file; // Create a FILE pointer
    char first_name[15], last_name[15]; // Create buffers to store user input
    int input_count, write_count; // Create variables to store return values

    printf("Please enter your first and last name: ");
    input_count = scanf("%s %s", first_name, last_name);

    if (input_count == 2) {
        my_file = fopen("demo.txt", "w"); // Open the file for writing

        write_count = fprintf(my_file, "%s, %s\n", last_name, first_name); // Write the name to the file

        printf("%d characters written to demo.txt\n", write_count);
    }

    fclose(my_file);
}