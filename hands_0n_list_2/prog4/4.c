/*
NAME: 4.c
AUTHOR: NIKHIL SHARMA

PROGRAM: 4. Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter. 

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<x86intrin.h>

int main(){

	unsigned long long start,end,diff;

	start = __rdtsc();
	for (int i=0;i<100;++i){
		getppid();
	}
	end = __rdtsc();

	printf("Time taken to execute 100 getppid() system call %llu\n",end-start);
	return 0;
}

/* OUTPUT 

nikhil-sharma@ubuntu:~/IIITB/software_systems_practicals/hands_0n_list_2/pg4$ ./a.out
Time taken to execute 100 getppid() system call 68448

*/
