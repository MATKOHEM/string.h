#include "s21_error.h"
#include "s21_string.h"

char* s21_strerror(int errnum) {
  /*
  Функция strerror формирует описание ошибки по коду ошибки указанному в
  аргументе errcode и возвращает указатель на строку, содержащую сформированное
  описание ошибки. Ошибки в хедере - s21_error.h

  Возвращает - Указатель на строку, содержащую описание ошибки, код которой
  указан в аргументе errcode.
  */
  if (errnum >= ERR_FIRST && errnum <= ERR_LAST) {
    const char* err_array[] = s21_error;
    return (char*)err_array[errnum];
  } else {
    char* p = (char*)calloc(100, sizeof(char));
    if (p) s21_sprintf(p, "%s %d", s21_string, errnum);
    return p;
  }
}
