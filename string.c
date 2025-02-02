// Filename: string.c
// Author: Faris Hawamdeh
// Date Created: January 24th 2024

# include <stdio.h> // Import the Standard I/O Library

int main(void) {
    char LastName[11];
    char FirstName[11];

    printf("Enter your name (last first): ");
    scanf("%s %s", LastName, FirstName);

    printf ("Nice to meet you %s %s\n\n", FirstName, LastName);

    return 0;
}