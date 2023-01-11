#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

// Функция memchr.

START_TEST(memchr_1) {
  char *s1 = "0";
  ck_assert_pstr_eq(memchr(s1, 48, 1), s21_memchr(s1, 48, 1));
}
END_TEST

START_TEST(memchr_2) {
  char str_1[16] = "Zdarova patsany";
  ck_assert_ptr_eq(memchr(str_1, 'p', 2), s21_memchr(str_1, 'p', 2));
}
END_TEST

START_TEST(memchr_3) {
  char str_3[12] = "I'm\nproger";
  ck_assert_str_eq(memchr(str_3, '\n', 6), s21_memchr(str_3, '\n', 6));
}
END_TEST

START_TEST(memchr_4) {
  char str_5[5] = " \n\0\0";
  ck_assert_str_eq(memchr(str_5, '\0', 4), s21_memchr(str_5, '\0', 4));
}
END_TEST

START_TEST(memchr_5) {
  char str_1[12] = "Hello world";
  ck_assert_str_eq(memchr(str_1, 'w', strlen(str_1)),
                   s21_memchr(str_1, 'w', s21_strlen(str_1)));
}
END_TEST

// Функция memcmp.

START_TEST(memcmp_1) {
  char str[] = "Hello World";
  char str1[] = "Hello World";
  int n = '\0';
  ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
}
END_TEST

START_TEST(memcmp_2) {
  char str[] = "Hello World";
  char str1[] = "Hello World";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
}
END_TEST

START_TEST(memcmp_3) {
  char str[] = "Hello";
  char str1[] = "notequal";
  int n = 5;
  ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
}
END_TEST

START_TEST(memcmp_4) {
  char str[] = "Hello World";
  char str1[] = "";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
}
END_TEST

START_TEST(memcmp_5) {
  char str[] = "Hello World";
  char str1[] = "";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
}
END_TEST

// Функция memcpy.

START_TEST(memcpy_1) {
  char str_5[3] = "a\n\0";
  char str_6[3] = "\0";
  ck_assert_str_eq(memcpy(str_5, str_6, 2), s21_memcpy(str_5, str_6, 2));
}
END_TEST

START_TEST(memcpy_2) {
  char str_1[] = "\0";
  char str_2[] = " ";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 1));
}
END_TEST

START_TEST(memcpy_3) {
  char str_1[] = "copy_! ";
  char str_2[] = "n66";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
}
END_TEST

START_TEST(memcpy_4) {
  char str_1[] = "\n/n";
  char str_2[] = "-55";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
}
END_TEST

START_TEST(memcpy_5) {
  char str_1[] = "5656";
  char str_2[] = "\0\f";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
}
END_TEST

// Функция memmove.

START_TEST(memmove_1) {
  char str[11] = "1234567890";
  ck_assert_str_eq(memmove(str + 4, str + 3, 3),
                   s21_memmove(str + 4, str + 3, 3));
}
END_TEST

START_TEST(memmove_2) {
  char str[11] = "321qwerty";
  ck_assert_str_eq(memmove(str + 4, str + 3, 0),
                   s21_memmove(str + 4, str + 3, 0));
}
END_TEST

START_TEST(memmove_3) {
  char str_1[50] = " school21\0";
  char str_2[12] = "I'm\nproger";
  ck_assert_str_eq(memmove(str_1, str_2, 10), s21_memmove(str_1, str_2, 10));
}
END_TEST

START_TEST(memmove_4) {
  char str_1[50] = " school21\0";
  char str_2[12] = "s_21\n\t";
  ck_assert_str_eq(memmove(str_1, str_2, 0), s21_memmove(str_1, str_2, 0));
}
END_TEST

START_TEST(memmove_5) {
  char str_1[11] = "1234567890";
  char str_2[50] = " \n\0\0";
  ck_assert_str_eq(memmove(str_1, str_2, 2), s21_memmove(str_1, str_2, 2));
}
END_TEST

// Функция memset.

START_TEST(memset_1) {
  char str[10] = "123456789";
  ck_assert_str_eq(memset(str, 'k', 3), s21_memset(str, 'k', 3));
}
END_TEST

START_TEST(memset_2) {
  char str1[15] = "1234567890";
  char str2[15] = "5432167890";
  int c = 'q';
  int n = 10;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(memset_3) {
  char str1[15] = "qweqweqweqwe";
  char str2[15] = "qweqweqweqwe";
  int c = '\0';
  int n = 5;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(memset_4) {
  char str1[15] = "qweqweqweqwe";
  char str2[15] = "qweqweqweqwe";
  int c = '\n';
  int n = 5;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(memset_5) {
  char s1[255] = "QWERTY";
  ck_assert_pstr_eq(memset(s1, 2, 6), s21_memset(s1, 2, 6));
}
END_TEST

// Функция strcat.

START_TEST(strcat_1) {
  char str_1[50] = "Hello";
  char str_2[50] = "Hello World";
  ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
}
END_TEST

START_TEST(strcat_2) {
  char str_1[50] = "Hello";
  char str_2[50] = "Hello World";
  ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
}
END_TEST

START_TEST(strcat_3) {
  char str_1[50] = "\0";
  char str_2[50] = "123";
  ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
}
END_TEST

START_TEST(strcat_4) {
  char str_1[50] = "\0";
  char str_2[50] = "\n\\\\\0";
  ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
}
END_TEST

START_TEST(strcat_5) {
  char str_1[50] = " 1 -";
  char str_2[50] = "\t!";
  ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
}
END_TEST

// Функция strncat.

START_TEST(strncat_1) {
  char str_1[100] = "Hello";
  char str_2[100] = " World";
  ck_assert_str_eq(strncat(str_1, str_2, 3), s21_strncat(str_1, str_2, 3));
}
END_TEST

START_TEST(strncat_2) {
  char str_1[100] = "\0";
  char str_2[100] = "i am proger";
  ck_assert_str_eq(strncat(str_1, str_2, 13), s21_strncat(str_1, str_2, 13));
}
END_TEST

START_TEST(strncat_3) {
  char str_1[100] = "\n";
  char str_2[100] = "p-\0-roger";
  ck_assert_str_eq(strncat(str_1, str_2, 9), s21_strncat(str_1, str_2, 9));
}
END_TEST

START_TEST(strncat_4) {
  char str_1[100] = "-\t-";
  char str_2[100] = "\0";
  ck_assert_str_eq(strncat(str_1, str_2, 2), s21_strncat(str_1, str_2, 2));
}
END_TEST

START_TEST(strncat_5) {
  char str_1[100] = " \b";
  char str_2[100] = "  1 \n";
  ck_assert_str_eq(strncat(str_1, str_2, 5), s21_strncat(str_1, str_2, 5));
}
END_TEST

// Функция strchr.

START_TEST(strchr_1) {
  char str[] = "Hello world";
  int c = 3;
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_2) {
  char str[] = "Hello world\0";
  int c = 5;
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_3) {
  char str[] = "Hello world";
  int c = 12;
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_4) {
  char str[] = "Hello world";
  int c = '\0';
  ck_assert_str_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_5) {
  char str[] = "";
  int c = 0;
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

// Функция strcmp.

START_TEST(strcmp_1) {
  ck_assert_int_eq(strcmp(" \n\0\0", " a\n\0"),
                   s21_strcmp(" \n\0\0", " a\n\0"));
}
END_TEST

START_TEST(strcmp_2) {
  ck_assert_int_eq(strcmp("Zdarova Patsany ", "Pagoda kharoshaya "),
                   s21_strcmp("Zdarova Patsany ", "Pagoda kharoshaya "));
}
END_TEST

START_TEST(strcmp_3) {
  char str[] = "Privet";
  char str1[] = "Privet";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(strcmp_4) {
  ck_assert_int_eq(strcmp("Privet", "Prvt"), s21_strcmp("Privet", "Prvt"));
}
END_TEST

START_TEST(strcmp_5) {
  ck_assert_int_eq(strcmp("Privet", ""), s21_strcmp("Privet", ""));
}
END_TEST
// Функция strncmp.

START_TEST(strncmp_1) {
  ck_assert_int_eq(strncmp("\0", "The love of coding", 0),
                   s21_strncmp("\0", "The love of coding", 0));
}
END_TEST

START_TEST(strncmp_2) {
  ck_assert_int_eq(strncmp("i am\nproger", " \n\0\0", 5),
                   s21_strncmp("i am\nproger", " \n\0\0", 5));
}
END_TEST

START_TEST(strncmp_3) {
  ck_assert_int_eq(strncmp(" a\n\0", "1234567890", 3),
                   s21_strncmp(" a\n\0", "1234567890", 3));
}
END_TEST

START_TEST(strncmp_4) {
  ck_assert_int_eq(strncmp("1234975654", "1234567890", 1),
                   s21_strncmp("1234975654", "1234567890", 1));
}
END_TEST

START_TEST(strncmp_5) {
  ck_assert_int_eq(strncmp("1234567890", "qwerty", 5),
                   s21_strncmp("1234567890", "qwerty", 5));
}
END_TEST

// Функция strcpy.

START_TEST(strcpy_1) {
  char str_1[50] = " \n\0\0";
  char str_2[50] = " a\n\0";
  ck_assert_str_eq(strcpy(str_1, str_2), s21_strcpy(str_1, str_2));
}
END_TEST

START_TEST(strcpy_2) {
  char str_1[50] = "\n\t";
  char str_2[50] = "\056";
  ck_assert_str_eq(strcpy(str_1, str_2), s21_strcpy(str_1, str_2));
}
END_TEST

START_TEST(strcpy_3) {
  char str_1[50] = "Hello";
  char str_2[50] = "\t\n World!";
  ck_assert_str_eq(strcpy(str_1, str_2), s21_strcpy(str_1, str_2));
}
END_TEST

START_TEST(strcpy_4) {
  char str_1[50] = "0";
  char str_2[50] = "0\n\n6\t/t8";
  ck_assert_str_eq(strcpy(str_1, str_2), s21_strcpy(str_1, str_2));
}
END_TEST

START_TEST(strcpy_5) {
  char str_1[50] = "\t/n\n\0/0 ";
  char str_2[50] = " \t/n\n\0/0";
  ck_assert_str_eq(strcpy(str_1, str_2), s21_strcpy(str_1, str_2));
}
END_TEST

// Функция strncpy.

START_TEST(strncpy_1) {
  char str_1[50] = "qwerty";
  char str_2[50] = "12345";
  ck_assert_str_eq(strncpy(str_1, str_2, 2 * 2),
                   s21_strncpy(str_1, str_2, 2 * 2));
}
END_TEST

START_TEST(strncpy_2) {
  char str_1[60] = "50 pdfh";
  char str_2[50] = "HELLO!\n5";
  ck_assert_str_eq(strncpy(str_1, str_2, 5 - 1),
                   s21_strncpy(str_1, str_2, 5 - 1));
}
END_TEST

START_TEST(strncpy_3) {
  char str_1[50] = "\n/f\f/n";
  char str_2[50] = "55/f/n\f\n";
  ck_assert_str_eq(strncpy(str_1, str_2, 0), s21_strncpy(str_1, str_2, 0));
}
END_TEST

START_TEST(strncpy_4) {
  char str_1[20] = "abrakadabra ";
  char str_2[] = " 123";
  ck_assert_str_eq(strncpy(str_1, str_2, 10), s21_strncpy(str_1, str_2, 10));
}
END_TEST

START_TEST(strncpy_5) {
  char str_1[50] = "s_=+*&/te   ";
  char str_2[50] = "vosem'";
  ck_assert_str_eq(strncpy(str_1, str_2, 6), s21_strncpy(str_1, str_2, 6));
}
END_TEST

// Функция strcspn.

START_TEST(strcspn_1) {
  char str[] = "23476";
  char str1[] = "234";
  ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_2) {
  char str[] = "Hello there\0ef234eferef46";
  char str1[] = " H";
  ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_3) {
  char str[] = "Hi there\n\0dg2few34erfe6";
  char str1[] = "H";
  ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_4) {
  char str[] = "Hi there\n\0def84vr98";
  char str1[] = " ";
  ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_5) {
  char str[] = "Hi there\084ewf74er9";
  char str1[] = "";
  ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

// Функция strerror.

START_TEST(strerror_1) {
  int num1 = 0;
  ck_assert_str_eq(strerror(num1), s21_strerror(num1));
}
END_TEST

START_TEST(strerror_2) {
  int num2 = 105;
  ck_assert_str_eq(strerror(num2), s21_strerror(num2));
}
END_TEST

START_TEST(strerror_3) {
  int num3 = 2147483647;
  ck_assert_str_eq(strerror(num3), s21_strerror(num3));
}
END_TEST

START_TEST(strerror_4) {
  int num4 = -2147483648;
  ck_assert_str_eq(strerror(num4), s21_strerror(num4));
}
END_TEST

START_TEST(strerror_5) {
  for (int i = 0; i < N - 1; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

// Функция strlen.

START_TEST(strlen_1) {
  char string[10] = "I'm here";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_2) {
  char string[] = "I'm here\0\n";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_3) {
  char string[] = "\n\n\f\r\t";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_4) {
  char string[] = "hdijcke fhvherpiov49879865er1v8f#$^$rggbre";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

START_TEST(strlen_5) {
  char string[] = "ncngejneferqjewnqw\0tjodfievgowemowerv45245";
  ck_assert_int_eq(strlen(string), s21_strlen(string));
}
END_TEST

// функия strpbrk

START_TEST(strpbrk_1) {
  char str[] = "\0";
  char str1[] = "the begin of the end";
  ck_assert_ptr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(strpbrk_2) {
  char str[] = "Hello";
  char str1[] = "lo";
  ck_assert_str_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(strpbrk_3) {
  char str[] = "";
  char str1[] = " a\n\0";
  ck_assert_ptr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(strpbrk_4) {
  char str[] = " school21\0";
  char str1[] = "";
  ck_assert_ptr_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

START_TEST(strpbrk_5) {
  char str[] = " \n\0\0";
  char str1[] = " a\n\0";
  ck_assert_str_eq(strpbrk(str, str1), s21_strpbrk(str, str1));
}
END_TEST

// Функция strrchr

START_TEST(strrchr_1) {
  char str[] = "Zdarova Patsany – pagoda kharoshaya";
  int c = 'P';
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_2) {
  char str[] = "Hi there";
  int c = 'e';
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_3) {
  char str[] = "Hi there ";
  int c = 'i';
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_4) {
  char str[] = "Hi there";
  int c = 0;
  ck_assert_str_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_5) {
  char str[] = "";
  int c = 'a';
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

// Функция strspn

START_TEST(strspn_1) {
  char str[] = "23476";
  char str1[] = "234";
  ck_assert_int_eq(strspn(str, str1), s21_strspn(str, str1));
}
END_TEST

START_TEST(strspn_2) {
  char str[] = "dg234asfd76";
  char str1[] = "23dfgh4";
  ck_assert_int_eq(strspn(str, str1), s21_strspn(str, str1));
}
END_TEST

START_TEST(strspn_3) {
  char str[] = "Hi there\0dg234asfd76";
  char str1[] = "";
  ck_assert_int_eq(strspn(str, str1), s21_strspn(str, str1));
}
END_TEST

START_TEST(strspn_4) {
  char str[] = "Hi there\0dg234asfd76";
  char str1[] = "\0";
  ck_assert_int_eq(strspn(str, str1), s21_strspn(str, str1));
}
END_TEST

START_TEST(strspn_5) {
  char str[] = "Hi there\0dg234asfd76";
  char str1[] = " H";
  ck_assert_int_eq(strspn(str, str1), s21_strspn(str, str1));
}
END_TEST

// Функция strstr

START_TEST(strstr_1) {
  char str[] = "Zdarova Patsany – Pagoda kharoshaya";
  char str1[] = "Pagoda";
  ck_assert_str_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_2) {
  char str[] = " \n\0\0";
  char str1[] = " a\n\0";
  ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_3) {
  char str[] = "\0";
  char str1[] = " school21\0";
  ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_4) {
  char str[] = "I'm\nproger";
  char str1[] = " a\n\0";
  ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_5) {
  char str[] = "Hello World";
  char str1[] = "Hell";
  ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

// Функция strtok

START_TEST(strtok_1) {
  char str1[6] = "delim";
  char str2[2] = "f";
  ck_assert_pstr_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_2) {
  char str1[] = "qwerty";
  char str2[] = "1234";
  ck_assert_pstr_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_3) {
  char str1[22] = "Per, :aspera;ad astra";
  char str2[3] = " ";
  ck_assert_pstr_eq(strtok(str1, str2), s21_strtok(str1, str2));
}
END_TEST

START_TEST(strtok_4) {
  char str1[] = "Abra/Kadabra\\";
  char str2[] = "Abra/Kadabra\\";
  char simbols[] = "/";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str1, simbols);
  nstr_2 = s21_strtok(str2, simbols);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, simbols);
    nstr_2 = s21_strtok(s21_NULL, simbols);
  }
}
END_TEST

START_TEST(strtok_5) {
  char str1[] = "Россия Германия Палестина  - страшный, комедийный фильм.";
  char str2[] = "Россия Германия Палестина - страшный, комедийный фильм.";
  char simbols[5] = " ,.-";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str1, simbols);
  nstr_2 = s21_strtok(str2, simbols);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, simbols);
    nstr_2 = s21_strtok(s21_NULL, simbols);
  }
}
END_TEST

START_TEST(strtok_6) {
  char str4_1[] = "testing with original string.h";
  char str4_2[] = "testing with original string.h";
  char del4[3] = ". ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, del4);
    nstr_2 = s21_strtok(s21_NULL, del4);
  }
}
END_TEST

// sprintf
START_TEST(sprintf_simple) {
  char buff[100];
  char s21_buff[100];
  int res = sprintf(buff, "abacaba");
  int s21_res = s21_sprintf(s21_buff, "abacaba");

  ck_assert_str_eq(buff, s21_buff);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(sprintf_c) {
  int c1 = 'F';
  char buff[100];
  char s21_buff[100];

  int res = sprintf(buff, "abc[%5c]", c1);
  int s21_res = s21_sprintf(s21_buff, "abc[%5c]", c1);

  ck_assert_str_eq(buff, s21_buff);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(sprintf_d) {
  int c1 = 0;
  char buff[100];
  char s21_buff[100];
  int res = sprintf(buff, "abc[%+d]", c1);
  int s21_res = s21_sprintf(s21_buff, "abc[%+d]", c1);
  ck_assert_str_eq(buff, s21_buff);
  ck_assert_int_eq(res, s21_res);

  c1 = 2345;
  res = sprintf(buff,"%-15.8d", c1);
  s21_res = s21_sprintf(s21_buff, "%-15.8d", c1);
  ck_assert_str_eq(buff, s21_buff);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(sprintf_f) {
  double c1 = 123.4567;
  char buff[100];
  char s21_buff[100];
  int res = sprintf(buff, "[%18.5f]", c1);
  int s21_res = s21_sprintf(s21_buff, "[%18.5f]", c1);
  ck_assert_str_eq(buff, s21_buff);
  ck_assert_int_eq(res, s21_res);

  c1 = -0.345;
  res = sprintf(buff, "[%*.*f]", 10, 5, c1);
  s21_res = s21_sprintf(s21_buff, "[%*.*f]", 10, 5, c1);
  ck_assert_str_eq(buff, s21_buff);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(sprintf_s) {
  char *c1 = "abacaba";
  char buff[100];
  char s21_buff[100];

  int res = sprintf(buff, "abc[%5s]", c1);
  int s21_res = s21_sprintf(s21_buff, "abc[%5s]", c1);

  ck_assert_str_eq(buff, s21_buff);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(sprintf_u) {
  unsigned c1 = 1234;
  char buff[100];
  char s21_buff[100];
  int res = sprintf(buff, "abc[%u]", c1);
  int s21_res = s21_sprintf(s21_buff, "abc[%u]", c1);

  ck_assert_str_eq(buff, s21_buff);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

// sscanf
START_TEST(test_d) {
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("298 7 3", "%d%*d%d", &x1, &x2),
                   s21_sscanf("298 7 3", "%d%*d%d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  ck_assert_int_eq(sscanf("298/02", "%d%*c%d", &x1, &x2),
                   s21_sscanf("298/02", "%d%*c%d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  ck_assert_int_eq(sscanf("298\n\t 3.1", "%d%d", &x1, &x2),
                   s21_sscanf("298\n\t 3.1", "%d%d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  int x5, y5;
  ck_assert_int_eq(sscanf("298\n\t 3.1", "%d%d%n", &x1, &x2, &x5),
                   s21_sscanf("298\n\t 3.1", "%d%d%n", &y1, &y2, &y5));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
  ck_assert_int_eq(x5, y5);

  short int x4, y4;
  ck_assert_int_eq(sscanf("298 3", "%d%hd", &x1, &x4),
                   s21_sscanf("298 3", "%d%hd", &y1, &y4));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x4, y4);

  long int x3, y3;
  ck_assert_int_eq(sscanf("298 3", "%ld%hd", &x3, &x4),
                   s21_sscanf("298 3", "%ld%hd", &y3, &y4));
  // ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);

  ck_assert_int_eq(sscanf("298 3", "%ld%n%hd", &x3, &x1, &x4),
                   s21_sscanf("298 3", "%ld%n%hd", &y3, &y1, &y4));
  // ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x4, y4);
}

END_TEST

START_TEST(test_x) {
  unsigned int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("298 7 ab", "%x%*x%x", &x1, &x2),
                   s21_sscanf("298 7 ab", "%x%*x%x", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  unsigned short x3, y3;
  unsigned long x4, y4;
  ck_assert_int_eq(sscanf("298 7 ab", "%hX%*i%lx", &x3, &x4),
                   s21_sscanf("298 7 ab", "%hX%*i%lx", &y3, &y4));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);
}

END_TEST

START_TEST(test_o) {
  unsigned int x1, x2 = 0, y1, y2 = 0;
  ck_assert_int_eq(sscanf("298 7 ab", "%o%*o%o", &x1, &x2),
                   s21_sscanf("298 7 ab", "%o%*o%o", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  short unsigned x3, y3;
  long unsigned x4, y4;
  ck_assert_int_eq(sscanf("298 7 ab", "%ho%*i%lo", &x3, &x4),
                   s21_sscanf("298 7 ab", "%ho%*i%lo", &y3, &y4));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);
}

END_TEST

START_TEST(test_u) {
  unsigned int x1, x2 = 0, y1, y2 = 0;
  ck_assert_int_eq(sscanf("298 -7 ab", "%u%*u%u", &x1, &x2),
                   s21_sscanf("298 -7 ab", "%u%*u%u", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  ck_assert_int_eq(sscanf("298 7 -3", "%u%*u%u", &x1, &x2),
                   s21_sscanf("298 7 -3", "%u%*u%u", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  short unsigned x3, y3;
  long unsigned x4, y4;
  ck_assert_int_eq(sscanf("298 -7 0003", "%hu%*i%lu", &x3, &x4),
                   s21_sscanf("298 -7 0003", "%hu%*i%lu", &y3, &y4));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);
}

END_TEST

START_TEST(test_i) {
  int x1, x2 = 0, y1, y2 = 0;
  ck_assert_int_eq(sscanf("0x298 -7 ab", "%i%*i%i", &x1, &x2),
                   s21_sscanf("0x298 -7 ab", "%i%*i%i", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  short x3, y3;
  long x4, y4;
  ck_assert_int_eq(sscanf("298 -7 0xab", "%hi%*i%li", &x3, &x4),
                   s21_sscanf("298 -7 0xab", "%hi%*i%li", &y3, &y4));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);

  ck_assert_int_eq(sscanf("298 -7 0xab", "%hn%i%ln", &x3, &x1, &x4),
                   s21_sscanf("298 -7 0xab", "%hn%i%ln", &y3, &y1, &y4));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);
}

END_TEST

START_TEST(test_f) {
  float x1, x2 = 0, y1, y2 = 0;
  ck_assert_int_eq(sscanf("298.3 4", "%f%f", &x1, &x2),
                   s21_sscanf("298.3 4", "%f%f", &y1, &y2));
  ck_assert_int_eq((x1 - y1) * 1e15, 0);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);

  ck_assert_int_eq(sscanf("298.3 0 nAN 4", "%f%*f%*f%f", &x1, &x2),
                   s21_sscanf("298.3 0 Nan 4", "%f%*f%*f%f", &y1, &y2));
  ck_assert_int_eq((x1 - y1) * 1e15, 0);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);

  long double x3, y3;
  ck_assert_int_eq(sscanf("298e-2 iNf 3E3", "%Lf%*f%f", &x3, &x2),
                   s21_sscanf("298e-2 InF 3E3", "%Lf%*f%f", &y3, &y2));
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
  ck_assert_int_eq((x3 - y3) * 1e15, 0);
}

END_TEST

START_TEST(test_c) {
  char x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("0 a", "%c %c", &x1, &x2),
                   s21_sscanf("0 a", "%c %c", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  ck_assert_int_eq(sscanf("0.a", "%c.%c", &x1, &x2),
                   s21_sscanf("0.a", "%c.%c", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  wchar_t x3, y3;
  ck_assert_int_eq(sscanf("3/5gf", "%lc%*c%cg%c", &x3, &x2, &x1),
                   s21_sscanf("3/5gf", "%lc%*c%cg%c", &y3, &y2, &y1));

  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
  ck_assert_int_eq(x3, y3);

  ck_assert_int_eq(sscanf("ȬŚƾ", "%lc%c%c", &x3, &x2, &x1),
                   s21_sscanf("ȬŚƾ", "%lc%c%c", &y3, &y2, &y1));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}

END_TEST

START_TEST(test_s) {
  char x1[10] = "\0", x2[10] = "\0", y1[10] = "\0", y2[10] = "\0";
  ck_assert_int_eq(sscanf("ya ebu sobak", "%9sebu%9s", x1, x2),
                   s21_sscanf("ya ebu sobak", "%9sebu%9s", y1, y2));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);

  ck_assert_int_eq(sscanf("ya ebu sobak", "%9s%*2s%9s", x1, x2),
                   s21_sscanf("ya ebu sobak", "%9s%*2s%9s", y1, y2));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);

  ck_assert_int_eq(sscanf("ya ebu sobak", "%9sf%9s", x1, x2),
                   s21_sscanf("ya ebu sobak", "%9sf%9s", y1, y2));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);

  ck_assert_int_eq(sscanf("  ya", "%9s%9s", x1, x2),
                   s21_sscanf("  ya", "%9s%9s", y1, y2));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);

  wchar_t x3[10], y3[10];
  int x4, y4;
  ck_assert_int_eq(
      sscanf("ya ebu % sobak", "%9ls%9s%%%n%9s", x3, x2, &x4, x1),
      s21_sscanf("ya ebu % sobak", "%9ls%s%%%n%9s", y3, y2, &y4, y1));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);
  ck_assert_int_eq(*x3, *y3);
  ck_assert_int_eq(x4, y4);

  ck_assert_int_eq(sscanf("ȬŚƾ", "%9ls%*s%n%9s", x3, &x4, x1),
                   s21_sscanf("ȬŚƾ", "%9ls%*s%n%9s", y3, &y4, y1));
  ck_assert_str_eq(x1, y1);
  ck_assert_int_eq(*x3, *y3);
  ck_assert_int_eq(x4, y4);
}

END_TEST

START_TEST(test_p) {
void *x1, *x2, *y1, *y2;
  sscanf("298 7 0xab", "%p%*p%p", &x1, &x2);
   s21_sscanf("298 7 0xab", "%p%*p%p", &y1, &y2);
  ck_assert_int_eq((long)x1, (long)y1);
  ck_assert_int_eq((long)x2, (long)y2);}

END_TEST

// Функция создания набора тестов.
Suite *example_suite_create(void) {
  Suite *suite = suite_create("s21_string.h functions");

  /*memchr cases*/
  TCase *tcase_core_memchr = tcase_create("memchr");
  tcase_add_test(tcase_core_memchr, memchr_1);
  tcase_add_test(tcase_core_memchr, memchr_2);
  tcase_add_test(tcase_core_memchr, memchr_3);
  tcase_add_test(tcase_core_memchr, memchr_4);
  tcase_add_test(tcase_core_memchr, memchr_5);
  suite_add_tcase(suite, tcase_core_memchr);

  /*memcmp cases*/
  TCase *tcase_core_memcmp = tcase_create("memcmp");
  tcase_add_test(tcase_core_memcmp, memcmp_1);
  tcase_add_test(tcase_core_memcmp, memcmp_2);
  tcase_add_test(tcase_core_memcmp, memcmp_3);
  tcase_add_test(tcase_core_memcmp, memcmp_4);
  tcase_add_test(tcase_core_memcmp, memcmp_5);
  suite_add_tcase(suite, tcase_core_memcmp);

  /*memcpy cases*/
  TCase *tcase_core_memcpy = tcase_create("memcpy");
  tcase_add_test(tcase_core_memcpy, memcpy_1);
  tcase_add_test(tcase_core_memcpy, memcpy_2);
  tcase_add_test(tcase_core_memcpy, memcpy_3);
  tcase_add_test(tcase_core_memcpy, memcpy_4);
  tcase_add_test(tcase_core_memcpy, memcpy_5);
  suite_add_tcase(suite, tcase_core_memcpy);

  /*memmove cases*/
  TCase *tcase_core_memmove = tcase_create("memmove");
  tcase_add_test(tcase_core_memmove, memmove_1);
  tcase_add_test(tcase_core_memmove, memmove_2);
  tcase_add_test(tcase_core_memmove, memmove_3);
  tcase_add_test(tcase_core_memmove, memmove_4);
  tcase_add_test(tcase_core_memmove, memmove_5);
  suite_add_tcase(suite, tcase_core_memmove);

  /*memset cases*/
  TCase *tcase_core_memset = tcase_create("memset");
  tcase_add_test(tcase_core_memset, memset_1);
  tcase_add_test(tcase_core_memset, memset_2);
  tcase_add_test(tcase_core_memset, memset_3);
  tcase_add_test(tcase_core_memset, memset_4);
  tcase_add_test(tcase_core_memset, memset_5);
  suite_add_tcase(suite, tcase_core_memset);

  /*strcat cases*/
  TCase *tcase_core_strcat = tcase_create("strcat");
  tcase_add_test(tcase_core_strcat, strcat_1);
  tcase_add_test(tcase_core_strcat, strcat_2);
  tcase_add_test(tcase_core_strcat, strcat_3);
  tcase_add_test(tcase_core_strcat, strcat_4);
  tcase_add_test(tcase_core_strcat, strcat_5);
  suite_add_tcase(suite, tcase_core_strcat);

  /*strncat cases*/
  TCase *tcase_core_strncat = tcase_create("strncat");
  tcase_add_test(tcase_core_strncat, strncat_1);
  tcase_add_test(tcase_core_strncat, strncat_2);
  tcase_add_test(tcase_core_strncat, strncat_3);
  tcase_add_test(tcase_core_strncat, strncat_4);
  tcase_add_test(tcase_core_strncat, strncat_5);
  suite_add_tcase(suite, tcase_core_strncat);

  /*strchr cases*/
  TCase *tcase_core_strchr = tcase_create("strchr");
  tcase_add_test(tcase_core_strchr, strchr_1);
  tcase_add_test(tcase_core_strchr, strchr_2);
  tcase_add_test(tcase_core_strchr, strchr_3);
  tcase_add_test(tcase_core_strchr, strchr_4);
  tcase_add_test(tcase_core_strchr, strchr_5);
  suite_add_tcase(suite, tcase_core_strchr);

  /*strcmp cases*/
  TCase *tcase_core_strcmp = tcase_create("strcmp");
  tcase_add_test(tcase_core_strcmp, strcmp_1);
  tcase_add_test(tcase_core_strcmp, strcmp_2);
  tcase_add_test(tcase_core_strcmp, strcmp_3);
  tcase_add_test(tcase_core_strcmp, strcmp_4);
  tcase_add_test(tcase_core_strcmp, strcmp_5);
  suite_add_tcase(suite, tcase_core_strcmp);

  /*strncmp cases*/
  TCase *tcase_core_strncmp = tcase_create("strncmp");
  tcase_add_test(tcase_core_strncmp, strncmp_1);
  tcase_add_test(tcase_core_strncmp, strncmp_2);
  tcase_add_test(tcase_core_strncmp, strncmp_3);
  tcase_add_test(tcase_core_strncmp, strncmp_4);
  tcase_add_test(tcase_core_strncmp, strncmp_5);
  suite_add_tcase(suite, tcase_core_strncmp);

  /*strcpy cases*/
  TCase *tcase_core_strcpy = tcase_create("strcpy");
  tcase_add_test(tcase_core_strcpy, strcpy_1);
  tcase_add_test(tcase_core_strcpy, strcpy_2);
  tcase_add_test(tcase_core_strcpy, strcpy_3);
  tcase_add_test(tcase_core_strcpy, strcpy_4);
  tcase_add_test(tcase_core_strcpy, strcpy_5);
  suite_add_tcase(suite, tcase_core_strcpy);

  /*strncpy cases*/
  TCase *tcase_core_strncpy = tcase_create("strncpy");
  tcase_add_test(tcase_core_strncpy, strncpy_1);
  tcase_add_test(tcase_core_strncpy, strncpy_2);
  tcase_add_test(tcase_core_strncpy, strncpy_3);
  tcase_add_test(tcase_core_strncpy, strncpy_4);
  tcase_add_test(tcase_core_strncpy, strncpy_5);
  suite_add_tcase(suite, tcase_core_strncpy);

  /*strcspn cases*/
  TCase *tcase_core_strcspn = tcase_create("strcspn");
  tcase_add_test(tcase_core_strcspn, strcspn_1);
  tcase_add_test(tcase_core_strcspn, strcspn_2);
  tcase_add_test(tcase_core_strcspn, strcspn_3);
  tcase_add_test(tcase_core_strcspn, strcspn_4);
  tcase_add_test(tcase_core_strcspn, strcspn_5);
  suite_add_tcase(suite, tcase_core_strcspn);

  /*strerror cases*/
  TCase *tcase_core_strerror = tcase_create("strerror");
  tcase_add_test(tcase_core_strerror, strerror_1);
  tcase_add_test(tcase_core_strerror, strerror_2);
  // tcase_add_test(tcase_core_strerror, strerror_3);
  // tcase_add_test(tcase_core_strerror, strerror_4);
  // tcase_add_test(tcase_core_strerror, strerror_5);
  suite_add_tcase(suite, tcase_core_strerror);

  /*strlen cases*/
  TCase *tcase_core_strlen = tcase_create("strlen");
  tcase_add_test(tcase_core_strlen, strlen_1);
  tcase_add_test(tcase_core_strlen, strlen_2);
  tcase_add_test(tcase_core_strlen, strlen_3);
  tcase_add_test(tcase_core_strlen, strlen_4);
  tcase_add_test(tcase_core_strlen, strlen_5);
  suite_add_tcase(suite, tcase_core_strlen);

  /*strpbrk cases*/
  TCase *tcase_core_strpbrk = tcase_create("strpbrk");
  tcase_add_test(tcase_core_strpbrk, strpbrk_1);
  tcase_add_test(tcase_core_strpbrk, strpbrk_2);
  tcase_add_test(tcase_core_strpbrk, strpbrk_3);
  tcase_add_test(tcase_core_strpbrk, strpbrk_4);
  tcase_add_test(tcase_core_strpbrk, strpbrk_5);
  suite_add_tcase(suite, tcase_core_strpbrk);

  /*strrchr cases*/
  TCase *tcase_core_strrchr = tcase_create("strrchr");
  tcase_add_test(tcase_core_strrchr, strrchr_1);
  tcase_add_test(tcase_core_strrchr, strrchr_2);
  tcase_add_test(tcase_core_strrchr, strrchr_3);
  tcase_add_test(tcase_core_strrchr, strrchr_4);
  tcase_add_test(tcase_core_strrchr, strrchr_5);
  suite_add_tcase(suite, tcase_core_strrchr);

  /*strspn cases*/
  TCase *tcase_core_strspn = tcase_create("strspn");
  tcase_add_test(tcase_core_strspn, strspn_1);
  tcase_add_test(tcase_core_strspn, strspn_2);
  tcase_add_test(tcase_core_strspn, strspn_3);
  tcase_add_test(tcase_core_strspn, strspn_4);
  tcase_add_test(tcase_core_strspn, strspn_5);
  suite_add_tcase(suite, tcase_core_strspn);

  /*strstr cases*/
  TCase *tcase_core_strstr = tcase_create("strstr");
  tcase_add_test(tcase_core_strstr, strstr_1);
  tcase_add_test(tcase_core_strstr, strstr_2);
  tcase_add_test(tcase_core_strstr, strstr_3);
  tcase_add_test(tcase_core_strstr, strstr_4);
  tcase_add_test(tcase_core_strstr, strstr_5);
  suite_add_tcase(suite, tcase_core_strstr);

  /*strtok cases*/
  TCase *tcase_core_strtok = tcase_create("strtok");
  tcase_add_test(tcase_core_strtok, strtok_1);
  tcase_add_test(tcase_core_strtok, strtok_2);
  tcase_add_test(tcase_core_strtok, strtok_3);
  tcase_add_test(tcase_core_strtok, strtok_4);
  tcase_add_test(tcase_core_strtok, strtok_5);
  tcase_add_test(tcase_core_strtok, strtok_6);
  suite_add_tcase(suite, tcase_core_strtok);

  TCase *tcase_core_sprintf = tcase_create("sprintf");

  tcase_add_test(tcase_core_sprintf, sprintf_simple);
  tcase_add_test(tcase_core_sprintf, sprintf_c);
  tcase_add_test(tcase_core_sprintf, sprintf_d);
  tcase_add_test(tcase_core_sprintf, sprintf_f);
  tcase_add_test(tcase_core_sprintf, sprintf_s);
  tcase_add_test(tcase_core_sprintf, sprintf_u);
  suite_add_tcase(suite, tcase_core_sprintf);

  TCase *tcase_core_sscanf = tcase_create("sscanf");

  tcase_add_test(tcase_core_sscanf, test_d);
  tcase_add_test(tcase_core_sscanf, test_x);
  tcase_add_test(tcase_core_sscanf, test_o);
  tcase_add_test(tcase_core_sscanf, test_u);
  tcase_add_test(tcase_core_sscanf, test_i);
  tcase_add_test(tcase_core_sscanf, test_f);
  tcase_add_test(tcase_core_sscanf, test_c);
  tcase_add_test(tcase_core_sscanf, test_s);
  // tcase_add_test(tcase_core_sscanf, test_p);

  suite_add_tcase(suite, tcase_core_sscanf);

  return suite;
}

int main(void) {
  Suite *suite = example_suite_create();
  SRunner *suite_runner = srunner_create(suite);
  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  // Получаем количество проваленных тестов.
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  if (failed_count != 0) {
    // Сигнализируем о том, что тестирование прошло неудачно.
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
