#include "s21_sprintf.h"

int parse_opt(const char **str, sopt *cur_opt, int *need_p_arg,
              int *need_w_arg) {
  // get flag
  if (s21_strchr("-+ #0", *(*str))) {
    cur_opt->flag = *(*str);
    (*str)++;
  } else {
    cur_opt->flag = 0;
  }

  // get width
  if (s21_strchr("0123456789", *(*str))) {
    cur_opt->width = 0;
    while (s21_strchr("0123456789", *(*str))) {
      cur_opt->width *= 10;
      cur_opt->width += *(*str) - '0';
      (*str)++;
    }
  } else if ('*' == *(*str)) {
    *need_w_arg = 1;
    (*str)++;
  } else {
    cur_opt->width = 0;
  }

  int have_precision = 0;
  // get precision
  if ('.' == *(*str)) {
    (*str)++;
    if (s21_strchr("0123456789", *(*str))) {
      cur_opt->precision = 0;
      while (s21_strchr("0123456789", *(*str))) {
        cur_opt->precision *= 10;
        cur_opt->precision += *(*str) - '0';
        (*str)++;
      }
    } else if ('*' == *(*str)) {
      *need_p_arg = 1;
      (*str)++;
    } else {
      cur_opt->precision = 0;
    }
  } else {
    have_precision = 1;
    cur_opt->precision = 0;
  }

  // get length
  if (s21_strchr("hlL", *(*str))) {
    cur_opt->lenght = *(*str);
    (*str)++;
  } else {
    cur_opt->lenght = 0;
  }

  // get specifier
  if (s21_strchr("cdieEfgGosuxXpn%", *(*str))) {
    cur_opt->specifier = *(*str);
    (*str)++;
  } else {
    return 2;
  }

  // check conflickts
  if (s21_strchr("f", cur_opt->specifier) && have_precision) {
    cur_opt->precision = 6;
  }
  return 0;
}