// Filename: write.c
// Author: Faris Hawamdeh
// Date Created: January 24th 2024


# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h> // Import the Standard I/O Library

int main(void)
{
    int fd, bytes_written;
    int array_to_write[] = {5, 4, 3, 4, 1};
 
    // open the file in write only mode, create if it doesnt exist,
    // and truncate it if it does exist
    fd = open("array.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        // print which type of error
        printf("Error Number %d\n", errno);

        // print program detail "Success or Failure"
        perror("Program");

        // terminate the Program
        exit(1);
    }
 
    // write N bytes to the file
    bytes_written = write(fd, array_to_write, sizeof(array_to_write));

    // print number of bytes written
    printf("Called write(%d, str_to_write, %d) which returned that %d bytes were written.\n", fd, sizeof(array_to_write), bytes_written);
 
    // close the file
    close(fd);

    fd = -1;

    return 0;
}