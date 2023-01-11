#ifndef PATTERNS_H
#define PATTERNS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_patterns(char ***patterns, int *patterns_size);

void free_patterns(char ***patterns, int *patterns_count);

void add_pattern(char *new_pattern, char ***patterns, int *patterns_size,
                 int *patterns_count);

void print_patterns(char ***patterns, int *patterns_count);

#endif
