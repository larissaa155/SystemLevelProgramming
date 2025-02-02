#include <stdio.h>
#include <time.h>

int main(void) {
    FILE* my_file; 
    int write_count;
    char str_to_write[] = "Hello There!";
    time_t start_time, stop_time;
    

    my_file = fopen("buffered.txt", "w"); 
    start_time = time(NULL);

    for (int i = 0; i < 1000000; i++) {
        write_count = fprintf(my_file, "%s\n", str_to_write); 
        printf("%d: %d characters written to buffered.txt\n", i, write_count);

    }

    stop_time = time (NULL);
    printf("Buffered IO Time Elapsed: %d seconds", stop_time - start_time);

    fclose(my_file);
}