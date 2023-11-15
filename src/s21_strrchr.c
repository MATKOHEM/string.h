#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  /*
  Функция strchr ищет последнее вхождения символа, код которого указан в
  аргументе ch, в строке, на которую указывает аргумент str.

  Возвращает - Указатель на искомый символ, если он найден в строке str, иначе
  NULL.
  */
  size_t i = 0;
  while (str[i] && str[i] != c) i++;
  if (c == str[i])
    return (char *)str + i;
  else
    return s21_NULL;
}