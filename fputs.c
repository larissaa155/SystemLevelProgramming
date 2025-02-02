// Filename: fputs.c
// Author: Faris Hawamdeh
// Date Created: January 24th 2024

# include <stdio.h> // Import the Standard I/O Library
# include <strings.h> // Import Stings library

int main(void) {
    FILE* my_file; // Create a FILE pointer
    char first_name[15], last_name[15]; // Create buffers to store user input
    int input_count, result; // Create variables to store return values

    printf("Please enter your first and last name: ");
    input_count = scanf("%s %s", first_name, last_name);

    if (input_count == 2) {
        my_file = fopen("demo.txt", "w"); // Open the file for reading writing

        result = fputs(strcat(last_name, first_name), my_file); // Write the name to the file

        if (result >= 0) {
            printf("Sucessfully wrote to file!\n");
        }
        else {
            printf("Error: Could not write to file!\n");
        }
        
    }

    fclose(my_file);
}