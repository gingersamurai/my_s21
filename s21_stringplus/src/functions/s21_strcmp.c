#include "../s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  int result = 0;
  for (int i = 0; *((char *)str1 + i) != '\0' || *((char *)str2 + i) != '\0';
       i++) {
    result = *(str1 + i) - *(str2 + i);
    if (result > 0) {
      return 1;
    } else if (result < 0) {
      return -1;
    }
  }
  return (result);
}
