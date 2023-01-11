#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  int flag;

  for (int i = 0; haystack[i] != '\0'; i++) {
    if (haystack[i] == needle[0]) flag = 0;
    for (int j = 0; needle[j] != '\0'; j++) {
      if (haystack[i + j] != needle[j]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) return (char *)haystack + i;
  }
  return s21_NULL;
}
