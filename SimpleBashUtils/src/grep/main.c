#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"
#include "patterns.h"
#include "reader.h"

int main(int argc, char *argv[]) {
  char **patterns;
  int patterns_size;
  int patterns_count = 0;
  init_patterns(&patterns, &patterns_size);

  cli_options cli_flags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int cnt = parse_arguments(argc, argv, &cli_flags, &patterns, &patterns_size,
                            &patterns_count);
  if (cnt < 0) {
    free_patterns(&patterns, &patterns_count);
    return 1;
  }

  int cnt_files = argc - optind;

  int sum = 0;
  if (cnt_files == 0) {
    // stdin
    cnt_files = 1;
    process_file(stdin, cli_flags, 1, patterns, patterns_count,
                 "(standart input)");
  } else {
    for (int i = optind; i < argc; i++) {
      FILE *file = fopen(argv[i], "r");
      if (!file) return 1;

      int have = process_file(file, cli_flags, (cnt_files != 1), patterns,
                              patterns_count, argv[i]);
      sum += have;
      if (have && cli_flags.l) {
        printf("%s\n", argv[i]);
      }
      fclose(file);
    }
  }

  free_patterns(&patterns, &patterns_count);
  if (cli_flags.c) {
    if (!cli_flags.l) {
      printf("%d\n", sum);
    }
  }
  if (sum == 0) {
    return 1;
  }
}