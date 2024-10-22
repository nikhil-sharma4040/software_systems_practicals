/*
NAME:30d.c
AUTHOR: NIKHIL SHARMA

PROGRAM:
30. Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>

void main() {
	int key, shmid;
    	char *data;

	key = ftok(".", 1);
    	shmid = shmget(key, 1024, 0);

	printf("shared memory id : %d\n",shmid);
    	data = (char*)shmat(shmid, (void *)0, 0);

	printf("Data stored is %s\n",data);
    	if (shmctl(shmid, IPC_RMID, NULL) == -1){
		perror("shmdt");
		exit(0);
	}
	printf("Shared memory removed successfully\n");

}

