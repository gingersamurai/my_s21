#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  size_t match = 0;
  char *result = s21_NULL;
  for (size_t i = 0; str1[i] != '\0' && match == 0; i++) {
    for (size_t j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        match = 1;
        result = (char *)str1 + i;
      }
    }
  }
  return result;
}
