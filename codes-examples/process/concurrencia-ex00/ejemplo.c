#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define SLEEP_TIME 1000000 //useg

void hola(void ) {
        char *msg = " Hola";
        int i;
        for ( i = 0 ; i < strlen ( msg ) ; i++ ) {
                printf (" %c", msg [i]);
                fflush ( stdout );
                usleep (SLEEP_TIME) ;
        }
}

void mundo ( void ) {
        char *msg = " mundo ";
        int i;
        for ( i = 0 ; i < strlen ( msg ) ; i++ ) {
                printf (" %c", msg [i]);
                fflush ( stdout );
                usleep (SLEEP_TIME) ;
        }
}


int main(int argc, char* argv[]){
  pid_t pid;

  if( (pid=fork()) == 0) { //Hijo
    hola();
  }
  else if(pid > 0) {
    mundo();
  }
  return(EXIT_SUCCESS);
}



