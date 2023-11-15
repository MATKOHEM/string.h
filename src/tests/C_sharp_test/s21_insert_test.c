#include "s21_string_tests.h"

START_TEST(insert_test_1) {
  char s1[] = "Helloworld!\0";
  char s2[] = " ";
  char res[] = "Hello world!";
  char *test = (char *)s21_insert(s1, s2, 5);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

START_TEST(insert_test_2) {
  char s1[] = "Hello world\n\0";
  char s2[] = "!";
  char res[] = "Hello world!\n";
  char *test = (char *)s21_insert(s1, s2, 11);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

START_TEST(insert_test_3) {
  char s1[] = "012789\n\0";
  char s2[] = "3456";
  char res[] = "0123456789\n";
  char *test = (char *)s21_insert(s1, s2, 3);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

START_TEST(insert_test_4) {
  char s1[] = "_insert\0";
  char s2[] = "s21";
  char res[] = "s21_insert";
  char *test = (char *)s21_insert(s1, s2, 0);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

START_TEST(insert_test_5) {
  char s1[] = " \0";
  char s2[] = "!!!";
  char *res = " !!!";
  char *test = (char *)s21_insert(s1, s2, 1);
  ck_assert_str_eq(test, res);
  if (test) free(test);
}
END_TEST

Suite *insert_suite(void) {
  Suite *suite = suite_create("[insert] suite");
  TCase *insert_tcase = tcase_create("[insert] case");

  tcase_add_test(insert_tcase, insert_test_1);
  tcase_add_test(insert_tcase, insert_test_2);
  tcase_add_test(insert_tcase, insert_test_3);
  tcase_add_test(insert_tcase, insert_test_4);
  tcase_add_test(insert_tcase, insert_test_5);

  suite_add_tcase(suite, insert_tcase);
  return suite;
}