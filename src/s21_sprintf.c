#include "s21_sprintf.h"

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  config flag = {0};
  va_list input;
  va_start(input, format);
  char *zero = str;
  while (*format) {
    char buffer[SIZE] = {'\0'};
    if (*format != '%') {
      *str++ = *format++;
      continue;
    } else {
      format++;
      s21_memset(&flag, 0, sizeof(config));  // s21
    }
    format = check_format(format, &flag);
    flag.specifier = *format;
    format++;
    conversion(flag, buffer, input);
    for (int i = 0; buffer[i]; i++, str++) {
      *str = buffer[i];
    }
  }
  *str = '\0';
  va_end(input);
  return str - zero;
}

const char *check_format(const char *format, config *flag) {
  while (*format == '+' || *format == '-' || *format == ' ') {
    if (*format == '+') {
      flag->plus = 1;
    } else if (*format == '-') {
      flag->minus = 1;
    } else if (*format == ' ') {
      flag->space = 1;
    }
    format++;
  }
  if (*format == '.') {
    flag->dot = 1;
    format++;
  }
  if (is_num(*format)) {
    char temp[SIZE] = {'\0'};
    for (int i = 0; is_num(*format); i++, format++) {
      temp[i] = *format;
    }
    if (!flag->dot) flag->width = char_to_int(temp);
    if (flag->dot) flag->precision = char_to_int(temp);
  }
  if (*format == 'h') {
    flag->length = 'h';
    format++;
  }
  if (*format == 'l') {
    flag->length = 'l';
    format++;
  }
  return format;
}

int is_num(char ch) { return ('0' <= ch && ch <= '9'); }

int char_to_int(const char *str) {
  int res = 0;
  while (*str && is_num(*str)) {
    res = res * 10 + (*str - '0');
    str++;
  }
  return res;
}

void conversion(config flag, char *buffer, va_list input) {
  if (flag.specifier == 'd' || flag.specifier == 'i' || flag.specifier == 'u') {
    pars_sign_unsign_int(flag, buffer, input);
  } else if (flag.specifier == 'c') {
    pars_char(flag, buffer, input);
  } else if (flag.specifier == 's') {
    pars_str(flag, buffer, input);
  } else if (flag.specifier == 'f') {
    pars_float(flag, buffer, input);
  } else if (flag.specifier == '%') {
    buffer[0] = '%';
  }
}

// "%.-10d" типо исключение
void pars_sign_unsign_int(config flag, char *buffer, va_list input) {
  long int value = va_arg(input, int64_t);
  flag.specifier == 'u' ? value = (uint32_t)value : value;

  if (flag.length == 0 && flag.specifier != 'u') {
    value = (int32_t)value;
  } else if (flag.length == 'l') {
    value = (uint64_t)value;
  } else if (flag.length == 'h') {
    if (flag.specifier != 'u')
      value = (int16_t)value;
    else
      value = (uint16_t)value;
  }
  if (!flag.precision && !value && !flag.plus && flag.dot) {
    buffer = s21_NULL;
  } else if (!flag.precision && !value && flag.plus && flag.specifier != 'u') {
    buffer[0] = '+';
    num_to_string(value, &buffer[1]);
  } else {
    num_to_string(value, buffer);
    do_precision(buffer, flag);
    use_flags(buffer, flag);
  }
}

void num_to_string(int64_t value, char *buffer) {
  int sign = 0, i = 0;
  value < 0 ? sign = 1 : 0;
  sign ? value = -value : value;
  do {
    buffer[i] = value % 10 + '0';
    value = value / 10;
    i++;
  } while (value > 0);
  if (sign == 1) {
    buffer[i++] = '-';
  }
  buffer[i] = '\0';
  reverse(buffer);
}

void reverse(char *s) {
  int i = 0, j = s21_strlen(s) - 1;  // s21
  for (; i < j; i++, j--) {
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void do_precision(char *buffer, config flag) {
  char temp[SIZE] = {'\0'};
  int sign = 0, len = s21_strlen(buffer);  // s21
  if (buffer[0] == '-') {
    temp[0] = '-';
    len--;
    sign = 1;
  }
  if (flag.precision > len) {
    int index = sign;
    for (; index < flag.precision - len + sign; temp[index++] = '0')
      ;
    for (; buffer[sign]; temp[index++] = buffer[sign++])
      ;
    s21_strcpy(buffer, temp);  // s21
  }
}

void use_flags(char *buffer, config flag) {
  char temp[SIZE + 1] = {'\0'};
  if (flag.plus && flag.specifier != 'u') {
    temp[0] = buffer[0] == '-' ? buffer[0] : '+';
    s21_strcpy(temp + 1, buffer[0] == '-' ? buffer + 1 : buffer);  // s21
    s21_strcpy(buffer, temp);                                      // s21
  } else if (flag.space && buffer[0] != '-' && flag.specifier != 'u') {
    temp[0] = ' ';
    s21_strcpy(temp + 1, buffer);  // s21
    s21_strcpy(buffer, temp);      // s21
  }
  if (flag.width > (int)s21_strlen(buffer)) {     // s21
    int index = flag.width - s21_strlen(buffer);  // s21
    if (!flag.minus) {
      s21_memset(temp, ' ', index);      // s21
      s21_strcpy(temp + index, buffer);  // s21
    } else {
      s21_strcpy(temp, buffer);                         // s21
      s21_memset(temp + s21_strlen(temp), ' ', index);  // s21 s21
    }
    s21_strcpy(buffer, temp);  // s21
  }
}

void pars_char(config flag, char *buffer, va_list input) {
  char c = va_arg(input, int);
  char_to_str(flag, buffer, c);
}

void pars_str(config flag, char *buffer, va_list input) {
  char *c = va_arg(input, char *);
  if (c == s21_NULL) {
    c = "(null)";
  }
  str_to_str(flag, buffer, c);
}

void char_to_str(config flag, char *buffer, char c) {
  if (!flag.minus && flag.width) {
    for (int i = 0; i < flag.width; i++) {
      buffer[i] = ' ';
      i == flag.width - 1 ? buffer[i] = c : buffer[i];
    }
  } else if (flag.width) {
    buffer[0] = c;
    for (int i = 1; i < flag.width; i++) {
      buffer[i] = ' ';
    }
  } else {
    buffer[0] = c;
  }
}

void str_to_str(config flag, char *buffer, char *str) {
  char temp[SIZE] = {'\0'};
  s21_strcpy(temp, str);  // s21
  if (flag.dot) temp[flag.precision] = '\0';
  int w = flag.width - s21_strlen(temp);  // s21
  int len = s21_strlen(temp);             // s21
  if (flag.minus && w > 0) {
    s21_strcpy(buffer, temp);          // s21
    s21_memset(buffer + len, ' ', w);  // s21
  } else if (w > 0) {
    s21_memset(buffer, ' ', w);    // s21
    s21_strcpy(buffer + w, temp);  // s21
  } else {
    s21_strcpy(buffer, temp);  // s21
  }
}

void pars_float(config flag, char *buffer, va_list input) {
  double value = va_arg(input, double);
  char temp[SIZE] = {'\0'};
  int sign = 0, index = SIZE - 2;
  !flag.dot ? flag.precision = 6 : flag.precision;
  value < 0 ? sign = 1 : 0;
  sign ? value = -value : value;
  double l = 0, r = modf(value, &l);
  if (!flag.precision) {
    l = roundl(value);
    r = 0;
  }
  char f[SIZE] = {'\0'};
  for (int i = 0; i < flag.precision; i++) {
    r *= 10;
    f[i] = (int)r + '0';
  }
  long long rt = roundl(r), left = l;
  if (!rt) {
    for (int i = 0; i < flag.precision; index--, i++) temp[index] = '0';
  } else {
    for (int i = s21_strlen(f); rt || i > 0; rt /= 10, index--, i--)  // s21
      temp[index] = (int)(rt % 10 + 0.05) + '0';
  }
  if ((flag.dot && flag.precision) || (int)r || (!flag.dot && !value) ||
      s21_strlen(f))  // s21
    temp[index--] = '.';
  if (!left) {
    temp[index--] = '0';
  } else {
    for (; left; left /= 10, index--) temp[index] = (int)(left % 10) + '0';
  }
  for (int i = 0; temp[index + 1]; index++, i++) {
    if (sign == 1) {
      buffer[0] = '-';
      i++;
      sign = 0;
    }
    buffer[i] = temp[index + 1];
  }
  use_flags(buffer, flag);
}

// char *s21_strcpy(char *destptr, const char *srcptr) {
//   int srcptrLength = s21_strlen(srcptr);

//   for (int x = 0; x <= srcptrLength; x += 1) {
//     destptr[x] = srcptr[x];
//   }

//   return destptr;
// }