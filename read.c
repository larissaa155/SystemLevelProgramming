// Filename: read.c
// Author: Faris Hawamdeh
// Date Created: January 24th 2024


# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h> // Import the Standard I/O Library

int main(void)
{
    int fd, bytes_read;
    char file_input[20];
 
    // open the file in read only mode
    fd = open("demo.txt", O_RDONLY);

    if (fd == -1) {
        // print which type of error
        printf("Error Number %d\n", errno);

        // print program detail "Success or Failure"
        perror("Program");

        // terminate the Program
        exit(1);
    }
 
    // read N bytes from file
    bytes_read = read(fd, file_input, 10);

    // print number of bytes read
    printf("Called read(%d, file_input, 10) which returned that %d bytes were read.\n", fd, bytes_read);
    // add null terminator to the end.
    file_input[bytes_read] = '\0';

    // print the bytes read
    printf("file_input: %s\n", file_input); 
 
    // close the file
    close(fd);

    return 0;
}