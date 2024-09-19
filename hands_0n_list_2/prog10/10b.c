/*
NAME:10b.c
AUTHOR: NIKHIL SHARMA
ROLLNO: MT2024101
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
	if(signum==SIGINT){
		printf("\nInterrupt triggered\n");
		exit(0);
	}

}


int main(){

	struct  sigaction sig;
	sig.sa_handler = handler;
	sig.sa_flags = 0;

	if(sigaction(SIGINT, &sig, NULL) == -1){
		perror("sigaction error\n");
		exit(0);
	}

	printf("press ctrl+c\n");
	while(1){};
	return 0;

}

