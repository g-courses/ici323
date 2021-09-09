#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
  printf("HOLA MUNDO, PID:%d\n", getpid() );

  system("./test");
  //execl("./test", "test",NULL);

  printf("HOLA MUNDO2, PID:%d\n", getpid() );
  return(EXIT_SUCCESS);
}