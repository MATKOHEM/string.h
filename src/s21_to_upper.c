#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *str_new = s21_NULL;
  int error = 0;
  s21_size_t len = 0;
  if (str != s21_NULL) {
    len = s21_strlen(str);
    if (len < SIZE) {
      for (s21_size_t i = 0; i < len; i++) {
        if (str[i] < 0) {
          error = 1;
        }
      }
    }
  } else {
    error = 1;
  }
  if (error == 0) {
    str_new = (char *)calloc((s21_strlen(str) + 1), sizeof(char));
    if (str_new) {
      for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          str_new[i] = str[i] - 32;
        } else {
          str_new[i] = str[i];
        }
      }
      str_new[len] = '\0';
    } else {
      error = 1;
    }
  }
  return (error == 1) ? s21_NULL : str_new;
}