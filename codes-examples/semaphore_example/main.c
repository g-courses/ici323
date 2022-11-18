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

time_t gClockInitial;

sem_t semTest;

typedef struct arguments_s {
	int32_t tid;
    int32_t ini;
    int32_t end;
} arguments_t;


time_t now()
{
	return(time(NULL) - gClockInitial);
}



void* threadMain(void* arg)
{
	srand(time(NULL));
	arguments_t* arguments = (arguments_t*)arg;
	
	int32_t tid = arguments->tid;
	int32_t ini = arguments->ini;
	int32_t end = arguments->end;
	
	printf("%ld: tid=%d, ini=%d, end=%d: Before CS..\n", now(), tid, ini, end);
	sem_wait(&semTest);
	
	//critical section
	int32_t timeToSleep = 1 + (rand() % 4);
	printf("%ld: tid=%d  inside CS .... sleep: %d s\n", now(), tid, timeToSleep);
	
	sleep(timeToSleep);

	sem_post(&semTest);
	printf("%ld: tid=%d: After CS..\n",now(), tid);
	
	return((void*)NULL);
}

int main(int argc, char *argv[])
{
	gClockInitial = time(NULL);
	args_t programArgs = check_args(argc, argv, "t:h");
	
	sem_init(&semTest, 0, 3);
	
	int totalThreads = programArgs.numThreads;
	
	pthread_t* threads;
	threads = (pthread_t*)malloc(totalThreads*sizeof(pthread_t));
	
	for(int idThread=0; idThread<totalThreads; idThread++){
		arguments_t* argsThread=malloc(sizeof(arguments_t));
		argsThread->tid  = idThread;
		argsThread->ini = 0+idThread;
		argsThread->end = 10+idThread;
		pthread_create(&threads[idThread], NULL, threadMain, (void *)argsThread);
		
	}
	
	for(int idThread=0; idThread<totalThreads; idThread++){
		pthread_join(threads[idThread],NULL);
	}

	free(threads);
	sem_destroy(&semTest);

	return(EXIT_SUCCESS);
}