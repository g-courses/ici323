#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <signal.h>


void func_sigint(int signal_number)
{
	static int count = 0;
	printf("Señal recibida: %d\n", signal_number);
	printf("Veces: %d\n", count);
	
	if(count == 2){
		exit(EXIT_SUCCESS);
	}
	else{
		count++;
	}
	
	//
}


int main()
{
	struct sigaction sigact;
	
	sigemptyset( &sigact.sa_mask );
    sigact.sa_flags = 0;
    sigact.sa_flags = SA_RESTART;
    sigact.sa_handler = func_sigint;
    sigaction(SIGINT, &sigact, NULL );
		
	//signal(SIGINT, func_sigint);

	while(1) {
		
		puts("Nada todavia");
		sleep(1);

	}

	return(EXIT_SUCCESS);
}
