#ifndef PARSER_H
#define PARSER_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _parse_results {
  int b;
  int v;
  int e;
  int E;
  int n;
  int s;
  int t;
  int T;
} parse_results;

int parse_arguments(int argc, char* argv[], parse_results* my_parse_res);

void print_results(parse_results res);

#endif
