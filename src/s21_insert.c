#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  void *res = s21_NULL;
  if (str && src) {
    s21_size_t str_len = s21_strlen(str);
    s21_size_t src_len = s21_strlen(src);
    if (start_index <= src_len) {
      res = malloc(sizeof(char) * (str_len + src_len + 1));
    }
    if (res) {
      char *pos;
      pos = (char *)s21_memcpy(res, src, start_index) + start_index;
      pos = (char *)s21_memcpy(pos, str, str_len) + str_len;
      s21_strcpy(pos, src + start_index);
    }
  }
  return res;
}