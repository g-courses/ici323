#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <signal.h>


void func_sigint(int signal_number)
{
	printf("Señal recibida: %d\n", signal_number);
	exit(EXIT_SUCCESS);
}


int main()
{	
	signal(SIGINT, func_sigint);

	while(1) {	
		printf("PID=%d\n",getpid());
		puts("Nada todavia");
		sleep(1);
	}

	return(EXIT_SUCCESS);
}
