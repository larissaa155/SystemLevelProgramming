#include <stdio.h>
#include <stdlib.h>

int main(void ) {
    FILE * text_file; 
    char file_input[200];

    text_file = fopen("lab03.txt", "t");

    while(fgets(file_input, 200, text_file) != NULL) {
        printf("ls\n", file_input);
    }

    fclose(text_file);
    return 0;

}