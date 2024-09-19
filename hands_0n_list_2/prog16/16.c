/*
NAME:16.c
AUTHOR: NIKHIL SHARMA

PROGRAM:16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(){

	int pipefdspc[2];
	int pipefdscp[2];
	if (pipe(pipefdspc) == -1 || pipe(pipefdscp) == -1){
		perror("pipe");
		exit(0);
	}
	if (fork()!=0){

		close(pipefdspc[0]);
		close(pipefdscp[1]);

		char *pbuf = "Hello from the parent side\n";
		int w = write(pipefdspc[1],&pbuf,sizeof(pbuf));
		if (w==-1){ perror("write");exit(0);}

		char *cbuf;
		int r = read(pipefdscp[0],&cbuf,sizeof(cbuf));
		if (r==-1){ perror("read");exit(0);}

		printf("Parent with pid %d reads :: %s\n",getpid(),cbuf);

		close(pipefdspc[1]);
		close(pipefdscp[0]);

		wait(0);

	}
	else{

		close(pipefdspc[1]);
		close(pipefdscp[0]);

		char *cbuf = "Hello from the child side\n";
		int w = write(pipefdscp[1],&cbuf,sizeof(cbuf));
		if (w==-1){ perror("write");exit(0);}


		char *pbuf;
		int r = read(pipefdspc[0],&pbuf,sizeof(pbuf));
		if (r==-1){ perror("read");exit(0);}


		printf("Child with pid %d and parent pid %d reads :: %s\n",getpid(),getppid(),pbuf);

		close(pipefdspc[0]);
		close(pipefdscp[1]);

	}
}

