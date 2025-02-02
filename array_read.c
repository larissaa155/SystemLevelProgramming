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
    int array_to_read[5];
 
    // open the file in read only mode
    fd = open("array.txt", O_RDONLY);

    if (fd == -1) {
        // print which type of error
        printf("Error Number %d\n", errno);

        // print program detail "Success or Failure"
        perror("Program");

        // terminate the Program
        exit(1);
    }
 
    // read N bytes from file
    bytes_read = read(fd, array_to_read, sizeof(array_to_read));

    // print number of bytes read
    printf("Called read(%d, array_to_read, 20) which returned that %d bytes were read.\n", fd, bytes_read);

    for (int i = 0; i < (bytes_read) / sizeof(int); i++){
        printf("array_to_read %d: %d\n", i, array_to_read[i]); 
    }

    // print the bytes read
    
 
    // close the file
    close(fd);

    return 0;
}