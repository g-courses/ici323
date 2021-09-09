#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>



int main(int argc, char* argv[]){
	
	printf("Antes del fork.PID=%d, PPID=%d\n",getpid(), getppid());
	
	fork(); //1
	
	fork(); //2
	
	printf("prueba de fork. PID=%d, PPID=%d\n", getpid(), getppid());

	return(EXIT_SUCCESS);
}


