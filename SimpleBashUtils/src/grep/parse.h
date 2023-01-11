#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "patterns.h"

typedef struct _cli_options {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
} cli_options;

// my_getline
int my_getline(char **res, FILE *file);

// print_parse_res
void print_parse_res(cli_options *cli_flags, char ***patterns,
                     int *patterns_count);

// parse_arguments
int parse_arguments(int argc, char *argv[], cli_options *cli_flags,
                    char ***patterns, int *patterns_size, int *patterns_count);

#endif
