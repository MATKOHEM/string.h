#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  /*
strstr ищет первое вхождение строки (за исключением признак конца строки), на
которую указывает аргумент needle, в строку , на которую указывает аргумент
haystack. Если строка needle имеет нулевую длину, то функция вернет указатель на
начало строки haystack.

Возвращает - NULL – если строка needle не входит в строку haystack. Указатель на
первое вхождение строки needle в строку haystack.
*/

  s21_size_t n = s21_strlen(needle);
  char *res = (n ? s21_NULL : (char *)haystack);
  while (*haystack && res == s21_NULL) {
    if (s21_strncmp(needle, haystack, n) == 0) {
      res = (char *)haystack;
    }
    ++haystack;
  }
  return res;
}