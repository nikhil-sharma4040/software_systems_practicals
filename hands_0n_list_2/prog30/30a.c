/*
NAME:30a.c
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
#include<unistd.h>
#include<sys/shm.h>

void main() {
	int key, shmid;
    	char *data;

	key = ftok(".", 1);
    	shmid = shmget(key, 1024, IPC_CREAT | 0744);
	
	printf("shared memory id : %d\n",shmid);
	
    	data = (char*)shmat(shmid, NULL, 0);

	printf("Enter input : ");
    	scanf("%s", data);
}

