/*
NAME:29.c
AUTHOR: NIKHIL SHARMA

PROGRAM:
29. Write a program to remove the message queue.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(void) {
 
    int key = ftok(".", 1);
    if(key == -1) { perror("ftok");exit(0); }

    int msgid = msgget(key, 0666 | IPC_CREAT);
    if(msgid == -1) { perror("msgget");exit(0); }

    printf("Message queue id = %d\n", msgid);

    system("ipcs -q");

    int ctr = msgctl(msgid, IPC_RMID, NULL);
    if(ctr == -1) { perror("msgctl");exit(0); }

    printf("Message queue removed.\n");
}

