#ifndef S21_SSCANF
#define S21_SSCANF

#define SET_C(x) x | 1 << 0
#define SET_D(x) x | 1 << 1
#define SET_I(x) x | 1 << 2
#define SET_E(x) x | 1 << 3  // E, e, f, g, G
#define SET_O(x) x | 1 << 4
#define SET_S(x) x | 1 << 5
#define SET_U(x) x | 1 << 6
#define SET_X(x) x | 1 << 7
#define SET_P(x) x | 1 << 8
#define SET_N(x) x | 1 << 9  // %

#define SET_LEN_H(x) x | 1 << 0
#define SET_LEN_L(x) x | 1 << 1
#define SET_LEN_LL(x) x | 1 << 2

#define GET_C(x) x & 1 << 0
#define GET_D(x) x & 1 << 1
#define GET_I(x) x & 1 << 2
#define GET_E(x) x & 1 << 3
#define GET_O(x) x & 1 << 4
#define GET_S(x) x & 1 << 5
#define GET_U(x) x & 1 << 6
#define GET_X(x) x & 1 << 7
#define GET_P(x) x & 1 << 8
#define GET_N(x) x & 1 << 9

#define GET_LEN_H(x) x & 1 << 0
#define GET_LEN_L(x) x & 1 << 1
#define GET_LEN_LL(x) x & 1 << 2
// #define s21_size_t unsigned int

typedef struct form {
  int spec;
  int widght;
  int lenght;
  int no_record;
  int error;
} form;

int s21_sscanf(const char* str, const char* format, ...);
const char* parse_format(const char* format, form* data, const char* str,
                         int* x);
int s21_sscanf(const char* str, const char* format, ...);
const char* get_no_record(const char* format, form* data);
const char* get_width(const char* format, form* data);
const char* get_specification(const char* format, form* data);
const char* write_c(const char* str, form data, const char* copy, int* count,
                    ...);
const char* write_d(const char* str, form data, int* count, ...);
const char* parse_str(const char* str, form data, void* tmp, int* count,
                      const char* copy);
const char* write_e(const char* str, form data, int* count, ...);
const char* get_numbers_int(const char* str, long int* tmp, int* w_count,
                            form data);
const char* write_u(const char* str, form data, int* count, ...);
const char* write_s(const char* str, form data, int* count, ...);
const char* write_i(const char* str, form data, int* count, ...);
const char* write_octal(const char* str, form data, long int* tmp, int* count,
                        int* w_count);
const char* write_hex(const char* str, form data, long int* tmp, int* count,
                      int* w_count);
int hex_to_int(char hex);
const char* spaces(const char* str);
const char* write_o(const char* str, form data, int* count, ...);
const char* write_x(const char* str, form data, int* count, ...);
const char* get_length(const char* format, form* data);
const char* nan_inf(const char* str, int* flag, long double* tmp_tmp);

#endif