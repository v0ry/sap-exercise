#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
/*
 * Explain, why two different Process ID?
*/ 

int main(int agrc, char* argv[]) 
{ 
	int pid = fork(); // create a new process with fork();
	if (pid == -1) {
		return 1;
	}; // Upon successfull completion fork() return 0, otherwise -1
	
	printf("This should be pid id of a PROCESS: %d\n", getpid());
	if (pid == -1) {
		return 1;
	};
    return 0;
}


