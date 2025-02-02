     // Filename: fscanf.c
// Author: Faris Hawamdeh
// Date Created: January 24th 2024

# include <stdio.h> // Import the Standard I/O Library

int main(void) {
    FILE* my_file; // Create a FILE pointer
    char first_name[15], last_name[15]; // Create buffers to store file input
    int read_count; // Create variables to store return values

    my_file = fopen("demo.txt", "r"); // Open the file for reading
    read_count = fscanf(my_file,"%s %s", last_name, first_name);

    if (read_count == 2) {
        printf("%s %s\n", first_name, last_name);
    }

    fclose(my_file);
}