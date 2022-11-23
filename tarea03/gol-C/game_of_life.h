#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include "check_args.h"


struct tablero_t {
	int ancho;
	int alto;
	char **estado_actual;
	char **estado_futuro;

} TABLERO;

extern int GENERACION;

void muestra_tablero();
void carga_tablero_inicial();

int celulas_vecinas(int, int );
void aplica_reglas();

