#ifndef TESTS_H
#define TESTS_H

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_string.h"

Suite *to_upper_suite(void);
Suite *to_lower_suite(void);
Suite *insert_suite(void);
Suite *trim_suite(void);
#endif