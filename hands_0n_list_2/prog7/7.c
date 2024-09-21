/*
NAME:7.c
AUTHOR: NIKHIL SHARMA

PROGRAM:
7. Write a simple program to print the created thread ids.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* print_threadpid(void* num){
	printf("This is thread %ld\n",pthread_self());
}

int main() {

	printf("PID:%d\n",getpid());

	pthread_t t1,t2,t3;

	pthread_create(&t1,NULL,print_threadpid,NULL);
	pthread_create(&t2,NULL,print_threadpid,NULL);
	pthread_create(&t3,NULL,print_threadpid,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);

	return 0;
}



/* OUTPUT 

nikhil-sharma@ubuntu:~/IIITB/software_systems_practicals/hands_0n_list_2/pg7$ ./7.out
PID:19063
This is thread 140355311761088
This is thread 140355303368384
This is thread 140355294975680

*/
