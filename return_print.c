// Filename: return_print.c
// Author: Faris Hawamdeh
// Date Created: January 24th 2024

# include <stdio.h> // Import the Standard I/O Library

int main(void) {
    int num1 = 5555, num2 = 30, sum, printCount;

    sum = num1 + num2;

    printCount = printf("%d + %d = %d\n", num1, num2, sum);

    printf("Characters printed: %d\n", printCount);

    return 0;
}