#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *ptr = dest;
  while ((*ptr = *src)) {
    ++ptr;
    ++src;
  }
  return dest;
}