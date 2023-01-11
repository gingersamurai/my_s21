#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const char *s1 = s21_NULL;
  const char *s2 = s21_NULL;
  s21_size_t first_match = 0;
  s21_size_t match_found = 0;
  for (s1 = str1; *s1; ++s1) {
    for (s2 = str2; *s2 && match_found == 0; ++s2) {
      if (*s1 == *s2) {
        first_match = s1 - str1;
        match_found = 1;
      }
    }
  }
  if (match_found == 0) {
    first_match = s21_strlen(str1);
  }
  return (first_match);
}
