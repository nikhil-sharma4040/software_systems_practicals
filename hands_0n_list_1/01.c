# software_systems_practicals
/*
================================================
Author : NIKHIL SHARMA


Create the following types of a files using (i) shell command (ii) system call
    a. soft link (symlink system call)
    b. hard link (link system call)
    c. FIFO (mkfifo Library Function or mknod system call)
================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    // Paths for the files and directories
    const char *source_file = "../test_dir_01/test_file_01.txt";
    const char *symlink_path = "./test_dir_02/test_file_01_symlink.txt";
    const char *hardlink_path = "./test_dir_02/test_file_01_hardlink.txt";
    const char *fifo_path = "./test_dir_02/test_named_pipe.fifo";

    // Create a symbolic link
    if (symlink(source_file, symlink_path) == -1) {
        perror("Error creating symbolic link");
        return EXIT_FAILURE;
    }

    // Create a hard link
    if (link(source_file, hardlink_path) == -1) {
        perror("Error creating hard link");
        return EXIT_FAILURE;
    }

    // Create a named pipe (FIFO)
    // Use mkfifo to create a FIFO special file
    if (mkfifo(fifo_path, 0666) == -1) {
        perror("Error creating named pipe");
        return EXIT_FAILURE;
    }

    // Success
    printf("Files created successfully:\n");
    printf("Symbolic link: %s -> %s\n", symlink_path, source_file);
    printf("Hard link: %s -> %s\n", hardlink_path, source_file);
    printf("Named pipe: %s\n", fifo_path);

    return EXIT_SUCCESS;
}
