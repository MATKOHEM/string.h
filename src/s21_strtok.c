#include "s21_string.h"

char* s21_strtok(char* str, const char* delim) {
  /*Функция strtok выделяет очередную часть строки, на которую указывает
  аргумент str, отделенную одним из символов разделителей указанных в строке, на
  которую указывает аргумент sep. Последовательный вызов функции strtok приводит
  к разбиению строки str на части (лексемы). При первом вызове в str подается
  строка, которую потом храним в static lastToken. И в последующих вызовах ы str
  передается NULL.

  Возвращает - NULL – если строку str невозможно разделить на части.
Указатель на первый символ выделенной части строки.
*/
  static char* ptr = s21_NULL;
  char* res = ptr;
  if (str) {
    ptr = str;
  }
  if (ptr) {
    while (*ptr && s21_strchr(delim, *ptr)) {
      ++ptr;
    }
    res = ptr;
    if ((ptr = s21_strpbrk(ptr, delim))) {
      *ptr = '\0';
      ++ptr;
    }
    if (*res == '\0') {
      res = s21_NULL;
    }
  }
  return res;
}