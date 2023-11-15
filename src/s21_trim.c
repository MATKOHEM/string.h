#include "s21_string.h"

char *s21_strend(const char *str) {
  while (*str) {
    ++str;
  }
  return (char *)str;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  const char *ptr = str1;
  while (*ptr && s21_strchr(str2, *ptr)) {
    ++ptr;
  }
  return (s21_size_t)(ptr - str1);
}

void *s21_trim(const char *src, const char *trim_chars) {
  void *res = s21_NULL;
  if (src && trim_chars) {
    src += s21_strspn(src, trim_chars);
    const char *last;
    last = (*src ? (const char *)s21_strend(src) - 1 : src);
    while (last > src && s21_strchr(trim_chars, *last)) {
      --last;
    }
    s21_size_t len = (s21_size_t)(last - src + 1);
    if ((res = malloc(sizeof(char) * (len + 1)))) {
      s21_memset(res, 0, sizeof(char));
      s21_strncat((char *)res, src, len);
    }
  }
  return res;
}