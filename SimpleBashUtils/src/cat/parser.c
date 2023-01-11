#include "parser.h"

int parse_arguments(int argc, char* argv[], parse_results* my_parse_res) {
  int cnt = 1;

  char* optstring = "bveEnstT";
  const struct option longopts[] = {{"number_nonblank", no_argument, NULL, 'b'},
                                    {"number", no_argument, NULL, 'n'},
                                    {"squeeze-blank", no_argument, NULL, 's'},
                                    {NULL, 0, NULL, 0}};

  int res;
  int longindex = -1;

  while ((res = getopt_long(argc, argv, optstring, longopts, &longindex)) !=
         -1) {
    cnt++;
    switch (res) {
      case 'b':
        my_parse_res->b = 1;
        break;
      case 'v':
        my_parse_res->v = 1;
        break;
      case 'e':
        my_parse_res->e = 1;
        break;
      case 'E':
        my_parse_res->E = 1;
        break;
      case 'n':
        my_parse_res->n = 1;
        break;
      case 's':
        my_parse_res->s = 1;
        break;
      case 't':
        my_parse_res->t = 1;
        break;
      case 'T':
        my_parse_res->T = 1;
        break;
      case '?':
        return -1;
    }
  }

  if (my_parse_res->e || my_parse_res->t) {
    my_parse_res->v = 1;
  }

  return cnt;
}

void print_results(parse_results res) {
  printf("---PARSE RESULTS:\n");
  printf("b: %d\n", res.b);
  printf("v: %d\n", res.v);
  printf("e: %d\n", res.e);
  printf("E: %d\n", res.E);
  printf("n: %d\n", res.n);
  printf("s: %d\n", res.s);
  printf("t: %d\n", res.t);
  printf("T: %d\n", res.T);
  printf("---DONE\n");
}
