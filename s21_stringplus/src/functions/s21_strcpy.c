#include "../s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *r = dest;
  while ((*dest++ = *src++)) {
  }
  return r;
}
