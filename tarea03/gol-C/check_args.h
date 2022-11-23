#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <getopt.h>

typedef struct args_s {
	int32_t NROWS;
	int32_t NCOLS;
	int32_t GENERATIONS;
	float   SEED;
} args_t;

args_t args;

void print_usage(char* name);
void check_args(int argc, char **argv, const char* optString);


