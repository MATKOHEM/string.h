#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../../s21_sscanf.h"

START_TEST(one_sscanf) {
  char *str = "1";
  char *format = "%d";
  int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(two_sscanf) {
  char *str = "-1";
  char *format = "%d";
  int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST
START_TEST(tree_sscanf) {
  char *str = "12345";
  char *format = "%4d";
  int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST
START_TEST(fore_sscanf) {
  char *str = "-12345";
  char *format = "%4d";
  int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST
START_TEST(five_sscanf) {
  char *str = "123";
  char *format = "%hd";
  short int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST
START_TEST(six_sscanf) {
  char *str = "123";
  char *format = "%hhd";
  signed char d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(seven_sscanf) {
  char *str = "123";
  char *format = "%lld";
  long long int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  // printf("\ns21_sscanf %lld \n", d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(eight_sscanf) {
  char *str = "123";
  char *format = "%ld";
  long int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(symbol_sscanf) {
  char *str = "c s";
  char *format = "%c";
  char symbol1, symbol2;

  int result1 = sscanf(str, format, &symbol1);
  int result2 = s21_sscanf(str, format, &symbol2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(symbol1, symbol2);

  format = "%*c %c";
  result1 = sscanf(str, format, &symbol1);
  result2 = s21_sscanf(str, format, &symbol2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(symbol1, symbol2);

  format = "%lc";
  wchar_t lsymbol1, lsymbol2;
  result1 = sscanf(str, format, &lsymbol1);
  result2 = s21_sscanf(str, format, &lsymbol2);
  ck_assert_int_eq(result1, result2);
  symbol1 = (char)lsymbol1;
  symbol2 = (char)lsymbol2;
  ck_assert_int_eq(symbol1, symbol2);
}
END_TEST

START_TEST(n_sscanf) {
  char *str = "nnn";
  char *format = "%n";
  int symbol1 = 0;
  int symbol2 = 0;

  int result1 = sscanf(str, format, &symbol1);
  int result2 = s21_sscanf(str, format, &symbol2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(symbol1, symbol2);

  format = "%*n";
  result1 = sscanf(str, format, &symbol1);
  result2 = s21_sscanf(str, format, &symbol2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(symbol1, symbol2);
}
END_TEST

START_TEST(proc_sscanf) {
  char *str = "%";
  char *format = "%%";
  char symbol1, symbol2;

  int result1 = sscanf(str, format, &symbol1);
  int result2 = s21_sscanf(str, format, &symbol2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(symbol1, symbol2);

  format = "%*%";
  result1 = sscanf(str, format, &symbol1);
  result2 = s21_sscanf(str, format, &symbol2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(symbol1, symbol2);
}
END_TEST

START_TEST(f_one_sscanf) {
  char *str = "1.2";
  char *format = "%f";
  float d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(f_two_sscanf) {
  char *str = "-1.23";
  char *format = "%f";
  int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(f_tree_sscanf) {
  char *str = "12345";
  char *format = "%4f";
  float d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(f_fore_sscanf) {
  char *str = "-12345.6789";
  char *format = "%4f";
  float d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(f_five_sscanf) {
  char *str = "1.0";  // ??????????
  char *format = "%Lf";
  long double d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_ldouble_eq(d1, d2);
}
END_TEST

START_TEST(f_six_sscanf) {
  char *str = "-12345.0000";
  char *format = "%4f";
  float d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(f_seven_sscanf) {
  char *str = "1.345e-05";
  char *format = "%7f";
  float d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(f_eight_sscanf) {
  char *str = "1.345e-05";
  char *format = "%f";
  float d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(f_nine_sscanf) {
  char *str = "1.345e+05";
  char *format = "%f";
  float d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(f_ten_sscanf) {
  char *str = "1.345e+05";
  char *format = "%Lf";
  long double d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_float_eq_tol(d1, d2, 0.0001);
}
END_TEST

START_TEST(o_one_sscanf) {
  char *str = "12";
  char *format = "%o";
  int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(o_two_sscanf) {
  char *str = "14";
  char *format = "%o";
  int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(o_tree_sscanf) {
  char *str = "12345";
  char *format = "%4o";
  int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(o_fore_sscanf) {
  char *str = "-12345";
  char *format = "%4o";
  int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}

START_TEST(o_five_sscanf) {
  char *str = "123";
  char *format = "%ho";
  short int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);

  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(o_six_sscanf) {
  char *str = "123";
  char *format = "%hho";
  signed char d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(o_seven_sscanf) {
  char *str = "123453456555555";
  char *format = "%llo";
  long long int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  // printf("\ns21_sscanf %lld \n", d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(o_eight_sscanf) {
  char *str = "123444444";
  char *format = "%lo";
  long int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(x_one_sscanf) {
  char *str = "12aAb";
  char *format = "%x";
  int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(x_two_sscanf) {
  char *str = "14";
  char *format = "%X";
  int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(x_tree_sscanf) {
  char *str = "12345";
  char *format = "%hx";
  short int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(x_fore_sscanf) {
  char *str = "123";
  char *format = "%hhx";
  signed char d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}

START_TEST(x_five_sscanf) {
  char *str = "12345";
  char *format = "%lX";
  long int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(x_six_sscanf) {
  char *str = "123adf3";
  char *format = "%llx";
  long long int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(x_seven_sscanf) {
  char *str = "123453456555555";
  char *format = "%6llx";
  long long int d1, d2;
  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(u_sscanf) {
  char *str = "1";
  char *format = "%u";
  unsigned int d1, d2;

  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(d1, d2);

  short unsigned int sd1, sd2;
  format = "%hu";
  result1 = sscanf(str, format, &sd1);
  result2 = s21_sscanf(str, format, &sd2);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(sd1, sd2);

  long unsigned int ld1, ld2;
  format = "%lu";
  result1 = sscanf(str, format, &ld1);
  result2 = s21_sscanf(str, format, &ld2);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(ld1, ld2);

  format = "%*lu";
  result1 = sscanf(str, format, &ld1);
  result2 = s21_sscanf(str, format, &ld2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(ld1, ld2);
}
END_TEST

START_TEST(hh_sscanf) {
  char *str = "122";
  char *format = "%hhu";
  unsigned char d1, d2;

  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(d1, d2);

  unsigned short int sd1, sd2;
  format = "%hu";
  result1 = sscanf(str, format, &sd1);
  result2 = s21_sscanf(str, format, &sd2);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(sd1, sd2);
}
END_TEST

START_TEST(ll_sscanf) {
  char *str = "12224352345234324";
  char *format = "%llu";
  unsigned long long int d1, d2;

  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(nu_sscanf) {
  char *str = "12224352345234324";
  char *format = "%10llu";
  unsigned long long int d1, d2;

  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(i_sscanf) {
  char *str = "01111";
  char *format = "%i";
  unsigned int d1, d2;

  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(ix_sscanf) {
  char *str = "0X1111";
  char *format = "%i";
  unsigned int d1, d2;

  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(id_sscanf) {
  char *str = "-1111";
  char *format = "%i";
  int d1, d2;

  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(id_minus_sscanf) {
  char *str = "-1111";
  char *format = "%4i";
  int d1, d2;

  int result1 = sscanf(str, format, &d1);
  int result2 = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(p_sscanf) {
  char str[20] = "0x123456a";

  char *format = "%p";
  void *p1, *p2;

  int result1 = sscanf(str, format, &p1);
  int result2 = s21_sscanf(str, format, &p2);
  ck_assert_int_eq(result1, result2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(pn_sscanf) {
  char str[] = "0x123456a";

  char *format = "%3p";
  void *p1, *p2;

  int result1 = sscanf(str, format, &p1);
  int result2 = s21_sscanf(str, format, &p2);
  ck_assert_int_eq(result1, result2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(string_sscanf) {
  char *str = "school_21 school_21";
  char *format = "%s%s";
  char str1[30], str2[30];

  int result1 = sscanf(str, format, str1, str2);
  int result2 = s21_sscanf(str, format, str1, str2);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(str1, str2);

  format = "%*s";
  result1 = sscanf(str, format, str1);
  result2 = s21_sscanf(str, format, str2);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(str1, str2);

  format = "%3s";
  result1 = sscanf(str, format, str1);
  result2 = s21_sscanf(str, format, str2);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(dot_sscanf) {
  char *str = "1; 1";
  char *format = "%d;%d";
  int d1, d2;
  int result1 = sscanf(str, format, &d1, &d2);
  int result2 = s21_sscanf(str, format, &d1, &d2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(dot_2_sscanf) {
  char *str = "1, 1";
  char *format = "%d;%d";
  int d1, d2;
  int result1 = sscanf(str, format, &d1, &d2);
  int result2 = s21_sscanf(str, format, &d1, &d2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

Suite *s21_sscanf_suite(void) {
  Suite *s;
  TCase *one_test, *two_test, *tree_test, *fore_test, *five_test, *six_test,
      *p_test, *s_test, *dot_test, *seven_test;

  s = suite_create("s21_sscanf");

  one_test = tcase_create("One test");  // %d
  tcase_add_test(one_test, one_sscanf);
  tcase_add_test(one_test, two_sscanf);
  tcase_add_test(one_test, tree_sscanf);
  tcase_add_test(one_test, fore_sscanf);
  tcase_add_test(one_test, five_sscanf);
  tcase_add_test(one_test, six_sscanf);
  tcase_add_test(one_test, seven_sscanf);
  tcase_add_test(one_test, eight_sscanf);
  tcase_add_test(one_test, symbol_sscanf);
  tcase_add_test(one_test, n_sscanf);
  tcase_add_test(one_test, proc_sscanf);
  suite_add_tcase(s, one_test);

  two_test = tcase_create("float One test");  // %f
  tcase_add_test(one_test, f_one_sscanf);
  tcase_add_test(one_test, f_two_sscanf);
  tcase_add_test(one_test, f_tree_sscanf);
  tcase_add_test(one_test, f_fore_sscanf);
  tcase_add_test(one_test, f_five_sscanf);
  tcase_add_test(one_test, f_six_sscanf);
  tcase_add_test(one_test, f_seven_sscanf);
  tcase_add_test(one_test, f_eight_sscanf);
  tcase_add_test(one_test, f_nine_sscanf);
  tcase_add_test(one_test, f_ten_sscanf);
  suite_add_tcase(s, two_test);

  tree_test = tcase_create("eight One test");  // %o
  tcase_add_test(one_test, o_one_sscanf);
  tcase_add_test(one_test, o_two_sscanf);
  tcase_add_test(one_test, o_tree_sscanf);
  tcase_add_test(one_test, o_fore_sscanf);
  tcase_add_test(one_test, o_five_sscanf);
  tcase_add_test(one_test, o_six_sscanf);
  tcase_add_test(one_test, o_seven_sscanf);
  tcase_add_test(one_test, o_eight_sscanf);
  suite_add_tcase(s, tree_test);

  fore_test = tcase_create("sixteen fore test");
  tcase_add_test(one_test, x_one_sscanf);
  tcase_add_test(one_test, x_two_sscanf);
  tcase_add_test(one_test, x_tree_sscanf);
  tcase_add_test(one_test, x_fore_sscanf);
  tcase_add_test(one_test, x_five_sscanf);
  tcase_add_test(one_test, x_six_sscanf);
  tcase_add_test(one_test, x_seven_sscanf);
  suite_add_tcase(s, fore_test);

  five_test = tcase_create("unsigned fore test");
  tcase_add_test(one_test, u_sscanf);
  tcase_add_test(one_test, hh_sscanf);
  tcase_add_test(one_test, ll_sscanf);
  tcase_add_test(one_test, nu_sscanf);
  suite_add_tcase(s, five_test);

  six_test = tcase_create("i fore test");
  tcase_add_test(one_test, i_sscanf);
  tcase_add_test(one_test, ix_sscanf);
  tcase_add_test(one_test, id_sscanf);
  tcase_add_test(one_test, id_minus_sscanf);
  suite_add_tcase(s, six_test);

  p_test = tcase_create("n fore test");
  tcase_add_test(one_test, p_sscanf);
  tcase_add_test(one_test, pn_sscanf);
  suite_add_tcase(s, p_test);

  s_test = tcase_create("s string test");
  tcase_add_test(one_test, string_sscanf);
  suite_add_tcase(s, s_test);

  dot_test = tcase_create("; : test");
  tcase_add_test(one_test, dot_sscanf);
  tcase_add_test(one_test, dot_2_sscanf);

  suite_add_tcase(s, dot_test);

  return s;
}

int main(void) {
  Suite *suite = s21_sscanf_suite();
  SRunner *suite_runner = srunner_create(suite);

  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
