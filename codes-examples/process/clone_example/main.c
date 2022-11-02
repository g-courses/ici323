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

#include <checkArgs.h>

char memShared[100];

typedef struct childArgs_s {
	uint32_t ID;
    uint32_t count;
    uint32_t table;
} childArgs_t;


int childCode(void *arg)
{
    srand(getpid());
	
	childArgs_t* childArgs = (childArgs_t*)arg;
	
    uint32_t count = childArgs->count; 
	uint32_t table = childArgs->table;
	
	printf("CHILD %d: count=%d\n", childArgs->ID, count);
	printf("CHILD %d: table=%d\n", childArgs->ID, table);
	
	uint32_t foo=0;
    for(uint32_t i = 1 ; i <= count ; i++ ) {
        foo += table*i;
    }
	
	// Coloca un caracter aleatorio en la memoria compartida con el padre
	memShared[childArgs->ID] = 65+(rand() % 25);
	printf("INFO: Child process %d terminated.\n", childArgs->ID);
    return 0;
}

void makeChild(uint32_t childID, uint32_t count, uint32_t table ){
	childArgs_t* childArgs = malloc(sizeof(childArgs_t));
	
	childArgs->ID = childID;
	childArgs->count = count;
	childArgs->table = table;
	
	const uint32_t stackSize = 1024*1024; //1M
    void *stack = malloc(stackSize);
    if ( stack == NULL ) {
        perror("ERROR: Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
	void* stackTop = stack + stackSize;
	
    pid_t pid = clone(childCode, stackTop, CLONE_VM|SIGCHLD, (void*)childArgs );
    if ( pid < 0 ) {
        perror("ERROR: Unable to create the child process.\n");
        exit(EXIT_FAILURE);
    }
	
}

int main(int argc, char *argv[])
{
	args_t programArgs;
	
	// Revisa los argumentos de entrada. Ver archivo checkArgs.{h,c}
	programArgs = check_args(argc, argv, "p:f:z:");
	
	// Padre inicializa el arreglo compartido.
	strcpy(memShared, "-----------------------------");
	
	// Realiza el fork
	for(int childID = 0; childID < programArgs.num1; childID++){
		makeChild(childID, programArgs.num1, programArgs.num2);
	}

	
	// Realiza el join
	for(int childID = 0; childID < programArgs.num1; childID++){
    	wait(NULL);
	}
	
	printf("\nPARENT: memShared=\"%s\".\n", memShared);


	return(EXIT_SUCCESS);
}