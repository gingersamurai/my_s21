#include "patterns.h"

void init_patterns(char ***patterns, int *patterns_size) {
  *patterns_size = 2;
  *patterns = malloc(sizeof(char *));
}

void free_patterns(char ***patterns, int *patterns_count) {
  for (int i = 0; i < *patterns_count; i++) {
    free((*patterns)[i]);
  }
  free(*patterns);
}

void add_pattern(char *new_pattern, char ***patterns, int *patterns_size,
                 int *patterns_count) {
  *patterns_count += 1;
  if (*patterns_count + 1 == *patterns_size) {
    *patterns_size *= 2;
    *patterns = realloc(*patterns, sizeof(char *) * *patterns_size);
  }
  (*patterns)[*patterns_count - 1] =
      malloc(sizeof(char) * (strlen(new_pattern) + 1));
  strcpy((*patterns)[*patterns_count - 1], new_pattern);
}

void print_patterns(char ***patterns, int *patterns_count) {
  printf("[ ");
  for (int i = 0; i < *patterns_count; i++) {
    printf("%s, ", (*patterns)[i]);
  }
  printf("]\n");
}
