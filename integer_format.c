// Filename: integer_format.c
// Author: Faris Hawamdeh
// Date Created: January 24th 2024

# include <stdio.h> // Import the Standard I/O Library

int main(void) {
    int a = 5, b = 15;

    printf("The value of a is %d and the value of b is %i\n", a, b);

    printf("The value of a is %o and the value of b is %o (Base 8)\n", a, b);

    printf("The value of a is %x and the value of b is %x (Base 16)\n", a, b);

    return 0;
}