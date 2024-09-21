/*
NAME:32a.c
AUTHOR: NIKHIL SHARMA

PROGRAM:
32. Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int tno = 0;
sem_t mutex;

void* sellTicket(void* arg) {

    while (1) {
        sem_wait(&mutex); 
        if (tno <= 50) {
            tno++;
            printf("Ticket %d sold. Acessed by thread %ld\n", tno,pthread_self());
        }
        sem_post(&mutex); 
        if (tno > 50){
		break;
	}
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t seller1, seller2;

    sem_init(&mutex, 0, 1);

    pthread_create(&seller1, NULL, sellTicket, NULL);
    pthread_create(&seller2, NULL, sellTicket, NULL);

    pthread_join(seller1, NULL);
    pthread_join(seller2, NULL);

    sem_destroy(&mutex);

    return 0;
}

