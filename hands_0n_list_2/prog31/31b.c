/*
NAME:31b.c
AUTHOR: NIKHIL SHARMA

PROGRAM:
31. Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/sem.h>
union semun {
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
};
int main() {

	key_t key = ftok(".", 1);
	if( key == -1){ perror("ftok");exit(0);}

	int semid = semget(key, 1, IPC_CREAT|0777);//no of semaphores = 1

        union semun arg;
	arg.val = 100;//counting semaphore

	int ret = semctl(semid,0,SETVAL,arg);
	if (ret != -1){
    		printf("Counting semaphore created and initialized\n");
	}
	else{
		perror("semctl");
		exit(0);
	}
}

