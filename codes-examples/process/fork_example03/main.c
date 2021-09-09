#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>



int main(int argc, char* argv[]){
	
	printf("Antes del fork.PID=%d, PPID=%d\n",getpid(), getppid());
	
	int result = fork(); //fork 1
	
	if(result == 0){
		//Codigo hijo
		printf("HIJO antes sleep()  : pid=%d, ppid=%d\n", getpid(), getppid());
		sleep(5); //simular computo por 5 segundos
		printf("HIJO despues sleep(): pid=%d, ppid=%d\n", getpid(), getppid());
		exit(EXIT_SUCCESS);
	}
	else if(result > 0){
		printf("PADRE: pid=%d, ppid=%d\n", getpid(), getppid());
		wait(NULL);
	}
	else{
		perror("Error en fork()");
		exit(EXIT_FAILURE);

	}

	printf("COMUN: PADRE: pid=%d, ppid=%d\n", getpid(), getppid());
	
	return(EXIT_SUCCESS);
}


