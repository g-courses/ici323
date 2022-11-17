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
void print_usage(char* name)
{
	printf("Uso: %s -t <num_threads> [-h]\n", name);
	printf("\nParametros:\n");
	printf("\t-t : Cantidad de threads.\n");
	printf("\t-h : Muestra este ayuda y termina.\n");
}
/* FIN print_usage()*/

/*
 *		Funcion que comprueba el ingreso de parametros
 */
args_t check_args(int argc, char **argv, const char *optString)
{
	// La definición de args_t se encuentra en el archivo header
	args_t args;

	args.numThreads = 0;

	int opcion;
	while ((opcion = getopt (argc, argv, optString)) != -1) {
		switch (opcion) {
		case 't':
			args.numThreads = atoi(optarg);
			break;
		case 'h':
		default:
			print_usage(argv[0]);
			exit(EXIT_FAILURE);
		}
	}

	// Caso en que los tres argumentos son obligatorios
	if (args.numThreads == 0) {
		print_usage(argv[0]);
		exit(EXIT_FAILURE);
	}

	return(args);
}
/* FIN check_args()*/