#include <global.h>

uint32_t* testVar;

void modify_testVar(uint32_t value){
	*testVar = value;
}

int main(int argc, char** argv)
{
	testVar = (uint32_t*)malloc(sizeof(uint32_t));
	
	modify_testVar(666);
	
	pid_t processID = fork();
	
	if(processID == 0){
		pid_t myPID = getpid();
		
		modify_testVar(670);
		std::cout << "PID:" << myPID <<  ", testVar:"<< testVar <<std::endl;
		std::cout << "PID:" << myPID <<  ", *testVar:"<< *testVar <<std::endl;
		sleep(5);	
		
		exit(EXIT_SUCCESS);
	}
	else if(processID > 0){
		pid_t myPID = getpid();
		std::cout << "PID:" << myPID <<  ", testVar:"<< testVar <<std::endl;
		
		wait(NULL);
		std::cout << "PID:" << myPID <<  ", *testVar:"<< *testVar <<std::endl;
		
		exit(EXIT_SUCCESS);
	}
	else{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	
	exit(EXIT_SUCCESS);
}

