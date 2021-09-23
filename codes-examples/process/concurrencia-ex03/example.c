#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h> 
#include <sys/types.h>
#include <sys/wait.h>

#define CALC_ITER 2000000000

void codigo_carga()
{
	double t = 1.1;
	for(int idx=1; idx< CALC_ITER; idx++) {
		t *= idx;
	}
	double a = t;
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
			clock_t st = clock();
			codigo_carga();
			float delta = (float)(clock() - st)/CLOCKS_PER_SEC;
			printf("working time of %d : %f\n", getpid(), delta);
			exit(EXIT_SUCCESS);
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


