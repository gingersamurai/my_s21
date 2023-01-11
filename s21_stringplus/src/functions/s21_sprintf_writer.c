#include "s21_sprintf.h"

void my_itoa(char *res, int x) {
    if (x == 0) {
        *res = '0';
        res++;
    }
    int start_id = 0;

    if (x < 0) {
        res[0] = '-';
        start_id = 1;
        x *= -1;
    }

    int id = start_id;
    while (x > 0) {
        int digit = x % 10;
        x /= 10;
        res[id++] = digit + '0';
    }
    for (int i = start_id; i < id / 2; i++) {
        char buff = res[i];
        res[i] = res[id - 1 - i];
        res[id - 1 - i] = buff;
    }
    res[id] = '\0';
}

void my_dtoa(char *res, double x, int prec) {
    if (x < 0) {
        *res = '-';
        res++;
        x *= -1;
    }
    prec = prec;
    my_utoa(res, (int) x);
    res += s21_strlen(res);
    // x -= (int) x;
    if (prec > 0) {
        *res = '.';
        res++;
        for (int i = 0; i < prec; i++) {
            x *= 10;
            int digit = (int) x;
            digit %= 10;
            // printf("%c\n", digit + '0');
            *res = digit + '0';
            res++;
        }
        *res = '\0';
    }
}

void my_utoa(char *res, unsigned x) {
    if (x == 0) {
        *res = '0';
        res++;
    }
    int start_id = 0;

    int id = start_id;
    while (x > 0) {
        int digit = x % 10;
        x /= 10;
        res[id++] = digit + '0';
    }
    for (int i = start_id; i < id / 2; i++) {
        char buff = res[i];
        res[i] = res[id - 1 - i];
        res[id - 1 - i] = buff;
    }
    res[id] = '\0';
}

void s_write_c(char *dest, sopt cur_opt, va_list *ap) {
    cur_opt = cur_opt;
    char arg = va_arg(*ap, int);
    *dest = arg;
}

void s_write_d(char *dest, sopt cur_opt, va_list *ap) {
    int arg = va_arg(*ap, int);
    // printf("arg: %d\n", arg);
    if (cur_opt.lenght == 'h') {
        arg = (short)arg;
    }

    if (cur_opt.flag == '+' && arg >= 0) {
        *dest = '+';
        dest++;
    } else if (cur_opt.flag == ' ' && arg >= 0) {
        *dest = ' ';
        dest++;
    }

    char digits[s21_MAXN];
    my_itoa(digits, arg);
    // printf("digits: %s\n", digits);
    int cnt = cur_opt.precision - s21_strlen(digits);
    while (cnt-- > 0) {
        *dest = '0';
        dest++;
    }

    char *digits_p = digits;
    cnt = s21_strlen(digits);
    while (cnt-- > 0) {
        *dest = *digits_p;
        dest++;
        digits_p++;
    }
}

void s_write_f(char *dest, sopt cur_opt, va_list *ap) {
    double arg = va_arg(*ap, double);

    if (cur_opt.flag == '+' && arg >= 0) {
        // printf("arg: %f\n", arg);
        *dest = '+';
        dest++;
    } else if (cur_opt.flag == ' ' && arg >= 0) {
        *dest = ' ';
        dest++;
    }

    char digits[s21_MAXN];
    my_dtoa(digits, arg, cur_opt.precision);
    // printf("digits: %s\n", digits);
    char *digits_p = digits;
    int cnt = s21_strlen(digits);
    while (cnt--) {
        *dest = *digits_p;
        dest++;
        digits_p++;
    }
}

void s_write_s(char *dest, sopt cur_opt, va_list *ap) {
    cur_opt = cur_opt;
    char *arg = va_arg(*ap, char *);
    int cnt = s21_strlen(arg);

    while (cnt-- > 0) {
        *dest = *arg;
        dest++;
        arg++;
    }
}

void s_write_u(char *dest, sopt cur_opt, va_list *ap) {
    unsigned arg = va_arg(*ap, unsigned);
    // printf("arg: %u\n", arg);
    if (cur_opt.lenght == 'h') {
        arg = (short)arg;
    }

    char digits[s21_MAXN];
    my_utoa(digits, arg);
    // printf("digits: %s\n", digits);
    int cnt = cur_opt.precision - s21_strlen(digits);
    while (cnt-- > 0) {
        *dest = '0';
        dest++;
    }

    char *digits_p = digits;
    cnt = s21_strlen(digits);
    while (cnt-- > 0) {
        *dest = *digits_p;
        dest++;
        digits_p++;
    }
}

void s_write_opt(char **str, sopt cur_opt, va_list *ap) {
    // создаю буффер
    char buff[s21_MAXN];
    for (int i = 0; i < s21_MAXN; i++) {
        buff[i] = '\0';
    }

    // записываю аргументы
    switch (cur_opt.specifier) {
        case 'c':
            s_write_c(buff, cur_opt, ap);
            break;
        case 'd':
            s_write_d(buff, cur_opt, ap);
            break;
        case 'i':
            s_write_d(buff, cur_opt, ap);
            break;
        case 'f':
            s_write_f(buff, cur_opt, ap);
            break;
        case 's':
            s_write_s(buff, cur_opt, ap);
            break;
        case 'u':
            s_write_u(buff, cur_opt, ap);
            break;
    }

    // printf("res_spec: %s\n\n", buff);

    // дописываю ширину слева
    if (cur_opt.flag != '-') {
        char add = ' ';
        if (cur_opt.flag == '0') {
            add = '0';
        }
        int cnt = cur_opt.width - s21_strlen(buff);
        while (cnt-- > 0) {
            **str = add;
            (*str)++;
        }
        // printf("res_spec: %s\n\n", buff);
    }

    // дописываю результат в str
    int cnt = s21_strlen(buff);
    char *buff_p = buff;
    while (cnt--) {
        *(*str) = *buff_p;
        (*str)++;
        buff_p++;
    }

    // дописываю ширину справа
    if (cur_opt.flag == '-') {
        cnt = cur_opt.width - s21_strlen(buff);
        while (cnt-- > 0) {
            **str = ' ';
            (*str)++;
        }
    }
}