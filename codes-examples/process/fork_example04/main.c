#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h> 
#include <sys/types.h>
#include <sys/wait.h>


void codigo_hijo()
{
	srand(getpid()); 
	int simTime = rand()%8+1	;
	printf("PID=%d, PPID=%d => simTime=%d\n", getpid(), getppid(), simTime);
	sleep(simTime);
	printf(">>PID=%d, PPID=%d ==> finalizó\n", getpid(), getppid());
	exit(EXIT_SUCCESS);
}

void codigo_carga()
{
	srand(getpid());
        int limSuperior = rand();

	double resultado = 1.5;
	printf("PID=%d, PPID=%d => limSup=%d\n", getpid(), getppid(), limSuperior);

	for(int i=0; i< limSuperior; i+=1){
		resultado *= resultado;
	}
	printf(">>PID=%d, PPID=%d ==> finalizó\n", getpid(), getppid());

	exit(EXIT_SUCCESS);
}


int main(int argc, char* argv[])
{

	if(argc != 2){
		fprintf(stderr, "Uso: %s <num_hijos>\n", argv[0]);
		exit(EXIT_FAILURE);

	}

	int NUM_HIJOS = atoi(argv[1]);

	for (int i=0; i<NUM_HIJOS; i++) {
		int ret = fork();
		if( ret == 0) {
			//codigo_hijo();
			codigo_carga();
		}
		else if (ret == -1) {
			perror("fallo en fork");
			exit(EXIT_FAILURE);
		}
	}

	for(int i=0; i<NUM_HIJOS; i++){
		wait(NULL);
	}

	return(EXIT_SUCCESS);
}


