#include "s21_sscanf.h"

#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_string.h"

int s21_sscanf(const char* str, const char* format, ...) {
  setlocale(LC_ALL, "");
  setlocale(LC_NUMERIC, "en_US.UTF-8");
  int count = 0;
  va_list ap;
  va_start(ap, format);
  const char* copy = str;
  while (*format && *str) {
    form data = {0};
    int x = 0;
    format = parse_format(format, &data, str, &x);
    str += x;
    if (!data.error && *str) {
      void* tmp = NULL;
      if (!(data.no_record)) tmp = va_arg(ap, void*);
      str = parse_str(str, data, tmp, &count, copy);
    } else if (data.error == 1) {
      break;
    } else if (data.error == 3) {
      str = spaces(str);
      if (*str == '%') str++;
    }
  }
  va_end(ap);
  return count;
}

const char* parse_format(const char* format, form* data, const char* str,
                         int* x) {
  while (*format == ' ') format++;
  if (*format == '%') {
    format = get_no_record(++format, data);
    format = get_width(format, data);
    format = get_length(format, data);
    format = get_specification(format, data);
  } else if (*format == *str) {
    while (*format == *str) {
      *x += 1;
      str++;
      format++;
      data->error = 2;
    }
  } else if (*format != ' ') {
    data->error = 1;
    // format++;
  }
  return format;
}

const char* get_length(const char* format, form* data) {
  if (*format == 'h') {
    data->lenght = SET_LEN_H(data->lenght);
    format++;
  } else if (*format == 'l') {
    data->lenght = SET_LEN_L(data->lenght);
    format++;
  } else if (*format == 'L') {
    data->lenght = SET_LEN_LL(data->lenght);
    format++;
  }
  return format;
}

const char* get_no_record(const char* format, form* data) {
  if (*format == '*') {
    data->no_record = 1;
    format++;
  }
  return format;
}

const char* get_width(const char* format, form* data) {
  while (*format >= 48 && *format <= 57) {
    int x = *format - '0';
    data->widght *= 10;
    data->widght += x;
    format++;
  }
  return format;
}

const char* get_specification(const char* format, form* data) {
  if (*format == 'c') {
    data->spec = SET_C(data->spec);
  } else if (*format == 'd')
    data->spec = SET_D(data->spec);
  else if (*format == 'i')
    data->spec = SET_I(data->spec);
  else if (*format == 'e')
    data->spec = SET_E(data->spec);
  else if (*format == 'E')
    data->spec = SET_E(data->spec);
  else if (*format == 'f')
    data->spec = SET_E(data->spec);
  else if (*format == 'g')
    data->spec = SET_E(data->spec);
  else if (*format == 'G')
    data->spec = SET_E(data->spec);
  else if (*format == 'o')
    data->spec = SET_O(data->spec);
  else if (*format == 's')
    data->spec = SET_S(data->spec);
  else if (*format == 'u')
    data->spec = SET_U(data->spec);
  else if (*format == 'x')
    data->spec = SET_X(data->spec);
  else if (*format == 'X')
    data->spec = SET_X(data->spec);
  else if (*format == 'p')
    data->spec = SET_P(data->spec);
  else if (*format == 'n')
    data->spec = SET_N(data->spec);
  else if (*format == '%')
    data->error = 3;
  else {
    data->error = 1;
  }
  return ++format;
}

const char* parse_str(const char* str, form data, void* tmp, int* count,
                      const char* copy) {
  if (GET_C(data.spec)) {  // spec. C
    if (data.no_record)
      str = write_c(str, data, copy, count);
    else if (GET_LEN_L(data.lenght)) {
      str = write_c(str, data, copy, count, (wchar_t*)tmp);
    } else
      str = write_c(str, data, copy, count, (char*)tmp);
  }
  if (GET_D(data.spec)) {  // spec. D
    if (data.no_record)
      str = write_d(str, data, count);
    else if (GET_LEN_H(data.lenght))
      str = write_d(str, data, count, (short int*)tmp);
    else if (GET_LEN_L(data.lenght))
      str = write_d(str, data, count, (long int*)tmp);
    else {
      str = write_d(str, data, count, (int*)tmp);
    }
  }
  if (GET_O(data.spec)) {  // spec. O
    if (data.no_record)
      str = write_o(str, data, count);
    else if (GET_LEN_H(data.lenght))
      str = write_o(str, data, count, (unsigned short int*)tmp);
    else if (GET_LEN_L(data.lenght))
      str = write_o(str, data, count, (unsigned long int*)tmp);
    else
      str = write_o(str, data, count, (unsigned int*)tmp);
  }
  if (GET_X(data.spec)) {  // spec. X
    if (data.no_record)
      str = write_x(str, data, count);
    else if (GET_LEN_H(data.lenght))
      str = write_x(str, data, count, (short unsigned int*)tmp);
    else if (GET_LEN_L(data.lenght))
      str = write_x(str, data, count, (long unsigned int*)tmp);
    else
      str = write_x(str, data, count, (unsigned int*)tmp);
  }
  if (GET_E(data.spec)) {  // spec. E
    if (data.no_record)
      str = write_e(str, data, count);
    else if (GET_LEN_LL(data.lenght))
      str = write_e(str, data, count, (long double*)tmp);
    else
      str = write_e(str, data, count, (float*)tmp);
  }
  if (GET_U(data.spec)) {  // spec. U
    if (data.no_record)
      str = write_u(str, data, count);
    else if (GET_LEN_H(data.lenght))
      str = write_u(str, data, count, (short unsigned int*)tmp);
    else if (GET_LEN_L(data.lenght))
      str = write_u(str, data, count, (long unsigned int*)tmp);
    else
      str = write_u(str, data, count, (unsigned int*)tmp);
  }
  if (GET_S(data.spec)) {  // spec. S
    if (data.no_record)
      str = write_s(str, data, count);
    else if (GET_LEN_L(data.lenght))
      str = write_s(str, data, count, (wchar_t*)tmp);
    else
      str = write_s(str, data, count, (char*)tmp);
  }
  if (GET_I(data.spec)) {  // spec. I
    if (data.no_record)
      str = write_i(str, data, count);
    else if (GET_LEN_H(data.lenght))
      str = write_i(str, data, count, (short int*)tmp);
    else if (GET_LEN_L(data.lenght))
      str = write_i(str, data, count, (long int*)tmp);
    else
      str = write_i(str, data, count, (int*)tmp);
  }
  if (GET_N(data.spec)) {
    if (GET_LEN_H(data.lenght)) {
      short int* x = (short int*)tmp;
      *x = ((short int)(s21_strstr(copy, str) - copy));
    } else if (GET_LEN_L(data.lenght)) {
      long int* x = (long int*)tmp;
      *x = ((long int)(s21_strstr(copy, str) - copy));
    } else {
      int* x = (int*)tmp;
      *x = s21_strstr(copy, str) - copy;
    }
  }
  return str;
}

const char* write_c(const char* str, form data, const char* copy, int* count,
                    ...) {
  if (!(s21_strstr(copy, str) - str)) str = spaces(str);
  va_list ap;
  va_start(ap, count);
  int w_count = 0;
  if (data.widght == 0) w_count = -1;
  if (!(data.no_record)) {
    *count += 1;
    if (GET_LEN_L(data.lenght)) {
      wchar_t* x = va_arg(ap, wchar_t*);
      mbtowc(x, str, 2);
      str += 1;
      if (*str < 0) str++;
      if (data.widght != 0) w_count++;
    } else {
      char* x = va_arg(ap, char*);
      *x = *str;
      str++;
    }
  } else {
    if (!data.widght) {
      str++;
    } else {
      while (w_count != data.widght - 1) {
        w_count++;
        str++;
      }
    }
  }
  va_end(ap);
  return str;
}

const char* write_d(const char* str, form data, int* count, ...) {
  va_list ap;
  va_start(ap, count);
  int w_count = 0;
  int sign = 0;
  long int numbers = 0;
  int flag = 0;
  if (data.widght == 0) w_count = -1;
  str = spaces(str);
  if (*str == '-') {
    sign = 1;
    str++;
    if (data.widght != 0) w_count++;
  } else if (*str == '+') {
    str++;
    if (data.widght != 0) w_count++;
  }
  while (*str >= 48 && *str <= 57 && w_count != data.widght) {
    str = get_numbers_int(str, &numbers, &w_count, data);
    flag++;
  }
  if (sign) numbers *= -1;
  if (!(data.no_record)) {
    if (GET_LEN_H(data.lenght)) {
      short int* x = va_arg(ap, short int*);
      *x = (short int)numbers;
      if (flag) *count += 1;
    } else if (data.lenght == 'l') {
      long int* x = va_arg(ap, long int*);
      *x = numbers;
      if (flag) *count += 1;
    } else {
      int* x = va_arg(ap, int*);
      *x = (int)numbers;
      if (flag) *count += 1;
    }
  }
  va_end(ap);
  return str;
}

const char* get_numbers_int(const char* str, long int* tmp, int* w_count,
                            form data) {
  int x = *str - '0';
  *tmp *= 10;
  *tmp += x;
  str++;
  if (data.widght != 0) *w_count += 1;
  return str;
}
const char* write_e(const char* str, form data, int* count, ...) {
  va_list ap;
  va_start(ap, count);
  long double tmp_tmp = 0;
  int w_count = 0;
  int sign = 0;
  int flag = 0;
  if (data.widght == 0) w_count = -1;
  str = spaces(str);
  if (*str == '-') {
    sign = 1;
    str++;
    if (data.widght != 0) w_count++;
  } else if (*str == '+') {
    str++;
    if (data.widght != 0) w_count++;
  }
  while (*str >= 48 && *str <= 57 && w_count != data.widght) {
    long double x = *str - '0';
    tmp_tmp *= 10.0;
    tmp_tmp += x;
    str++;
    flag = 1;
    if (data.widght != 0) w_count += 1;
  }
  if (*str == '.' && w_count != data.widght) {
    str++;
    long double float_count = 1.0;
    flag = 1;
    if (data.widght != 0) w_count++;
    while (*str >= 48 && *str <= 57 && w_count != data.widght) {
      long double x = *str - '0';
      long double y = x / (powl(10.0, float_count));
      tmp_tmp += y;
      str++;
      flag = 1;
      float_count += 1.0;
      if (data.widght != 0) w_count++;
    }
  }
  if ((*str == 'E' || *str == 'e') && w_count != data.widght) {
    str++;
    long double tmp_pow = 0.0;
    int pow_sign = 0;
    if (data.widght != 0) w_count++;
    if (*str == '-') {
      pow_sign = 1;
      str++;
      if (data.widght != 0) w_count++;
    } else if (*str == '+') {
      str++;
      if (data.widght != 0) w_count++;
    }
    while (*str >= 48 && *str <= 57 && w_count != data.widght) {
      long double x = *str - '0';
      tmp_pow *= 10.0;
      tmp_pow += x;
      str++;
      flag = 1;
      if (data.widght != 0) w_count++;
    }
    if (pow_sign) tmp_pow *= -1;
    tmp_tmp *= powl(10, tmp_pow);
  }
  str = nan_inf(str, &flag, &tmp_tmp);
  if (sign) tmp_tmp *= -1;
  if (!data.no_record) {
    if (flag) *count += 1;
    if (GET_LEN_LL(data.lenght)) {
      long double* x = va_arg(ap, long double*);
      *x = tmp_tmp;
    } else {
      float* x = va_arg(ap, float*);
      *x = (float)tmp_tmp;
    }
  }
  va_end(ap);
  return str;
}

const char* nan_inf(const char* str, int* flag, long double* tmp_tmp) {
  if ((*str == 'N' || *str == 'n') &&
      (*(str + 1) == 'a' || *(str + 1) == 'A') &&
      (*(str + 2) == 'n' || *(str + 2) == 'N')) {
    *tmp_tmp = NAN;
    str += 3;
    *flag = 1;
  } else if ((*str == 'i' || *str == 'I') &&
             (*(str + 1) == 'n' || *(str + 1) == 'N') &&
             (*(str + 2) == 'f' || *(str + 2) == 'F')) {
    *tmp_tmp = INFINITY;
    str += 3;
    *flag = 1;
  }
  return str;
}
const char* write_u(const char* str, form data, int* count, ...) {
  va_list ap;
  va_start(ap, count);
  int w_count = 0;
  if (data.widght == 0) w_count = -1;
  str = spaces(str);
  int sign = 0;
  long int signed_tmp = 0;
  int flag = 0;
  if (*str == '-') {
    sign = 1;
    str++;
    if (data.widght != 0) w_count++;
  } else if (*str == '+') {
    str++;
    if (data.widght != 0) w_count++;
  }
  while (*str >= 48 && *str <= 57 && w_count != data.widght) {
    str = get_numbers_int(str, &signed_tmp, &w_count, data);
    flag = 1;
  }
  if (sign) signed_tmp *= -1;
  if (!data.no_record) {
    if (GET_LEN_H(data.lenght)) {
      short unsigned int* x = va_arg(ap, short unsigned int*);
      *x = (short unsigned int)signed_tmp;
      if (flag) *count += 1;
    } else if (GET_LEN_L(data.lenght)) {
      long unsigned int* x = va_arg(ap, long unsigned int*);
      *x = (long unsigned int)signed_tmp;
      if (flag) *count += 1;
    } else {
      unsigned int* x = va_arg(ap, unsigned int*);
      *x = (unsigned int)signed_tmp;
      if (flag) *count += 1;
    }
  }
  va_end(ap);
  return str;
}

const char* write_i(const char* str, form data, int* count, ...) {
  va_list ap;
  va_start(ap, count);
  int w_count = 0;
  long int tmp = 0;
  int sign = 0;
  int flag = 0;
  if (data.widght == 0) w_count = -1;
  str = spaces(str);
  if (*str == '-') {  // добавить +
    sign = 1;
    str++;
    if (data.widght != 0) w_count++;
  } else if (*str == '+') {
    str++;
    if (data.widght != 0) w_count++;
  }
  if (*str == '0') {
    str++;
    if (data.widght != 0) w_count++;
    if (*str == 'x') {
      str++;
      if (data.widght != 0) w_count++;
      str = write_hex(str, data, &tmp, &flag, &w_count);
    } else {
      str = write_octal(str, data, &tmp, &flag, &w_count);
    }
  } else {
    while (*str >= 48 && *str <= 57 && w_count != data.widght) {
      str = get_numbers_int(str, &tmp, &w_count, data);
      flag = 1;
    }
  }
  if (sign) tmp *= -1;
  if (!(data.no_record)) {
    if (GET_LEN_H(data.lenght)) {
      short int* x = va_arg(ap, short int*);
      *x = (short int)tmp;
      if (flag) *count += 1;
    } else if (GET_LEN_L(data.lenght)) {
      long int* x = va_arg(ap, long int*);
      *x = tmp;
      if (flag) *count += 1;
    } else {
      int* x = va_arg(ap, int*);
      *x = (int)tmp;
      if (flag) *count += 1;
    }
  }
  va_end(ap);
  return str;
}

const char* write_octal(const char* str, form data, long int* tmp, int* flag,
                        int* w_count) {
  long int octal = 0;
  long int dec = 0;
  int i = 0;
  while (*str > 47 && *str < 56 && *w_count != data.widght) {
    str = get_numbers_int(str, &octal, w_count, data);
    *flag = 1;
  }
  while (octal != 0) {
    dec = dec + (octal % 10) * pow(8, i);
    i++;
    octal /= 10;
  }
  *tmp = dec;
  return str;
}

const char* write_hex(const char* str, form data, long int* tmp, int* flag,
                      int* w_count) {  // добавить w_count
  int dec = 0;
  int i = 0;
  char hex[100] = {'\0'};
  int i_hex = 0;
  while (((*str > 47 && *str < 58) || (*str > 64 && *str < 71) ||
          (*str > 96 && *str < 103)) &&
         *w_count != data.widght) {
    hex[i] = *str;
    i++;
    str++;
    if (data.widght != 0) *w_count += 1;
    *flag = 1;
  }
  i--;
  while (i >= 0) {
    dec = dec + (hex_to_int(hex[i_hex]) * pow(16, i));
    i--;
    i_hex++;
  }
  *tmp = dec;
  return str;
}

int hex_to_int(char hex) {
  char dec = 0;
  if (hex >= '0' && hex <= '9')
    dec = hex - '0';
  else if (hex >= 'A' && hex <= 'F')
    dec = hex - 'A' + 10;
  else if (hex >= 'a' && hex <= 'f')
    dec = hex - 'a' + 10;
  return dec;
}
const char* write_s(const char* str, form data, int* count,
                    ...) {  // добавить w_count
  str = spaces(str);
  va_list ap;
  va_start(ap, count);
  int w_count = 0;
  if (data.widght == 0) w_count = -1;
  char* s = malloc(sizeof(char));
  int i = 0;
  int flag = 0;
  while (*str != ' ' && w_count != data.widght && *str && *str != '\n' &&
         *str != '\t' && *str != '\r' && *str != '\x0B' && *str != '\f') {
    s[i] = *str;
    s = realloc(s, (i + 2) * sizeof(char));
    if (!s) exit(0);
    if (data.widght != 0) w_count++;
    i++;
    str++;
    flag = 1;
  }
  s[i] = '\0';
  int k = s21_strlen(s) + 1;
  if (!data.no_record) {
    if (GET_LEN_L(data.lenght)) {
      wchar_t* x = va_arg(ap, wchar_t*);
      mbstowcs(x, s, k);
      if (flag) *count += 1;
    } else {
      char* x = va_arg(ap, char*);
      if (flag) *count += 1;
      for (int j = 0; j < k; j++) {
        x[j] = s[j];
      }
    }
  }
  free(s);
  va_end(ap);
  return str;
}

const char* spaces(const char* str) {  // добавить w_count
  while (*str < 33 && *str >= 0) {
    str++;
  }
  return str;
}

const char* write_o(const char* str, form data, int* count, ...) {
  va_list ap;
  va_start(ap, count);
  long int signed_tmp = 0;
  int w_count = 0;
  int sign = 0;
  int flag = 0;
  if (data.widght == 0) w_count = -1;
  str = spaces(str);
  if (*str == '-') {  // добавить +
    sign = 1;
    str++;
    if (data.widght != 0) w_count++;
  } else if (*str == '+') {
    str++;
    if (data.widght != 0) w_count++;
  }
  str = write_octal(str, data, &signed_tmp, &flag, &w_count);
  if (sign) signed_tmp *= -1;
  if (!data.no_record) {
    if (GET_LEN_H(data.lenght)) {
      unsigned short int* x = va_arg(ap, unsigned short int*);
      *x = (unsigned short int)signed_tmp;
      if (flag) *count += 1;
    } else if (GET_LEN_L(data.lenght)) {
      unsigned long int* x = va_arg(ap, unsigned long int*);
      *x = (unsigned long int)signed_tmp;
      if (flag) *count += 1;
    } else {
      unsigned int* x = va_arg(ap, unsigned int*);
      *x = (unsigned int)signed_tmp;
      if (flag) *count += 1;
    }
  }
  va_end(ap);
  return str;
}

const char* write_x(const char* str, form data, int* count, ...) {
  va_list ap;
  va_start(ap, count);
  long int signed_tmp = 0;
  int w_count = 0;
  int sign = 0;
  int flag = 0;
  if (data.widght == 0) w_count = -1;
  str = spaces(str);
  if (*str == '-') {
    sign = 1;
    str++;
    if (data.widght != 0) w_count++;
  } else if (*str == '+') {
    str++;
    if (data.widght != 0) w_count++;
  }
  if (*str == '0') {
    str++;
    if (data.widght != 0) w_count++;
    if (*str == 'x') {
      str++;
      if (data.widght != 0) w_count++;
    }
  }
  str = write_hex(str, data, &signed_tmp, &flag, &w_count);
  if (sign) signed_tmp *= -1;
  if (!data.no_record) {
    if (GET_LEN_H(data.lenght)) {
      short unsigned int* x = va_arg(ap, short unsigned int*);
      *x = (short unsigned int)signed_tmp;
      if (flag) *count += 1;
    } else if (GET_LEN_L(data.lenght)) {
      long unsigned int* x = va_arg(ap, long unsigned int*);
      *x = (long unsigned int)signed_tmp;
      if (flag) *count += 1;
    } else {
      unsigned int* x = va_arg(ap, unsigned int*);
      *x = (unsigned int)signed_tmp;
      if (flag) *count += 1;
    }
  }
  va_end(ap);
  return str;
}