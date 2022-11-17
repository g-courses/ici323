#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

/*
 *  Argumentos de entrada y configuracion de getopt
 */
typedef struct args_s{
	uint32_t numThreads;
} args_t;


void print_usage(char* name);
args_t check_args(int argc , char **argv,  const char *optString);