#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define CALC_ITER 2000000000 //useg

void hola(void ) {
	double t = 1.1;
	for(int idx=1; idx< CALC_ITER; idx++){
		t *= idx;
	}
	double a = t;
}

void mundo ( void ) {
	double t = 1.1;
    for(int idx=1; idx< CALC_ITER; idx++){
         t *= idx;
    }
	double a = t;

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



