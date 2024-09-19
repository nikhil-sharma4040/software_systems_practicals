/*
NAME:18.c 
AUTHOR: NIKHIL SHARMA

PROGRAM:18. Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
int main(){

	int pipefds1[2],pipefds2[2];
	if (pipe(pipefds1) == -1 || pipe(pipefds2) == -1){
		perror("pipe");
		exit(0);
	}

	if(fork()){

		sleep(1);
		close(pipefds2[0]);
		close(pipefds2[1]);
		close(pipefds1[0]);

		dup2(pipefds1[1],1);  		//replacing stdout with fds1[0]
		char *args[] = {"ls","-l",NULL};
		int w = execv("/bin/ls", args);

		close(pipefds1[1]);
		wait(0);

	}
	else{

		if(fork()){

			sleep(1);
			close(pipefds1[1]);
			close(pipefds2[0]);

			dup2(pipefds1[0],0);	//replacing stdin  with fds1[1]
			dup2(pipefds2[1],1);    //replacing stdout with fds2[0]
			char *args[] = {"grep","^d",NULL};
			int w = execv("/bin/grep", args);

			close(pipefds2[0]);
			close(pipefds1[1]);
			wait(0);

		}
		else{

			close(pipefds1[1]);
			close(pipefds1[0]);
			close(pipefds2[1]);

			dup2(pipefds2[0],0);  //replacing stdin with fds2[0]
			char *args[] = {"wc", NULL};
			int w =execv("/bin/wc", args);
			close(pipefds2[1]);

		}
	}
}

