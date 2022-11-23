#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <semaphore.h>

#include "check_args.h"
#include "game_of_life.h"


int GENERACION;

void muestra_parametros()
{
	printf("Parámetros del juego\n");
	printf("Filas       : %u\n", args.NROWS);
	printf("Columnas    : %u\n", args.NCOLS);
	printf("Generaciones: %u\n", args.GENERATIONS);
	printf("Semilla     : %f\n", args.SEED);
}


int main(int argc, char **argv)
{

	check_args(argc, argv, "r:c:g:s:h");

	TABLERO.ancho = args.NCOLS;
	TABLERO.alto  = args.NROWS;

	muestra_parametros();
	getchar();

	GENERACION = 0;
	carga_tablero_inicial();


	do {
		muestra_tablero();

		GENERACION++;
		aplica_reglas();

		usleep(100000);
	} while ( GENERACION < args.GENERATIONS );


	return(EXIT_SUCCESS);
}
