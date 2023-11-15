#include "s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  /*
  Функция strcspn определяет наибольшую длину начального участка строки, на
  которую указывает аргумент str, не содержащего не один из символов строки, на
  которую указывает аргумент sym.

  Возвращает - Длина начального участка строки, не содержащая символов указанных
  в аргументе sym.
  */
  s21_size_t count = 0;
  int flag = 0;
  s21_size_t i = 0;
  for (; str1[i] && flag == 0; i++) {
    s21_size_t j = 0;
    for (; str2[j]; j++) {
      if (*((char *)str1 + i) == *((char *)str2 + j)) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      count++;
    }
  }
  return count;
}