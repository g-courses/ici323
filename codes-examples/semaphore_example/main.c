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

#include <pthread.h>
#include <semaphore.h>

#include <checkArgs.h>


sem_t semTest;

typedef struct arguments_s {
	int32_t ID;
    int32_t ini;
    int32_t end;
} arguments_t;


void* threadMain(void* arg)
{
	srand(time(NULL));
	arguments_t* arguments = (arguments_t*)arg;
	
	int32_t id = arguments->ID;
	int32_t ini = arguments->ini;
	int32_t end = arguments->end;
	
	printf("ID=%d, ini=%d, end=%d: Before CZ..\n", id, ini, end);
	sem_wait(&semTest);
	printf("ID=%d  CZ ....\n", id);

	//critical section
	int32_t timeToSleep = 1 + (rand() % 4);
	sleep(timeToSleep);

	sem_post(&semTest);
	printf("ID=%d: After CZ..\n", id);
	
	return((void*)NULL);
}

int main(int argc, char *argv[])
{
	args_t programArgs = check_args(argc, argv, "t:h");
	
	sem_init(&semTest, 0, 3);
	
	int totalThreads = programArgs.numThreads;
	
	pthread_t* threads;
	threads = (pthread_t*)malloc(totalThreads*sizeof(pthread_t));
	
	for(int idThread=0; idThread<totalThreads; idThread++){
		arguments_t argsThread;
		argsThread.ID  = idThread;
		argsThread.ini = 0+idThread;
		argsThread.end = 10+idThread;
		
		pthread_create(&threads[idThread], NULL, threadMain, (void *)&argsThread);
	}
	
	for(int idThread=0; idThread<totalThreads; idThread++){
		pthread_join(threads[idThread],NULL);
	}

	free(threads);
	sem_destroy(&semTest);

	return(EXIT_SUCCESS);
}