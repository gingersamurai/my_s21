#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *start = dest;
  dest += s21_strlen(dest);
  for (; (n != 0 && *src != '\0'); n--) {
    *dest = *src;
    src++;
    dest++;
  }
  if (*(dest - 1) != '\0') {
    *dest = '\0';
  }
  return start;
}
