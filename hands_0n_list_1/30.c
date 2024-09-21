
/*
================================================
Author : NIKHIL SHARMA

Description :
Write a program to run a script at a specific time using a Daemon process.
================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/stat.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){


    time_t curr_time;

    if(argc!=4){
        printf("Please enter 3 arguments in HH24 MI SS format\n");
        exit(0);
    }

    time(&curr_time);

    struct tm * deadline = localtime(&curr_time);
    printf("Current time is %s",ctime(&curr_time));

    deadline->tm_hour = atoi(argv[1]);
    deadline->tm_min = atoi(argv[2]);
    deadline->tm_sec = atoi(argv[3]);

    time_t end_time = mktime(deadline);

    printf("Amount of seconds left :%f\n",difftime(end_time,curr_time));

    if (fork()==0){
        setsid();
        chdir("/");
        umask(0);


        do {
            time(&curr_time);
        } while(difftime(end_time,curr_time)>0);

        printf("Deadline Done\n");
        exit(0);
    }

}

