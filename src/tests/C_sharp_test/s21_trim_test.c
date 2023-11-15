#include "s21_string_tests.h"

// Функция тестирования какой-либо задачи.
START_TEST(trim_test_1) {
  char s1[30] = "-?hello, world!";
  char s3[] = "!?-";
  char s4[] = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_3) {
  char *s1 = s21_NULL;
  char s3[] = "";
  char *s4 = s21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_4) {
  char s1[30] = "!!!abcdefghij!?!";
  char s3[] = "!?";
  char s4[] = "abcdefghij";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_5) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = "abc";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_6) {
  char s1[30] = "hello, world!";
  char s3[] = "?!";
  char *s4 = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_7) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_8) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_9) {
  char s1[] = " wtf ";
  char *s3 = NULL;
  char *s4 = NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_10) {
  char s1[] = " wtf ";
  char *s3 = "";
  char *s4 = " wtf ";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_11) {
  char s1[50] = "hello world";
  char s3[50] = "dh";
  char s4[50] = "ello worl";
  char *s2 = (char *)(s21_trim(s1, s3));
  ck_assert_str_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_12) {
  char s1[] = "123abc456xyz789";
  char *s3 = "123456789";
  char *s4 = "abc456xyz";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_13) {
  char s1[] = "---abc---xyz----";
  char *s3 = "-";
  char *s4 = "abc---xyz";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_14) {
  char s1[] = "*** Much Ado About Nothing ***";
  char *s3 = "*?/ ";
  char *s4 = "Much Ado About Nothing";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_15) {
  char s1[] = "hello world";
  char *s3 = "dh--";
  char *s4 = "ello worl";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_16) {
  char s1[] = "123abc456xyz789";
  char *s3 = "12345678900000";
  char *s4 = "abc456xyz";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_17) {
  char s1[] = "---abc---xyz----";
  char *s3 = "-?";
  char *s4 = "abc---xyz";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_18) {
  char s1[] = "*** Much Ado About Nothing ***";
  char *s3 = "*_?/ ";
  char *s4 = "Much Ado About Nothing";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_19) {
  char s1[] = "hello world";
  char *s3 = "--";
  char *s4 = "hello world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_20) {
  char s1[] = "123abc456xyz789";
  char *s3 = "0";
  char *s4 = "123abc456xyz789";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(trim_test_21) {
  char s1[] = "";
  char *s3 = "abc";
  char *s4 = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

Suite *trim_suite(void) {
  Suite *suite = suite_create("[trim] suite");
  TCase *trim_tcase = tcase_create("[trim] case");

  tcase_add_test(trim_tcase, trim_test_1);
  tcase_add_test(trim_tcase, trim_test_2);
  tcase_add_test(trim_tcase, trim_test_3);
  tcase_add_test(trim_tcase, trim_test_4);
  tcase_add_test(trim_tcase, trim_test_5);
  tcase_add_test(trim_tcase, trim_test_6);
  tcase_add_test(trim_tcase, trim_test_7);
  tcase_add_test(trim_tcase, trim_test_8);
  tcase_add_test(trim_tcase, trim_test_9);
  tcase_add_test(trim_tcase, trim_test_10);
  tcase_add_test(trim_tcase, trim_test_11);
  tcase_add_test(trim_tcase, trim_test_12);
  tcase_add_test(trim_tcase, trim_test_13);
  tcase_add_test(trim_tcase, trim_test_14);
  tcase_add_test(trim_tcase, trim_test_15);
  tcase_add_test(trim_tcase, trim_test_16);
  tcase_add_test(trim_tcase, trim_test_17);
  tcase_add_test(trim_tcase, trim_test_18);
  tcase_add_test(trim_tcase, trim_test_19);
  tcase_add_test(trim_tcase, trim_test_20);
  tcase_add_test(trim_tcase, trim_test_21);

  suite_add_tcase(suite, trim_tcase);
  return suite;
}