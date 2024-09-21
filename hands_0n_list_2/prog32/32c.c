/*
NAME:32c.c
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
#include <pthread.h>
#include <semaphore.h>


int resource[2];
sem_t semaphore;

void* useResource(void* arg) {
    int resource_id = *(int*)arg;

    sem_wait(&semaphore); 


    printf("Using resource %d.\n", resource_id);
    resource[resource_id] = 0;

    sem_post(&semaphore); 

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2];

    sem_init(&semaphore, 0,2);

    for (int i = 0; i < 2; ++i) {
        resource[i] = 1; 
        pthread_create(&threads[i], NULL, useResource, (void*)&i);
    }

    for (int i = 0; i < 2; ++i) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore);
}

