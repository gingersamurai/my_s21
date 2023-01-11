#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  char *str_beginning = str;

  while (*format) {
    if (*format != '%') {
      *str = *format;
      str++;
      format++;
    } else {
      format++;
      sopt cur_opt;
      int need_w_arg = 0, need_p_arg = 0;
      int res = parse_opt(&format, &cur_opt, &need_p_arg, &need_w_arg);
      if (res != 0) {
        va_end(ap);
        return 0;
      }
      if (need_w_arg) {
        int x = va_arg(ap, int);
        cur_opt.width = (int)x;
      }
      if (need_p_arg) {
        int x = va_arg(ap, int);
        cur_opt.precision = x;
      }
      // printf("fl: %c\nlen: %c\nprec: %d\nspec: %c\nwid: %d\n\n", cur_opt.flag, cur_opt.lenght, cur_opt.precision, cur_opt.specifier, cur_opt.width);
      // print_opt(cur_opt);
      s_write_opt(&str, cur_opt, &ap);
    }
  }
  *str = '\0';
  str++;
  va_end(ap);

  return str - str_beginning - 1;
}
