/*
NAME:13.c
AUTHOR: NIKHIL SHARMA

PROGRAM:
13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<signal.h>

int main(){

	pid_t pid;
	printf("Enter PID to be killed\n");
	scanf("%d",&pid);
	if(kill(pid,SIGSTOP)==0){
		printf("SIGSTOP Signal sent\n");
	} else{
		perror("kill");
	}
}

