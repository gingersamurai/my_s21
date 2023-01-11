#ifndef S21_SPRINTF
#define S21_SPRINTF

#include <stdarg.h>

#include "../s21_string.h"

typedef struct _sopt {
  char specifier;
  char flag;
  int width;
  int precision;
  char lenght;
} sopt;

int s21_sprintf(char *str, const char *format, ...);

int parse_opt(const char **str, sopt *cur_opt, int *need_p_arg,
              int *need_w_arg);

void my_itoa(char *res, int x);

void my_dtoa(char *res, double x, int prec);

void my_utoa(char *res, unsigned x);

void s_write_c(char *dest, sopt cur_opt, va_list *ap);

void s_write_d(char *dest, sopt cur_opt, va_list *ap);

void s_write_f(char *dest, sopt cur_opt, va_list *ap);

void s_write_s(char *dest, sopt cur_opt, va_list *ap);

void s_write_u(char *dest, sopt cur_opt, va_list *ap);

void s_write_opt(char **str, sopt cur_opt, va_list *ap);

#endif
