#include <stdio.h>

void swap(char *left, char *right) {
    char temp = *left;
    *left = *right;
    *right = temp;
}

void reverseString(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++ ;
    }
    
    for (int i = 0; i < len / 2; i++) {
    swap (&str[i], &str[len - i - 1]);
} 

}

int main() {
    char userString[100];
    
    printf("Enter a string: ");
    fgets(userString, sizeof(userString), stdin);

    userString[strcspn(userString, "\n")] = '\0';

    printf("Original string: %s\n", userString);

    reverseString(userString);

    printf("Reversed string: %s\n", userString);

    return 0;

}
 
