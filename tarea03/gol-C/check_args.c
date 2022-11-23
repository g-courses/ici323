#include "check_args.h"
extern char *optarg;
extern int optind, opterr, optopt;

/*
 *		Funcion que imprime en stdout el uso
 *		del programa.
 */


void print_usage(char* name)
{
	char opciones[] = "-r NROWS -c NCOLS -g GENERATIONS\n"
	                  "\t-s SEED [-h]\n";

	char descripcion[] = "Descripción:\n"
	                     "\t-r   Número de filas\n"
	                     "\t-c   Número de columnas\n"
	                     "\t-g   Número de generaciones a simular\n"
	                     "\t-s   Número inicial de células vivas\n";

	printf("Uso: %s %s\n%s\n", name, opciones, descripcion);
}
/* FIN print_usage()*/

void check_args(int argc, char **argv, const char *optString)
{
	int opcion;

	args.NROWS        = 0;
	args.NCOLS        = 0;
	args.GENERATIONS   = 0;
	args.SEED         = 0.0;

	while ((opcion = getopt (argc, argv, optString)) != -1) {
		switch (opcion) {
		case 'r':
			args.NROWS = atoi(optarg);
			break;
		case 'c':
			args.NCOLS = atoi(optarg);
			break;
		case 'g':
			args.GENERATIONS = atoi(optarg);
			break;
		case 's':
			args.SEED = atof(optarg);
			break;
		case 'h':
		default:
			print_usage(argv[0]);
			exit(EXIT_FAILURE);
		}
	}

	// Caso en que los tres argumentos son obligatorios
	if ( args.NROWS == 0      || args.NCOLS == 0 ||
	        args.GENERATIONS == 0 || args.SEED  == 0) {
		print_usage(argv[0]);
		exit(EXIT_FAILURE);
	}

}
/* FIN check_args()*/
