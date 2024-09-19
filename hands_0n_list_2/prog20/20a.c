/*
NAME:20.c
AUTHOR:NIKHIL SHARMA

PROGRAM:
20. Write two programs so that both can communicate by FIFO -Use one way communication.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

int main(){

	const char *path = "myfifo";

	int ret = mkfifo(path,0666);
	if (ret == -1){ perror("mkfifo");}

	char buf[500];
	printf("Data to be sent from a to b:\n");
	scanf("%[^\n]",buf);


	int fd = open(path, O_WRONLY);
	if (fd == -1){ perror("open"); exit(0);}

	int w = write(fd,buf,strlen(buf));
	if (w == -1){ perror("write"); exit(0);}
	else{ printf("no of bytes written %d\n",w);}
	close(fd);
}

