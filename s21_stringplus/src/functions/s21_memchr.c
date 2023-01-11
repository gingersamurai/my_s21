#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *s1 = (unsigned char *)str;
  int check = 0;
  while (n--) {
    if (*s1 == (unsigned char)c) {
      check = 1;
      break;
    }
    s1++;
  }
  if (check != 1) {
    s1 = s21_NULL;
  }
  return s1;
}
