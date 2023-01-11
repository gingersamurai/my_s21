#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "reader.h"

int main(int argc, char *argv[]) {
  parse_results my_res = {0, 0, 0, 0, 0, 0, 0, 0};
  int cnt = parse_arguments(argc, argv, &my_res);
  if (cnt == -1) {
    return 1;
  }
  if (argc == optind) {
    process_file(stdin, my_res);
  } else {
    for (int file_i = optind; file_i < argc; file_i++) {
      FILE *file = fopen(argv[file_i], "r");
      if (file == NULL) return 2;
      process_file(file, my_res);
      fclose(file);
    }
  }
}
