#ifndef READER_H
#define READER_H

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

#include "parse.h"
#include "patterns.h"
// print_res
void print_res(char *s, cli_options cli_flags, int strnum, regmatch_t *pmatch,
               int *first, char *filename, int many_files);

// process_file
int process_file(FILE *file, cli_options cli_flags, int many_files,
                 char **patterns, int patterns_count, char *filename);

#endif
