// Filename: multi_format.c
// Author: Faris Hawamdeh
// Date Created: January 24th 2024

# include <stdio.h> // Import the Standard I/O Library

int main(void) {
    int x = 5, y = 7;
    float rate = 0.07f;

    printf("x = %d\n", x);
    printf("%d + %d = %d\n", x, y, x + y);
    printf("Rate is %d%%\n", (int) (rate * 100) );

    return 0;
}