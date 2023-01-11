#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  int size = s21_strlen(dest);
  for (int j = 0; j < size; j++) {
    *(dest + j) = 0;
  }
  do {
    if (i < n) {
      *(dest + i) = *(src + i);
      i++;
    } else {
      break;
    }
  } while (*((char *)src + i) != '\0');
  return (dest);
}
