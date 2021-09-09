#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


void hola(void ) {
	printf("hola\n");
	sleep(8);
}

void mundo ( void ) {
	printf("mundo\n");
	sleep(5);
}


int main(int argc, char* argv[]){
  pid_t pid;

  if( (pid=fork()) == 0) { //Hijo
    hola();
  }
  else if(pid > 0) {
    mundo();
	wait(NULL);
  }
  return(EXIT_SUCCESS);
}



