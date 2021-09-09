#define  _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
  uint64_t iteraciones;
  
  struct rusage r_usage;
  
  if(argc != 2){
    fprintf(stderr, "Uso: %s <iteraciones> \n", argv[0]);
    exit(EXIT_FAILURE);
  }
  
  iteraciones = atoi(argv[1]);

  printf("PID: %d\n", getpid());
  printf("Iteraciones: %ld", iteraciones);
  int total = 0;

  for(size_t i=0; i<iteraciones;i++){
	usleep(100);
	total += i*i*i & 0xFFFF;
	//printf("total=%d\n", total);
  }
    

  getrusage(RUSAGE_SELF,&r_usage);
  
  printf("Cambios de contexto\n");
  printf("Ctxt Voluntarios      = %ld\n", r_usage.ru_nvcsw);
  printf("Ctxt No Voluntarios   = %ld\n", r_usage.ru_nivcsw); 

  return(EXIT_SUCCESS);
}
