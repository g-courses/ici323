#include "game_of_life.h"



void muestra_tablero()
{
	int celulas_vivas;

	celulas_vivas = 0;
	puts ("\033[H\033[J");
	printf("\u2554");
	for(int j=1; j<=TABLERO.ancho; j++) {
		printf("\u2550");
	}
	printf("\u2557\n");
	for(int i=0; i<TABLERO.alto; i++) {
		printf("\u2551");
		for(int j=0; j<TABLERO.ancho; j++) {
			celulas_vivas += TABLERO.estado_actual[i][j];
			printf("%s", TABLERO.estado_actual[i][j] == 0 ? " ": "\u258A");
		}
		printf("\u2551\n");
	}
	printf("\u255A");
	for(int j=1; j<=TABLERO.ancho; j++) {
		printf("\u2550");
	}
	printf("\u255D\n");
	printf("Generación: %d, Células vivas: %d\n", GENERACION, celulas_vivas);
}
/* FIN imprime_tablero*/


void carga_tablero_inicial()
{
	float prob_viva;

	srand(time(NULL));
	TABLERO.estado_actual    = (char**)malloc( TABLERO.alto * sizeof(char*));
	TABLERO.estado_actual[0] = (char*)malloc(TABLERO.alto*TABLERO.ancho * sizeof(char));

	TABLERO.estado_futuro    = (char**)malloc( TABLERO.alto * sizeof(char*));
	TABLERO.estado_futuro[0] = (char*)malloc(TABLERO.alto*TABLERO.ancho * sizeof(char));

	for(int i=0; i<TABLERO.alto; i++) {
		TABLERO.estado_actual[i] = *TABLERO.estado_actual + TABLERO.ancho * i;
		TABLERO.estado_futuro[i] = *TABLERO.estado_futuro + TABLERO.ancho * i;
	}


	for(int i=0; i<TABLERO.alto; i++) {
		for(int j=0; j<TABLERO.ancho; j++) {
			prob_viva = (float)rand() / (float)RAND_MAX;
			TABLERO.estado_actual[i][j] = prob_viva <= args.SEED ? 1 : 0;
			TABLERO.estado_futuro[i][j] = 0;
		}
	}
}
/* FIN carga_tablero_aleatorio*/

int celulas_vecinas(int i, int j)
{
	int i_min, i_max, j_min, j_max;
	int count;

	i_min = (i-1) == -1 ?  0 : i-1;
	i_max = (i+1) == TABLERO.alto ? i : i+1;
	j_min = (j-1) == -1 ?  0 : j-1;
	j_max = (j+1) == TABLERO.ancho ? j : j+1;

	count = 0;
	for(int ii=i_min; ii<=i_max; ii++) {
		for(int jj=j_min; jj<=j_max; jj++) {
			if ((ii!=i) || (jj!=j)) {
				count += (TABLERO.estado_actual[ii][jj]);
			}
		}
	}

	return(count);
}
/*FIN celulas_vecinas*/

void aplica_reglas()
{
	int vecinas_on;

	for(int i=0; i<TABLERO.alto; i++) {
		for(int j=0; j<TABLERO.ancho; j++) {
			vecinas_on = celulas_vecinas(i,j);

			if ( ((vecinas_on == 2) || (vecinas_on == 3)) &&
			        (TABLERO.estado_actual[i][j]) == 1) {
				TABLERO.estado_futuro[i][j] = TABLERO.estado_actual[i][j];
			} else if ( vecinas_on == 3 ) {
				TABLERO.estado_futuro[i][j] = 1;
			} else  {
				TABLERO.estado_futuro[i][j] = 0;
			}

		}
	}

	for(int i=0; i<TABLERO.alto; i++) {
		for(int j=0; j<TABLERO.ancho; j++) {
			TABLERO.estado_actual[i][j] = TABLERO.estado_futuro[i][j];
		}
	}
}
/* FIN aplica_reglas*/







