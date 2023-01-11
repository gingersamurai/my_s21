#include "reader.h"

void print_res(char *s, cli_options cli_flags, int strnum, regmatch_t *pmatch,
               int *first, char *filename, int many_files) {
  if (cli_flags.l || cli_flags.c) return;
  if (!cli_flags.h && many_files) {
    printf("%s:", filename);
  }
  if (cli_flags.n) {
    if (cli_flags.o && *first) {
      printf("%d:", strnum);
      *first = 0;
    } else if (!cli_flags.o) {
      printf("%d:", strnum);
    }
  }
  int start = 0;
  int finish = strlen(s);
  if (cli_flags.o) {
    start = pmatch[0].rm_so;
    finish = pmatch[0].rm_eo;
  }
  for (int i = start; i < finish; i++) {
    printf("%c", s[i]);
  }
  printf("\n");
}

int process_file(FILE *file, cli_options cli_flags, int many_files,
                 char **patterns, int patterns_count, char *filename) {
  int cnt = 0;

  int strnum = 0;
  while (1) {
    strnum += 1;
    char *buff;
    int len = my_getline(&buff, file);
    if (len == -1) {
      free(buff);
      break;
    }

    int first = 1;
    for (int i = 0; i < patterns_count; i++) {
      regex_t reg;
      int cflags = 0;
      if (cli_flags.i) cflags |= REG_ICASE;
      regcomp(&reg, patterns[i], cflags);
      const size_t nmatch = 1;
      regmatch_t pmatch[1];

      int status = regexec(&reg, buff, nmatch, pmatch, 0);
      if (status == REG_NOMATCH) {
        if (cli_flags.v) {
          cnt += 1;
          print_res(buff, cli_flags, strnum, pmatch, &first, filename,
                    many_files);
        }
      } else {
        if (!cli_flags.v) {
          cnt += 1;
          print_res(buff, cli_flags, strnum, pmatch, &first, filename,
                    many_files);
        }
      }
      regfree(&reg);
    }
    free(buff);
  }

  return cnt;
}
