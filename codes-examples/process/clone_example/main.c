#define _GNU_SOURCE 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <sched.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

char memShared[100];

int fn(void *arg)
{
    printf("\nCHILD: memShared=\"%s\". PID=%d\n", memShared, getpid());

    int i = 0;

    int n = atoi(arg);

    for ( i = 1 ; i <= 10 ; i++ ) {
        printf("%d * %d = %d\n", n, i, (n*i));
    }

    printf("\n");
	
	strcpy(memShared, "mensaje desde el proceso hijo");

    return 0;
}

int main(int argc, char *argv[])
{
    printf("INFO: Begining\n");

	const uint32_t stackSize = 1024*1024; //1M

    void *stack = malloc(stackSize);
    if ( stack == NULL ) {
        perror("ERROR: Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
	void* stackTop = stack + stackSize;
	
	strcpy(memShared, "mensaje desde el proceso padre");
	
    int pid = clone(fn, stackTop, CLONE_VM|SIGCHLD, argv[1]);
	
    if ( pid < 0 ) {
        perror("ERROR: Unable to create the child process.\n");
        exit(EXIT_FAILURE);
    }

    wait(NULL);
	
	printf("\nPARENT: memShared=\"%s\".\n", memShared);

    free(stack);

    printf("INFO: Child process terminated.\n");
	return(EXIT_SUCCESS);
}