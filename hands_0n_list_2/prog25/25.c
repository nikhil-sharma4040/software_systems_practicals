/*
NAME:25.c
AUTHOR: NIKHIL SHARMA

PROGRAM:
25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>

int main() {

	int key = ftok(".",1);
	int msg_queue = msgget(key,IPC_CREAT| 0777);
	if (msg_queue == -1){
		perror("msgqueue");
		exit(0);
	}

	struct msqid_ds info;
	int m = msgctl(msg_queue, IPC_STAT, &info);
	if (m == -1){
		perror("ms_gen");
	}

	printf("Access permission: %d\n",info.msg_perm.mode);
	printf("UID: %d\t GID: %d\n", info.msg_perm.uid, info.msg_perm.gid);
	printf("Time of last message sent is: %ld\n", info.msg_stime);
	printf("Time of last message received is: %ld\n", info.msg_rtime);
	printf("Time of last change in the message queue: %ld\n", info.msg_ctime);
	printf("Size of Queue is: %ld\n", info.__msg_cbytes);
	printf("Number of message in the queue is: %ld\n", info.msg_qnum);
	printf("Maximum number of bytes allowed is: %ld\n", info.msg_qbytes);
	printf("Pid of the msgsnd: %d\n", info.msg_lspid);
	printf("Pid of the msgrcv: %d\n", info.msg_lrpid);

}

