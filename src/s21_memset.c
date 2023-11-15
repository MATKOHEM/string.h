#include "s21_string.h"

void *s21_memset(void *str, int c, size_t n) {
  /*
  Функция memset заполняет первые n байт области памяти, на которую указывает
  аргумент destination, символом, код которого указывается аргументом c.

  Возвращает - указатель на заполняемый массив.

  */

  s21_size_t i = 0;
  for (; i < n; i++) {
    *((char *)str + i) = c;
  }
  return str;
}
