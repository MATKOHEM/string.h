#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  /*
  Функция strchr ищет первое вхождения символа, код которого указан в аргументе
ch, в строке, на которую указывает аргумент str.

Возвращает - Указатель на искомый символ, если он найден в строке str, иначе
NULL.
  */
  const char ch = (const char)c;
  while (*str && *str != ch) {
    ++str;
  }
  if (*str != ch) {
    str = s21_NULL;
  }
  return (char *)str;
}
