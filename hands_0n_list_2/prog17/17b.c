/*
NAME:17b.c
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

int main(){

	int pipefds[2];

	if (pipe(pipefds)==-1){
		perror("pipe");
		exit(0);
	}

	if (!fork()){

		close(pipefds[0]);
		dup2(pipefds[1],1);			//replacing stdout
		char *args[] = {"ls","-l",NULL};
		execv("/bin/ls",args);
		close(pipefds[1]);
		wait(0);
	}
	else{

		close(pipefds[1]);
		dup2(pipefds[0],0);			//replacing stdin
		char *args[] = {"wc",NULL};
		execv("/bin/wc",args);
		close(pipefds[0]);

	}
}

