#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  /*
  Функция strpbrk ищет первое вхождение в строку, на которую указывает аргумент
str1, одного из символов, входящих в строку, на которую указывает аргумент str2.

  Возвращает:

  NULL – если не один символ из троки sym не найден в строке str.
Указатель на первый найденный в строке str символ из множества символов строки
sym.
  */
  char *res = s21_NULL;
  s21_size_t i = 0;
  s21_size_t j = 0;
  int flag = 0;
  for (; str1[i]; i++) {
    j = 0;
    for (; str2[j]; j++) {
      if (str1[i] == str2[j]) {
        flag = 1;
        res = (char *)str1 + i;
        break;
      }
    }
    if (flag == 1) {
      break;
    }
  }
  return res;
}