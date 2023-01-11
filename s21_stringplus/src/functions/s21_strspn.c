#include "../s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t i, j;
  for (i = 0; str1[i] != '\0'; i++) {
    for (j = 0; str2[j] != str1[i]; j++) {
      if (str2[j] == '\0') return i;
    }
  }
  return i;
}
