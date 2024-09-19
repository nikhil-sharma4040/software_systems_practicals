/*
NAME:10c.c
AUTHOR: NIKHL SHARMA

PROGRAM:
10. Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void  handler(int signum){
	if(signum==SIGFPE){
		printf("Floating Point error triggered\n");
		exit(0);
	}

}


int main(){

	struct  sigaction sig;
	sig.sa_handler = handler;
	sig.sa_flags = 0;

	if(sigaction(SIGFPE, &sig, NULL) == -1){
		perror("sigaction error\n");
		exit(0);
	}
	int x = 0/0;
	return 0;

}

