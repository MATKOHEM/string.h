#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n) {
  /*
  Функция strncpy копирует данные из строки, на которую указывает аргумент
source, в строку на который указывает аргумент destination, пока не встретится
символ конца строки (нулевой символ) или количество скопированных символов не
достигнет величины указанной в аргументе n. При этом символ конца строки не
копируется.

Если в аргументе n указана величина большая, чем длинна строки, т.е. символ
конца строки '\000' встретился раньше, чем было скопировано n символов, то в
массив, на который указывает аргумент destination, дозаписывается столько
нулевых символов, чтобы общая длина записанной строки достигла величины
указанной в аргументе n.

Если строки перекрываются, результат копирования будет не определен.

Возвращает - Функция возвращает указатель на строку, в которую скопированы
данные.
*/
  s21_size_t i = 0;
  int flag = 0;
  while (i < n) {
    if (src[i] != '\0' && flag == 0) {
      dest[i] = src[i];
    } else {
      dest[i] = '\0';
      flag = 1;
    }
    i++;
  }
  return dest;
}
