/*
NAME: 15.c
AUTHOR: NIKHIL SHARMA

PROGRAM:
15. Write a simple program to send some data from parent to the child proces

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(){

	int pipefds[2];
	pid_t x;

	if (pipe(pipefds)== -1){
		perror("pipe");
		exit(0);
	}
	if(fork()!=0){

		close(pipefds[0]);//close read of parent

		char bufw[100];
		printf("I am parent process please enter some data to send to child : \n");
		scanf("%[^\n]",bufw);

		int w = write(pipefds[1],bufw,strlen(bufw));
		printf("Parent with PID %d sent the data with %d bytes\n",getpid(),w);

		close(pipefds[1]);//finished writing close write of parent

	}
	else{
		close(pipefds[1]);//close write of child

		char bufr[100];
		int r = read(pipefds[0],bufr,sizeof(bufr)-1);
		if (r>0){
			bufr[r]='\n';
		}
		printf("Child with pid %d ppid %d finished reading %d bytes of data\n",getpid(),getppid(),r);
		printf("String specified by parent : %s\n",bufr);

		close(pipefds[0]);//finished reading close read of parent
	}
}

