/*
NAME: 2.c
AUTHOR: NIKHIL SHARMA

PROGRAM:
2. Write a program to print the system resource limits. Use getrlimit system call. 

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<sys/resource.h>

int displayresources(int resource, char *name){

	struct rlimit r;
	int ret = getrlimit(resource,&r);
	static int count =1;
	if (ret==0){
		printf("%d)%s\n",count,name);
		printf("Soft limit: %ld\n",r.rlim_cur);
		printf("Hard limit: %ld\n",r.rlim_max);
		count++;
	}
	else{
		perror("getrlimit error");
	}
}


int main(){

	displayresources(RLIMIT_CPU,"CPU TIME");
	displayresources(RLIMIT_FSIZE,"FILE SIZE");
	displayresources(RLIMIT_STACK,"STACK SIZE IN BYTES");
	displayresources(RLIMIT_DATA,"DATA SEGMENT SIZE");
	displayresources(RLIMIT_NOFILE,"NUMBER OF FILES");
	displayresources(RLIMIT_AS,"VIRTUAL ADDRESS SPACE SIZE");
	displayresources(RLIMIT_NPROC,"NUMBER OF PROCESSES");
	displayresources(RLIMIT_MEMLOCK,"MAXIMUM BYTES LOCKED INTO MEMORY");
	displayresources(RLIMIT_LOCKS,"NUMBER NUMBER OF FILE LOCKS");
	displayresources(RLIMIT_SIGPENDING,"NUMBER OF SIGNALS WAITING FOR A PROCESS");
	displayresources(RLIMIT_MSGQUEUE,"MAX SIZE FOR MESSAGE QUEUE IN BYTES");
	displayresources(RLIMIT_NICE,"MAX VALUE OF NICE");
	displayresources(RLIMIT_RTPRIO,"MAX PRIORITY FOR REALTIME SCHEDULING POLICY(FIFO,RR)");
	displayresources(RLIMIT_RTTIME,"MAX TIME IN RT MODE");

}


