#ifndef C2_S21_STRINGPLUS_2_S21_SSCANF_H
#define C2_S21_STRINGPLUS_2_S21_SSCANF_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUFF_SIZE 1000

struct specifier {
  bool unsigned_number;
  bool octal_number;
  bool hexadecimal_number;
  bool decimal_number;
  bool ignore;
  bool short_int;
  bool long_int;
  bool long_double;
  bool num_match;
  bool break_function;
  int count_characters;
  int width;
};

int s21_sscanf(const char *str, const char *format, ...);
const char *sscanf_float(const char *str, long double *value,
                         struct specifier *conditions);
const char *sscanf_int(const char *str, long *value,
                       struct specifier *conditions);
const char *sscanf_ptr(const char *str, unsigned long *value,
                       struct specifier *conditions);
const char *sscanf_str(const char *str, char *value,
                       struct specifier *conditions);
const char *sscanf_char(const char *str, char *value,
                        struct specifier *conditions);
const char *parse_hexadecimal(const char *str, long *result, int *flag,
                              struct specifier *conditions);
const char *parse_octal(const char *str, long *result, int *flag,
                        struct specifier *conditions);
const char *parse_digit(const char *str, long *result, int *flag,
                        struct specifier *conditions);
int define_specifier(const char *format, const char **str, va_list *args,
                     struct specifier *conditions);
void reset_conditions(struct specifier *conditions);
const char *check_space(const char *str, struct specifier *conditions);
int check_width(const char *format, struct specifier *conditions);
int check_length(const char *format, struct specifier *conditions);
int check_flag(int *flag, struct specifier *conditions);
int process_int(const char **str, va_list *args, struct specifier *conditions);
int process_float(const char **str, va_list *args,
                  struct specifier *conditions);
int process_char(const char **str, va_list *args, struct specifier *conditions);
int process_string(const char **str, va_list *args,
                   struct specifier *conditions);
int process_pointer(const char **str, va_list *args,
                    struct specifier *conditions);
void process_counter(va_list *args, struct specifier *conditions);
int is_digit(char c);
int is_space(char c);
int is_octal(char c);
int is_hexadecimal(char c);
int invisible_characters(char c);

#endif  // C2_S21_STRINGPLUS_2_S21_SSCANF_H
