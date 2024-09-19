/*
NAME:26.c
AUTHOR: NIKHIL SHARMA

PROGRAM:
26. Write a program to send messages to the message queue. Check $ipcs -q

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<stdlib.h>

struct buffer{
	long message_type;
	char m[100];
}msg;

int main() {

	int key = ftok(".",1);
	int msg_queue = msgget(key, 0666 | IPC_CREAT);
	if (msg_queue == -1){
		perror("msgget");
	}
	printf("message queue id : %d\n",msg_queue);
	msg.message_type = 1;
	fgets(msg.m, 10 ,stdin);
	int ms = msgsnd(msg_queue,&msg,sizeof(msg),0);
	if(ms == -1){
		perror("msgsend");
		exit(0);
	}
	printf("Data sent to message queue\n");

}

