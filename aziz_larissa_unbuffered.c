#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int fd, bytes_written;
    char str_to_write[] = "Hello There!\n";
    time_t start_time, stop_time;

    fd = open("unbuffered.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("Error Number %d\n", errno);
        perror("Program");
        exit(1);
}

    start_time = time(NULL);

    for (int i = 0; i < 1000000; i++) {
        bytes_written = write(fd, str_to_write, strlen(str_to_write));
        printf("%3d: Called write (%d, str_to_write, %d) which returned that %d bytes were written.\n", i, fd, strlen(str_to_write), bytes_written);

    }

    stop_time = time (NULL);
    printf("Unbuffered IO Time Elapsed: %d seconds", stop_time - start_time);
    
    close(fd);
    
    fd = -1;
    
    return 0;

    
}


