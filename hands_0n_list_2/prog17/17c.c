/*
NAME:17c.c
AUTHOR: NIKHIL SHARMA

PROGRAM:
17. Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(){

	int pipefds[2];

	if (pipe(pipefds)==-1){
		perror("pipe");
		exit(0);
	}

	if (!fork()){

		close(pipefds[0]);
		close(1);
		fcntl(pipefds[1],F_DUPFD);
		char *args[] = {"ls","-l",NULL};
		execv("/bin/ls",args);
		close(pipefds[1]);
		wait(0);
	}
	else{

		close(pipefds[1]);
		close(0);
		fcntl(pipefds[0],F_DUPFD);
		char *args[] = {"wc",NULL};
		execv("/bin/wc",args);
		close(pipefds[0]);

	}
}
