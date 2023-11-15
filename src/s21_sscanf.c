#include "s21_sscanf.h"

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int num_match = 0;
  struct specifier conditions = {0};

  while (*format) {
    if (*format == '%') {
      format++;
      int width_check = check_width(format, &conditions);
      if (width_check > 0) {
        format = format + width_check;
      }
      if (check_length(format, &conditions) == 1) {
        format++;
      }
      num_match += define_specifier(format, &str, &args, &conditions);
    } else if (*format == *str) {
      str++;
      conditions.count_characters++;
      while (is_space(*str)) {
        str++;
        conditions.count_characters++;
      }
    } else if (invisible_characters(*str)) {
      str++;
      conditions.count_characters++;
      str = check_space(str, &conditions);
      continue;
    } else if (is_space(*format)) {
      format++;
      continue;
    } else {
      break;
    }

    reset_conditions(&conditions);
    format++;
  }

  va_end(args);
  return num_match;
}

int define_specifier(const char *format, const char **str, va_list *args,
                     struct specifier *conditions) {
  int num_match = 0;
  if (!conditions->break_function) {
    switch (*format) {
      case 'u':
        conditions->unsigned_number = true;
        num_match = process_int(str, args, conditions);
        break;

      case 'i':
        num_match = process_int(str, args, conditions);
        break;
      case 'd':
        conditions->decimal_number = true;
        num_match = process_int(str, args, conditions);
        break;
      case 'e':
      case 'E':
      case 'g':
      case 'G':
      case 'f': {
        num_match = process_float(str, args, conditions);
        break;
      }
      case 'c':
        num_match = process_char(str, args, conditions);
        break;
      case 's':
        num_match = process_string(str, args, conditions);
        break;
      case 'o':
        conditions->unsigned_number = true;
        conditions->octal_number = true;
        num_match = process_int(str, args, conditions);
        break;
      case 'x':
      case 'X':
        conditions->unsigned_number = true;
        conditions->hexadecimal_number = true;
        num_match = process_int(str, args, conditions);
        break;
      case 'p':
        num_match = process_pointer(str, args, conditions);
        break;
      case 'n':
        process_counter(args, conditions);
        break;
      case '%':
        (*str)++;
        conditions->count_characters++;
        break;
      default:
        break;
    }
  }

  return num_match;
}

int process_int(const char **str, va_list *args, struct specifier *conditions) {
  int num_match = 0;

  if (conditions->ignore) {
    // если встретилась *
    long *value = malloc(sizeof(long));
    if (value != NULL) {
      *str = sscanf_int(*str, value, conditions);
      free(value);
    }
  } else if (conditions->short_int) {
    // короткое целое
    short *value = va_arg(*args, short *);
    long temp;
    *str = sscanf_int(*str, &temp, conditions);
    *value = (short)temp;
    if (conditions->num_match) num_match++;
  } else if (conditions->long_int) {
    // длинное целое
    long *value = va_arg(*args, long *);
    *str = sscanf_int(*str, value, conditions);
    if (conditions->num_match) num_match++;
  } else {
    // просто целое
    int *value = va_arg(*args, int *);
    long temp;
    *str = sscanf_int(*str, &temp, conditions);
    *value = (int)temp;
    if (conditions->num_match) num_match++;
  }

  return num_match;
}

int process_float(const char **str, va_list *args,
                  struct specifier *conditions) {
  int num_match = 0;
  if (conditions->ignore) {
    long double *value = malloc(sizeof(long double));
    *str = sscanf_float(*str, value, conditions);
    free(value);
  } else if (conditions->long_double) {
    long double *value = va_arg(*args, long double *);
    *str = sscanf_float(*str, value, conditions);
    if (conditions->num_match) num_match++;
  } else {
    float *value = va_arg(*args, float *);
    long double temp;
    *str = sscanf_float(*str, &temp, conditions);
    *value = (float)temp;
    if (conditions->num_match) num_match++;
  }
  return num_match;
}

int process_char(const char **str, va_list *args,
                 struct specifier *conditions) {
  int num_match = 0;
  if (!conditions->ignore) {
    char *value = va_arg(*args, char *);
    *str = sscanf_char(*str, value, conditions);
    if (conditions->num_match) num_match++;
  } else {
    char *value = malloc(sizeof(char));
    *str = sscanf_char(*str, value, conditions);
    free(value);
  }
  return num_match;
}

int process_string(const char **str, va_list *args,
                   struct specifier *conditions) {
  int num_match = 0;
  if (!conditions->ignore) {
    char *value = va_arg(*args, char *);
    *str = sscanf_str(*str, value, conditions);
    if (conditions->num_match) num_match++;
  } else {
    char value[BUFF_SIZE];
    *str = sscanf_str(*str, value, conditions);
  }
  return num_match;
}

int process_pointer(const char **str, va_list *args,
                    struct specifier *conditions) {
  int num_match = 0;
  if (!conditions->ignore) {
    void *value = va_arg(*args, void *);
    *str = sscanf_ptr(*str, value, conditions);
    if (conditions->num_match) num_match++;
  } else {
    unsigned long *value = malloc(sizeof(unsigned long));
    *str = sscanf_ptr(*str, value, conditions);
    free(value);
  }
  return num_match;
}

void process_counter(va_list *args, struct specifier *conditions) {
  if (!conditions->ignore) {
    int *value = va_arg(*args, int *);
    *value = conditions->count_characters;
  }
}

int is_digit(char c) { return (c >= '0' && c <= '9'); }

int is_hexadecimal(char c) {
  return (is_digit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

int is_space(char c) { return c == ' '; }

int is_octal(char c) { return c >= '0' && c < '8'; }

int invisible_characters(char c) { return c == '\t' || c == '\n' || c == ' '; }

int check_sign(const char *str, struct specifier *conditions) {
  int sign = 1;

  if (conditions->unsigned_number != true) {
    if (*str == '-') {
      sign = -1;
    }
  }
  if (sign != 1 || *str == '+') {
    conditions->count_characters++;
  }

  return sign;
}

const char *check_space(const char *str, struct specifier *conditions) {
  while ((is_space(*str) || invisible_characters(*str)) && *str != '\0') {
    str++;
    conditions->count_characters++;
  }
  return str;
}

const char *parse_hexadecimal(const char *str, long *result, int *flag,
                              struct specifier *conditions) {
  int count = 0;
  while (is_hexadecimal(*str) && count < conditions->width) {
    *result = *result * 16;
    if (is_digit(*str)) {
      *result += *str - '0';
    } else if (*str >= 'A' && *str <= 'F') {
      *result += *str - 'A' + 10;
    } else if (*str >= 'a' && *str <= 'f') {
      *result += *str - 'a' + 10;
    }
    str++;
    count++;
    *flag = 1;
  }
  conditions->count_characters += count;
  return str;
}

const char *parse_octal(const char *str, long *result, int *flag,
                        struct specifier *conditions) {
  int count = 0;
  while (is_octal(*str) && count < conditions->width &&
         !conditions->decimal_number) {
    *result = *result * 8 + (*str - '0');
    str++;
    count++;
    *flag = 1;
  }
  conditions->count_characters += count;
  return str;
}

const char *parse_digit(const char *str, long *result, int *flag,
                        struct specifier *conditions) {
  int count = 0;
  while (is_digit(*str) && count < conditions->width) {
    *result = *result * 10 + (*str - '0');
    str++;
    count++;
    *flag = 1;
  }
  conditions->width -= count;
  conditions->count_characters += count;
  return str;
}

const char *sscanf_int(const char *str, long *value,
                       struct specifier *conditions) {
  int count = 0;
  int flag = 0;
  long result = 0;
  int sign = 1;
  conditions->width = conditions->width > 0 ? conditions->width : 100;

  str = check_space(str, conditions);

  if ((sign = check_sign(str, conditions)) != 1 || *str == '+') {
    str++;
    conditions->width--;
  }

  while (*str != '\0' && *str != ' ' && count < conditions->width &&
         !conditions->break_function) {
    if (*str == '0' && !conditions->octal_number) {
      str++;
      count++;
      flag = 1;

      if (*str == 'x' || *str == 'X') {
        // 16
        str++;
        count++;
        conditions->width -= count;
        str = parse_hexadecimal(str, &result, &flag, conditions);

      } else {
        // 8
        conditions->width -= count;
        str = parse_octal(str, &result, &flag, conditions);
        str = parse_digit(str, &result, &flag, conditions);
      }
      break;
    } else if (conditions->hexadecimal_number && is_hexadecimal(*str)) {
      conditions->width -= count;
      str = parse_hexadecimal(str, &result, &flag, conditions);
      break;
    } else if (conditions->octal_number && is_octal(*str)) {
      conditions->width -= count;
      str = parse_octal(str, &result, &flag, conditions);
      break;
    } else {
      if (is_digit(*str) && !conditions->octal_number &&
          !conditions->hexadecimal_number) {
        conditions->width -= count;
        str = parse_digit(str, &result, &flag, conditions);
        break;
      } else {
        str++;
        break;
      }
    }
  }

  if (check_flag(&flag, conditions) == 1) {
    *value = sign * result;
    conditions->count_characters += count;
  }

  return str;
}

const char *sscanf_char(const char *str, char *value,
                        struct specifier *conditions) {
  if (*str != '\0') {
    conditions->num_match = true;
  }

  *value = *str;
  str++;
  conditions->count_characters++;
  if ((--conditions->width > 0)) {
    while (*str != '\0' && conditions->width > 0) {
      str++;
      conditions->count_characters++;
      conditions->width--;
    }
  }

  return str;
}

const char *sscanf_str(const char *str, char *value,
                       struct specifier *conditions) {
  if (*str == '\0') {
    conditions->count_characters = 0;
  }

  int i = 0;
  if (conditions->width > 0) {
    while (*str && *str != ' ' && conditions->width > 0) {
      value[i] = *str++;
      conditions->count_characters++;
      conditions->num_match = true;
      conditions->width--;
      i++;
    }
  } else {
    while (*str && !invisible_characters(*str)) {
      value[i] = *str++;
      conditions->count_characters++;
      i++;
      conditions->num_match = true;
    }
  }

  value[i] = '\0';
  return str;
}

const char *sscanf_ptr(const char *str, unsigned long *value,
                       struct specifier *conditions) {
  unsigned long result = 0;
  int count = 0;
  int flag = 0;
  conditions->width = conditions->width > 0 ? conditions->width : BUFF_SIZE;

  str = check_space(str, conditions);

  while (*str != '\0' && *str != ' ' && count < conditions->width) {
    if (*str == '0') {
      str++;
      count++;
      if (*str == 'x' || *str == 'X') {
        str++;
        count++;
      }
    } else if (is_hexadecimal(*str)) {
      conditions->width -= count;
      long temp = 0;
      str = parse_hexadecimal(str, &temp, &flag, conditions);
      result = (unsigned long)temp;
    } else {
      break;
    }
  }

  if (check_flag(&flag, conditions) == 1) {
    *value = result;
    conditions->count_characters += count;
  }

  return str;
}

const char *sscanf_float(const char *str, long double *value,
                         struct specifier *conditions) {
  int flag = 0;
  int count = 0;
  conditions->width = conditions->width > 0 ? conditions->width : BUFF_SIZE;
  int sign = 1;
  long double result = 0;

  str = check_space(str, conditions);

  if ((sign = check_sign(str, conditions)) != 1 || *str == '+') {
    str++;
    conditions->width--;
  }

  if (count < conditions->width && is_digit(*str) &&
      !conditions->break_function) {
    conditions->width -= count;
    long temp = 0;
    str = parse_digit(str, &temp, &flag, conditions);
    result = (long double)temp;

    if (count < conditions->width && *str == '.') {
      str++;
      count++;
      flag = 1;

      double fraction_divisor = 1.0;
      while (count < conditions->width && is_digit(*str) && *str != '\0') {
        result = result * 10 + (*str - '0');
        fraction_divisor *= 10;
        str++;
        count++;
      }

      result /= fraction_divisor;
    }

    if (count < conditions->width && (*str == 'e' || *str == 'E')) {
      str++;
      count++;

      int exponent_sign = 1;
      if (count < conditions->width && (*str == '-' || *str == '+')) {
        exponent_sign = *str == '-' ? -1 : 1;
        str++;
        count++;
      }

      int exponent = 0;
      while (count < conditions->width && is_digit(*str)) {
        exponent = exponent * 10 + (*str - '0');
        str++;
        count++;
      }
      double exponent_value = 1.0;
      for (int i = 0; i < exponent; i++) {
        exponent_value *= 10.0;
      }

      if (exponent_sign == -1) {
        result /= exponent_value;
      } else {
        result *= exponent_value;
      }
    }
  }

  if (check_flag(&flag, conditions) == 1) {
    *value = sign * result;
    conditions->count_characters += count;
  }

  return str;
}

// функция проверяет было ли прочитано нормальное значение
int check_flag(int *flag, struct specifier *conditions) {
  int check = 0;
  if (*flag) {
    conditions->num_match = true;
    conditions->break_function = false;
    check = 1;
  } else {
    conditions->break_function = true;
    conditions->count_characters = 0;
    check = 0;
  }

  return check;
}

void reset_conditions(struct specifier *conditions) {
  conditions->unsigned_number = false;
  conditions->octal_number = false;
  conditions->hexadecimal_number = false;
  conditions->decimal_number = false;
  conditions->num_match = false;
  conditions->width = 0;
  conditions->ignore = false;
  conditions->short_int = false;
  conditions->long_int = false;
  conditions->long_double = false;
}

int check_width(const char *format, struct specifier *conditions) {
  int check = 0;
  if (*format >= '0' && *format <= '9') {
    while ((*format) >= '0' && (*format) <= '9') {
      conditions->width = conditions->width * 10 + (*format) - '0';
      format++;
      check++;
    }
  } else if (*format == '*') {
    conditions->ignore = true;
    check++;
  }
  return check;
}

int check_length(const char *format, struct specifier *conditions) {
  int check = 1;
  switch (*format) {
    case 'h':
      conditions->short_int = true;
      break;
    case 'l':
      conditions->long_int = true;
      break;
    case 'L':
      conditions->long_double = true;
      break;
    default:
      check = 0;
      break;
  }
  return check;
}
