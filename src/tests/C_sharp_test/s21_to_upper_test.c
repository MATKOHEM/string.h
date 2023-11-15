#include "s21_string_tests.h"

START_TEST(to_upper_test_1) {
  char str[] = "Hell0 wor123\0";
  char res[] = "HELL0 WOR123";
  char *test = s21_to_upper(str);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

START_TEST(to_upper_test_2) {
  char str[] = "hell0 world!\n\0";
  char res[] = "HELL0 WORLD!\n";
  char *test = s21_to_upper(str);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

START_TEST(to_upper_test_3) {
  char str[] = "aaaaa\n\0";
  char res[] = "AAAAA\n";
  char *test = s21_to_upper(str);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

START_TEST(to_upper_test_4) {
  char str[] = " \n\0";
  char res[] = " \n";
  char *test = s21_to_upper(str);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

START_TEST(to_upper_test_5) {
  char str[] = " \0";
  char res[] = " ";
  char *test = s21_to_upper(str);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

START_TEST(to_upper_test_6) {
  char str[] = "\n\0";
  char res[] = "\n";
  char *test = s21_to_upper(str);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

START_TEST(to_upper_test_7) {
  char str[] = "\0";
  char res[] = "";
  char *test = s21_to_upper(str);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

START_TEST(to_upper_test_8) {
  char str[] = "";
  char res[] = "";
  char *test = s21_to_upper(str);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

Suite *to_upper_suite(void) {
  Suite *suite = suite_create("[to_upper] suite");
  TCase *to_upper_tcase = tcase_create("[to_upper] case");

  tcase_add_test(to_upper_tcase, to_upper_test_1);
  tcase_add_test(to_upper_tcase, to_upper_test_2);
  tcase_add_test(to_upper_tcase, to_upper_test_3);
  tcase_add_test(to_upper_tcase, to_upper_test_4);
  tcase_add_test(to_upper_tcase, to_upper_test_5);
  tcase_add_test(to_upper_tcase, to_upper_test_6);
  tcase_add_test(to_upper_tcase, to_upper_test_7);
  tcase_add_test(to_upper_tcase, to_upper_test_8);

  suite_add_tcase(suite, to_upper_tcase);
  return suite;
}