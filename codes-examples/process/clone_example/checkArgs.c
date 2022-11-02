#include <checkArgs.h>

extern char *optarg;
extern int optind, opterr, optopt;
/*
 *		==================================
 *		FUNCIONES RELACIONADAS CON EL PASO
 *		DE ARGUMENTOS AL PROGRAMA
 *    ==================================
 */



/*
 *		Funcion que imprime en stdout el uso
 *		del programa.
 */
void print_usage(char* name){
	printf("Uso: %s -p num1 -f num2 -z num3\n", name);
	printf("\nParametros:\n");
	printf("\tnum1 : número 1.\n");
	printf("\tnum2 : número 2.\n");
	printf("\tnum3 : número 3.\n");
}
/* FIN print_usage()*/

/*
 *		Funcion que comprueba el ingreso de parametros
 */
args_t check_args(int argc , char **argv, const char *optString){
	args_t args;
	
	args.num1 = 0;
	args.num2 = 0;
	args.num3 = 0;

	int opcion;
	while ((opcion = getopt (argc, argv, optString)) != -1){
		switch (opcion) {
			case 'p':
					args.num1 = atoi(optarg);
					break;
			case 'f':
					args.num2 = atoi(optarg);
					break;
			case 'z':
					args.num3 = atoi(optarg);
					break;
			case 'h':
			default: print_usage(argv[0]);
								exit(EXIT_FAILURE);
		}
	}
	
	// Caso en que los tres argumentos son obligatorios
	if (args.num1 == 0 || args.num2 ==0 || args.num3 == 0 ) {
		print_usage(argv[0]);
		exit(EXIT_FAILURE);
	}

	return(args);
}
/* FIN check_args()*/