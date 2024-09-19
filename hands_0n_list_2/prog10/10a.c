/*
NAME:10a.c
AUTHOR: NIKHIL SHARMA

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
	if(signum==SIGSEGV){
		printf("Segmentation fault triggered\n");
		exit(0);
	}

}


int main(){

	struct  sigaction sig;
	sig.sa_handler = handler;
	sig.sa_flags = 0;

	if(sigaction(SIGSEGV, &sig, NULL) == -1){
		perror("sigaction error\n");
		exit(0);
	}
	int *ptr = NULL;
	*ptr =42;

	return 0;

}

