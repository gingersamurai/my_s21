#include "reader.h"

#include "hack.h"

int process_file(FILE *file, parse_results my_parse_res) {
  int now = 0;
  int prev = 0;
  int string_num = 1;

  int was_eol = 0;
  int is_eol = 1;

  while ((now = fgetc(file)) != EOF) {
    // перед началом текста
    if (is_eol) {
      if (was_eol && now == '\n' && my_parse_res.s) {
        was_eol = 1;
        is_eol = 1;
        prev = '\n';
        continue;
      } else if ((my_parse_res.n && !my_parse_res.b) ||
                 (my_parse_res.b && now != '\n')) {
        // if (my_parse_res.b && now != '\n') {
        //     fprintf(stderr, "%d, %d\n", now, string_num);
        // }
        printf("%6d\t", string_num++);
      }
    }

    if ((my_parse_res.T || my_parse_res.t) && now == '\t') {
      printf("^I");
    } else if ((my_parse_res.E || my_parse_res.e) && now == '\n') {
      printf("$\n");
    } else if (!(is_eol && was_eol && my_parse_res.s && now == '\n')) {
      if (my_parse_res.v) {
        printf("%s", hack[now]);
      } else {
        printf("%c", now);
      }
    }
    was_eol = (prev == '\n');
    is_eol = (now == '\n');

    prev = now;
  }

  return 0;
}
