/*
================================================
Author : NIKHIL SHARMA

Description :
Write a program to create a file and print the file descriptor value. Use creat () system call
================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int file_d = creat("./test_dir_02/test_file_02.txt", 0666);
	printf("%d\n", file_d);

	close(file_d);
	return 0;
}
