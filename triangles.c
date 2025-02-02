// Filename: triangles.c
// Author: Faris Hawamdeh
// Date Created: January 22nd 2024

# include <stdio.h> // Import the Standard I/O Library
# include <math.h>  // Import the Math Library

int main(void) {
    float a = 5, b = 10, c = 7;   // Initialize the variables for each side of our triangle
    float alpha, beta, gamma;     // Declare our variables for each of the angles
    float alpha_degrees, beta_degrees, gamma_degrees;

    alpha = acos( ( pow(b, 2) + pow(c, 2) - pow(a, 2) ) / (2 * b * c) );    // Use arc cosine function from math funtion to compute value of angle alpha

    beta = acos( ( pow(a, 2) + pow(c, 2) - pow(b, 2) ) / (2 * a * c) );     // Use arc cosine function from math funtion to compute value of angle beta

    gamma = acos( ( pow(a, 2) + pow(b, 2) - pow(c, 2) ) / (2 * a * b) );    // Use arc cosine function from math funtion to compute value of angle gamma

    alpha_degrees = alpha * 180 / M_PI;     // Convert alpha from radians to degrees
    beta_degrees = beta * 180 / M_PI;       // Convert beta from radians to degrees
    gamma_degrees = gamma * 180 / M_PI;     // Convert gamma from radians to degrees

    printf("The value of alpha is %f radians or %f degrees.\n", alpha, alpha_degrees);   // Print out the value of our calculated alpha

    printf("The value of beta is %f degrees or %f degrees.\n", beta, beta_degrees);     // Print out the value of our calculated beta

    printf("The value of gamma is %f degree or %f degrees.\n", gamma, gamma_degrees);   // Print out the value of our calculated gamma

    return 0;
}