#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <stdlib.h>

#include "parser.h"

int process_file(FILE *file, parse_results my_parse_res);

#endif
