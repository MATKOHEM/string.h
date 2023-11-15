#ifndef TEST_H_
#define TEST_H_

#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

Suite *s21_memchr_test();
Suite *s21_memcmp_test();
Suite *s21_memcpy_test();
Suite *s21_memset_test();
Suite *s21_strncat_test();
Suite *s21_strchr_test();
Suite *s21_strncmp_test();
Suite *s21_strncpy_test();
Suite *s21_strcspn_test();
Suite *s21_strlen_test();
Suite *s21_strerror_test();
Suite *s21_strpbrk_test();
Suite *s21_strrchr_test();
Suite *s21_strstr_test();
Suite *s21_strtok_test();

#endif
