/*
NAME:28.c
AUTHOR: NIKHIL SHARMA

PROGRAM:
28. Write a program to change the exiting message queue 
permission. (use msqid_ds structure)

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>


int main(void) {

	int key = ftok(".", 2);
	if(key == -1) { perror("ftok");exit(0); }

	int msg_id = msgget(key, 0777 | IPC_CREAT);
	if(msg_id == -1) { perror("msgget");exit(0); }

	struct msqid_ds msg_ds;
	int t = msgctl(msg_id, IPC_STAT, &msg_ds);
	if(t == -1) { perror("msgctl");exit(0); }

	printf("The current permission is: %o\n", msg_ds.msg_perm.mode);
	msg_ds.msg_perm.mode = 0766;

	t = msgctl(msg_id, IPC_SET, &msg_ds);
	if(t == -1) { perror("msgctl");exit(0); }

	printf("The permission changed to %o\n", msg_ds.msg_perm.mode);

}

