#ifndef S21_SPRINTF_H_
#define S21_SPRINTF_H_

#include "s21_string.h"

typedef struct {
  int plus;
  int minus;
  int space;
  int dot;
  int width;
  int precision;
  char length;
  char specifier;  // текущий спецификатор
} config;

int s21_sprintf(char *str, const char *format, ...);
const char *check_format(const char *format, config *flag);
int is_num(char ch);
int char_to_int(const char *str);
void conversion(config flag, char *buffer, va_list input);
void pars_sign_unsign_int(config flag, char *buffer, va_list input);
void num_to_string(int64_t value, char *buffer);
void reverse(char *s);
void do_precision(char *buffer, config flag);
void use_flags(char *buffer, config flag);
void pars_char(config flag, char *buffer, va_list input);
void pars_str(config flag, char *buffer, va_list input);
void pars_float(config flag, char *buffer, va_list input);
void char_to_str(config flag, char *buffer, char c);
void str_to_str(config flag, char *buffer, char *str);
void float_to_str(config flag, char *buffer, va_list input);
char *s21_strcpy(char *destptr, const char *srcptr);

#endif  //  SRC_S21_SPRINTF_H_
