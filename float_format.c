// Filename: float_format.c
// Author: Faris Hawamdeh
// Date Created: January 24th 2024

# include <stdio.h> // Import the Standard I/O Library

int main(void) {
    float a = 5.0, b = 0.000045;

    printf("The value of a is %f and the value of b is %f\n", a, b);

    printf("The value of a is %e and the value of b is %e\n", a, b);

    printf("The value of a is %g and the value of b is %g\n", a, b);

    return 0;
}