#include "s21_string.h"
#include <string.h>
#include <stdio.h>

int main() {
    double c1 = 123.4567;
    char buff[100];
    char s21_buff[100];
    sprintf(buff, "[%-18.5f]", c1);
    s21_sprintf(s21_buff, "[%-18.5f]", c1);
    printf("buff: %s\n", buff);
    printf("s21_buff: %s\n", s21_buff);
}