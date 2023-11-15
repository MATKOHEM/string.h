#include "s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
  /*
  Функция memchr ищет вхождение в массив (область памяти) символа, код которого
задан аргументом c, сравнивая каждый байт массива (области памяти) определенный
как unsigned char с кодом искомого символа. Если искомый символ найден, то
возвращается адрес найденного символа и сравнение завершается. Если, после
проверки n байтов, искомый символ не найден, то сравнение прекращается и функция
возвращает NULL.

  Возвращает:
  Указатель на найденный символ, если, на указанном участке массива, найден
требуемый символ. NULL – если требуемый символ не найден.
  */
  const unsigned char *ch = (const unsigned char *)str;
  s21_size_t i;

  for (i = 0; i < n && ch[i] != (unsigned char)c; i++)
    ;

  return (i == n ? s21_NULL : (void *)(ch + i));
}
