#include "s21_string_tests.h"

START_TEST(to_lower_test_1) {
  char str[] = "HELL0 WOR123\0";
  char res[] = "hell0 wor123";
  char *test = s21_to_lower(str);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

START_TEST(to_lower_test_2) {
  char str[] = "HELL0 WORLD!\n\0";
  char res[] = "hell0 world!\n";
  char *test = s21_to_lower(str);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

START_TEST(to_lower_test_3) {
  char str[] = "AAA\n\0";
  char res[] = "aaa\n";
  char *test = s21_to_lower(str);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

START_TEST(to_lower_test_4) {
  char str[] = " \n\0";
  char res[] = " \n";
  char *test = s21_to_lower(str);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

START_TEST(to_lower_test_5) {
  char str[] = " \0";
  char res[] = " ";
  char *test = s21_to_lower(str);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

START_TEST(to_lower_test_6) {
  char str[] = "\n\0";
  char res[] = "\n";
  char *test = s21_to_lower(str);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

START_TEST(to_lower_test_7) {
  char str[] = "\0";
  char res[] = "";
  char *test = s21_to_lower(str);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

START_TEST(to_lower_test_8) {
  char str[] = "";
  char res[] = "";
  char *test = s21_to_lower(str);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

Suite *to_lower_suite(void) {
  Suite *suite = suite_create("[to_lower] suite");
  TCase *to_lower_tcase = tcase_create("[to_lower] case");

  tcase_add_test(to_lower_tcase, to_lower_test_1);
  tcase_add_test(to_lower_tcase, to_lower_test_2);
  tcase_add_test(to_lower_tcase, to_lower_test_3);
  tcase_add_test(to_lower_tcase, to_lower_test_4);
  tcase_add_test(to_lower_tcase, to_lower_test_5);
  tcase_add_test(to_lower_tcase, to_lower_test_6);
  tcase_add_test(to_lower_tcase, to_lower_test_7);
  tcase_add_test(to_lower_tcase, to_lower_test_8);

  suite_add_tcase(suite, to_lower_tcase);
  return suite;
}