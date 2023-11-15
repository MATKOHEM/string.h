#include "C_sharp_test/s21_string_tests.h"
#include "other_test/tests.h"
// #include "sprintf_test/test.c"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_sprintf.h"
#include "../s21_string.h"

// Suite *s21_sscanf_suit(void);
// #include "sscanf_test/test.c"
// #include "sscanf_test/test1.c"

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

// START_TEST(six_sscanf) {
//   char *str = "123";
//   char *format = "%hhd";
//   signed char d1, d2;
//   int result1 = sscanf(str, format, &d1);
//   int result2 = s21_sscanf(str, format, &d2);
//   ck_assert_int_eq(result1, result2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(seven_sscanf) {
//   char *str = "123";
//   char *format = "%lld";
//   long long int d1, d2;
//   int result1 = sscanf(str, format, &d1);
//   int result2 = s21_sscanf(str, format, &d2);
//   // printf("\ns21_sscanf %lld \n", d2);
//   ck_assert_int_eq(result1, result2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

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

//   float

//> БЕКМУРАТ :
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

//  o   eight

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

// START_TEST(o_fore_sscanf) {
//   char *str = "-12345";
//   char *format = "%4o";
//   int d1, d2;
//   int result1 = sscanf(str, format, &d1);
//   int result2 = s21_sscanf(str, format, &d2);
//   ck_assert_int_eq(result1, result2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

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

// START_TEST(o_six_sscanf) {
//   char *str = "123";
//   char *format = "%hho";
//   signed char d1, d2;
//   int result1 = sscanf(str, format, &d1);
//   int result2 = s21_sscanf(str, format, &d2);
//   ck_assert_int_eq(result1, result2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(o_seven_sscanf) {
//   char *str = "123453456555555";
//   char *format = "%llo";
//   long long int d1, d2;
//   int result1 = sscanf(str, format, &d1);
//   int result2 = s21_sscanf(str, format, &d2);
//   // printf("\ns21_sscanf %lld \n", d2);
//   ck_assert_int_eq(result1, result2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

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

// test xxxxxxxx

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

// START_TEST(x_fore_sscanf) {
//   char *str = "123";
//   char *format = "%hhx";
//   signed char d1, d2;
//   int result1 = sscanf(str, format, &d1);
//   int result2 = s21_sscanf(str, format, &d2);
//   ck_assert_int_eq(result1, result2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

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

// START_TEST(x_six_sscanf) {
//   char *str = "123adf3";
//   char *format = "%llx";
//   long long int d1, d2;
//   int result1 = sscanf(str, format, &d1);
//   int result2 = s21_sscanf(str, format, &d2);
//   ck_assert_int_eq(result1, result2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// START_TEST(x_seven_sscanf) {
//   char *str = "123453456555555";
//   char *format = "%6llx";
//   long long int d1, d2;
//   int result1 = sscanf(str, format, &d1);
//   int result2 = s21_sscanf(str, format, &d2);
//   // printf("\ns21_sscanf %lld \n", d2);
//   ck_assert_int_eq(result1, result2);
//   ck_assert_int_eq(d1, d2);
// }
// END_TEST

// u test
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

// START_TEST(hh_sscanf) {
//   char *str = "122";
//   char *format = "%hhu";
//   unsigned char d1, d2;

//   int result1 = sscanf(str, format, &d1);
//   int result2 = s21_sscanf(str, format, &d2);
//   ck_assert_int_eq(result1, result2);
//   ck_assert_uint_eq(d1, d2);

//   unsigned short int sd1, sd2;
//   format = "%hu";
//   result1 = sscanf(str, format, &sd1);
//   result2 = s21_sscanf(str, format, &sd2);
//   ck_assert_int_eq(result1, result2);
//   ck_assert_uint_eq(sd1, sd2);
// }
// END_TEST

// START_TEST(ll_sscanf) {
//   char *str = "12224352345234324";
//   char *format = "%llu";
//   unsigned long long int d1, d2;

//   int result1 = sscanf(str, format, &d1);
//   int result2 = s21_sscanf(str, format, &d2);
//   ck_assert_int_eq(result1, result2);
//   ck_assert_uint_eq(d1, d2);
// }
// END_TEST

// START_TEST(nu_sscanf) {
//   char *str = "12224352345234324";
//   char *format = "%10llu";
//   unsigned long long int d1, d2;

//   int result1 = sscanf(str, format, &d1);
//   int result2 = s21_sscanf(str, format, &d2);
//   ck_assert_int_eq(result1, result2);
//   ck_assert_uint_eq(d1, d2);
// }
// END_TEST

//  i test
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

// p test

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

// s test
// START_TEST(string_sscanf) {
//   char *str = "school_21 school_21";
//   char *format = "%s%s";
//   char str1[30], str2[30];

//   int result1 = sscanf(str, format, str1, str2);
//   int result2 = s21_sscanf(str, format, str1, str2);
//   ck_assert_int_eq(result1, result2);
//   ck_assert_str_eq(str1, str2);

//   format = "%*s";
//   result1 = sscanf(str, format, str1);
//   result2 = s21_sscanf(str, format, str2);
//   ck_assert_int_eq(result1, result2);
//   ck_assert_str_eq(str1, str2);

//   format = "%3s";
//   result1 = sscanf(str, format, str1);
//   result2 = s21_sscanf(str, format, str2);
//   ck_assert_int_eq(result1, result2);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

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

// Suite *s21_sscanf_suit(void) {
//   Suite *s;
//   TCase *one_test, *two_test, *tree_test, *fore_test, *five_test, *six_test,
//       *p_test, *s_test, *dot_test;

//   s = suite_create("s21_sscanf");

//   one_test = tcase_create("One test");  // %d
//   tcase_add_test(one_test, one_sscanf);
//   tcase_add_test(one_test, two_sscanf);
//   tcase_add_test(one_test, tree_sscanf);
//   tcase_add_test(one_test, fore_sscanf);
//   tcase_add_test(one_test, five_sscanf);
//   tcase_add_test(one_test, six_sscanf);
//   tcase_add_test(one_test, seven_sscanf);
//   tcase_add_test(one_test, eight_sscanf);
//   tcase_add_test(one_test, symbol_sscanf);
//   tcase_add_test(one_test, n_sscanf);
//   tcase_add_test(one_test, proc_sscanf);
//   suite_add_tcase(s, one_test);

//   two_test = tcase_create("float One test");  // %f
//   tcase_add_test(one_test, f_one_sscanf);
//   tcase_add_test(one_test, f_two_sscanf);
//   tcase_add_test(one_test, f_tree_sscanf);
//   tcase_add_test(one_test, f_fore_sscanf);
//   tcase_add_test(one_test, f_five_sscanf);
//   tcase_add_test(one_test, f_six_sscanf);
//   tcase_add_test(one_test, f_seven_sscanf);
//   tcase_add_test(one_test, f_eight_sscanf);
//   tcase_add_test(one_test, f_nine_sscanf);
//   tcase_add_test(one_test, f_ten_sscanf);
//   suite_add_tcase(s, two_test);

//   tree_test = tcase_create("eight One test");  // %o
//   tcase_add_test(one_test, o_one_sscanf);
//   tcase_add_test(one_test, o_two_sscanf);
//   tcase_add_test(one_test, o_tree_sscanf);
//   tcase_add_test(one_test, o_fore_sscanf);
//   tcase_add_test(one_test, o_five_sscanf);
//   tcase_add_test(one_test, o_six_sscanf);
//   tcase_add_test(one_test, o_seven_sscanf);
//   tcase_add_test(one_test, o_eight_sscanf);
//   suite_add_tcase(s, tree_test);

//   fore_test = tcase_create("sixteen fore test");
//   tcase_add_test(one_test, x_one_sscanf);
//   tcase_add_test(one_test, x_two_sscanf);
//   tcase_add_test(one_test, x_tree_sscanf);
//   tcase_add_test(one_test, x_fore_sscanf);
//   tcase_add_test(one_test, x_five_sscanf);
//   tcase_add_test(one_test, x_six_sscanf);
//   tcase_add_test(one_test, x_seven_sscanf);
//   suite_add_tcase(s, fore_test);

//   five_test = tcase_create("unsigned fore test");
//   tcase_add_test(one_test, u_sscanf);
//   tcase_add_test(one_test, hh_sscanf);
//   tcase_add_test(one_test, ll_sscanf);
//   tcase_add_test(one_test, nu_sscanf);
//   suite_add_tcase(s, five_test);

//   six_test = tcase_create("i fore test");
//   tcase_add_test(one_test, i_sscanf);
//   tcase_add_test(one_test, ix_sscanf);
//   tcase_add_test(one_test, id_sscanf);
//   tcase_add_test(one_test, id_minus_sscanf);
//   suite_add_tcase(s, six_test);

//   p_test = tcase_create("n fore test");
//   tcase_add_test(one_test, p_sscanf);
//   tcase_add_test(one_test, pn_sscanf);
//   suite_add_tcase(s, p_test);

//   s_test = tcase_create("s string test");
//   tcase_add_test(one_test, string_sscanf);
//   suite_add_tcase(s, s_test);

//   dot_test = tcase_create("; : test");
//   tcase_add_test(one_test, dot_sscanf);
//   tcase_add_test(one_test, dot_2_sscanf);
//   suite_add_tcase(s, dot_test);

//   return s;
// }

//------------------------------------------------

START_TEST(sprintf_test_1) {
  char test_str_1[50] = "";
  char test_str_1_1[50] = "";
  s21_sprintf(test_str_1, "%-d", 0);
  sprintf(test_str_1_1, "%-d", 0);
  ck_assert_str_eq(test_str_1, test_str_1_1);
}
END_TEST

START_TEST(sprintf_test_2) {
  char test_str_2[50] = "";
  char test_str_2_2[50] = "";
  s21_sprintf(test_str_2, "%-d", 1);
  sprintf(test_str_2_2, "%-d", 1);
  ck_assert_str_eq(test_str_2, test_str_2_2);
}
END_TEST

START_TEST(sprintf_test_3) {
  char test_str_3[50] = "";
  char test_str_3_3[50] = "";
  s21_sprintf(test_str_3, "%-d", 10);
  sprintf(test_str_3_3, "%-d", 10);
  ck_assert_str_eq(test_str_3, test_str_3_3);
}
END_TEST

START_TEST(sprintf_test_4) {
  char test_str_4[50] = "";
  char test_str_4_4[50] = "";
  s21_sprintf(test_str_4, "%-d", 123456);
  sprintf(test_str_4_4, "%-d", 123456);
  ck_assert_str_eq(test_str_4, test_str_4_4);
}
END_TEST

START_TEST(sprintf_test_5) {
  char test_str_5[50] = "";
  char test_str_5_5[50] = "";
  s21_sprintf(test_str_5, "%-d", -67890123);
  sprintf(test_str_5_5, "%-d", -67890123);
  ck_assert_str_eq(test_str_5, test_str_5_5);
}
END_TEST

START_TEST(sprintf_test_6) {
  char test_str_6[50] = "";
  char test_str_6_6[50] = "";
  s21_sprintf(test_str_6, "%-d", 4343);
  sprintf(test_str_6_6, "%-d", 4343);
  ck_assert_str_eq(test_str_6, test_str_6_6);
}
END_TEST

START_TEST(sprintf_test_7) {
  char test_str_7[50] = "";
  char test_str_7_7[50] = "";
  s21_sprintf(test_str_7, "%-d", -1);
  sprintf(test_str_7_7, "%-d", -1);
  ck_assert_str_eq(test_str_7, test_str_7_7);
}
END_TEST

START_TEST(sprintf_test_8) {
  char test_str_8[50] = "";
  char test_str_8_8[50] = "";
  s21_sprintf(test_str_8, "%-d", -10);
  sprintf(test_str_8_8, "%-d", -10);
  ck_assert_str_eq(test_str_8, test_str_8_8);
}
END_TEST

START_TEST(sprintf_test_9) {
  char test_str_9[50] = "";
  char test_str_9_9[50] = "";
  s21_sprintf(test_str_9, "%-d", 43);
  sprintf(test_str_9_9, "%-d", 43);
  ck_assert_str_eq(test_str_9, test_str_9_9);
}
END_TEST

START_TEST(sprintf_test_10) {
  char test_str_10[50] = "";
  char test_str_10_10[50] = "";
  s21_sprintf(test_str_10, "%-i", 0);
  sprintf(test_str_10_10, "%-i", 0);
  ck_assert_str_eq(test_str_10, test_str_10_10);
}
END_TEST

START_TEST(sprintf_test_11) {
  char test_str_11[50] = "";
  char test_str_11_11[50] = "";
  s21_sprintf(test_str_11, "%-i", 1);
  sprintf(test_str_11_11, "%-i", 1);
  ck_assert_str_eq(test_str_11, test_str_11_11);
}
END_TEST

START_TEST(sprintf_test_12) {
  char test_str_12[50] = "";
  char test_str_12_12[50] = "";
  s21_sprintf(test_str_12, "%-i", 10);
  sprintf(test_str_12_12, "%-i", 10);
  ck_assert_str_eq(test_str_12, test_str_12_12);
}
END_TEST

START_TEST(sprintf_test_13) {
  char test_str_13[50] = "";
  char test_str_13_13[50] = "";
  s21_sprintf(test_str_13, "%-i", 123456);
  sprintf(test_str_13_13, "%-i", 123456);
  ck_assert_str_eq(test_str_13, test_str_13_13);
}
END_TEST

START_TEST(sprintf_test_14) {
  char test_str_14[50] = "";
  char test_str_14_14[50] = "";
  s21_sprintf(test_str_14, "%-i", -67890123);
  sprintf(test_str_14_14, "%-i", -67890123);
  ck_assert_str_eq(test_str_14, test_str_14_14);
}
END_TEST

START_TEST(sprintf_test_15) {
  char test_str_15[50] = "";
  char test_str_15_15[50] = "";
  s21_sprintf(test_str_15, "%-i", 4343);
  sprintf(test_str_15_15, "%-i", 4343);
  ck_assert_str_eq(test_str_15, test_str_15_15);
}
END_TEST

START_TEST(sprintf_test_16) {
  char test_str_16[50] = "";
  char test_str_16_16[50] = "";
  s21_sprintf(test_str_16, "%-i", -1);
  sprintf(test_str_16_16, "%-i", -1);
  ck_assert_str_eq(test_str_16, test_str_16_16);
}
END_TEST

START_TEST(sprintf_test_17) {
  char test_str_17[50] = "";
  char test_str_17_17[50] = "";
  s21_sprintf(test_str_17, "%-i", -10);
  sprintf(test_str_17_17, "%-i", -10);
  ck_assert_str_eq(test_str_17, test_str_17_17);
}
END_TEST

START_TEST(sprintf_test_18) {
  char test_str_18[50] = "";
  char test_str_18_18[50] = "";
  s21_sprintf(test_str_18, "%-i", 43);
  sprintf(test_str_18_18, "%-i", 43);
  ck_assert_str_eq(test_str_18, test_str_18_18);
}
END_TEST

// START_TEST(sprintf_test_19) {
//   char test_str_19[50] = "";
//   char test_str_19_19[50] = "";
//   s21_sprintf(test_str_19, "%%", 0);
//   sprintf(test_str_19_19, "%%", 0);
//   ck_assert_str_eq(test_str_19, test_str_19_19);
// }
// END_TEST

// START_TEST(sprintf_test_20) {
//   char test_str_20[50] = "";
//   char test_str_20_20[50] = "";
//   s21_sprintf(test_str_20, "%lf", 1.12312);
//   sprintf(test_str_20_20, "%lf", 1.12312);
//   ck_assert_str_eq(test_str_20, test_str_20_20);
// }
// END_TEST

// START_TEST(sprintf_test_21) {
//   char test_str_20[50] = "";
//   char test_str_20_20[50] = "";
//   s21_sprintf(test_str_20, "%lf %ld", 1.12312, 1122334455);
//   sprintf(test_str_20_20, "%lf %ld", 1.12312, 1122334455);
//   ck_assert_str_eq(test_str_20, test_str_20_20);
// }
// END_TEST

// START_TEST(sprintf_test_22) {
//   char test_str_20[50] = "";
//   char test_str_20_20[50] = "";
//   s21_sprintf(test_str_20, "%s", NULL);
//   sprintf(test_str_20_20, "%s", NULL);
//   ck_assert_str_eq(test_str_20, test_str_20_20);
// }
// END_TEST

// START_TEST(sprintf_test_23) {
//   char test_str_20[50] = "";
//   char test_str_20_20[50] = "";
//   s21_sprintf(test_str_20, "%.0f", 0.0);
//   sprintf(test_str_20_20, "%.0f", 0.0);
//   ck_assert_str_eq(test_str_20, test_str_20_20);
// }
// END_TEST

START_TEST(sprintf_test_28) {
  char test_str_28[50] = "";
  char test_str_28_28[50] = "";
  s21_sprintf(test_str_28, "%-u", 0);
  sprintf(test_str_28_28, "%-u", 0);
  ck_assert_str_eq(test_str_28, test_str_28_28);
}
END_TEST

START_TEST(sprintf_test_29) {
  char test_str_29[50] = "";
  char test_str_29_29[50] = "";
  s21_sprintf(test_str_29, "%-u", 1);
  sprintf(test_str_29_29, "%-u", 1);
  ck_assert_str_eq(test_str_29, test_str_29_29);
}
END_TEST

START_TEST(sprintf_test_30) {
  char test_str_30[50] = "";
  char test_str_30_30[50] = "";
  s21_sprintf(test_str_30, "%-u", 10);
  sprintf(test_str_30_30, "%-u", 10);
  ck_assert_str_eq(test_str_30, test_str_30_30);
}
END_TEST

START_TEST(sprintf_test_31) {
  char test_str_31[50] = "";
  char test_str_31_31[50] = "";
  s21_sprintf(test_str_31, "%-u", 123456);
  sprintf(test_str_31_31, "%-u", 123456);
  ck_assert_str_eq(test_str_31, test_str_31_31);
}
END_TEST

START_TEST(sprintf_test_32) {
  char test_str_32[50] = "";
  char test_str_32_32[50] = "";
  s21_sprintf(test_str_32, "%-u", -67890123);
  sprintf(test_str_32_32, "%-u", -67890123);
  ck_assert_str_eq(test_str_32, test_str_32_32);
}
END_TEST

START_TEST(sprintf_test_33) {
  char test_str_33[50] = "";
  char test_str_33_33[50] = "";
  s21_sprintf(test_str_33, "%-u", 4343);
  sprintf(test_str_33_33, "%-u", 4343);
  ck_assert_str_eq(test_str_33, test_str_33_33);
}
END_TEST

START_TEST(sprintf_test_34) {
  char test_str_34[50] = "";
  char test_str_34_34[50] = "";
  s21_sprintf(test_str_34, "%-u", -1);
  sprintf(test_str_34_34, "%-u", -1);
  ck_assert_str_eq(test_str_34, test_str_34_34);
}
END_TEST

START_TEST(sprintf_test_35) {
  char test_str_35[50] = "";
  char test_str_35_35[50] = "";
  s21_sprintf(test_str_35, "%-u", -10);
  sprintf(test_str_35_35, "%-u", -10);
  ck_assert_str_eq(test_str_35, test_str_35_35);
}
END_TEST

START_TEST(sprintf_test_36) {
  char test_str_36[50] = "";
  char test_str_36_36[50] = "";
  s21_sprintf(test_str_36, "%-u", 43);
  sprintf(test_str_36_36, "%-u", 43);
  ck_assert_str_eq(test_str_36, test_str_36_36);
}
END_TEST

START_TEST(sprintf_test_55) {
  char test_str_55[50] = "";
  char test_str_55_55[50] = "";
  s21_sprintf(test_str_55, "%+d", 0);
  sprintf(test_str_55_55, "%+d", 0);
  ck_assert_str_eq(test_str_55, test_str_55_55);
}
END_TEST

START_TEST(sprintf_test_56) {
  char test_str_56[50] = "";
  char test_str_56_56[50] = "";
  s21_sprintf(test_str_56, "%+d", 1);
  sprintf(test_str_56_56, "%+d", 1);
  ck_assert_str_eq(test_str_56, test_str_56_56);
}
END_TEST

START_TEST(sprintf_test_57) {
  char test_str_57[50] = "";
  char test_str_57_57[50] = "";
  s21_sprintf(test_str_57, "%+d", 10);
  sprintf(test_str_57_57, "%+d", 10);
  ck_assert_str_eq(test_str_57, test_str_57_57);
}
END_TEST

START_TEST(sprintf_test_58) {
  char test_str_58[50] = "";
  char test_str_58_58[50] = "";
  s21_sprintf(test_str_58, "%+d", 123456);
  sprintf(test_str_58_58, "%+d", 123456);
  ck_assert_str_eq(test_str_58, test_str_58_58);
}
END_TEST

START_TEST(sprintf_test_59) {
  char test_str_59[50] = "";
  char test_str_59_59[50] = "";
  s21_sprintf(test_str_59, "%+d", -67890123);
  sprintf(test_str_59_59, "%+d", -67890123);
  ck_assert_str_eq(test_str_59, test_str_59_59);
}
END_TEST

START_TEST(sprintf_test_60) {
  char test_str_60[50] = "";
  char test_str_60_60[50] = "";
  s21_sprintf(test_str_60, "%+d", 4343);
  sprintf(test_str_60_60, "%+d", 4343);
  ck_assert_str_eq(test_str_60, test_str_60_60);
}
END_TEST

START_TEST(sprintf_test_61) {
  char test_str_61[50] = "";
  char test_str_61_61[50] = "";
  s21_sprintf(test_str_61, "%+d", -1);
  sprintf(test_str_61_61, "%+d", -1);
  ck_assert_str_eq(test_str_61, test_str_61_61);
}
END_TEST

START_TEST(sprintf_test_62) {
  char test_str_62[50] = "";
  char test_str_62_62[50] = "";
  s21_sprintf(test_str_62, "%+d", -10);
  sprintf(test_str_62_62, "%+d", -10);
  ck_assert_str_eq(test_str_62, test_str_62_62);
}
END_TEST

START_TEST(sprintf_test_63) {
  char test_str_63[50] = "";
  char test_str_63_63[50] = "";
  s21_sprintf(test_str_63, "%+d", 43);
  sprintf(test_str_63_63, "%+d", 43);
  ck_assert_str_eq(test_str_63, test_str_63_63);
}
END_TEST

START_TEST(sprintf_test_64) {
  char test_str_64[50] = "";
  char test_str_64_64[50] = "";
  s21_sprintf(test_str_64, "%+i", 0);
  sprintf(test_str_64_64, "%+i", 0);
  ck_assert_str_eq(test_str_64, test_str_64_64);
}
END_TEST

START_TEST(sprintf_test_65) {
  char test_str_65[50] = "";
  char test_str_65_65[50] = "";
  s21_sprintf(test_str_65, "%+i", 1);
  sprintf(test_str_65_65, "%+i", 1);
  ck_assert_str_eq(test_str_65, test_str_65_65);
}
END_TEST

START_TEST(sprintf_test_66) {
  char test_str_66[50] = "";
  char test_str_66_66[50] = "";
  s21_sprintf(test_str_66, "%+i", 10);
  sprintf(test_str_66_66, "%+i", 10);
  ck_assert_str_eq(test_str_66, test_str_66_66);
}
END_TEST

START_TEST(sprintf_test_67) {
  char test_str_67[50] = "";
  char test_str_67_67[50] = "";
  s21_sprintf(test_str_67, "%+i", 123456);
  sprintf(test_str_67_67, "%+i", 123456);
  ck_assert_str_eq(test_str_67, test_str_67_67);
}
END_TEST

START_TEST(sprintf_test_68) {
  char test_str_68[50] = "";
  char test_str_68_68[50] = "";
  s21_sprintf(test_str_68, "%+i", -67890123);
  sprintf(test_str_68_68, "%+i", -67890123);
  ck_assert_str_eq(test_str_68, test_str_68_68);
}
END_TEST

START_TEST(sprintf_test_69) {
  char test_str_69[50] = "";
  char test_str_69_69[50] = "";
  s21_sprintf(test_str_69, "%+i", 4343);
  sprintf(test_str_69_69, "%+i", 4343);
  ck_assert_str_eq(test_str_69, test_str_69_69);
}
END_TEST

START_TEST(sprintf_test_70) {
  char test_str_70[50] = "";
  char test_str_70_70[50] = "";
  s21_sprintf(test_str_70, "%+i", -1);
  sprintf(test_str_70_70, "%+i", -1);
  ck_assert_str_eq(test_str_70, test_str_70_70);
}
END_TEST

START_TEST(sprintf_test_71) {
  char test_str_71[50] = "";
  char test_str_71_71[50] = "";
  s21_sprintf(test_str_71, "%+i", -10);
  sprintf(test_str_71_71, "%+i", -10);
  ck_assert_str_eq(test_str_71, test_str_71_71);
}
END_TEST

START_TEST(sprintf_test_72) {
  char test_str_72[50] = "";
  char test_str_72_72[50] = "";
  s21_sprintf(test_str_72, "%+i", 43);
  sprintf(test_str_72_72, "%+i", 43);
  ck_assert_str_eq(test_str_72, test_str_72_72);
}
END_TEST

START_TEST(sprintf_test_109) {
  char test_str_109[50] = "";
  char test_str_109_109[50] = "";
  s21_sprintf(test_str_109, "% d", 0);
  sprintf(test_str_109_109, "% d", 0);
  ck_assert_str_eq(test_str_109, test_str_109_109);
}
END_TEST

START_TEST(sprintf_test_110) {
  char test_str_110[50] = "";
  char test_str_110_110[50] = "";
  s21_sprintf(test_str_110, "% d", 1);
  sprintf(test_str_110_110, "% d", 1);
  ck_assert_str_eq(test_str_110, test_str_110_110);
}
END_TEST

START_TEST(sprintf_test_111) {
  char test_str_111[50] = "";
  char test_str_111_111[50] = "";
  s21_sprintf(test_str_111, "% d", 10);
  sprintf(test_str_111_111, "% d", 10);
  ck_assert_str_eq(test_str_111, test_str_111_111);
}
END_TEST

START_TEST(sprintf_test_112) {
  char test_str_112[50] = "";
  char test_str_112_112[50] = "";
  s21_sprintf(test_str_112, "% d", 123456);
  sprintf(test_str_112_112, "% d", 123456);
  ck_assert_str_eq(test_str_112, test_str_112_112);
}
END_TEST

START_TEST(sprintf_test_113) {
  char test_str_113[50] = "";
  char test_str_113_113[50] = "";
  s21_sprintf(test_str_113, "% d", -67890123);
  sprintf(test_str_113_113, "% d", -67890123);
  ck_assert_str_eq(test_str_113, test_str_113_113);
}
END_TEST

START_TEST(sprintf_test_114) {
  char test_str_114[50] = "";
  char test_str_114_114[50] = "";
  s21_sprintf(test_str_114, "% d", 4343);
  sprintf(test_str_114_114, "% d", 4343);
  ck_assert_str_eq(test_str_114, test_str_114_114);
}
END_TEST

START_TEST(sprintf_test_115) {
  char test_str_115[50] = "";
  char test_str_115_115[50] = "";
  s21_sprintf(test_str_115, "% d", -1);
  sprintf(test_str_115_115, "% d", -1);
  ck_assert_str_eq(test_str_115, test_str_115_115);
}
END_TEST

START_TEST(sprintf_test_116) {
  char test_str_116[50] = "";
  char test_str_116_116[50] = "";
  s21_sprintf(test_str_116, "% d", -10);
  sprintf(test_str_116_116, "% d", -10);
  ck_assert_str_eq(test_str_116, test_str_116_116);
}
END_TEST

START_TEST(sprintf_test_117) {
  char test_str_117[50] = "";
  char test_str_117_117[50] = "";
  s21_sprintf(test_str_117, "% d", 43);
  sprintf(test_str_117_117, "% d", 43);
  ck_assert_str_eq(test_str_117, test_str_117_117);
}
END_TEST

START_TEST(sprintf_test_118) {
  char test_str_118[50] = "";
  char test_str_118_118[50] = "";
  s21_sprintf(test_str_118, "% i", 0);
  sprintf(test_str_118_118, "% i", 0);
  ck_assert_str_eq(test_str_118, test_str_118_118);
}
END_TEST

START_TEST(sprintf_test_119) {
  char test_str_119[50] = "";
  char test_str_119_119[50] = "";
  s21_sprintf(test_str_119, "% i", 1);
  sprintf(test_str_119_119, "% i", 1);
  ck_assert_str_eq(test_str_119, test_str_119_119);
}
END_TEST

START_TEST(sprintf_test_120) {
  char test_str_120[50] = "";
  char test_str_120_120[50] = "";
  s21_sprintf(test_str_120, "% i", 10);
  sprintf(test_str_120_120, "% i", 10);
  ck_assert_str_eq(test_str_120, test_str_120_120);
}
END_TEST

START_TEST(sprintf_test_121) {
  char test_str_121[50] = "";
  char test_str_121_121[50] = "";
  s21_sprintf(test_str_121, "% i", 123456);
  sprintf(test_str_121_121, "% i", 123456);
  ck_assert_str_eq(test_str_121, test_str_121_121);
}
END_TEST

START_TEST(sprintf_test_122) {
  char test_str_122[50] = "";
  char test_str_122_122[50] = "";
  s21_sprintf(test_str_122, "% i", -67890123);
  sprintf(test_str_122_122, "% i", -67890123);
  ck_assert_str_eq(test_str_122, test_str_122_122);
}
END_TEST

START_TEST(sprintf_test_123) {
  char test_str_123[50] = "";
  char test_str_123_123[50] = "";
  s21_sprintf(test_str_123, "% i", 4343);
  sprintf(test_str_123_123, "% i", 4343);
  ck_assert_str_eq(test_str_123, test_str_123_123);
}
END_TEST

START_TEST(sprintf_test_124) {
  char test_str_124[50] = "";
  char test_str_124_124[50] = "";
  s21_sprintf(test_str_124, "% i", -1);
  sprintf(test_str_124_124, "% i", -1);
  ck_assert_str_eq(test_str_124, test_str_124_124);
}
END_TEST

START_TEST(sprintf_test_125) {
  char test_str_125[50] = "";
  char test_str_125_125[50] = "";
  s21_sprintf(test_str_125, "% i", -10);
  sprintf(test_str_125_125, "% i", -10);
  ck_assert_str_eq(test_str_125, test_str_125_125);
}
END_TEST

START_TEST(sprintf_test_126) {
  char test_str_126[50] = "";
  char test_str_126_126[50] = "";
  s21_sprintf(test_str_126, "% i", 43);
  sprintf(test_str_126_126, "% i", 43);
  ck_assert_str_eq(test_str_126, test_str_126_126);
}
END_TEST

START_TEST(sprintf_test_325) {
  char test_str_325[50] = "";
  char test_str_325_325[50] = "";
  s21_sprintf(test_str_325, "%10d", 0);
  sprintf(test_str_325_325, "%10d", 0);
  ck_assert_str_eq(test_str_325, test_str_325_325);
}
END_TEST

START_TEST(sprintf_test_326) {
  char test_str_326[50] = "";
  char test_str_326_326[50] = "";
  s21_sprintf(test_str_326, "%10d", 1);
  sprintf(test_str_326_326, "%10d", 1);
  ck_assert_str_eq(test_str_326, test_str_326_326);
}
END_TEST

START_TEST(sprintf_test_327) {
  char test_str_327[50] = "";
  char test_str_327_327[50] = "";
  s21_sprintf(test_str_327, "%10d", 10);
  sprintf(test_str_327_327, "%10d", 10);
  ck_assert_str_eq(test_str_327, test_str_327_327);
}
END_TEST

START_TEST(sprintf_test_328) {
  char test_str_328[50] = "";
  char test_str_328_328[50] = "";
  s21_sprintf(test_str_328, "%10d", 123456);
  sprintf(test_str_328_328, "%10d", 123456);
  ck_assert_str_eq(test_str_328, test_str_328_328);
}
END_TEST

START_TEST(sprintf_test_329) {
  char test_str_329[50] = "";
  char test_str_329_329[50] = "";
  s21_sprintf(test_str_329, "%10d", -67890123);
  sprintf(test_str_329_329, "%10d", -67890123);
  ck_assert_str_eq(test_str_329, test_str_329_329);
}
END_TEST

START_TEST(sprintf_test_330) {
  char test_str_330[50] = "";
  char test_str_330_330[50] = "";
  s21_sprintf(test_str_330, "%10d", 4343);
  sprintf(test_str_330_330, "%10d", 4343);
  ck_assert_str_eq(test_str_330, test_str_330_330);
}
END_TEST

START_TEST(sprintf_test_331) {
  char test_str_331[50] = "";
  char test_str_331_331[50] = "";
  s21_sprintf(test_str_331, "%10d", -1);
  sprintf(test_str_331_331, "%10d", -1);
  ck_assert_str_eq(test_str_331, test_str_331_331);
}
END_TEST

START_TEST(sprintf_test_332) {
  char test_str_332[50] = "";
  char test_str_332_332[50] = "";
  s21_sprintf(test_str_332, "%10d", -10);
  sprintf(test_str_332_332, "%10d", -10);
  ck_assert_str_eq(test_str_332, test_str_332_332);
}
END_TEST

START_TEST(sprintf_test_333) {
  char test_str_333[50] = "";
  char test_str_333_333[50] = "";
  s21_sprintf(test_str_333, "%10d", 43);
  sprintf(test_str_333_333, "%10d", 43);
  ck_assert_str_eq(test_str_333, test_str_333_333);
}
END_TEST

START_TEST(sprintf_test_334) {
  char test_str_334[50] = "";
  char test_str_334_334[50] = "";
  s21_sprintf(test_str_334, "%10i", 0);
  sprintf(test_str_334_334, "%10i", 0);
  ck_assert_str_eq(test_str_334, test_str_334_334);
}
END_TEST

START_TEST(sprintf_test_335) {
  char test_str_335[50] = "";
  char test_str_335_335[50] = "";
  s21_sprintf(test_str_335, "%10i", 1);
  sprintf(test_str_335_335, "%10i", 1);
  ck_assert_str_eq(test_str_335, test_str_335_335);
}
END_TEST

START_TEST(sprintf_test_336) {
  char test_str_336[50] = "";
  char test_str_336_336[50] = "";
  s21_sprintf(test_str_336, "%10i", 10);
  sprintf(test_str_336_336, "%10i", 10);
  ck_assert_str_eq(test_str_336, test_str_336_336);
}
END_TEST

START_TEST(sprintf_test_337) {
  char test_str_337[50] = "";
  char test_str_337_337[50] = "";
  s21_sprintf(test_str_337, "%10i", 123456);
  sprintf(test_str_337_337, "%10i", 123456);
  ck_assert_str_eq(test_str_337, test_str_337_337);
}
END_TEST

START_TEST(sprintf_test_338) {
  char test_str_338[50] = "";
  char test_str_338_338[50] = "";
  s21_sprintf(test_str_338, "%10i", -67890123);
  sprintf(test_str_338_338, "%10i", -67890123);
  ck_assert_str_eq(test_str_338, test_str_338_338);
}
END_TEST

START_TEST(sprintf_test_339) {
  char test_str_339[50] = "";
  char test_str_339_339[50] = "";
  s21_sprintf(test_str_339, "%10i", 4343);
  sprintf(test_str_339_339, "%10i", 4343);
  ck_assert_str_eq(test_str_339, test_str_339_339);
}
END_TEST

START_TEST(sprintf_test_340) {
  char test_str_340[50] = "";
  char test_str_340_340[50] = "";
  s21_sprintf(test_str_340, "%10i", -1);
  sprintf(test_str_340_340, "%10i", -1);
  ck_assert_str_eq(test_str_340, test_str_340_340);
}
END_TEST

START_TEST(sprintf_test_341) {
  char test_str_341[50] = "";
  char test_str_341_341[50] = "";
  s21_sprintf(test_str_341, "%10i", -10);
  sprintf(test_str_341_341, "%10i", -10);
  ck_assert_str_eq(test_str_341, test_str_341_341);
}
END_TEST

START_TEST(sprintf_test_342) {
  char test_str_342[50] = "";
  char test_str_342_342[50] = "";
  s21_sprintf(test_str_342, "%10i", 43);
  sprintf(test_str_342_342, "%10i", 43);
  ck_assert_str_eq(test_str_342, test_str_342_342);
}
END_TEST

START_TEST(sprintf_test_352) {
  char test_str_352[50] = "";
  char test_str_352_352[50] = "";
  s21_sprintf(test_str_352, "%10u", 0);
  sprintf(test_str_352_352, "%10u", 0);
  ck_assert_str_eq(test_str_352, test_str_352_352);
}
END_TEST

START_TEST(sprintf_test_353) {
  char test_str_353[50] = "";
  char test_str_353_353[50] = "";
  s21_sprintf(test_str_353, "%10u", 1);
  sprintf(test_str_353_353, "%10u", 1);
  ck_assert_str_eq(test_str_353, test_str_353_353);
}
END_TEST

START_TEST(sprintf_test_354) {
  char test_str_354[50] = "";
  char test_str_354_354[50] = "";
  s21_sprintf(test_str_354, "%10u", 10);
  sprintf(test_str_354_354, "%10u", 10);
  ck_assert_str_eq(test_str_354, test_str_354_354);
}
END_TEST

START_TEST(sprintf_test_355) {
  char test_str_355[50] = "";
  char test_str_355_355[50] = "";
  s21_sprintf(test_str_355, "%10u", 123456);
  sprintf(test_str_355_355, "%10u", 123456);
  ck_assert_str_eq(test_str_355, test_str_355_355);
}
END_TEST

START_TEST(sprintf_test_356) {
  char test_str_356[50] = "";
  char test_str_356_356[50] = "";
  s21_sprintf(test_str_356, "%10u", -67890123);
  sprintf(test_str_356_356, "%10u", -67890123);
  ck_assert_str_eq(test_str_356, test_str_356_356);
}
END_TEST

START_TEST(sprintf_test_357) {
  char test_str_357[50] = "";
  char test_str_357_357[50] = "";
  s21_sprintf(test_str_357, "%10u", 4343);
  sprintf(test_str_357_357, "%10u", 4343);
  ck_assert_str_eq(test_str_357, test_str_357_357);
}
END_TEST

START_TEST(sprintf_test_358) {
  char test_str_358[50] = "";
  char test_str_358_358[50] = "";
  s21_sprintf(test_str_358, "%10u", -1);
  sprintf(test_str_358_358, "%10u", -1);
  ck_assert_str_eq(test_str_358, test_str_358_358);
}
END_TEST

START_TEST(sprintf_test_359) {
  char test_str_359[50] = "";
  char test_str_359_359[50] = "";
  s21_sprintf(test_str_359, "%10u", -10);
  sprintf(test_str_359_359, "%10u", -10);
  ck_assert_str_eq(test_str_359, test_str_359_359);
}
END_TEST

START_TEST(sprintf_test_360) {
  char test_str_360[50] = "";
  char test_str_360_360[50] = "";
  s21_sprintf(test_str_360, "%10u", 43);
  sprintf(test_str_360_360, "%10u", 43);
  ck_assert_str_eq(test_str_360, test_str_360_360);
}
END_TEST

START_TEST(sprintf_test_379) {
  char test_str_379[50] = "";
  char test_str_379_379[50] = "";
  s21_sprintf(test_str_379, "%20d", 0);
  sprintf(test_str_379_379, "%20d", 0);
  ck_assert_str_eq(test_str_379, test_str_379_379);
}
END_TEST

START_TEST(sprintf_test_380) {
  char test_str_380[50] = "";
  char test_str_380_380[50] = "";
  s21_sprintf(test_str_380, "%20d", 1);
  sprintf(test_str_380_380, "%20d", 1);
  ck_assert_str_eq(test_str_380, test_str_380_380);
}
END_TEST

START_TEST(sprintf_test_381) {
  char test_str_381[50] = "";
  char test_str_381_381[50] = "";
  s21_sprintf(test_str_381, "%20d", 10);
  sprintf(test_str_381_381, "%20d", 10);
  ck_assert_str_eq(test_str_381, test_str_381_381);
}
END_TEST

START_TEST(sprintf_test_382) {
  char test_str_382[50] = "";
  char test_str_382_382[50] = "";
  s21_sprintf(test_str_382, "%20d", 123456);
  sprintf(test_str_382_382, "%20d", 123456);
  ck_assert_str_eq(test_str_382, test_str_382_382);
}
END_TEST

START_TEST(sprintf_test_383) {
  char test_str_383[50] = "";
  char test_str_383_383[50] = "";
  s21_sprintf(test_str_383, "%20d", -67890123);
  sprintf(test_str_383_383, "%20d", -67890123);
  ck_assert_str_eq(test_str_383, test_str_383_383);
}
END_TEST

START_TEST(sprintf_test_384) {
  char test_str_384[50] = "";
  char test_str_384_384[50] = "";
  s21_sprintf(test_str_384, "%20d", 4343);
  sprintf(test_str_384_384, "%20d", 4343);
  ck_assert_str_eq(test_str_384, test_str_384_384);
}
END_TEST

START_TEST(sprintf_test_385) {
  char test_str_385[50] = "";
  char test_str_385_385[50] = "";
  s21_sprintf(test_str_385, "%20d", -1);
  sprintf(test_str_385_385, "%20d", -1);
  ck_assert_str_eq(test_str_385, test_str_385_385);
}
END_TEST

START_TEST(sprintf_test_386) {
  char test_str_386[50] = "";
  char test_str_386_386[50] = "";
  s21_sprintf(test_str_386, "%20d", -10);
  sprintf(test_str_386_386, "%20d", -10);
  ck_assert_str_eq(test_str_386, test_str_386_386);
}
END_TEST

START_TEST(sprintf_test_387) {
  char test_str_387[50] = "";
  char test_str_387_387[50] = "";
  s21_sprintf(test_str_387, "%20d", 43);
  sprintf(test_str_387_387, "%20d", 43);
  ck_assert_str_eq(test_str_387, test_str_387_387);
}
END_TEST

START_TEST(sprintf_test_388) {
  char test_str_388[50] = "";
  char test_str_388_388[50] = "";
  s21_sprintf(test_str_388, "%20i", 0);
  sprintf(test_str_388_388, "%20i", 0);
  ck_assert_str_eq(test_str_388, test_str_388_388);
}
END_TEST

START_TEST(sprintf_test_389) {
  char test_str_389[50] = "";
  char test_str_389_389[50] = "";
  s21_sprintf(test_str_389, "%20i", 1);
  sprintf(test_str_389_389, "%20i", 1);
  ck_assert_str_eq(test_str_389, test_str_389_389);
}
END_TEST

START_TEST(sprintf_test_390) {
  char test_str_390[50] = "";
  char test_str_390_390[50] = "";
  s21_sprintf(test_str_390, "%20i", 10);
  sprintf(test_str_390_390, "%20i", 10);
  ck_assert_str_eq(test_str_390, test_str_390_390);
}
END_TEST

START_TEST(sprintf_test_391) {
  char test_str_391[50] = "";
  char test_str_391_391[50] = "";
  s21_sprintf(test_str_391, "%20i", 123456);
  sprintf(test_str_391_391, "%20i", 123456);
  ck_assert_str_eq(test_str_391, test_str_391_391);
}
END_TEST

START_TEST(sprintf_test_392) {
  char test_str_392[50] = "";
  char test_str_392_392[50] = "";
  s21_sprintf(test_str_392, "%20i", -67890123);
  sprintf(test_str_392_392, "%20i", -67890123);
  ck_assert_str_eq(test_str_392, test_str_392_392);
}
END_TEST

START_TEST(sprintf_test_393) {
  char test_str_393[50] = "";
  char test_str_393_393[50] = "";
  s21_sprintf(test_str_393, "%20i", 4343);
  sprintf(test_str_393_393, "%20i", 4343);
  ck_assert_str_eq(test_str_393, test_str_393_393);
}
END_TEST

START_TEST(sprintf_test_394) {
  char test_str_394[50] = "";
  char test_str_394_394[50] = "";
  s21_sprintf(test_str_394, "%20i", -1);
  sprintf(test_str_394_394, "%20i", -1);
  ck_assert_str_eq(test_str_394, test_str_394_394);
}
END_TEST

START_TEST(sprintf_test_395) {
  char test_str_395[50] = "";
  char test_str_395_395[50] = "";
  s21_sprintf(test_str_395, "%20i", -10);
  sprintf(test_str_395_395, "%20i", -10);
  ck_assert_str_eq(test_str_395, test_str_395_395);
}
END_TEST

START_TEST(sprintf_test_396) {
  char test_str_396[50] = "";
  char test_str_396_396[50] = "";
  s21_sprintf(test_str_396, "%20i", 43);
  sprintf(test_str_396_396, "%20i", 43);
  ck_assert_str_eq(test_str_396, test_str_396_396);
}
END_TEST

START_TEST(sprintf_test_406) {
  char test_str_406[50] = "";
  char test_str_406_406[50] = "";
  s21_sprintf(test_str_406, "%20u", 0);
  sprintf(test_str_406_406, "%20u", 0);
  ck_assert_str_eq(test_str_406, test_str_406_406);
}
END_TEST

START_TEST(sprintf_test_407) {
  char test_str_407[50] = "";
  char test_str_407_407[50] = "";
  s21_sprintf(test_str_407, "%20u", 1);
  sprintf(test_str_407_407, "%20u", 1);
  ck_assert_str_eq(test_str_407, test_str_407_407);
}
END_TEST

START_TEST(sprintf_test_408) {
  char test_str_408[50] = "";
  char test_str_408_408[50] = "";
  s21_sprintf(test_str_408, "%20u", 10);
  sprintf(test_str_408_408, "%20u", 10);
  ck_assert_str_eq(test_str_408, test_str_408_408);
}
END_TEST

START_TEST(sprintf_test_409) {
  char test_str_409[50] = "";
  char test_str_409_409[50] = "";
  s21_sprintf(test_str_409, "%20u", 123456);
  sprintf(test_str_409_409, "%20u", 123456);
  ck_assert_str_eq(test_str_409, test_str_409_409);
}
END_TEST

START_TEST(sprintf_test_410) {
  char test_str_410[50] = "";
  char test_str_410_410[50] = "";
  s21_sprintf(test_str_410, "%20u", -67890123);
  sprintf(test_str_410_410, "%20u", -67890123);
  ck_assert_str_eq(test_str_410, test_str_410_410);
}
END_TEST

START_TEST(sprintf_test_411) {
  char test_str_411[50] = "";
  char test_str_411_411[50] = "";
  s21_sprintf(test_str_411, "%20u", 4343);
  sprintf(test_str_411_411, "%20u", 4343);
  ck_assert_str_eq(test_str_411, test_str_411_411);
}
END_TEST

START_TEST(sprintf_test_412) {
  char test_str_412[50] = "";
  char test_str_412_412[50] = "";
  s21_sprintf(test_str_412, "%20u", -1);
  sprintf(test_str_412_412, "%20u", -1);
  ck_assert_str_eq(test_str_412, test_str_412_412);
}
END_TEST

START_TEST(sprintf_test_413) {
  char test_str_413[50] = "";
  char test_str_413_413[50] = "";
  s21_sprintf(test_str_413, "%20u", -10);
  sprintf(test_str_413_413, "%20u", -10);
  ck_assert_str_eq(test_str_413, test_str_413_413);
}
END_TEST

START_TEST(sprintf_test_414) {
  char test_str_414[50] = "";
  char test_str_414_414[50] = "";
  s21_sprintf(test_str_414, "%20u", 43);
  sprintf(test_str_414_414, "%20u", 43);
  ck_assert_str_eq(test_str_414, test_str_414_414);
}
END_TEST

START_TEST(sprintf_test_433) {
  char test_str_433[50] = "";
  char test_str_433_433[50] = "";
  s21_sprintf(test_str_433, "%-10d", 0);
  sprintf(test_str_433_433, "%-10d", 0);
  ck_assert_str_eq(test_str_433, test_str_433_433);
}
END_TEST

START_TEST(sprintf_test_434) {
  char test_str_434[50] = "";
  char test_str_434_434[50] = "";
  s21_sprintf(test_str_434, "%-10d", 1);
  sprintf(test_str_434_434, "%-10d", 1);
  ck_assert_str_eq(test_str_434, test_str_434_434);
}
END_TEST

START_TEST(sprintf_test_435) {
  char test_str_435[50] = "";
  char test_str_435_435[50] = "";
  s21_sprintf(test_str_435, "%-10d", 10);
  sprintf(test_str_435_435, "%-10d", 10);
  ck_assert_str_eq(test_str_435, test_str_435_435);
}
END_TEST

START_TEST(sprintf_test_436) {
  char test_str_436[50] = "";
  char test_str_436_436[50] = "";
  s21_sprintf(test_str_436, "%-10d", 123456);
  sprintf(test_str_436_436, "%-10d", 123456);
  ck_assert_str_eq(test_str_436, test_str_436_436);
}
END_TEST

START_TEST(sprintf_test_437) {
  char test_str_437[50] = "";
  char test_str_437_437[50] = "";
  s21_sprintf(test_str_437, "%-10d", -67890123);
  sprintf(test_str_437_437, "%-10d", -67890123);
  ck_assert_str_eq(test_str_437, test_str_437_437);
}
END_TEST

START_TEST(sprintf_test_438) {
  char test_str_438[50] = "";
  char test_str_438_438[50] = "";
  s21_sprintf(test_str_438, "%-10d", 4343);
  sprintf(test_str_438_438, "%-10d", 4343);
  ck_assert_str_eq(test_str_438, test_str_438_438);
}
END_TEST

START_TEST(sprintf_test_439) {
  char test_str_439[50] = "";
  char test_str_439_439[50] = "";
  s21_sprintf(test_str_439, "%-10d", -1);
  sprintf(test_str_439_439, "%-10d", -1);
  ck_assert_str_eq(test_str_439, test_str_439_439);
}
END_TEST

START_TEST(sprintf_test_440) {
  char test_str_440[50] = "";
  char test_str_440_440[50] = "";
  s21_sprintf(test_str_440, "%-10d", -10);
  sprintf(test_str_440_440, "%-10d", -10);
  ck_assert_str_eq(test_str_440, test_str_440_440);
}
END_TEST

START_TEST(sprintf_test_441) {
  char test_str_441[50] = "";
  char test_str_441_441[50] = "";
  s21_sprintf(test_str_441, "%-10d", 43);
  sprintf(test_str_441_441, "%-10d", 43);
  ck_assert_str_eq(test_str_441, test_str_441_441);
}
END_TEST

START_TEST(sprintf_test_442) {
  char test_str_442[50] = "";
  char test_str_442_442[50] = "";
  s21_sprintf(test_str_442, "%-10i", 0);
  sprintf(test_str_442_442, "%-10i", 0);
  ck_assert_str_eq(test_str_442, test_str_442_442);
}
END_TEST

START_TEST(sprintf_test_443) {
  char test_str_443[50] = "";
  char test_str_443_443[50] = "";
  s21_sprintf(test_str_443, "%-10i", 1);
  sprintf(test_str_443_443, "%-10i", 1);
  ck_assert_str_eq(test_str_443, test_str_443_443);
}
END_TEST

START_TEST(sprintf_test_444) {
  char test_str_444[50] = "";
  char test_str_444_444[50] = "";
  s21_sprintf(test_str_444, "%-10i", 10);
  sprintf(test_str_444_444, "%-10i", 10);
  ck_assert_str_eq(test_str_444, test_str_444_444);
}
END_TEST

START_TEST(sprintf_test_445) {
  char test_str_445[50] = "";
  char test_str_445_445[50] = "";
  s21_sprintf(test_str_445, "%-10i", 123456);
  sprintf(test_str_445_445, "%-10i", 123456);
  ck_assert_str_eq(test_str_445, test_str_445_445);
}
END_TEST

START_TEST(sprintf_test_446) {
  char test_str_446[50] = "";
  char test_str_446_446[50] = "";
  s21_sprintf(test_str_446, "%-10i", -67890123);
  sprintf(test_str_446_446, "%-10i", -67890123);
  ck_assert_str_eq(test_str_446, test_str_446_446);
}
END_TEST

START_TEST(sprintf_test_447) {
  char test_str_447[50] = "";
  char test_str_447_447[50] = "";
  s21_sprintf(test_str_447, "%-10i", 4343);
  sprintf(test_str_447_447, "%-10i", 4343);
  ck_assert_str_eq(test_str_447, test_str_447_447);
}
END_TEST

START_TEST(sprintf_test_448) {
  char test_str_448[50] = "";
  char test_str_448_448[50] = "";
  s21_sprintf(test_str_448, "%-10i", -1);
  sprintf(test_str_448_448, "%-10i", -1);
  ck_assert_str_eq(test_str_448, test_str_448_448);
}
END_TEST

START_TEST(sprintf_test_449) {
  char test_str_449[50] = "";
  char test_str_449_449[50] = "";
  s21_sprintf(test_str_449, "%-10i", -10);
  sprintf(test_str_449_449, "%-10i", -10);
  ck_assert_str_eq(test_str_449, test_str_449_449);
}
END_TEST

START_TEST(sprintf_test_450) {
  char test_str_450[50] = "";
  char test_str_450_450[50] = "";
  s21_sprintf(test_str_450, "%-10i", 43);
  sprintf(test_str_450_450, "%-10i", 43);
  ck_assert_str_eq(test_str_450, test_str_450_450);
}
END_TEST

START_TEST(sprintf_test_460) {
  char test_str_460[50] = "";
  char test_str_460_460[50] = "";
  s21_sprintf(test_str_460, "%-10u", 0);
  sprintf(test_str_460_460, "%-10u", 0);
  ck_assert_str_eq(test_str_460, test_str_460_460);
}
END_TEST

START_TEST(sprintf_test_461) {
  char test_str_461[50] = "";
  char test_str_461_461[50] = "";
  s21_sprintf(test_str_461, "%-10u", 1);
  sprintf(test_str_461_461, "%-10u", 1);
  ck_assert_str_eq(test_str_461, test_str_461_461);
}
END_TEST

START_TEST(sprintf_test_462) {
  char test_str_462[50] = "";
  char test_str_462_462[50] = "";
  s21_sprintf(test_str_462, "%-10u", 10);
  sprintf(test_str_462_462, "%-10u", 10);
  ck_assert_str_eq(test_str_462, test_str_462_462);
}
END_TEST

START_TEST(sprintf_test_463) {
  char test_str_463[50] = "";
  char test_str_463_463[50] = "";
  s21_sprintf(test_str_463, "%-10u", 123456);
  sprintf(test_str_463_463, "%-10u", 123456);
  ck_assert_str_eq(test_str_463, test_str_463_463);
}
END_TEST

START_TEST(sprintf_test_464) {
  char test_str_464[50] = "";
  char test_str_464_464[50] = "";
  s21_sprintf(test_str_464, "%-10u", -67890123);
  sprintf(test_str_464_464, "%-10u", -67890123);
  ck_assert_str_eq(test_str_464, test_str_464_464);
}
END_TEST

START_TEST(sprintf_test_465) {
  char test_str_465[50] = "";
  char test_str_465_465[50] = "";
  s21_sprintf(test_str_465, "%-10u", 4343);
  sprintf(test_str_465_465, "%-10u", 4343);
  ck_assert_str_eq(test_str_465, test_str_465_465);
}
END_TEST

START_TEST(sprintf_test_466) {
  char test_str_466[50] = "";
  char test_str_466_466[50] = "";
  s21_sprintf(test_str_466, "%-10u", -1);
  sprintf(test_str_466_466, "%-10u", -1);
  ck_assert_str_eq(test_str_466, test_str_466_466);
}
END_TEST

START_TEST(sprintf_test_467) {
  char test_str_467[50] = "";
  char test_str_467_467[50] = "";
  s21_sprintf(test_str_467, "%-10u", -10);
  sprintf(test_str_467_467, "%-10u", -10);
  ck_assert_str_eq(test_str_467, test_str_467_467);
}
END_TEST

START_TEST(sprintf_test_468) {
  char test_str_468[50] = "";
  char test_str_468_468[50] = "";
  s21_sprintf(test_str_468, "%-10u", 43);
  sprintf(test_str_468_468, "%-10u", 43);
  ck_assert_str_eq(test_str_468, test_str_468_468);
}
END_TEST

START_TEST(sprintf_test_487) {
  char test_str_487[50] = "";
  char test_str_487_487[50] = "";
  s21_sprintf(test_str_487, "%-20d", 0);
  sprintf(test_str_487_487, "%-20d", 0);
  ck_assert_str_eq(test_str_487, test_str_487_487);
}
END_TEST

START_TEST(sprintf_test_488) {
  char test_str_488[50] = "";
  char test_str_488_488[50] = "";
  s21_sprintf(test_str_488, "%-20d", 1);
  sprintf(test_str_488_488, "%-20d", 1);
  ck_assert_str_eq(test_str_488, test_str_488_488);
}
END_TEST

START_TEST(sprintf_test_489) {
  char test_str_489[50] = "";
  char test_str_489_489[50] = "";
  s21_sprintf(test_str_489, "%-20d", 10);
  sprintf(test_str_489_489, "%-20d", 10);
  ck_assert_str_eq(test_str_489, test_str_489_489);
}
END_TEST

START_TEST(sprintf_test_490) {
  char test_str_490[50] = "";
  char test_str_490_490[50] = "";
  s21_sprintf(test_str_490, "%-20d", 123456);
  sprintf(test_str_490_490, "%-20d", 123456);
  ck_assert_str_eq(test_str_490, test_str_490_490);
}
END_TEST

START_TEST(sprintf_test_491) {
  char test_str_491[50] = "";
  char test_str_491_491[50] = "";
  s21_sprintf(test_str_491, "%-20d", -67890123);
  sprintf(test_str_491_491, "%-20d", -67890123);
  ck_assert_str_eq(test_str_491, test_str_491_491);
}
END_TEST

START_TEST(sprintf_test_492) {
  char test_str_492[50] = "";
  char test_str_492_492[50] = "";
  s21_sprintf(test_str_492, "%-20d", 4343);
  sprintf(test_str_492_492, "%-20d", 4343);
  ck_assert_str_eq(test_str_492, test_str_492_492);
}
END_TEST

START_TEST(sprintf_test_493) {
  char test_str_493[50] = "";
  char test_str_493_493[50] = "";
  s21_sprintf(test_str_493, "%-20d", -1);
  sprintf(test_str_493_493, "%-20d", -1);
  ck_assert_str_eq(test_str_493, test_str_493_493);
}
END_TEST

START_TEST(sprintf_test_494) {
  char test_str_494[50] = "";
  char test_str_494_494[50] = "";
  s21_sprintf(test_str_494, "%-20d", -10);
  sprintf(test_str_494_494, "%-20d", -10);
  ck_assert_str_eq(test_str_494, test_str_494_494);
}
END_TEST

START_TEST(sprintf_test_495) {
  char test_str_495[50] = "";
  char test_str_495_495[50] = "";
  s21_sprintf(test_str_495, "%-20d", 43);
  sprintf(test_str_495_495, "%-20d", 43);
  ck_assert_str_eq(test_str_495, test_str_495_495);
}
END_TEST

START_TEST(sprintf_test_496) {
  char test_str_496[50] = "";
  char test_str_496_496[50] = "";
  s21_sprintf(test_str_496, "%-20i", 0);
  sprintf(test_str_496_496, "%-20i", 0);
  ck_assert_str_eq(test_str_496, test_str_496_496);
}
END_TEST

START_TEST(sprintf_test_497) {
  char test_str_497[50] = "";
  char test_str_497_497[50] = "";
  s21_sprintf(test_str_497, "%-20i", 1);
  sprintf(test_str_497_497, "%-20i", 1);
  ck_assert_str_eq(test_str_497, test_str_497_497);
}
END_TEST

START_TEST(sprintf_test_498) {
  char test_str_498[50] = "";
  char test_str_498_498[50] = "";
  s21_sprintf(test_str_498, "%-20i", 10);
  sprintf(test_str_498_498, "%-20i", 10);
  ck_assert_str_eq(test_str_498, test_str_498_498);
}
END_TEST

START_TEST(sprintf_test_499) {
  char test_str_499[50] = "";
  char test_str_499_499[50] = "";
  s21_sprintf(test_str_499, "%-20i", 123456);
  sprintf(test_str_499_499, "%-20i", 123456);
  ck_assert_str_eq(test_str_499, test_str_499_499);
}
END_TEST

START_TEST(sprintf_test_500) {
  char test_str_500[50] = "";
  char test_str_500_500[50] = "";
  s21_sprintf(test_str_500, "%-20i", -67890123);
  sprintf(test_str_500_500, "%-20i", -67890123);
  ck_assert_str_eq(test_str_500, test_str_500_500);
}
END_TEST

START_TEST(sprintf_test_501) {
  char test_str_501[50] = "";
  char test_str_501_501[50] = "";
  s21_sprintf(test_str_501, "%-20i", 4343);
  sprintf(test_str_501_501, "%-20i", 4343);
  ck_assert_str_eq(test_str_501, test_str_501_501);
}
END_TEST

START_TEST(sprintf_test_502) {
  char test_str_502[50] = "";
  char test_str_502_502[50] = "";
  s21_sprintf(test_str_502, "%-20i", -1);
  sprintf(test_str_502_502, "%-20i", -1);
  ck_assert_str_eq(test_str_502, test_str_502_502);
}
END_TEST

START_TEST(sprintf_test_503) {
  char test_str_503[50] = "";
  char test_str_503_503[50] = "";
  s21_sprintf(test_str_503, "%-20i", -10);
  sprintf(test_str_503_503, "%-20i", -10);
  ck_assert_str_eq(test_str_503, test_str_503_503);
}
END_TEST

START_TEST(sprintf_test_504) {
  char test_str_504[50] = "";
  char test_str_504_504[50] = "";
  s21_sprintf(test_str_504, "%-20i", 43);
  sprintf(test_str_504_504, "%-20i", 43);
  ck_assert_str_eq(test_str_504, test_str_504_504);
}
END_TEST

START_TEST(sprintf_test_514) {
  char test_str_514[50] = "";
  char test_str_514_514[50] = "";
  s21_sprintf(test_str_514, "%-20u", 0);
  sprintf(test_str_514_514, "%-20u", 0);
  ck_assert_str_eq(test_str_514, test_str_514_514);
}
END_TEST

START_TEST(sprintf_test_515) {
  char test_str_515[50] = "";
  char test_str_515_515[50] = "";
  s21_sprintf(test_str_515, "%-20u", 1);
  sprintf(test_str_515_515, "%-20u", 1);
  ck_assert_str_eq(test_str_515, test_str_515_515);
}
END_TEST

START_TEST(sprintf_test_516) {
  char test_str_516[50] = "";
  char test_str_516_516[50] = "";
  s21_sprintf(test_str_516, "%-20u", 10);
  sprintf(test_str_516_516, "%-20u", 10);
  ck_assert_str_eq(test_str_516, test_str_516_516);
}
END_TEST

START_TEST(sprintf_test_517) {
  char test_str_517[50] = "";
  char test_str_517_517[50] = "";
  s21_sprintf(test_str_517, "%-20u", 123456);
  sprintf(test_str_517_517, "%-20u", 123456);
  ck_assert_str_eq(test_str_517, test_str_517_517);
}
END_TEST

START_TEST(sprintf_test_518) {
  char test_str_518[50] = "";
  char test_str_518_518[50] = "";
  s21_sprintf(test_str_518, "%-20u", -67890123);
  sprintf(test_str_518_518, "%-20u", -67890123);
  ck_assert_str_eq(test_str_518, test_str_518_518);
}
END_TEST

START_TEST(sprintf_test_519) {
  char test_str_519[50] = "";
  char test_str_519_519[50] = "";
  s21_sprintf(test_str_519, "%-20u", 4343);
  sprintf(test_str_519_519, "%-20u", 4343);
  ck_assert_str_eq(test_str_519, test_str_519_519);
}
END_TEST

START_TEST(sprintf_test_520) {
  char test_str_520[50] = "";
  char test_str_520_520[50] = "";
  s21_sprintf(test_str_520, "%-20u", -1);
  sprintf(test_str_520_520, "%-20u", -1);
  ck_assert_str_eq(test_str_520, test_str_520_520);
}
END_TEST

START_TEST(sprintf_test_521) {
  char test_str_521[50] = "";
  char test_str_521_521[50] = "";
  s21_sprintf(test_str_521, "%-20u", -10);
  sprintf(test_str_521_521, "%-20u", -10);
  ck_assert_str_eq(test_str_521, test_str_521_521);
}
END_TEST

START_TEST(sprintf_test_522) {
  char test_str_522[50] = "";
  char test_str_522_522[50] = "";
  s21_sprintf(test_str_522, "%-20u", 43);
  sprintf(test_str_522_522, "%-20u", 43);
  ck_assert_str_eq(test_str_522, test_str_522_522);
}
END_TEST

START_TEST(sprintf_test_811) {
  char test_str_811[50] = "";
  char test_str_811_811[50] = "";
  s21_sprintf(test_str_811, "%.0d", 0);
  sprintf(test_str_811_811, "%.0d", 0);
  ck_assert_str_eq(test_str_811, test_str_811_811);
}
END_TEST

START_TEST(sprintf_test_812) {
  char test_str_812[50] = "";
  char test_str_812_812[50] = "";
  s21_sprintf(test_str_812, "%.0d", 1);
  sprintf(test_str_812_812, "%.0d", 1);
  ck_assert_str_eq(test_str_812, test_str_812_812);
}
END_TEST

START_TEST(sprintf_test_813) {
  char test_str_813[50] = "";
  char test_str_813_813[50] = "";
  s21_sprintf(test_str_813, "%.0d", 10);
  sprintf(test_str_813_813, "%.0d", 10);
  ck_assert_str_eq(test_str_813, test_str_813_813);
}
END_TEST

START_TEST(sprintf_test_814) {
  char test_str_814[50] = "";
  char test_str_814_814[50] = "";
  s21_sprintf(test_str_814, "%.0d", 123456);
  sprintf(test_str_814_814, "%.0d", 123456);
  ck_assert_str_eq(test_str_814, test_str_814_814);
}
END_TEST

START_TEST(sprintf_test_815) {
  char test_str_815[50] = "";
  char test_str_815_815[50] = "";
  s21_sprintf(test_str_815, "%.0d", -67890123);
  sprintf(test_str_815_815, "%.0d", -67890123);
  ck_assert_str_eq(test_str_815, test_str_815_815);
}
END_TEST

START_TEST(sprintf_test_816) {
  char test_str_816[50] = "";
  char test_str_816_816[50] = "";
  s21_sprintf(test_str_816, "%.0d", 4343);
  sprintf(test_str_816_816, "%.0d", 4343);
  ck_assert_str_eq(test_str_816, test_str_816_816);
}
END_TEST

START_TEST(sprintf_test_817) {
  char test_str_817[50] = "";
  char test_str_817_817[50] = "";
  s21_sprintf(test_str_817, "%.0d", -1);
  sprintf(test_str_817_817, "%.0d", -1);
  ck_assert_str_eq(test_str_817, test_str_817_817);
}
END_TEST

START_TEST(sprintf_test_818) {
  char test_str_818[50] = "";
  char test_str_818_818[50] = "";
  s21_sprintf(test_str_818, "%.0d", -10);
  sprintf(test_str_818_818, "%.0d", -10);
  ck_assert_str_eq(test_str_818, test_str_818_818);
}
END_TEST

START_TEST(sprintf_test_819) {
  char test_str_819[50] = "";
  char test_str_819_819[50] = "";
  s21_sprintf(test_str_819, "%.0d", 43);
  sprintf(test_str_819_819, "%.0d", 43);
  ck_assert_str_eq(test_str_819, test_str_819_819);
}
END_TEST

START_TEST(sprintf_test_820) {
  char test_str_820[50] = "";
  char test_str_820_820[50] = "";
  s21_sprintf(test_str_820, "%.0i", 0);
  sprintf(test_str_820_820, "%.0i", 0);
  ck_assert_str_eq(test_str_820, test_str_820_820);
}
END_TEST

START_TEST(sprintf_test_821) {
  char test_str_821[50] = "";
  char test_str_821_821[50] = "";
  s21_sprintf(test_str_821, "%.0i", 1);
  sprintf(test_str_821_821, "%.0i", 1);
  ck_assert_str_eq(test_str_821, test_str_821_821);
}
END_TEST

START_TEST(sprintf_test_822) {
  char test_str_822[50] = "";
  char test_str_822_822[50] = "";
  s21_sprintf(test_str_822, "%.0i", 10);
  sprintf(test_str_822_822, "%.0i", 10);
  ck_assert_str_eq(test_str_822, test_str_822_822);
}
END_TEST

START_TEST(sprintf_test_823) {
  char test_str_823[50] = "";
  char test_str_823_823[50] = "";
  s21_sprintf(test_str_823, "%.0i", 123456);
  sprintf(test_str_823_823, "%.0i", 123456);
  ck_assert_str_eq(test_str_823, test_str_823_823);
}
END_TEST

START_TEST(sprintf_test_824) {
  char test_str_824[50] = "";
  char test_str_824_824[50] = "";
  s21_sprintf(test_str_824, "%.0i", -67890123);
  sprintf(test_str_824_824, "%.0i", -67890123);
  ck_assert_str_eq(test_str_824, test_str_824_824);
}
END_TEST

START_TEST(sprintf_test_825) {
  char test_str_825[50] = "";
  char test_str_825_825[50] = "";
  s21_sprintf(test_str_825, "%.0i", 4343);
  sprintf(test_str_825_825, "%.0i", 4343);
  ck_assert_str_eq(test_str_825, test_str_825_825);
}
END_TEST

START_TEST(sprintf_test_826) {
  char test_str_826[50] = "";
  char test_str_826_826[50] = "";
  s21_sprintf(test_str_826, "%.0i", -1);
  sprintf(test_str_826_826, "%.0i", -1);
  ck_assert_str_eq(test_str_826, test_str_826_826);
}
END_TEST

START_TEST(sprintf_test_827) {
  char test_str_827[50] = "";
  char test_str_827_827[50] = "";
  s21_sprintf(test_str_827, "%.0i", -10);
  sprintf(test_str_827_827, "%.0i", -10);
  ck_assert_str_eq(test_str_827, test_str_827_827);
}
END_TEST

START_TEST(sprintf_test_828) {
  char test_str_828[50] = "";
  char test_str_828_828[50] = "";
  s21_sprintf(test_str_828, "%.0i", 43);
  sprintf(test_str_828_828, "%.0i", 43);
  ck_assert_str_eq(test_str_828, test_str_828_828);
}
END_TEST

START_TEST(sprintf_test_838) {
  char test_str_838[50] = "";
  char test_str_838_838[50] = "";
  s21_sprintf(test_str_838, "%.0u", 0);
  sprintf(test_str_838_838, "%.0u", 0);
  ck_assert_str_eq(test_str_838, test_str_838_838);
}
END_TEST

START_TEST(sprintf_test_839) {
  char test_str_839[50] = "";
  char test_str_839_839[50] = "";
  s21_sprintf(test_str_839, "%.0u", 1);
  sprintf(test_str_839_839, "%.0u", 1);
  ck_assert_str_eq(test_str_839, test_str_839_839);
}
END_TEST

START_TEST(sprintf_test_840) {
  char test_str_840[50] = "";
  char test_str_840_840[50] = "";
  s21_sprintf(test_str_840, "%.0u", 10);
  sprintf(test_str_840_840, "%.0u", 10);
  ck_assert_str_eq(test_str_840, test_str_840_840);
}
END_TEST

START_TEST(sprintf_test_841) {
  char test_str_841[50] = "";
  char test_str_841_841[50] = "";
  s21_sprintf(test_str_841, "%.0u", 123456);
  sprintf(test_str_841_841, "%.0u", 123456);
  ck_assert_str_eq(test_str_841, test_str_841_841);
}
END_TEST

START_TEST(sprintf_test_842) {
  char test_str_842[50] = "";
  char test_str_842_842[50] = "";
  s21_sprintf(test_str_842, "%.0u", -67890123);
  sprintf(test_str_842_842, "%.0u", -67890123);
  ck_assert_str_eq(test_str_842, test_str_842_842);
}
END_TEST

START_TEST(sprintf_test_843) {
  char test_str_843[50] = "";
  char test_str_843_843[50] = "";
  s21_sprintf(test_str_843, "%.0u", 4343);
  sprintf(test_str_843_843, "%.0u", 4343);
  ck_assert_str_eq(test_str_843, test_str_843_843);
}
END_TEST

START_TEST(sprintf_test_844) {
  char test_str_844[50] = "";
  char test_str_844_844[50] = "";
  s21_sprintf(test_str_844, "%.0u", -1);
  sprintf(test_str_844_844, "%.0u", -1);
  ck_assert_str_eq(test_str_844, test_str_844_844);
}
END_TEST

START_TEST(sprintf_test_845) {
  char test_str_845[50] = "";
  char test_str_845_845[50] = "";
  s21_sprintf(test_str_845, "%.0u", -10);
  sprintf(test_str_845_845, "%.0u", -10);
  ck_assert_str_eq(test_str_845, test_str_845_845);
}
END_TEST

START_TEST(sprintf_test_846) {
  char test_str_846[50] = "";
  char test_str_846_846[50] = "";
  s21_sprintf(test_str_846, "%.0u", 43);
  sprintf(test_str_846_846, "%.0u", 43);
  ck_assert_str_eq(test_str_846, test_str_846_846);
}
END_TEST

START_TEST(sprintf_test_865) {
  char test_str_865[50] = "";
  char test_str_865_865[50] = "";
  s21_sprintf(test_str_865, "%.10d", 0);
  sprintf(test_str_865_865, "%.10d", 0);
  ck_assert_str_eq(test_str_865, test_str_865_865);
}
END_TEST

START_TEST(sprintf_test_866) {
  char test_str_866[50] = "";
  char test_str_866_866[50] = "";
  s21_sprintf(test_str_866, "%.10d", 1);
  sprintf(test_str_866_866, "%.10d", 1);
  ck_assert_str_eq(test_str_866, test_str_866_866);
}
END_TEST

START_TEST(sprintf_test_867) {
  char test_str_867[50] = "";
  char test_str_867_867[50] = "";
  s21_sprintf(test_str_867, "%.10d", 10);
  sprintf(test_str_867_867, "%.10d", 10);
  ck_assert_str_eq(test_str_867, test_str_867_867);
}
END_TEST

START_TEST(sprintf_test_868) {
  char test_str_868[50] = "";
  char test_str_868_868[50] = "";
  s21_sprintf(test_str_868, "%.10d", 123456);
  sprintf(test_str_868_868, "%.10d", 123456);
  ck_assert_str_eq(test_str_868, test_str_868_868);
}
END_TEST

START_TEST(sprintf_test_869) {
  char test_str_869[50] = "";
  char test_str_869_869[50] = "";
  s21_sprintf(test_str_869, "%.10d", -67890123);
  sprintf(test_str_869_869, "%.10d", -67890123);
  ck_assert_str_eq(test_str_869, test_str_869_869);
}
END_TEST

START_TEST(sprintf_test_870) {
  char test_str_870[50] = "";
  char test_str_870_870[50] = "";
  s21_sprintf(test_str_870, "%.10d", 4343);
  sprintf(test_str_870_870, "%.10d", 4343);
  ck_assert_str_eq(test_str_870, test_str_870_870);
}
END_TEST

START_TEST(sprintf_test_871) {
  char test_str_871[50] = "";
  char test_str_871_871[50] = "";
  s21_sprintf(test_str_871, "%.10d", -1);
  sprintf(test_str_871_871, "%.10d", -1);
  ck_assert_str_eq(test_str_871, test_str_871_871);
}
END_TEST

START_TEST(sprintf_test_872) {
  char test_str_872[50] = "";
  char test_str_872_872[50] = "";
  s21_sprintf(test_str_872, "%.10d", -10);
  sprintf(test_str_872_872, "%.10d", -10);
  ck_assert_str_eq(test_str_872, test_str_872_872);
}
END_TEST

START_TEST(sprintf_test_873) {
  char test_str_873[50] = "";
  char test_str_873_873[50] = "";
  s21_sprintf(test_str_873, "%.10d", 43);
  sprintf(test_str_873_873, "%.10d", 43);
  ck_assert_str_eq(test_str_873, test_str_873_873);
}
END_TEST

START_TEST(sprintf_test_874) {
  char test_str_874[50] = "";
  char test_str_874_874[50] = "";
  s21_sprintf(test_str_874, "%.10i", 0);
  sprintf(test_str_874_874, "%.10i", 0);
  ck_assert_str_eq(test_str_874, test_str_874_874);
}
END_TEST

START_TEST(sprintf_test_875) {
  char test_str_875[50] = "";
  char test_str_875_875[50] = "";
  s21_sprintf(test_str_875, "%.10i", 1);
  sprintf(test_str_875_875, "%.10i", 1);
  ck_assert_str_eq(test_str_875, test_str_875_875);
}
END_TEST

START_TEST(sprintf_test_876) {
  char test_str_876[50] = "";
  char test_str_876_876[50] = "";
  s21_sprintf(test_str_876, "%.10i", 10);
  sprintf(test_str_876_876, "%.10i", 10);
  ck_assert_str_eq(test_str_876, test_str_876_876);
}
END_TEST

START_TEST(sprintf_test_877) {
  char test_str_877[50] = "";
  char test_str_877_877[50] = "";
  s21_sprintf(test_str_877, "%.10i", 123456);
  sprintf(test_str_877_877, "%.10i", 123456);
  ck_assert_str_eq(test_str_877, test_str_877_877);
}
END_TEST

START_TEST(sprintf_test_878) {
  char test_str_878[50] = "";
  char test_str_878_878[50] = "";
  s21_sprintf(test_str_878, "%.10i", -67890123);
  sprintf(test_str_878_878, "%.10i", -67890123);
  ck_assert_str_eq(test_str_878, test_str_878_878);
}
END_TEST

START_TEST(sprintf_test_879) {
  char test_str_879[50] = "";
  char test_str_879_879[50] = "";
  s21_sprintf(test_str_879, "%.10i", 4343);
  sprintf(test_str_879_879, "%.10i", 4343);
  ck_assert_str_eq(test_str_879, test_str_879_879);
}
END_TEST

START_TEST(sprintf_test_880) {
  char test_str_880[50] = "";
  char test_str_880_880[50] = "";
  s21_sprintf(test_str_880, "%.10i", -1);
  sprintf(test_str_880_880, "%.10i", -1);
  ck_assert_str_eq(test_str_880, test_str_880_880);
}
END_TEST

START_TEST(sprintf_test_881) {
  char test_str_881[50] = "";
  char test_str_881_881[50] = "";
  s21_sprintf(test_str_881, "%.10i", -10);
  sprintf(test_str_881_881, "%.10i", -10);
  ck_assert_str_eq(test_str_881, test_str_881_881);
}
END_TEST

START_TEST(sprintf_test_882) {
  char test_str_882[50] = "";
  char test_str_882_882[50] = "";
  s21_sprintf(test_str_882, "%.10i", 43);
  sprintf(test_str_882_882, "%.10i", 43);
  ck_assert_str_eq(test_str_882, test_str_882_882);
}
END_TEST

START_TEST(sprintf_test_892) {
  char test_str_892[50] = "";
  char test_str_892_892[50] = "";
  s21_sprintf(test_str_892, "%.10u", 0);
  sprintf(test_str_892_892, "%.10u", 0);
  ck_assert_str_eq(test_str_892, test_str_892_892);
}
END_TEST

START_TEST(sprintf_test_893) {
  char test_str_893[50] = "";
  char test_str_893_893[50] = "";
  s21_sprintf(test_str_893, "%.10u", 1);
  sprintf(test_str_893_893, "%.10u", 1);
  ck_assert_str_eq(test_str_893, test_str_893_893);
}
END_TEST

START_TEST(sprintf_test_894) {
  char test_str_894[50] = "";
  char test_str_894_894[50] = "";
  s21_sprintf(test_str_894, "%.10u", 10);
  sprintf(test_str_894_894, "%.10u", 10);
  ck_assert_str_eq(test_str_894, test_str_894_894);
}
END_TEST

START_TEST(sprintf_test_895) {
  char test_str_895[50] = "";
  char test_str_895_895[50] = "";
  s21_sprintf(test_str_895, "%.10u", 123456);
  sprintf(test_str_895_895, "%.10u", 123456);
  ck_assert_str_eq(test_str_895, test_str_895_895);
}
END_TEST

START_TEST(sprintf_test_896) {
  char test_str_896[50] = "";
  char test_str_896_896[50] = "";
  s21_sprintf(test_str_896, "%.10u", -67890123);
  sprintf(test_str_896_896, "%.10u", -67890123);
  ck_assert_str_eq(test_str_896, test_str_896_896);
}
END_TEST

START_TEST(sprintf_test_897) {
  char test_str_897[50] = "";
  char test_str_897_897[50] = "";
  s21_sprintf(test_str_897, "%.10u", 4343);
  sprintf(test_str_897_897, "%.10u", 4343);
  ck_assert_str_eq(test_str_897, test_str_897_897);
}
END_TEST

START_TEST(sprintf_test_898) {
  char test_str_898[50] = "";
  char test_str_898_898[50] = "";
  s21_sprintf(test_str_898, "%.10u", -1);
  sprintf(test_str_898_898, "%.10u", -1);
  ck_assert_str_eq(test_str_898, test_str_898_898);
}
END_TEST

START_TEST(sprintf_test_899) {
  char test_str_899[50] = "";
  char test_str_899_899[50] = "";
  s21_sprintf(test_str_899, "%.10u", -10);
  sprintf(test_str_899_899, "%.10u", -10);
  ck_assert_str_eq(test_str_899, test_str_899_899);
}
END_TEST

START_TEST(sprintf_test_900) {
  char test_str_900[50] = "";
  char test_str_900_900[50] = "";
  s21_sprintf(test_str_900, "%.10u", 43);
  sprintf(test_str_900_900, "%.10u", 43);
  ck_assert_str_eq(test_str_900, test_str_900_900);
}
END_TEST

START_TEST(sprintf_test_919) {
  char test_str_919[50] = "";
  char test_str_919_919[50] = "";
  s21_sprintf(test_str_919, "%.20d", 0);
  sprintf(test_str_919_919, "%.20d", 0);
  ck_assert_str_eq(test_str_919, test_str_919_919);
}
END_TEST

START_TEST(sprintf_test_920) {
  char test_str_920[50] = "";
  char test_str_920_920[50] = "";
  s21_sprintf(test_str_920, "%.20d", 1);
  sprintf(test_str_920_920, "%.20d", 1);
  ck_assert_str_eq(test_str_920, test_str_920_920);
}
END_TEST

START_TEST(sprintf_test_921) {
  char test_str_921[50] = "";
  char test_str_921_921[50] = "";
  s21_sprintf(test_str_921, "%.20d", 10);
  sprintf(test_str_921_921, "%.20d", 10);
  ck_assert_str_eq(test_str_921, test_str_921_921);
}
END_TEST

START_TEST(sprintf_test_922) {
  char test_str_922[50] = "";
  char test_str_922_922[50] = "";
  s21_sprintf(test_str_922, "%.20d", 123456);
  sprintf(test_str_922_922, "%.20d", 123456);
  ck_assert_str_eq(test_str_922, test_str_922_922);
}
END_TEST

START_TEST(sprintf_test_923) {
  char test_str_923[50] = "";
  char test_str_923_923[50] = "";
  s21_sprintf(test_str_923, "%.20d", -67890123);
  sprintf(test_str_923_923, "%.20d", -67890123);
  ck_assert_str_eq(test_str_923, test_str_923_923);
}
END_TEST

START_TEST(sprintf_test_924) {
  char test_str_924[50] = "";
  char test_str_924_924[50] = "";
  s21_sprintf(test_str_924, "%.20d", 4343);
  sprintf(test_str_924_924, "%.20d", 4343);
  ck_assert_str_eq(test_str_924, test_str_924_924);
}
END_TEST

START_TEST(sprintf_test_925) {
  char test_str_925[50] = "";
  char test_str_925_925[50] = "";
  s21_sprintf(test_str_925, "%.20d", -1);
  sprintf(test_str_925_925, "%.20d", -1);
  ck_assert_str_eq(test_str_925, test_str_925_925);
}
END_TEST

START_TEST(sprintf_test_926) {
  char test_str_926[50] = "";
  char test_str_926_926[50] = "";
  s21_sprintf(test_str_926, "%.20d", -10);
  sprintf(test_str_926_926, "%.20d", -10);
  ck_assert_str_eq(test_str_926, test_str_926_926);
}
END_TEST

START_TEST(sprintf_test_927) {
  char test_str_927[50] = "";
  char test_str_927_927[50] = "";
  s21_sprintf(test_str_927, "%.20d", 43);
  sprintf(test_str_927_927, "%.20d", 43);
  ck_assert_str_eq(test_str_927, test_str_927_927);
}
END_TEST

START_TEST(sprintf_test_928) {
  char test_str_928[50] = "";
  char test_str_928_928[50] = "";
  s21_sprintf(test_str_928, "%.20i", 0);
  sprintf(test_str_928_928, "%.20i", 0);
  ck_assert_str_eq(test_str_928, test_str_928_928);
}
END_TEST

START_TEST(sprintf_test_929) {
  char test_str_929[50] = "";
  char test_str_929_929[50] = "";
  s21_sprintf(test_str_929, "%.20i", 1);
  sprintf(test_str_929_929, "%.20i", 1);
  ck_assert_str_eq(test_str_929, test_str_929_929);
}
END_TEST

START_TEST(sprintf_test_930) {
  char test_str_930[50] = "";
  char test_str_930_930[50] = "";
  s21_sprintf(test_str_930, "%.20i", 10);
  sprintf(test_str_930_930, "%.20i", 10);
  ck_assert_str_eq(test_str_930, test_str_930_930);
}
END_TEST

START_TEST(sprintf_test_931) {
  char test_str_931[50] = "";
  char test_str_931_931[50] = "";
  s21_sprintf(test_str_931, "%.20i", 123456);
  sprintf(test_str_931_931, "%.20i", 123456);
  ck_assert_str_eq(test_str_931, test_str_931_931);
}
END_TEST

START_TEST(sprintf_test_932) {
  char test_str_932[50] = "";
  char test_str_932_932[50] = "";
  s21_sprintf(test_str_932, "%.20i", -67890123);
  sprintf(test_str_932_932, "%.20i", -67890123);
  ck_assert_str_eq(test_str_932, test_str_932_932);
}
END_TEST

START_TEST(sprintf_test_933) {
  char test_str_933[50] = "";
  char test_str_933_933[50] = "";
  s21_sprintf(test_str_933, "%.20i", 4343);
  sprintf(test_str_933_933, "%.20i", 4343);
  ck_assert_str_eq(test_str_933, test_str_933_933);
}
END_TEST

START_TEST(sprintf_test_934) {
  char test_str_934[50] = "";
  char test_str_934_934[50] = "";
  s21_sprintf(test_str_934, "%.20i", -1);
  sprintf(test_str_934_934, "%.20i", -1);
  ck_assert_str_eq(test_str_934, test_str_934_934);
}
END_TEST

START_TEST(sprintf_test_935) {
  char test_str_935[50] = "";
  char test_str_935_935[50] = "";
  s21_sprintf(test_str_935, "%.20i", -10);
  sprintf(test_str_935_935, "%.20i", -10);
  ck_assert_str_eq(test_str_935, test_str_935_935);
}
END_TEST

START_TEST(sprintf_test_936) {
  char test_str_936[50] = "";
  char test_str_936_936[50] = "";
  s21_sprintf(test_str_936, "%.20i", 43);
  sprintf(test_str_936_936, "%.20i", 43);
  ck_assert_str_eq(test_str_936, test_str_936_936);
}
END_TEST

START_TEST(sprintf_test_946) {
  char test_str_946[50] = "";
  char test_str_946_946[50] = "";
  s21_sprintf(test_str_946, "%.20u", 0);
  sprintf(test_str_946_946, "%.20u", 0);
  ck_assert_str_eq(test_str_946, test_str_946_946);
}
END_TEST

START_TEST(sprintf_test_947) {
  char test_str_947[50] = "";
  char test_str_947_947[50] = "";
  s21_sprintf(test_str_947, "%.20u", 1);
  sprintf(test_str_947_947, "%.20u", 1);
  ck_assert_str_eq(test_str_947, test_str_947_947);
}
END_TEST

START_TEST(sprintf_test_948) {
  char test_str_948[50] = "";
  char test_str_948_948[50] = "";
  s21_sprintf(test_str_948, "%.20u", 10);
  sprintf(test_str_948_948, "%.20u", 10);
  ck_assert_str_eq(test_str_948, test_str_948_948);
}
END_TEST

START_TEST(sprintf_test_949) {
  char test_str_949[50] = "";
  char test_str_949_949[50] = "";
  s21_sprintf(test_str_949, "%.20u", 123456);
  sprintf(test_str_949_949, "%.20u", 123456);
  ck_assert_str_eq(test_str_949, test_str_949_949);
}
END_TEST

START_TEST(sprintf_test_950) {
  char test_str_950[50] = "";
  char test_str_950_950[50] = "";
  s21_sprintf(test_str_950, "%.20u", -67890123);
  sprintf(test_str_950_950, "%.20u", -67890123);
  ck_assert_str_eq(test_str_950, test_str_950_950);
}
END_TEST

START_TEST(sprintf_test_951) {
  char test_str_951[50] = "";
  char test_str_951_951[50] = "";
  s21_sprintf(test_str_951, "%.20u", 4343);
  sprintf(test_str_951_951, "%.20u", 4343);
  ck_assert_str_eq(test_str_951, test_str_951_951);
}
END_TEST

START_TEST(sprintf_test_952) {
  char test_str_952[50] = "";
  char test_str_952_952[50] = "";
  s21_sprintf(test_str_952, "%.20u", -1);
  sprintf(test_str_952_952, "%.20u", -1);
  ck_assert_str_eq(test_str_952, test_str_952_952);
}
END_TEST

START_TEST(sprintf_test_953) {
  char test_str_953[50] = "";
  char test_str_953_953[50] = "";
  s21_sprintf(test_str_953, "%.20u", -10);
  sprintf(test_str_953_953, "%.20u", -10);
  ck_assert_str_eq(test_str_953, test_str_953_953);
}
END_TEST

START_TEST(sprintf_test_954) {
  char test_str_954[50] = "";
  char test_str_954_954[50] = "";
  s21_sprintf(test_str_954, "%.20u", 43);
  sprintf(test_str_954_954, "%.20u", 43);
  ck_assert_str_eq(test_str_954, test_str_954_954);
}
END_TEST

START_TEST(sprintf_test_1081) {
  char test_str_1081[50] = "";
  char test_str_1081_1081[50] = "";
  s21_sprintf(test_str_1081, "%d", 0);
  sprintf(test_str_1081_1081, "%d", 0);
  ck_assert_str_eq(test_str_1081, test_str_1081_1081);
}
END_TEST

START_TEST(sprintf_test_1082) {
  char test_str_1082[50] = "";
  char test_str_1082_1082[50] = "";
  s21_sprintf(test_str_1082, "%d", 1);
  sprintf(test_str_1082_1082, "%d", 1);
  ck_assert_str_eq(test_str_1082, test_str_1082_1082);
}
END_TEST

START_TEST(sprintf_test_1083) {
  char test_str_1083[50] = "";
  char test_str_1083_1083[50] = "";
  s21_sprintf(test_str_1083, "%d", 10);
  sprintf(test_str_1083_1083, "%d", 10);
  ck_assert_str_eq(test_str_1083, test_str_1083_1083);
}
END_TEST

START_TEST(sprintf_test_1084) {
  char test_str_1084[50] = "";
  char test_str_1084_1084[50] = "";
  s21_sprintf(test_str_1084, "%d", 123456);
  sprintf(test_str_1084_1084, "%d", 123456);
  ck_assert_str_eq(test_str_1084, test_str_1084_1084);
}
END_TEST

START_TEST(sprintf_test_1085) {
  char test_str_1085[50] = "";
  char test_str_1085_1085[50] = "";
  s21_sprintf(test_str_1085, "%d", -678901);
  sprintf(test_str_1085_1085, "%d", -678901);
  ck_assert_str_eq(test_str_1085, test_str_1085_1085);
}
END_TEST

START_TEST(sprintf_test_1086) {
  char test_str_1086[50] = "";
  char test_str_1086_1086[50] = "";
  s21_sprintf(test_str_1086, "%d", 4343);
  sprintf(test_str_1086_1086, "%d", 4343);
  ck_assert_str_eq(test_str_1086, test_str_1086_1086);
}
END_TEST

START_TEST(sprintf_test_1087) {
  char test_str_1087[50] = "";
  char test_str_1087_1087[50] = "";
  s21_sprintf(test_str_1087, "%d", -1);
  sprintf(test_str_1087_1087, "%d", -1);
  ck_assert_str_eq(test_str_1087, test_str_1087_1087);
}
END_TEST

START_TEST(sprintf_test_1088) {
  char test_str_1088[50] = "";
  char test_str_1088_1088[50] = "";
  s21_sprintf(test_str_1088, "%d", -10);
  sprintf(test_str_1088_1088, "%d", -10);
  ck_assert_str_eq(test_str_1088, test_str_1088_1088);
}
END_TEST

START_TEST(sprintf_test_1089) {
  char test_str_1089[50] = "";
  char test_str_1089_1089[50] = "";
  s21_sprintf(test_str_1089, "%d", 43);
  sprintf(test_str_1089_1089, "%d", 43);
  ck_assert_str_eq(test_str_1089, test_str_1089_1089);
}
END_TEST

START_TEST(sprintf_test_1090) {
  char test_str_1090[50] = "";
  char test_str_1090_1090[50] = "";
  s21_sprintf(test_str_1090, "%i", 0);
  sprintf(test_str_1090_1090, "%i", 0);
  ck_assert_str_eq(test_str_1090, test_str_1090_1090);
}
END_TEST

START_TEST(sprintf_test_1091) {
  char test_str_1091[50] = "";
  char test_str_1091_1091[50] = "";
  s21_sprintf(test_str_1091, "%i", 1);
  sprintf(test_str_1091_1091, "%i", 1);
  ck_assert_str_eq(test_str_1091, test_str_1091_1091);
}
END_TEST

START_TEST(sprintf_test_1092) {
  char test_str_1092[50] = "";
  char test_str_1092_1092[50] = "";
  s21_sprintf(test_str_1092, "%i", 10);
  sprintf(test_str_1092_1092, "%i", 10);
  ck_assert_str_eq(test_str_1092, test_str_1092_1092);
}
END_TEST

START_TEST(sprintf_test_1093) {
  char test_str_1093[50] = "";
  char test_str_1093_1093[50] = "";
  s21_sprintf(test_str_1093, "%i", 123456);
  sprintf(test_str_1093_1093, "%i", 123456);
  ck_assert_str_eq(test_str_1093, test_str_1093_1093);
}
END_TEST

START_TEST(sprintf_test_1094) {
  char test_str_1094[50] = "";
  char test_str_1094_1094[50] = "";
  s21_sprintf(test_str_1094, "%i", -678901);
  sprintf(test_str_1094_1094, "%i", -678901);
  ck_assert_str_eq(test_str_1094, test_str_1094_1094);
}
END_TEST

START_TEST(sprintf_test_1095) {
  char test_str_1095[50] = "";
  char test_str_1095_1095[50] = "";
  s21_sprintf(test_str_1095, "%i", 4343);
  sprintf(test_str_1095_1095, "%i", 4343);
  ck_assert_str_eq(test_str_1095, test_str_1095_1095);
}
END_TEST

START_TEST(sprintf_test_1096) {
  char test_str_1096[50] = "";
  char test_str_1096_1096[50] = "";
  s21_sprintf(test_str_1096, "%i", -1);
  sprintf(test_str_1096_1096, "%i", -1);
  ck_assert_str_eq(test_str_1096, test_str_1096_1096);
}
END_TEST

START_TEST(sprintf_test_1097) {
  char test_str_1097[50] = "";
  char test_str_1097_1097[50] = "";
  s21_sprintf(test_str_1097, "%i", -10);
  sprintf(test_str_1097_1097, "%i", -10);
  ck_assert_str_eq(test_str_1097, test_str_1097_1097);
}
END_TEST

START_TEST(sprintf_test_1098) {
  char test_str_1098[50] = "";
  char test_str_1098_1098[50] = "";
  s21_sprintf(test_str_1098, "%i", 43);
  sprintf(test_str_1098_1098, "%i", 43);
  ck_assert_str_eq(test_str_1098, test_str_1098_1098);
}
END_TEST

START_TEST(sprintf_test_1108) {
  char test_str_1108[50] = "";
  char test_str_1108_1108[50] = "";
  s21_sprintf(test_str_1108, "%d", 0);
  sprintf(test_str_1108_1108, "%d", 0);
  ck_assert_str_eq(test_str_1108, test_str_1108_1108);
}
END_TEST

START_TEST(sprintf_test_1109) {
  char test_str_1109[50] = "";
  char test_str_1109_1109[50] = "";
  s21_sprintf(test_str_1109, "%d", 1);
  sprintf(test_str_1109_1109, "%d", 1);
  ck_assert_str_eq(test_str_1109, test_str_1109_1109);
}
END_TEST

START_TEST(sprintf_test_1110) {
  char test_str_1110[50] = "";
  char test_str_1110_1110[50] = "";
  s21_sprintf(test_str_1110, "%d", 10);
  sprintf(test_str_1110_1110, "%d", 10);
  ck_assert_str_eq(test_str_1110, test_str_1110_1110);
}
END_TEST

START_TEST(sprintf_test_1111) {
  char test_str_1111[50] = "";
  char test_str_1111_1111[50] = "";
  s21_sprintf(test_str_1111, "%d", 123456);
  sprintf(test_str_1111_1111, "%d", 123456);
  ck_assert_str_eq(test_str_1111, test_str_1111_1111);
}
END_TEST

START_TEST(sprintf_test_1112) {
  char test_str_1112[50] = "";
  char test_str_1112_1112[50] = "";
  s21_sprintf(test_str_1112, "%d", -678901);
  sprintf(test_str_1112_1112, "%d", -678901);
  ck_assert_str_eq(test_str_1112, test_str_1112_1112);
}
END_TEST

START_TEST(sprintf_test_1113) {
  char test_str_1113[50] = "";
  char test_str_1113_1113[50] = "";
  s21_sprintf(test_str_1113, "%d", 4343);
  sprintf(test_str_1113_1113, "%d", 4343);
  ck_assert_str_eq(test_str_1113, test_str_1113_1113);
}
END_TEST

START_TEST(sprintf_test_1114) {
  char test_str_1114[50] = "";
  char test_str_1114_1114[50] = "";
  s21_sprintf(test_str_1114, "%d", -1);
  sprintf(test_str_1114_1114, "%d", -1);
  ck_assert_str_eq(test_str_1114, test_str_1114_1114);
}
END_TEST

START_TEST(sprintf_test_1115) {
  char test_str_1115[50] = "";
  char test_str_1115_1115[50] = "";
  s21_sprintf(test_str_1115, "%d", -10);
  sprintf(test_str_1115_1115, "%d", -10);
  ck_assert_str_eq(test_str_1115, test_str_1115_1115);
}
END_TEST

START_TEST(sprintf_test_1116) {
  char test_str_1116[50] = "";
  char test_str_1116_1116[50] = "";
  s21_sprintf(test_str_1116, "%d", 43);
  sprintf(test_str_1116_1116, "%d", 43);
  ck_assert_str_eq(test_str_1116, test_str_1116_1116);
}
END_TEST

START_TEST(sprintf_test_1189) {
  char test_str_1189[50] = "";
  char test_str_1189_1189[50] = "";
  s21_sprintf(test_str_1189, "%-s", "1234567");
  sprintf(test_str_1189_1189, "%-s", "1234567");
  ck_assert_str_eq(test_str_1189, test_str_1189_1189);
}
END_TEST

START_TEST(sprintf_test_1190) {
  char test_str_1190[50] = "";
  char test_str_1190_1190[50] = "";
  s21_sprintf(test_str_1190, "%-s", "dffdsfsf");
  sprintf(test_str_1190_1190, "%-s", "dffdsfsf");
  ck_assert_str_eq(test_str_1190, test_str_1190_1190);
}
END_TEST

START_TEST(sprintf_test_1191) {
  char test_str_1191[50] = "";
  char test_str_1191_1191[50] = "";
  s21_sprintf(test_str_1191, "%-s", "");
  sprintf(test_str_1191_1191, "%-s", "");
  ck_assert_str_eq(test_str_1191, test_str_1191_1191);
}
END_TEST

START_TEST(sprintf_test_1192) {
  char test_str_1192[50] = "";
  char test_str_1192_1192[50] = "";
  s21_sprintf(test_str_1192, "%-s", "eefwfweweffwefw");
  sprintf(test_str_1192_1192, "%-s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1192, test_str_1192_1192);
}
END_TEST

START_TEST(sprintf_test_1197) {
  char test_str_1197[50] = "";
  char test_str_1197_1197[50] = "";
  s21_sprintf(test_str_1197, "%s", "1234567");
  sprintf(test_str_1197_1197, "%s", "1234567");
  ck_assert_str_eq(test_str_1197, test_str_1197_1197);
}
END_TEST

START_TEST(sprintf_test_1198) {
  char test_str_1198[50] = "";
  char test_str_1198_1198[50] = "";
  s21_sprintf(test_str_1198, "%s", "dffdsfsf");
  sprintf(test_str_1198_1198, "%s", "dffdsfsf");
  ck_assert_str_eq(test_str_1198, test_str_1198_1198);
}
END_TEST

START_TEST(sprintf_test_1199) {
  char test_str_1199[50] = "";
  char test_str_1199_1199[50] = "";
  s21_sprintf(test_str_1199, "%s", "");
  sprintf(test_str_1199_1199, "%s", "");
  ck_assert_str_eq(test_str_1199, test_str_1199_1199);
}
END_TEST

START_TEST(sprintf_test_1200) {
  char test_str_1200[50] = "";
  char test_str_1200_1200[50] = "";
  s21_sprintf(test_str_1200, "%s", "eefwfweweffwefw");
  sprintf(test_str_1200_1200, "%s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1200, test_str_1200_1200);
}
END_TEST

START_TEST(sprintf_test_1209) {
  char test_str_1209[50] = "";
  char test_str_1209_1209[50] = "";
  s21_sprintf(test_str_1209, "%20s", "1234567");
  sprintf(test_str_1209_1209, "%20s", "1234567");
  ck_assert_str_eq(test_str_1209, test_str_1209_1209);
}
END_TEST

START_TEST(sprintf_test_1210) {
  char test_str_1210[50] = "";
  char test_str_1210_1210[50] = "";
  s21_sprintf(test_str_1210, "%20s", "dffdsfsf");
  sprintf(test_str_1210_1210, "%20s", "dffdsfsf");
  ck_assert_str_eq(test_str_1210, test_str_1210_1210);
}
END_TEST

START_TEST(sprintf_test_1211) {
  char test_str_1211[50] = "";
  char test_str_1211_1211[50] = "";
  s21_sprintf(test_str_1211, "%20s", "");
  sprintf(test_str_1211_1211, "%20s", "");
  ck_assert_str_eq(test_str_1211, test_str_1211_1211);
}
END_TEST

START_TEST(sprintf_test_1212) {
  char test_str_1212[50] = "";
  char test_str_1212_1212[50] = "";
  s21_sprintf(test_str_1212, "%20s", "eefwfweweffwefw");
  sprintf(test_str_1212_1212, "%20s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1212, test_str_1212_1212);
}
END_TEST

START_TEST(sprintf_test_1217) {
  char test_str_1217[50] = "";
  char test_str_1217_1217[50] = "";
  s21_sprintf(test_str_1217, "%.0s", "1234567");
  sprintf(test_str_1217_1217, "%.0s", "1234567");
  ck_assert_str_eq(test_str_1217, test_str_1217_1217);
}
END_TEST

START_TEST(sprintf_test_1218) {
  char test_str_1218[50] = "";
  char test_str_1218_1218[50] = "";
  s21_sprintf(test_str_1218, "%.0s", "dffdsfsf");
  sprintf(test_str_1218_1218, "%.0s", "dffdsfsf");
  ck_assert_str_eq(test_str_1218, test_str_1218_1218);
}
END_TEST

START_TEST(sprintf_test_1219) {
  char test_str_1219[50] = "";
  char test_str_1219_1219[50] = "";
  s21_sprintf(test_str_1219, "%.0s", "");
  sprintf(test_str_1219_1219, "%.0s", "");
  ck_assert_str_eq(test_str_1219, test_str_1219_1219);
}
END_TEST

START_TEST(sprintf_test_1220) {
  char test_str_1220[50] = "";
  char test_str_1220_1220[50] = "";
  s21_sprintf(test_str_1220, "%.0s", "eefwfweweffwefw");
  sprintf(test_str_1220_1220, "%.0s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1220, test_str_1220_1220);
}
END_TEST

START_TEST(sprintf_test_1221) {
  char test_str_1221[50] = "";
  char test_str_1221_1221[50] = "";
  s21_sprintf(test_str_1221, "%10s", "1234567");
  sprintf(test_str_1221_1221, "%10s", "1234567");
  ck_assert_str_eq(test_str_1221, test_str_1221_1221);
}
END_TEST

START_TEST(sprintf_test_1222) {
  char test_str_1222[50] = "";
  char test_str_1222_1222[50] = "";
  s21_sprintf(test_str_1222, "%10s", "dffdsfsf");
  sprintf(test_str_1222_1222, "%10s", "dffdsfsf");
  ck_assert_str_eq(test_str_1222, test_str_1222_1222);
}
END_TEST

START_TEST(sprintf_test_1223) {
  char test_str_1223[50] = "";
  char test_str_1223_1223[50] = "";
  s21_sprintf(test_str_1223, "%10s", "");
  sprintf(test_str_1223_1223, "%10s", "");
  ck_assert_str_eq(test_str_1223, test_str_1223_1223);
}
END_TEST

START_TEST(sprintf_test_1224) {
  char test_str_1224[50] = "";
  char test_str_1224_1224[50] = "";
  s21_sprintf(test_str_1224, "%10s", "eefwfweweffwefw");
  sprintf(test_str_1224_1224, "%10s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1224, test_str_1224_1224);
}
END_TEST

START_TEST(sprintf_test_1225) {
  char test_str_1225[50] = "";
  char test_str_1225_1225[50] = "";
  s21_sprintf(test_str_1225, "%-10s", "1234567");
  sprintf(test_str_1225_1225, "%-10s", "1234567");
  ck_assert_str_eq(test_str_1225, test_str_1225_1225);
}
END_TEST

START_TEST(sprintf_test_1226) {
  char test_str_1226[50] = "";
  char test_str_1226_1226[50] = "";
  s21_sprintf(test_str_1226, "%-10s", "dffdsfsf");
  sprintf(test_str_1226_1226, "%-10s", "dffdsfsf");
  ck_assert_str_eq(test_str_1226, test_str_1226_1226);
}
END_TEST

START_TEST(sprintf_test_1227) {
  char test_str_1227[50] = "";
  char test_str_1227_1227[50] = "";
  s21_sprintf(test_str_1227, "%-10s", "");
  sprintf(test_str_1227_1227, "%-10s", "");
  ck_assert_str_eq(test_str_1227, test_str_1227_1227);
}
END_TEST

START_TEST(sprintf_test_1228) {
  char test_str_1228[50] = "";
  char test_str_1228_1228[50] = "";
  s21_sprintf(test_str_1228, "%-10s", "eefwfweweffwefw");
  sprintf(test_str_1228_1228, "%-10s", "eefwfweweffwefw");
  ck_assert_str_eq(test_str_1228, test_str_1228_1228);
}
END_TEST

START_TEST(sprintf_test_1249) {
  char test_str_1249[50] = "";
  char test_str_1249_1249[50] = "";
  s21_sprintf(test_str_1249, "%-c", 'a');
  sprintf(test_str_1249_1249, "%-c", 'a');
  ck_assert_str_eq(test_str_1249, test_str_1249_1249);
}
END_TEST

START_TEST(sprintf_test_1250) {
  char test_str_1250[50] = "";
  char test_str_1250_1250[50] = "";
  s21_sprintf(test_str_1250, "%-c", ' ');
  sprintf(test_str_1250_1250, "%-c", ' ');
  ck_assert_str_eq(test_str_1250, test_str_1250_1250);
}
END_TEST

START_TEST(sprintf_test_1251) {
  char test_str_1251[50] = "";
  char test_str_1251_1251[50] = "";
  s21_sprintf(test_str_1251, "%-c", ' ');
  sprintf(test_str_1251_1251, "%-c", ' ');
  ck_assert_str_eq(test_str_1251, test_str_1251_1251);
}
END_TEST

START_TEST(sprintf_test_1252) {
  char test_str_1252[50] = "";
  char test_str_1252_1252[50] = "";
  s21_sprintf(test_str_1252, "%-c", '1');
  sprintf(test_str_1252_1252, "%-c", '1');
  ck_assert_str_eq(test_str_1252, test_str_1252_1252);
}
END_TEST

START_TEST(sprintf_test_1257) {
  char test_str_1257[50] = "";
  char test_str_1257_1257[50] = "";
  s21_sprintf(test_str_1257, "%c", 'a');
  sprintf(test_str_1257_1257, "%c", 'a');
  ck_assert_str_eq(test_str_1257, test_str_1257_1257);
}
END_TEST

START_TEST(sprintf_test_1258) {
  char test_str_1258[50] = "";
  char test_str_1258_1258[50] = "";
  s21_sprintf(test_str_1258, "%c", ' ');
  sprintf(test_str_1258_1258, "%c", ' ');
  ck_assert_str_eq(test_str_1258, test_str_1258_1258);
}
END_TEST

START_TEST(sprintf_test_1259) {
  char test_str_1259[50] = "";
  char test_str_1259_1259[50] = "";
  s21_sprintf(test_str_1259, "%c", ' ');
  sprintf(test_str_1259_1259, "%c", ' ');
  ck_assert_str_eq(test_str_1259, test_str_1259_1259);
}
END_TEST

START_TEST(sprintf_test_1260) {
  char test_str_1260[50] = "";
  char test_str_1260_1260[50] = "";
  s21_sprintf(test_str_1260, "%c", '1');
  sprintf(test_str_1260_1260, "%c", '1');
  ck_assert_str_eq(test_str_1260, test_str_1260_1260);
}
END_TEST

START_TEST(sprintf_test_1269) {
  char test_str_1269[50] = "";
  char test_str_1269_1269[50] = "";
  s21_sprintf(test_str_1269, "%20c", 'a');
  sprintf(test_str_1269_1269, "%20c", 'a');
  ck_assert_str_eq(test_str_1269, test_str_1269_1269);
}
END_TEST

START_TEST(sprintf_test_1270) {
  char test_str_1270[50] = "";
  char test_str_1270_1270[50] = "";
  s21_sprintf(test_str_1270, "%20c", ' ');
  sprintf(test_str_1270_1270, "%20c", ' ');
  ck_assert_str_eq(test_str_1270, test_str_1270_1270);
}
END_TEST

START_TEST(sprintf_test_1271) {
  char test_str_1271[50] = "";
  char test_str_1271_1271[50] = "";
  s21_sprintf(test_str_1271, "%20c", ' ');
  sprintf(test_str_1271_1271, "%20c", ' ');
  ck_assert_str_eq(test_str_1271, test_str_1271_1271);
}
END_TEST

START_TEST(sprintf_test_1272) {
  char test_str_1272[50] = "";
  char test_str_1272_1272[50] = "";
  s21_sprintf(test_str_1272, "%20c", '1');
  sprintf(test_str_1272_1272, "%20c", '1');
  ck_assert_str_eq(test_str_1272, test_str_1272_1272);
}
END_TEST

START_TEST(sprintf_test_1281) {
  char test_str_1281[50] = "";
  char test_str_1281_1281[50] = "";
  s21_sprintf(test_str_1281, "%10c", 'a');
  sprintf(test_str_1281_1281, "%10c", 'a');
  ck_assert_str_eq(test_str_1281, test_str_1281_1281);
}
END_TEST

START_TEST(sprintf_test_1282) {
  char test_str_1282[50] = "";
  char test_str_1282_1282[50] = "";
  s21_sprintf(test_str_1282, "%10c", ' ');
  sprintf(test_str_1282_1282, "%10c", ' ');
  ck_assert_str_eq(test_str_1282, test_str_1282_1282);
}
END_TEST

START_TEST(sprintf_test_1283) {
  char test_str_1283[50] = "";
  char test_str_1283_1283[50] = "";
  s21_sprintf(test_str_1283, "%10c", ' ');
  sprintf(test_str_1283_1283, "%10c", ' ');
  ck_assert_str_eq(test_str_1283, test_str_1283_1283);
}
END_TEST

START_TEST(sprintf_test_1284) {
  char test_str_1284[50] = "";
  char test_str_1284_1284[50] = "";
  s21_sprintf(test_str_1284, "%10c", '1');
  sprintf(test_str_1284_1284, "%10c", '1');
  ck_assert_str_eq(test_str_1284, test_str_1284_1284);
}
END_TEST

START_TEST(sprintf_test_1285) {
  char test_str_1285[50] = "";
  char test_str_1285_1285[50] = "";
  s21_sprintf(test_str_1285, "%-10c", 'a');
  sprintf(test_str_1285_1285, "%-10c", 'a');
  ck_assert_str_eq(test_str_1285, test_str_1285_1285);
}
END_TEST

START_TEST(sprintf_test_1286) {
  char test_str_1286[50] = "";
  char test_str_1286_1286[50] = "";
  s21_sprintf(test_str_1286, "%-10c", ' ');
  sprintf(test_str_1286_1286, "%-10c", ' ');
  ck_assert_str_eq(test_str_1286, test_str_1286_1286);
}
END_TEST

START_TEST(sprintf_test_1287) {
  char test_str_1287[50] = "";
  char test_str_1287_1287[50] = "";
  s21_sprintf(test_str_1287, "%-10c", ' ');
  sprintf(test_str_1287_1287, "%-10c", ' ');
  ck_assert_str_eq(test_str_1287, test_str_1287_1287);
}
END_TEST

START_TEST(sprintf_test_1288) {
  char test_str_1288[50] = "";
  char test_str_1288_1288[50] = "";
  s21_sprintf(test_str_1288, "%-10c", '1');
  sprintf(test_str_1288_1288, "%-10c", '1');
  ck_assert_str_eq(test_str_1288, test_str_1288_1288);
}
END_TEST

START_TEST(sprintf_test_1289) {
  char test_str_1289[50] = "";
  char test_str_1289_1289[50] = "";
  s21_sprintf(test_str_1289, "%-f", 0.0);
  sprintf(test_str_1289_1289, "%-f", 0.0);
  ck_assert_str_eq(test_str_1289, test_str_1289_1289);
}
END_TEST

START_TEST(sprintf_test_1290) {
  char test_str_1290[50] = "";
  char test_str_1290_1290[50] = "";
  s21_sprintf(test_str_1290, "%-f", 123456789.0);
  sprintf(test_str_1290_1290, "%-f", 123456789.0);
  ck_assert_str_eq(test_str_1290, test_str_1290_1290);
}
END_TEST

START_TEST(sprintf_test_1291) {
  char test_str_1291[50] = "";
  char test_str_1291_1291[50] = "";
  s21_sprintf(test_str_1291, "%-f", 0.123456789);
  sprintf(test_str_1291_1291, "%-f", 0.123456789);
  ck_assert_str_eq(test_str_1291, test_str_1291_1291);
}
END_TEST

START_TEST(sprintf_test_1292) {
  char test_str_1292[50] = "";
  char test_str_1292_1292[50] = "";
  s21_sprintf(test_str_1292, "%-f", -123456789.0);
  sprintf(test_str_1292_1292, "%-f", -123456789.0);
  ck_assert_str_eq(test_str_1292, test_str_1292_1292);
}
END_TEST

START_TEST(sprintf_test_1293) {
  char test_str_1293[50] = "";
  char test_str_1293_1293[50] = "";
  s21_sprintf(test_str_1293, "%-f", -0.123456789);
  sprintf(test_str_1293_1293, "%-f", -0.123456789);
  ck_assert_str_eq(test_str_1293, test_str_1293_1293);
}
END_TEST

START_TEST(sprintf_test_1294) {
  char test_str_1294[50] = "";
  char test_str_1294_1294[50] = "";
  s21_sprintf(test_str_1294, "%-f", 123456789.12345679);
  sprintf(test_str_1294_1294, "%-f", 123456789.12345679);
  ck_assert_str_eq(test_str_1294, test_str_1294_1294);
}
END_TEST

START_TEST(sprintf_test_1295) {
  char test_str_1295[50] = "";
  char test_str_1295_1295[50] = "";
  s21_sprintf(test_str_1295, "%-f", -123456789.12345678);
  sprintf(test_str_1295_1295, "%-f", -123456789.12345678);
  ck_assert_str_eq(test_str_1295, test_str_1295_1295);
}
END_TEST

START_TEST(sprintf_test_1296) {
  char test_str_1296[50] = "";
  char test_str_1296_1296[50] = "";
  s21_sprintf(test_str_1296, "%-f", 1.23e-09);
  sprintf(test_str_1296_1296, "%-f", 1.23e-09);
  ck_assert_str_eq(test_str_1296, test_str_1296_1296);
}
END_TEST

START_TEST(sprintf_test_1297) {
  char test_str_1297[50] = "";
  char test_str_1297_1297[50] = "";
  s21_sprintf(test_str_1297, "%-f", 1.23e-09);
  sprintf(test_str_1297_1297, "%-f", 1.23e-09);
  ck_assert_str_eq(test_str_1297, test_str_1297_1297);
}
END_TEST

START_TEST(sprintf_test_1298) {
  char test_str_1298[50] = "";
  char test_str_1298_1298[50] = "";
  s21_sprintf(test_str_1298, "%+f", 0.0);
  sprintf(test_str_1298_1298, "%+f", 0.0);
  ck_assert_str_eq(test_str_1298, test_str_1298_1298);
}
END_TEST

START_TEST(sprintf_test_1299) {
  char test_str_1299[50] = "";
  char test_str_1299_1299[50] = "";
  s21_sprintf(test_str_1299, "%+f", 123456789.0);
  sprintf(test_str_1299_1299, "%+f", 123456789.0);
  ck_assert_str_eq(test_str_1299, test_str_1299_1299);
}
END_TEST

START_TEST(sprintf_test_1300) {
  char test_str_1300[50] = "";
  char test_str_1300_1300[50] = "";
  s21_sprintf(test_str_1300, "%+f", 0.123456789);
  sprintf(test_str_1300_1300, "%+f", 0.123456789);
  ck_assert_str_eq(test_str_1300, test_str_1300_1300);
}
END_TEST

START_TEST(sprintf_test_1301) {
  char test_str_1301[50] = "";
  char test_str_1301_1301[50] = "";
  s21_sprintf(test_str_1301, "%+f", -123456789.0);
  sprintf(test_str_1301_1301, "%+f", -123456789.0);
  ck_assert_str_eq(test_str_1301, test_str_1301_1301);
}
END_TEST

START_TEST(sprintf_test_1302) {
  char test_str_1302[50] = "";
  char test_str_1302_1302[50] = "";
  s21_sprintf(test_str_1302, "%+f", -0.123456789);
  sprintf(test_str_1302_1302, "%+f", -0.123456789);
  ck_assert_str_eq(test_str_1302, test_str_1302_1302);
}
END_TEST

START_TEST(sprintf_test_1303) {
  char test_str_1303[50] = "";
  char test_str_1303_1303[50] = "";
  s21_sprintf(test_str_1303, "%+f", 123456789.12345679);
  sprintf(test_str_1303_1303, "%+f", 123456789.12345679);
  ck_assert_str_eq(test_str_1303, test_str_1303_1303);
}
END_TEST

START_TEST(sprintf_test_1304) {
  char test_str_1304[50] = "";
  char test_str_1304_1304[50] = "";
  s21_sprintf(test_str_1304, "%+f", -123456789.12345678);
  sprintf(test_str_1304_1304, "%+f", -123456789.12345678);
  ck_assert_str_eq(test_str_1304, test_str_1304_1304);
}
END_TEST

START_TEST(sprintf_test_1305) {
  char test_str_1305[50] = "";
  char test_str_1305_1305[50] = "";
  s21_sprintf(test_str_1305, "%+f", 1.23e-09);
  sprintf(test_str_1305_1305, "%+f", 1.23e-09);
  ck_assert_str_eq(test_str_1305, test_str_1305_1305);
}
END_TEST

START_TEST(sprintf_test_1306) {
  char test_str_1306[50] = "";
  char test_str_1306_1306[50] = "";
  s21_sprintf(test_str_1306, "%+f", 1.23e-09);
  sprintf(test_str_1306_1306, "%+f", 1.23e-09);
  ck_assert_str_eq(test_str_1306, test_str_1306_1306);
}
END_TEST

START_TEST(sprintf_test_1307) {
  char test_str_1307[50] = "";
  char test_str_1307_1307[50] = "";
  s21_sprintf(test_str_1307, "% f", 0.0);
  sprintf(test_str_1307_1307, "% f", 0.0);
  ck_assert_str_eq(test_str_1307, test_str_1307_1307);
}
END_TEST

START_TEST(sprintf_test_1308) {
  char test_str_1308[50] = "";
  char test_str_1308_1308[50] = "";
  s21_sprintf(test_str_1308, "% f", 123456789.0);
  sprintf(test_str_1308_1308, "% f", 123456789.0);
  ck_assert_str_eq(test_str_1308, test_str_1308_1308);
}
END_TEST

START_TEST(sprintf_test_1309) {
  char test_str_1309[50] = "";
  char test_str_1309_1309[50] = "";
  s21_sprintf(test_str_1309, "% f", 0.123456789);
  sprintf(test_str_1309_1309, "% f", 0.123456789);
  ck_assert_str_eq(test_str_1309, test_str_1309_1309);
}
END_TEST

START_TEST(sprintf_test_1310) {
  char test_str_1310[50] = "";
  char test_str_1310_1310[50] = "";
  s21_sprintf(test_str_1310, "% f", -123456789.0);
  sprintf(test_str_1310_1310, "% f", -123456789.0);
  ck_assert_str_eq(test_str_1310, test_str_1310_1310);
}
END_TEST

START_TEST(sprintf_test_1311) {
  char test_str_1311[50] = "";
  char test_str_1311_1311[50] = "";
  s21_sprintf(test_str_1311, "% f", -0.123456789);
  sprintf(test_str_1311_1311, "% f", -0.123456789);
  ck_assert_str_eq(test_str_1311, test_str_1311_1311);
}
END_TEST

START_TEST(sprintf_test_1312) {
  char test_str_1312[50] = "";
  char test_str_1312_1312[50] = "";
  s21_sprintf(test_str_1312, "% f", 123456789.12345679);
  sprintf(test_str_1312_1312, "% f", 123456789.12345679);
  ck_assert_str_eq(test_str_1312, test_str_1312_1312);
}
END_TEST

START_TEST(sprintf_test_1313) {
  char test_str_1313[50] = "";
  char test_str_1313_1313[50] = "";
  s21_sprintf(test_str_1313, "% f", -123456789.12345678);
  sprintf(test_str_1313_1313, "% f", -123456789.12345678);
  ck_assert_str_eq(test_str_1313, test_str_1313_1313);
}
END_TEST

START_TEST(sprintf_test_1314) {
  char test_str_1314[50] = "";
  char test_str_1314_1314[50] = "";
  s21_sprintf(test_str_1314, "% f", 1.23e-09);
  sprintf(test_str_1314_1314, "% f", 1.23e-09);
  ck_assert_str_eq(test_str_1314, test_str_1314_1314);
}
END_TEST

START_TEST(sprintf_test_1315) {
  char test_str_1315[50] = "";
  char test_str_1315_1315[50] = "";
  s21_sprintf(test_str_1315, "% f", 1.23e-09);
  sprintf(test_str_1315_1315, "% f", 1.23e-09);
  ck_assert_str_eq(test_str_1315, test_str_1315_1315);
}
END_TEST

START_TEST(sprintf_test_1325) {
  char test_str_1325[50] = "";
  char test_str_1325_1325[50] = "";
  s21_sprintf(test_str_1325, "%0f", 0.0);
  sprintf(test_str_1325_1325, "%0f", 0.0);
  ck_assert_str_eq(test_str_1325, test_str_1325_1325);
}
END_TEST

START_TEST(sprintf_test_1326) {
  char test_str_1326[50] = "";
  char test_str_1326_1326[50] = "";
  s21_sprintf(test_str_1326, "%0f", 123456789.0);
  sprintf(test_str_1326_1326, "%0f", 123456789.0);
  ck_assert_str_eq(test_str_1326, test_str_1326_1326);
}
END_TEST

START_TEST(sprintf_test_1327) {
  char test_str_1327[50] = "";
  char test_str_1327_1327[50] = "";
  s21_sprintf(test_str_1327, "%0f", 0.123456789);
  sprintf(test_str_1327_1327, "%0f", 0.123456789);
  ck_assert_str_eq(test_str_1327, test_str_1327_1327);
}
END_TEST

START_TEST(sprintf_test_1328) {
  char test_str_1328[50] = "";
  char test_str_1328_1328[50] = "";
  s21_sprintf(test_str_1328, "%0f", -123456789.0);
  sprintf(test_str_1328_1328, "%0f", -123456789.0);
  ck_assert_str_eq(test_str_1328, test_str_1328_1328);
}
END_TEST

START_TEST(sprintf_test_1329) {
  char test_str_1329[50] = "";
  char test_str_1329_1329[50] = "";
  s21_sprintf(test_str_1329, "%0f", -0.123456789);
  sprintf(test_str_1329_1329, "%0f", -0.123456789);
  ck_assert_str_eq(test_str_1329, test_str_1329_1329);
}
END_TEST

START_TEST(sprintf_test_1330) {
  char test_str_1330[50] = "";
  char test_str_1330_1330[50] = "";
  s21_sprintf(test_str_1330, "%0f", 123456789.12345679);
  sprintf(test_str_1330_1330, "%0f", 123456789.12345679);
  ck_assert_str_eq(test_str_1330, test_str_1330_1330);
}
END_TEST

START_TEST(sprintf_test_1331) {
  char test_str_1331[50] = "";
  char test_str_1331_1331[50] = "";
  s21_sprintf(test_str_1331, "%0f", -123456789.12345678);
  sprintf(test_str_1331_1331, "%0f", -123456789.12345678);
  ck_assert_str_eq(test_str_1331, test_str_1331_1331);
}
END_TEST

START_TEST(sprintf_test_1332) {
  char test_str_1332[50] = "";
  char test_str_1332_1332[50] = "";
  s21_sprintf(test_str_1332, "%0f", 1.23e-09);
  sprintf(test_str_1332_1332, "%0f", 1.23e-09);
  ck_assert_str_eq(test_str_1332, test_str_1332_1332);
}
END_TEST

START_TEST(sprintf_test_1333) {
  char test_str_1333[50] = "";
  char test_str_1333_1333[50] = "";
  s21_sprintf(test_str_1333, "%0f", 1.23e-09);
  sprintf(test_str_1333_1333, "%0f", 1.23e-09);
  ck_assert_str_eq(test_str_1333, test_str_1333_1333);
}
END_TEST

START_TEST(sprintf_test_1334) {
  char test_str_1334[50] = "";
  char test_str_1334_1334[50] = "";
  s21_sprintf(test_str_1334, "%0f", 0.0);
  sprintf(test_str_1334_1334, "%0f", 0.0);
  ck_assert_str_eq(test_str_1334, test_str_1334_1334);
}
END_TEST

START_TEST(sprintf_test_1335) {
  char test_str_1335[50] = "";
  char test_str_1335_1335[50] = "";
  s21_sprintf(test_str_1335, "%0f", 123456789.0);
  sprintf(test_str_1335_1335, "%0f", 123456789.0);
  ck_assert_str_eq(test_str_1335, test_str_1335_1335);
}
END_TEST

START_TEST(sprintf_test_1336) {
  char test_str_1336[50] = "";
  char test_str_1336_1336[50] = "";
  s21_sprintf(test_str_1336, "%0f", 0.123456789);
  sprintf(test_str_1336_1336, "%0f", 0.123456789);
  ck_assert_str_eq(test_str_1336, test_str_1336_1336);
}
END_TEST

START_TEST(sprintf_test_1337) {
  char test_str_1337[50] = "";
  char test_str_1337_1337[50] = "";
  s21_sprintf(test_str_1337, "%0f", -123456789.0);
  sprintf(test_str_1337_1337, "%0f", -123456789.0);
  ck_assert_str_eq(test_str_1337, test_str_1337_1337);
}
END_TEST

START_TEST(sprintf_test_1338) {
  char test_str_1338[50] = "";
  char test_str_1338_1338[50] = "";
  s21_sprintf(test_str_1338, "%0f", -0.123456789);
  sprintf(test_str_1338_1338, "%0f", -0.123456789);
  ck_assert_str_eq(test_str_1338, test_str_1338_1338);
}
END_TEST

START_TEST(sprintf_test_1339) {
  char test_str_1339[50] = "";
  char test_str_1339_1339[50] = "";
  s21_sprintf(test_str_1339, "%0f", 123456789.12345679);
  sprintf(test_str_1339_1339, "%0f", 123456789.12345679);
  ck_assert_str_eq(test_str_1339, test_str_1339_1339);
}
END_TEST

START_TEST(sprintf_test_1340) {
  char test_str_1340[50] = "";
  char test_str_1340_1340[50] = "";
  s21_sprintf(test_str_1340, "%0f", -123456789.12345678);
  sprintf(test_str_1340_1340, "%0f", -123456789.12345678);
  ck_assert_str_eq(test_str_1340, test_str_1340_1340);
}
END_TEST

START_TEST(sprintf_test_1341) {
  char test_str_1341[50] = "";
  char test_str_1341_1341[50] = "";
  s21_sprintf(test_str_1341, "%0f", 1.23e-09);
  sprintf(test_str_1341_1341, "%0f", 1.23e-09);
  ck_assert_str_eq(test_str_1341, test_str_1341_1341);
}
END_TEST

START_TEST(sprintf_test_1342) {
  char test_str_1342[50] = "";
  char test_str_1342_1342[50] = "";
  s21_sprintf(test_str_1342, "%0f", 1.23e-09);
  sprintf(test_str_1342_1342, "%0f", 1.23e-09);
  ck_assert_str_eq(test_str_1342, test_str_1342_1342);
}
END_TEST

START_TEST(sprintf_test_1343) {
  char test_str_1343[50] = "";
  char test_str_1343_1343[50] = "";
  s21_sprintf(test_str_1343, "%10f", 0.0);
  sprintf(test_str_1343_1343, "%10f", 0.0);
  ck_assert_str_eq(test_str_1343, test_str_1343_1343);
}
END_TEST

START_TEST(sprintf_test_1344) {
  char test_str_1344[50] = "";
  char test_str_1344_1344[50] = "";
  s21_sprintf(test_str_1344, "%10f", 123456789.0);
  sprintf(test_str_1344_1344, "%10f", 123456789.0);
  ck_assert_str_eq(test_str_1344, test_str_1344_1344);
}
END_TEST

START_TEST(sprintf_test_1345) {
  char test_str_1345[50] = "";
  char test_str_1345_1345[50] = "";
  s21_sprintf(test_str_1345, "%10f", 0.123456789);
  sprintf(test_str_1345_1345, "%10f", 0.123456789);
  ck_assert_str_eq(test_str_1345, test_str_1345_1345);
}
END_TEST

START_TEST(sprintf_test_1346) {
  char test_str_1346[50] = "";
  char test_str_1346_1346[50] = "";
  s21_sprintf(test_str_1346, "%10f", -123456789.0);
  sprintf(test_str_1346_1346, "%10f", -123456789.0);
  ck_assert_str_eq(test_str_1346, test_str_1346_1346);
}
END_TEST

START_TEST(sprintf_test_1347) {
  char test_str_1347[50] = "";
  char test_str_1347_1347[50] = "";
  s21_sprintf(test_str_1347, "%10f", -0.123456789);
  sprintf(test_str_1347_1347, "%10f", -0.123456789);
  ck_assert_str_eq(test_str_1347, test_str_1347_1347);
}
END_TEST

START_TEST(sprintf_test_1348) {
  char test_str_1348[50] = "";
  char test_str_1348_1348[50] = "";
  s21_sprintf(test_str_1348, "%10f", 123456789.12345679);
  sprintf(test_str_1348_1348, "%10f", 123456789.12345679);
  ck_assert_str_eq(test_str_1348, test_str_1348_1348);
}
END_TEST

START_TEST(sprintf_test_1349) {
  char test_str_1349[50] = "";
  char test_str_1349_1349[50] = "";
  s21_sprintf(test_str_1349, "%10f", -123456789.12345678);
  sprintf(test_str_1349_1349, "%10f", -123456789.12345678);
  ck_assert_str_eq(test_str_1349, test_str_1349_1349);
}
END_TEST

START_TEST(sprintf_test_1350) {
  char test_str_1350[50] = "";
  char test_str_1350_1350[50] = "";
  s21_sprintf(test_str_1350, "%10f", 1.23e-09);
  sprintf(test_str_1350_1350, "%10f", 1.23e-09);
  ck_assert_str_eq(test_str_1350, test_str_1350_1350);
}
END_TEST

START_TEST(sprintf_test_1351) {
  char test_str_1351[50] = "";
  char test_str_1351_1351[50] = "";
  s21_sprintf(test_str_1351, "%10f", 1.23e-09);
  sprintf(test_str_1351_1351, "%10f", 1.23e-09);
  ck_assert_str_eq(test_str_1351, test_str_1351_1351);
}
END_TEST

START_TEST(sprintf_test_1352) {
  char test_str_1352[50] = "";
  char test_str_1352_1352[50] = "";
  s21_sprintf(test_str_1352, "%20f", 0.0);
  sprintf(test_str_1352_1352, "%20f", 0.0);
  ck_assert_str_eq(test_str_1352, test_str_1352_1352);
}
END_TEST

START_TEST(sprintf_test_1353) {
  char test_str_1353[50] = "";
  char test_str_1353_1353[50] = "";
  s21_sprintf(test_str_1353, "%20f", 123456789.0);
  sprintf(test_str_1353_1353, "%20f", 123456789.0);
  ck_assert_str_eq(test_str_1353, test_str_1353_1353);
}
END_TEST

START_TEST(sprintf_test_1354) {
  char test_str_1354[50] = "";
  char test_str_1354_1354[50] = "";
  s21_sprintf(test_str_1354, "%20f", 0.123456789);
  sprintf(test_str_1354_1354, "%20f", 0.123456789);
  ck_assert_str_eq(test_str_1354, test_str_1354_1354);
}
END_TEST

START_TEST(sprintf_test_1355) {
  char test_str_1355[50] = "";
  char test_str_1355_1355[50] = "";
  s21_sprintf(test_str_1355, "%20f", -123456789.0);
  sprintf(test_str_1355_1355, "%20f", -123456789.0);
  ck_assert_str_eq(test_str_1355, test_str_1355_1355);
}
END_TEST

START_TEST(sprintf_test_1356) {
  char test_str_1356[50] = "";
  char test_str_1356_1356[50] = "";
  s21_sprintf(test_str_1356, "%20f", -0.123456789);
  sprintf(test_str_1356_1356, "%20f", -0.123456789);
  ck_assert_str_eq(test_str_1356, test_str_1356_1356);
}
END_TEST

START_TEST(sprintf_test_1357) {
  char test_str_1357[50] = "";
  char test_str_1357_1357[50] = "";
  s21_sprintf(test_str_1357, "%20f", 123456789.12345679);
  sprintf(test_str_1357_1357, "%20f", 123456789.12345679);
  ck_assert_str_eq(test_str_1357, test_str_1357_1357);
}
END_TEST

START_TEST(sprintf_test_1358) {
  char test_str_1358[50] = "";
  char test_str_1358_1358[50] = "";
  s21_sprintf(test_str_1358, "%20f", -123456789.12345678);
  sprintf(test_str_1358_1358, "%20f", -123456789.12345678);
  ck_assert_str_eq(test_str_1358, test_str_1358_1358);
}
END_TEST

START_TEST(sprintf_test_1359) {
  char test_str_1359[50] = "";
  char test_str_1359_1359[50] = "";
  s21_sprintf(test_str_1359, "%20f", 1.23e-09);
  sprintf(test_str_1359_1359, "%20f", 1.23e-09);
  ck_assert_str_eq(test_str_1359, test_str_1359_1359);
}
END_TEST

START_TEST(sprintf_test_1360) {
  char test_str_1360[50] = "";
  char test_str_1360_1360[50] = "";
  s21_sprintf(test_str_1360, "%20f", 1.23e-09);
  sprintf(test_str_1360_1360, "%20f", 1.23e-09);
  ck_assert_str_eq(test_str_1360, test_str_1360_1360);
}
END_TEST

START_TEST(sprintf_test_1361) {
  char test_str_1361[50] = "";
  char test_str_1361_1361[50] = "";
  s21_sprintf(test_str_1361, "%-10f", 0.0);
  sprintf(test_str_1361_1361, "%-10f", 0.0);
  ck_assert_str_eq(test_str_1361, test_str_1361_1361);
}
END_TEST

START_TEST(sprintf_test_1362) {
  char test_str_1362[50] = "";
  char test_str_1362_1362[50] = "";
  s21_sprintf(test_str_1362, "%-10f", 123456789.0);
  sprintf(test_str_1362_1362, "%-10f", 123456789.0);
  ck_assert_str_eq(test_str_1362, test_str_1362_1362);
}
END_TEST

START_TEST(sprintf_test_1363) {
  char test_str_1363[50] = "";
  char test_str_1363_1363[50] = "";
  s21_sprintf(test_str_1363, "%-10f", 0.123456789);
  sprintf(test_str_1363_1363, "%-10f", 0.123456789);
  ck_assert_str_eq(test_str_1363, test_str_1363_1363);
}
END_TEST

START_TEST(sprintf_test_1364) {
  char test_str_1364[50] = "";
  char test_str_1364_1364[50] = "";
  s21_sprintf(test_str_1364, "%-10f", -123456789.0);
  sprintf(test_str_1364_1364, "%-10f", -123456789.0);
  ck_assert_str_eq(test_str_1364, test_str_1364_1364);
}
END_TEST

START_TEST(sprintf_test_1365) {
  char test_str_1365[50] = "";
  char test_str_1365_1365[50] = "";
  s21_sprintf(test_str_1365, "%-10f", -0.123456789);
  sprintf(test_str_1365_1365, "%-10f", -0.123456789);
  ck_assert_str_eq(test_str_1365, test_str_1365_1365);
}
END_TEST

START_TEST(sprintf_test_1366) {
  char test_str_1366[50] = "";
  char test_str_1366_1366[50] = "";
  s21_sprintf(test_str_1366, "%-10f", 123456789.12345679);
  sprintf(test_str_1366_1366, "%-10f", 123456789.12345679);
  ck_assert_str_eq(test_str_1366, test_str_1366_1366);
}
END_TEST

START_TEST(sprintf_test_1367) {
  char test_str_1367[50] = "";
  char test_str_1367_1367[50] = "";
  s21_sprintf(test_str_1367, "%-10f", -123456789.12345678);
  sprintf(test_str_1367_1367, "%-10f", -123456789.12345678);
  ck_assert_str_eq(test_str_1367, test_str_1367_1367);
}
END_TEST

START_TEST(sprintf_test_1368) {
  char test_str_1368[50] = "";
  char test_str_1368_1368[50] = "";
  s21_sprintf(test_str_1368, "%-10f", 1.23e-09);
  sprintf(test_str_1368_1368, "%-10f", 1.23e-09);
  ck_assert_str_eq(test_str_1368, test_str_1368_1368);
}
END_TEST

START_TEST(sprintf_test_1369) {
  char test_str_1369[50] = "";
  char test_str_1369_1369[50] = "";
  s21_sprintf(test_str_1369, "%-10f", 1.23e-09);
  sprintf(test_str_1369_1369, "%-10f", 1.23e-09);
  ck_assert_str_eq(test_str_1369, test_str_1369_1369);
}
END_TEST

START_TEST(sprintf_test_1370) {
  char test_str_1370[50] = "";
  char test_str_1370_1370[50] = "";
  s21_sprintf(test_str_1370, "%-20f", 0.0);
  sprintf(test_str_1370_1370, "%-20f", 0.0);
  ck_assert_str_eq(test_str_1370, test_str_1370_1370);
}
END_TEST

START_TEST(sprintf_test_1371) {
  char test_str_1371[50] = "";
  char test_str_1371_1371[50] = "";
  s21_sprintf(test_str_1371, "%-20f", 123456789.0);
  sprintf(test_str_1371_1371, "%-20f", 123456789.0);
  ck_assert_str_eq(test_str_1371, test_str_1371_1371);
}
END_TEST

START_TEST(sprintf_test_1372) {
  char test_str_1372[50] = "";
  char test_str_1372_1372[50] = "";
  s21_sprintf(test_str_1372, "%-20f", 0.123456789);
  sprintf(test_str_1372_1372, "%-20f", 0.123456789);
  ck_assert_str_eq(test_str_1372, test_str_1372_1372);
}
END_TEST

START_TEST(sprintf_test_1373) {
  char test_str_1373[50] = "";
  char test_str_1373_1373[50] = "";
  s21_sprintf(test_str_1373, "%-20f", -123456789.0);
  sprintf(test_str_1373_1373, "%-20f", -123456789.0);
  ck_assert_str_eq(test_str_1373, test_str_1373_1373);
}
END_TEST

START_TEST(sprintf_test_1374) {
  char test_str_1374[50] = "";
  char test_str_1374_1374[50] = "";
  s21_sprintf(test_str_1374, "%-20f", -0.123456789);
  sprintf(test_str_1374_1374, "%-20f", -0.123456789);
  ck_assert_str_eq(test_str_1374, test_str_1374_1374);
}
END_TEST

START_TEST(sprintf_test_1375) {
  char test_str_1375[50] = "";
  char test_str_1375_1375[50] = "";
  s21_sprintf(test_str_1375, "%-20f", 123456789.12345679);
  sprintf(test_str_1375_1375, "%-20f", 123456789.12345679);
  ck_assert_str_eq(test_str_1375, test_str_1375_1375);
}
END_TEST

START_TEST(sprintf_test_1376) {
  char test_str_1376[50] = "";
  char test_str_1376_1376[50] = "";
  s21_sprintf(test_str_1376, "%-20f", -123456789.12345678);
  sprintf(test_str_1376_1376, "%-20f", -123456789.12345678);
  ck_assert_str_eq(test_str_1376, test_str_1376_1376);
}
END_TEST

START_TEST(sprintf_test_1377) {
  char test_str_1377[50] = "";
  char test_str_1377_1377[50] = "";
  s21_sprintf(test_str_1377, "%-20f", 1.23e-09);
  sprintf(test_str_1377_1377, "%-20f", 1.23e-09);
  ck_assert_str_eq(test_str_1377, test_str_1377_1377);
}
END_TEST

START_TEST(sprintf_test_1378) {
  char test_str_1378[50] = "";
  char test_str_1378_1378[50] = "";
  s21_sprintf(test_str_1378, "%-20f", 1.23e-09);
  sprintf(test_str_1378_1378, "%-20f", 1.23e-09);
  ck_assert_str_eq(test_str_1378, test_str_1378_1378);
}
END_TEST

START_TEST(sprintf_test_1424) {
  char test_str_1424[50] = "";
  char test_str_1424_1424[50] = "";
  s21_sprintf(test_str_1424, "%.10f", 0.0);
  sprintf(test_str_1424_1424, "%.10f", 0.0);
  ck_assert_str_eq(test_str_1424, test_str_1424_1424);
}
END_TEST

START_TEST(sprintf_test_1425) {
  char test_str_1425[50] = "";
  char test_str_1425_1425[50] = "";
  s21_sprintf(test_str_1425, "%.10f", 123456789.0);
  sprintf(test_str_1425_1425, "%.10f", 123456789.0);
  ck_assert_str_eq(test_str_1425, test_str_1425_1425);
}
END_TEST

START_TEST(sprintf_test_1426) {
  char test_str_1426[50] = "";
  char test_str_1426_1426[50] = "";
  s21_sprintf(test_str_1426, "%.10f", 0.123456789);
  sprintf(test_str_1426_1426, "%.10f", 0.123456789);
  ck_assert_str_eq(test_str_1426, test_str_1426_1426);
}
END_TEST

START_TEST(sprintf_test_1427) {
  char test_str_1427[50] = "";
  char test_str_1427_1427[50] = "";
  s21_sprintf(test_str_1427, "%.10f", -123456789.0);
  sprintf(test_str_1427_1427, "%.10f", -123456789.0);
  ck_assert_str_eq(test_str_1427, test_str_1427_1427);
}
END_TEST

START_TEST(sprintf_test_1428) {
  char test_str_1428[50] = "";
  char test_str_1428_1428[50] = "";
  s21_sprintf(test_str_1428, "%.10f", -0.123456789);
  sprintf(test_str_1428_1428, "%.10f", -0.123456789);
  ck_assert_str_eq(test_str_1428, test_str_1428_1428);
}
END_TEST

START_TEST(sprintf_test_1429) {
  char test_str_1429[50] = "";
  char test_str_1429_1429[50] = "";
  s21_sprintf(test_str_1429, "%.10f", 123456789.12345679);
  sprintf(test_str_1429_1429, "%.10f", 123456789.12345679);
  ck_assert_str_eq(test_str_1429, test_str_1429_1429);
}
END_TEST

START_TEST(sprintf_test_1430) {
  char test_str_1430[50] = "";
  char test_str_1430_1430[50] = "";
  s21_sprintf(test_str_1430, "%.10f", -123456789.12345678);
  sprintf(test_str_1430_1430, "%.10f", -123456789.12345678);
  ck_assert_str_eq(test_str_1430, test_str_1430_1430);
}
END_TEST

START_TEST(sprintf_test_1431) {
  char test_str_1431[50] = "";
  char test_str_1431_1431[50] = "";
  s21_sprintf(test_str_1431, "%.10f", 1.23e-09);
  sprintf(test_str_1431_1431, "%.10f", 1.23e-09);
  ck_assert_str_eq(test_str_1431, test_str_1431_1431);
}
END_TEST

START_TEST(sprintf_test_1432) {
  char test_str_1432[50] = "";
  char test_str_1432_1432[50] = "";
  s21_sprintf(test_str_1432, "%.10f", 1.23e-09);
  sprintf(test_str_1432_1432, "%.10f", 1.23e-09);
  ck_assert_str_eq(test_str_1432, test_str_1432_1432);
}
END_TEST

START_TEST(sprintf_test_1433) {
  char test_str_1433[50] = "";
  char test_str_1433_1433[50] = "";
  s21_sprintf(test_str_1433, "%.14f", 0.0);
  sprintf(test_str_1433_1433, "%.14f", 0.0);
  ck_assert_str_eq(test_str_1433, test_str_1433_1433);
}
END_TEST

START_TEST(sprintf_test_1434) {
  char test_str_1434[50] = "";
  char test_str_1434_1434[50] = "";
  s21_sprintf(test_str_1434, "%.14f", 123456789.0);
  sprintf(test_str_1434_1434, "%.14f", 123456789.0);
  ck_assert_str_eq(test_str_1434, test_str_1434_1434);
}
END_TEST

START_TEST(sprintf_test_1435) {
  char test_str_1435[50] = "";
  char test_str_1435_1435[50] = "";
  s21_sprintf(test_str_1435, "%.14f", 0.123456789);
  sprintf(test_str_1435_1435, "%.14f", 0.123456789);
  ck_assert_str_eq(test_str_1435, test_str_1435_1435);
}
END_TEST

START_TEST(sprintf_test_1436) {
  char test_str_1436[50] = "";
  char test_str_1436_1436[50] = "";
  s21_sprintf(test_str_1436, "%.14f", -123456789.0);
  sprintf(test_str_1436_1436, "%.14f", -123456789.0);
  ck_assert_str_eq(test_str_1436, test_str_1436_1436);
}
END_TEST

START_TEST(sprintf_test_1437) {
  char test_str_1437[50] = "";
  char test_str_1437_1437[50] = "";
  s21_sprintf(test_str_1437, "%.14f", -0.123456789);
  sprintf(test_str_1437_1437, "%.14f", -0.123456789);
  ck_assert_str_eq(test_str_1437, test_str_1437_1437);
}
END_TEST

START_TEST(sprintf_test_1438) {
  char test_str_1438[50] = "";
  char test_str_1438_1438[50] = "";
  s21_sprintf(test_str_1438, "%.14f", 123456789.12345679);
  sprintf(test_str_1438_1438, "%.14f", 123456789.12345679);
  ck_assert_str_eq(test_str_1438, test_str_1438_1438);
}
END_TEST

START_TEST(sprintf_test_1439) {
  char test_str_1439[50] = "";
  char test_str_1439_1439[50] = "";
  s21_sprintf(test_str_1439, "%.14f", -123456789.12345678);
  sprintf(test_str_1439_1439, "%.14f", -123456789.12345678);
  ck_assert_str_eq(test_str_1439, test_str_1439_1439);
}
END_TEST

START_TEST(sprintf_test_1440) {
  char test_str_1440[50] = "";
  char test_str_1440_1440[50] = "";
  s21_sprintf(test_str_1440, "%.14f", 1.23e-09);
  sprintf(test_str_1440_1440, "%.14f", 1.23e-09);
  ck_assert_str_eq(test_str_1440, test_str_1440_1440);
}
END_TEST

START_TEST(sprintf_test_1441) {
  char test_str_1441[50] = "";
  char test_str_1441_1441[50] = "";
  s21_sprintf(test_str_1441, "%.14f", 1.23e-09);
  sprintf(test_str_1441_1441, "%.14f", 1.23e-09);
  ck_assert_str_eq(test_str_1441, test_str_1441_1441);
}
END_TEST

START_TEST(sprintf_test_1442) {
  char test_str_1442[50] = "";
  char test_str_1442_1442[50] = "";
  s21_sprintf(test_str_1442, "%.1f", 0.0);
  sprintf(test_str_1442_1442, "%.1f", 0.0);
  ck_assert_str_eq(test_str_1442, test_str_1442_1442);
}
END_TEST

START_TEST(sprintf_test_1443) {
  char test_str_1443[50] = "";
  char test_str_1443_1443[50] = "";
  s21_sprintf(test_str_1443, "%.1f", 123456789.0);
  sprintf(test_str_1443_1443, "%.1f", 123456789.0);
  ck_assert_str_eq(test_str_1443, test_str_1443_1443);
}
END_TEST

START_TEST(sprintf_test_1444) {
  char test_str_1444[50] = "";
  char test_str_1444_1444[50] = "";
  s21_sprintf(test_str_1444, "%.1f", 0.123456789);
  sprintf(test_str_1444_1444, "%.1f", 0.123456789);
  ck_assert_str_eq(test_str_1444, test_str_1444_1444);
}
END_TEST

START_TEST(sprintf_test_1445) {
  char test_str_1445[50] = "";
  char test_str_1445_1445[50] = "";
  s21_sprintf(test_str_1445, "%.1f", -123456789.0);
  sprintf(test_str_1445_1445, "%.1f", -123456789.0);
  ck_assert_str_eq(test_str_1445, test_str_1445_1445);
}
END_TEST

START_TEST(sprintf_test_1446) {
  char test_str_1446[50] = "";
  char test_str_1446_1446[50] = "";
  s21_sprintf(test_str_1446, "%.1f", -0.123456789);
  sprintf(test_str_1446_1446, "%.1f", -0.123456789);
  ck_assert_str_eq(test_str_1446, test_str_1446_1446);
}
END_TEST

START_TEST(sprintf_test_1447) {
  char test_str_1447[50] = "";
  char test_str_1447_1447[50] = "";
  s21_sprintf(test_str_1447, "%.1f", 123456789.12345679);
  sprintf(test_str_1447_1447, "%.1f", 123456789.12345679);
  ck_assert_str_eq(test_str_1447, test_str_1447_1447);
}
END_TEST

START_TEST(sprintf_test_1448) {
  char test_str_1448[50] = "";
  char test_str_1448_1448[50] = "";
  s21_sprintf(test_str_1448, "%.1f", -123456789.12345678);
  sprintf(test_str_1448_1448, "%.1f", -123456789.12345678);
  ck_assert_str_eq(test_str_1448, test_str_1448_1448);
}
END_TEST

START_TEST(sprintf_test_1449) {
  char test_str_1449[50] = "";
  char test_str_1449_1449[50] = "";
  s21_sprintf(test_str_1449, "%.1f", 1.23e-09);
  sprintf(test_str_1449_1449, "%.1f", 1.23e-09);
  ck_assert_str_eq(test_str_1449, test_str_1449_1449);
}
END_TEST

START_TEST(sprintf_test_1450) {
  char test_str_1450[50] = "";
  char test_str_1450_1450[50] = "";
  s21_sprintf(test_str_1450, "%.1f", 1.23e-09);
  sprintf(test_str_1450_1450, "%.1f", 1.23e-09);
  ck_assert_str_eq(test_str_1450, test_str_1450_1450);
}
END_TEST

int main() {
  int cnt_failed = 0;

  //----------------------------------------------------------------
  printf("\nOTHER_TEST\n");
  //----------------------------------------------------------------

  Suite *suite = s21_memchr_test("s21_memchr:");
  SRunner *tc_memchr = srunner_create(suite);
  srunner_set_fork_status(tc_memchr, CK_NOFORK);
  srunner_run_all(tc_memchr, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(tc_memchr);
  srunner_free(tc_memchr);

  suite = s21_memcmp_test("s21_memcmp:");
  SRunner *tc_memcmp = srunner_create(suite);
  srunner_set_fork_status(tc_memcmp, CK_NOFORK);
  srunner_run_all(tc_memcmp, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(tc_memcmp);
  srunner_free(tc_memcmp);

  suite = s21_memcpy_test("s21_memcpy:");
  SRunner *tc_memcpy = srunner_create(suite);
  srunner_set_fork_status(tc_memcpy, CK_NOFORK);
  srunner_run_all(tc_memcpy, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(tc_memcpy);
  srunner_free(tc_memcpy);

  suite = s21_memset_test("s21_memset:");
  SRunner *tc_memset = srunner_create(suite);
  srunner_set_fork_status(tc_memset, CK_NOFORK);
  srunner_run_all(tc_memset, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(tc_memset);
  srunner_free(tc_memset);

  suite = s21_strncat_test("s21_strncat:");
  SRunner *tc_strncat = srunner_create(suite);
  srunner_set_fork_status(tc_strncat, CK_NOFORK);
  srunner_run_all(tc_strncat, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(tc_strncat);
  srunner_free(tc_strncat);

  suite = s21_strchr_test("s21_strchr:");
  SRunner *tc_strchr = srunner_create(suite);
  srunner_set_fork_status(tc_strchr, CK_NOFORK);
  srunner_run_all(tc_strchr, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(tc_strchr);
  srunner_free(tc_strchr);

  suite = s21_strncmp_test("s21_strcmp:");
  SRunner *tc_strncmp = srunner_create(suite);
  srunner_set_fork_status(tc_strncmp, CK_NOFORK);
  srunner_run_all(tc_strncmp, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(tc_strncmp);
  srunner_free(tc_strncmp);

  suite = s21_strncpy_test("s21_strncpy:");
  SRunner *tc_strncpy = srunner_create(suite);
  srunner_set_fork_status(tc_strncpy, CK_NOFORK);
  srunner_run_all(tc_strncpy, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(tc_strncpy);
  srunner_free(tc_strncpy);

  suite = s21_strcspn_test("s21_strcspn:");
  SRunner *tc_strcspn = srunner_create(suite);
  srunner_set_fork_status(tc_strcspn, CK_NOFORK);
  srunner_run_all(tc_strcspn, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(tc_strcspn);
  srunner_free(tc_strcspn);

  suite = s21_strlen_test("s21_strlen:");
  SRunner *tc_strlen = srunner_create(suite);
  srunner_set_fork_status(tc_strlen, CK_NOFORK);
  srunner_run_all(tc_strlen, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(tc_strlen);
  srunner_free(tc_strlen);

  suite = s21_strerror_test("s21_strerror:");
  SRunner *tc_strerror = srunner_create(suite);
  srunner_set_fork_status(tc_strerror, CK_NOFORK);
  srunner_run_all(tc_strerror, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(tc_strerror);
  srunner_free(tc_strerror);

  suite = s21_strpbrk_test("s21_strpbrk:");
  SRunner *tc_strpbrk = srunner_create(suite);
  srunner_set_fork_status(tc_strpbrk, CK_NOFORK);
  srunner_run_all(tc_strpbrk, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(tc_strpbrk);
  srunner_free(tc_strpbrk);

  suite = s21_strrchr_test("s21_strrchr:");
  SRunner *tc_strrchr = srunner_create(suite);
  srunner_set_fork_status(tc_strrchr, CK_NOFORK);
  srunner_run_all(tc_strrchr, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(tc_strrchr);
  srunner_free(tc_strrchr);

  suite = s21_strstr_test("s21_strstr:");
  SRunner *tc_strstr = srunner_create(suite);
  srunner_set_fork_status(tc_strstr, CK_NOFORK);
  srunner_run_all(tc_strstr, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(tc_strstr);
  srunner_free(tc_strstr);

  suite = s21_strtok_test("s21_strtok:");
  SRunner *tc_strtok = srunner_create(suite);
  srunner_set_fork_status(tc_strtok, CK_NOFORK);
  srunner_run_all(tc_strtok, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(tc_strtok);
  srunner_free(tc_strtok);

  //----------------------------------------------------------------
  printf("\nC_SHARP_TEST\n");
  //----------------------------------------------------------------

  suite = to_upper_suite();
  SRunner *to_upper_tcase = srunner_create(suite);
  srunner_set_fork_status(to_upper_tcase, CK_NOFORK);
  srunner_run_all(to_upper_tcase, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(to_upper_tcase);
  srunner_free(to_upper_tcase);

  suite = to_lower_suite();
  SRunner *to_lower_suite = srunner_create(suite);
  srunner_set_fork_status(to_lower_suite, CK_NOFORK);
  srunner_run_all(to_lower_suite, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(to_lower_suite);
  srunner_free(to_lower_suite);

  suite = insert_suite();
  SRunner *insert_suite = srunner_create(suite);
  srunner_set_fork_status(insert_suite, CK_NOFORK);
  srunner_run_all(insert_suite, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(insert_suite);
  srunner_free(insert_suite);

  suite = trim_suite();
  SRunner *trim_suite = srunner_create(suite);
  srunner_set_fork_status(trim_suite, CK_NOFORK);
  srunner_run_all(trim_suite, CK_NORMAL);
  cnt_failed += srunner_ntests_failed(trim_suite);
  srunner_free(trim_suite);

  //----------------------------------------------------------------
  printf("\nSPRINTF_TEST\n");
  //----------------------------------------------------------------

  Suite *s1 = suite_create("Core1");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, tc1_1);

  {
    tcase_add_test(tc1_1, sprintf_test_1);
    tcase_add_test(tc1_1, sprintf_test_2);
    tcase_add_test(tc1_1, sprintf_test_3);
    tcase_add_test(tc1_1, sprintf_test_4);
    tcase_add_test(tc1_1, sprintf_test_5);
    tcase_add_test(tc1_1, sprintf_test_6);
    tcase_add_test(tc1_1, sprintf_test_7);
    tcase_add_test(tc1_1, sprintf_test_8);
    tcase_add_test(tc1_1, sprintf_test_9);
    tcase_add_test(tc1_1, sprintf_test_10);
    tcase_add_test(tc1_1, sprintf_test_11);
    tcase_add_test(tc1_1, sprintf_test_12);
    tcase_add_test(tc1_1, sprintf_test_13);
    tcase_add_test(tc1_1, sprintf_test_14);
    tcase_add_test(tc1_1, sprintf_test_15);
    tcase_add_test(tc1_1, sprintf_test_16);
    tcase_add_test(tc1_1, sprintf_test_17);
    tcase_add_test(tc1_1, sprintf_test_18);
    tcase_add_test(tc1_1, sprintf_test_28);
    tcase_add_test(tc1_1, sprintf_test_29);
    tcase_add_test(tc1_1, sprintf_test_30);
    tcase_add_test(tc1_1, sprintf_test_31);
    tcase_add_test(tc1_1, sprintf_test_32);
    tcase_add_test(tc1_1, sprintf_test_33);
    tcase_add_test(tc1_1, sprintf_test_34);
    tcase_add_test(tc1_1, sprintf_test_35);
    tcase_add_test(tc1_1, sprintf_test_36);
    tcase_add_test(tc1_1, sprintf_test_55);
    tcase_add_test(tc1_1, sprintf_test_56);
    tcase_add_test(tc1_1, sprintf_test_57);
    tcase_add_test(tc1_1, sprintf_test_58);
    tcase_add_test(tc1_1, sprintf_test_59);
    tcase_add_test(tc1_1, sprintf_test_60);
    tcase_add_test(tc1_1, sprintf_test_61);
    tcase_add_test(tc1_1, sprintf_test_62);
    tcase_add_test(tc1_1, sprintf_test_63);
    tcase_add_test(tc1_1, sprintf_test_64);
    tcase_add_test(tc1_1, sprintf_test_65);
    tcase_add_test(tc1_1, sprintf_test_66);
    tcase_add_test(tc1_1, sprintf_test_67);
    tcase_add_test(tc1_1, sprintf_test_68);
    tcase_add_test(tc1_1, sprintf_test_69);
    tcase_add_test(tc1_1, sprintf_test_70);
    tcase_add_test(tc1_1, sprintf_test_71);
    tcase_add_test(tc1_1, sprintf_test_72);
    tcase_add_test(tc1_1, sprintf_test_109);
    tcase_add_test(tc1_1, sprintf_test_110);
    tcase_add_test(tc1_1, sprintf_test_111);
    tcase_add_test(tc1_1, sprintf_test_112);
    tcase_add_test(tc1_1, sprintf_test_113);
    tcase_add_test(tc1_1, sprintf_test_114);
    tcase_add_test(tc1_1, sprintf_test_115);
    tcase_add_test(tc1_1, sprintf_test_116);
    tcase_add_test(tc1_1, sprintf_test_117);
    tcase_add_test(tc1_1, sprintf_test_118);
    tcase_add_test(tc1_1, sprintf_test_119);
    tcase_add_test(tc1_1, sprintf_test_120);
    tcase_add_test(tc1_1, sprintf_test_121);
    tcase_add_test(tc1_1, sprintf_test_122);
    tcase_add_test(tc1_1, sprintf_test_123);
    tcase_add_test(tc1_1, sprintf_test_124);
    tcase_add_test(tc1_1, sprintf_test_125);
    tcase_add_test(tc1_1, sprintf_test_126);
    tcase_add_test(tc1_1, sprintf_test_325);
    tcase_add_test(tc1_1, sprintf_test_326);
    tcase_add_test(tc1_1, sprintf_test_327);
    tcase_add_test(tc1_1, sprintf_test_328);
    tcase_add_test(tc1_1, sprintf_test_329);
    tcase_add_test(tc1_1, sprintf_test_330);
    tcase_add_test(tc1_1, sprintf_test_331);
    tcase_add_test(tc1_1, sprintf_test_332);
    tcase_add_test(tc1_1, sprintf_test_333);
    tcase_add_test(tc1_1, sprintf_test_334);
    tcase_add_test(tc1_1, sprintf_test_335);
    tcase_add_test(tc1_1, sprintf_test_336);
    tcase_add_test(tc1_1, sprintf_test_337);
    tcase_add_test(tc1_1, sprintf_test_338);
    tcase_add_test(tc1_1, sprintf_test_339);
    tcase_add_test(tc1_1, sprintf_test_340);
    tcase_add_test(tc1_1, sprintf_test_341);
    tcase_add_test(tc1_1, sprintf_test_342);
    tcase_add_test(tc1_1, sprintf_test_352);
    tcase_add_test(tc1_1, sprintf_test_353);
    tcase_add_test(tc1_1, sprintf_test_354);
    tcase_add_test(tc1_1, sprintf_test_355);
    tcase_add_test(tc1_1, sprintf_test_356);
    tcase_add_test(tc1_1, sprintf_test_357);
    tcase_add_test(tc1_1, sprintf_test_358);
    tcase_add_test(tc1_1, sprintf_test_359);
    tcase_add_test(tc1_1, sprintf_test_360);
    tcase_add_test(tc1_1, sprintf_test_379);
    tcase_add_test(tc1_1, sprintf_test_380);
    tcase_add_test(tc1_1, sprintf_test_381);
    tcase_add_test(tc1_1, sprintf_test_382);
    tcase_add_test(tc1_1, sprintf_test_383);
    tcase_add_test(tc1_1, sprintf_test_384);
    tcase_add_test(tc1_1, sprintf_test_385);
    tcase_add_test(tc1_1, sprintf_test_386);
    tcase_add_test(tc1_1, sprintf_test_387);
    tcase_add_test(tc1_1, sprintf_test_388);
    tcase_add_test(tc1_1, sprintf_test_389);
    tcase_add_test(tc1_1, sprintf_test_390);
    tcase_add_test(tc1_1, sprintf_test_391);
    tcase_add_test(tc1_1, sprintf_test_392);
    tcase_add_test(tc1_1, sprintf_test_393);
    tcase_add_test(tc1_1, sprintf_test_394);
    tcase_add_test(tc1_1, sprintf_test_395);
    tcase_add_test(tc1_1, sprintf_test_396);
    tcase_add_test(tc1_1, sprintf_test_406);
    tcase_add_test(tc1_1, sprintf_test_407);
    tcase_add_test(tc1_1, sprintf_test_408);
    tcase_add_test(tc1_1, sprintf_test_409);
    tcase_add_test(tc1_1, sprintf_test_410);
    tcase_add_test(tc1_1, sprintf_test_411);
    tcase_add_test(tc1_1, sprintf_test_412);
    tcase_add_test(tc1_1, sprintf_test_413);
    tcase_add_test(tc1_1, sprintf_test_414);
    tcase_add_test(tc1_1, sprintf_test_433);
    tcase_add_test(tc1_1, sprintf_test_434);
    tcase_add_test(tc1_1, sprintf_test_435);
    tcase_add_test(tc1_1, sprintf_test_436);
    tcase_add_test(tc1_1, sprintf_test_437);
    tcase_add_test(tc1_1, sprintf_test_438);
    tcase_add_test(tc1_1, sprintf_test_439);
    tcase_add_test(tc1_1, sprintf_test_440);
    tcase_add_test(tc1_1, sprintf_test_441);
    tcase_add_test(tc1_1, sprintf_test_442);
    tcase_add_test(tc1_1, sprintf_test_443);
    tcase_add_test(tc1_1, sprintf_test_444);
    tcase_add_test(tc1_1, sprintf_test_445);
    tcase_add_test(tc1_1, sprintf_test_446);
    tcase_add_test(tc1_1, sprintf_test_447);
    tcase_add_test(tc1_1, sprintf_test_448);
    tcase_add_test(tc1_1, sprintf_test_449);
    tcase_add_test(tc1_1, sprintf_test_450);
    tcase_add_test(tc1_1, sprintf_test_460);
    tcase_add_test(tc1_1, sprintf_test_461);
    tcase_add_test(tc1_1, sprintf_test_462);
    tcase_add_test(tc1_1, sprintf_test_463);
    tcase_add_test(tc1_1, sprintf_test_464);
    tcase_add_test(tc1_1, sprintf_test_465);
    tcase_add_test(tc1_1, sprintf_test_466);
    tcase_add_test(tc1_1, sprintf_test_467);
    tcase_add_test(tc1_1, sprintf_test_468);
    tcase_add_test(tc1_1, sprintf_test_487);
    tcase_add_test(tc1_1, sprintf_test_488);
    tcase_add_test(tc1_1, sprintf_test_489);
    tcase_add_test(tc1_1, sprintf_test_490);
    tcase_add_test(tc1_1, sprintf_test_491);
    tcase_add_test(tc1_1, sprintf_test_492);
    tcase_add_test(tc1_1, sprintf_test_493);
    tcase_add_test(tc1_1, sprintf_test_494);
    tcase_add_test(tc1_1, sprintf_test_495);
    tcase_add_test(tc1_1, sprintf_test_496);
    tcase_add_test(tc1_1, sprintf_test_497);
    tcase_add_test(tc1_1, sprintf_test_498);
    tcase_add_test(tc1_1, sprintf_test_499);
    tcase_add_test(tc1_1, sprintf_test_500);
    tcase_add_test(tc1_1, sprintf_test_501);
    tcase_add_test(tc1_1, sprintf_test_502);
    tcase_add_test(tc1_1, sprintf_test_503);
    tcase_add_test(tc1_1, sprintf_test_504);
    tcase_add_test(tc1_1, sprintf_test_514);
    tcase_add_test(tc1_1, sprintf_test_515);
    tcase_add_test(tc1_1, sprintf_test_516);
    tcase_add_test(tc1_1, sprintf_test_517);
    tcase_add_test(tc1_1, sprintf_test_518);
    tcase_add_test(tc1_1, sprintf_test_519);
    tcase_add_test(tc1_1, sprintf_test_520);
    tcase_add_test(tc1_1, sprintf_test_521);
    tcase_add_test(tc1_1, sprintf_test_522);
    tcase_add_test(tc1_1, sprintf_test_811);
    tcase_add_test(tc1_1, sprintf_test_812);
    tcase_add_test(tc1_1, sprintf_test_813);
    tcase_add_test(tc1_1, sprintf_test_814);
    tcase_add_test(tc1_1, sprintf_test_815);
    tcase_add_test(tc1_1, sprintf_test_816);
    tcase_add_test(tc1_1, sprintf_test_817);
    tcase_add_test(tc1_1, sprintf_test_818);
    tcase_add_test(tc1_1, sprintf_test_819);
    tcase_add_test(tc1_1, sprintf_test_820);
    tcase_add_test(tc1_1, sprintf_test_821);
    tcase_add_test(tc1_1, sprintf_test_822);
    tcase_add_test(tc1_1, sprintf_test_823);
    tcase_add_test(tc1_1, sprintf_test_824);
    tcase_add_test(tc1_1, sprintf_test_825);
    tcase_add_test(tc1_1, sprintf_test_826);
    tcase_add_test(tc1_1, sprintf_test_827);
    tcase_add_test(tc1_1, sprintf_test_828);
    tcase_add_test(tc1_1, sprintf_test_838);
    tcase_add_test(tc1_1, sprintf_test_839);
    tcase_add_test(tc1_1, sprintf_test_840);
    tcase_add_test(tc1_1, sprintf_test_841);
    tcase_add_test(tc1_1, sprintf_test_842);
    tcase_add_test(tc1_1, sprintf_test_843);
    tcase_add_test(tc1_1, sprintf_test_844);
    tcase_add_test(tc1_1, sprintf_test_845);
    tcase_add_test(tc1_1, sprintf_test_846);
    tcase_add_test(tc1_1, sprintf_test_865);
    tcase_add_test(tc1_1, sprintf_test_866);
    tcase_add_test(tc1_1, sprintf_test_867);
    tcase_add_test(tc1_1, sprintf_test_868);
    tcase_add_test(tc1_1, sprintf_test_869);
    tcase_add_test(tc1_1, sprintf_test_870);
    tcase_add_test(tc1_1, sprintf_test_871);
    tcase_add_test(tc1_1, sprintf_test_872);
    tcase_add_test(tc1_1, sprintf_test_873);
    tcase_add_test(tc1_1, sprintf_test_874);
    tcase_add_test(tc1_1, sprintf_test_875);
    tcase_add_test(tc1_1, sprintf_test_876);
    tcase_add_test(tc1_1, sprintf_test_877);
    tcase_add_test(tc1_1, sprintf_test_878);
    tcase_add_test(tc1_1, sprintf_test_879);
    tcase_add_test(tc1_1, sprintf_test_880);
    tcase_add_test(tc1_1, sprintf_test_881);
    tcase_add_test(tc1_1, sprintf_test_882);
    tcase_add_test(tc1_1, sprintf_test_892);
    tcase_add_test(tc1_1, sprintf_test_893);
    tcase_add_test(tc1_1, sprintf_test_894);
    tcase_add_test(tc1_1, sprintf_test_895);
    tcase_add_test(tc1_1, sprintf_test_896);
    tcase_add_test(tc1_1, sprintf_test_897);
    tcase_add_test(tc1_1, sprintf_test_898);
    tcase_add_test(tc1_1, sprintf_test_899);
    tcase_add_test(tc1_1, sprintf_test_900);
    tcase_add_test(tc1_1, sprintf_test_919);
    tcase_add_test(tc1_1, sprintf_test_920);
    tcase_add_test(tc1_1, sprintf_test_921);
    tcase_add_test(tc1_1, sprintf_test_922);
    tcase_add_test(tc1_1, sprintf_test_923);
    tcase_add_test(tc1_1, sprintf_test_924);
    tcase_add_test(tc1_1, sprintf_test_925);
    tcase_add_test(tc1_1, sprintf_test_926);
    tcase_add_test(tc1_1, sprintf_test_927);
    tcase_add_test(tc1_1, sprintf_test_928);
    tcase_add_test(tc1_1, sprintf_test_929);
    tcase_add_test(tc1_1, sprintf_test_930);
    tcase_add_test(tc1_1, sprintf_test_931);
    tcase_add_test(tc1_1, sprintf_test_932);
    tcase_add_test(tc1_1, sprintf_test_933);
    tcase_add_test(tc1_1, sprintf_test_934);
    tcase_add_test(tc1_1, sprintf_test_935);
    tcase_add_test(tc1_1, sprintf_test_936);
    tcase_add_test(tc1_1, sprintf_test_946);
    tcase_add_test(tc1_1, sprintf_test_947);
    tcase_add_test(tc1_1, sprintf_test_948);
    tcase_add_test(tc1_1, sprintf_test_949);
    tcase_add_test(tc1_1, sprintf_test_950);
    tcase_add_test(tc1_1, sprintf_test_951);
    tcase_add_test(tc1_1, sprintf_test_952);
    tcase_add_test(tc1_1, sprintf_test_953);
    tcase_add_test(tc1_1, sprintf_test_954);
    tcase_add_test(tc1_1, sprintf_test_1081);
    tcase_add_test(tc1_1, sprintf_test_1082);
    tcase_add_test(tc1_1, sprintf_test_1083);
    tcase_add_test(tc1_1, sprintf_test_1084);
    tcase_add_test(tc1_1, sprintf_test_1085);
    tcase_add_test(tc1_1, sprintf_test_1086);
    tcase_add_test(tc1_1, sprintf_test_1087);
    tcase_add_test(tc1_1, sprintf_test_1088);
    tcase_add_test(tc1_1, sprintf_test_1089);
    tcase_add_test(tc1_1, sprintf_test_1090);
    tcase_add_test(tc1_1, sprintf_test_1091);
    tcase_add_test(tc1_1, sprintf_test_1092);
    tcase_add_test(tc1_1, sprintf_test_1093);
    tcase_add_test(tc1_1, sprintf_test_1094);
    tcase_add_test(tc1_1, sprintf_test_1095);
    tcase_add_test(tc1_1, sprintf_test_1096);
    tcase_add_test(tc1_1, sprintf_test_1097);
    tcase_add_test(tc1_1, sprintf_test_1098);
    tcase_add_test(tc1_1, sprintf_test_1108);
    tcase_add_test(tc1_1, sprintf_test_1109);
    tcase_add_test(tc1_1, sprintf_test_1110);
    tcase_add_test(tc1_1, sprintf_test_1111);
    tcase_add_test(tc1_1, sprintf_test_1112);
    tcase_add_test(tc1_1, sprintf_test_1113);
    tcase_add_test(tc1_1, sprintf_test_1114);
    tcase_add_test(tc1_1, sprintf_test_1115);
    tcase_add_test(tc1_1, sprintf_test_1116);
    tcase_add_test(tc1_1, sprintf_test_1189);
    tcase_add_test(tc1_1, sprintf_test_1190);
    tcase_add_test(tc1_1, sprintf_test_1191);
    tcase_add_test(tc1_1, sprintf_test_1192);
    tcase_add_test(tc1_1, sprintf_test_1197);
    tcase_add_test(tc1_1, sprintf_test_1198);
    tcase_add_test(tc1_1, sprintf_test_1199);
    tcase_add_test(tc1_1, sprintf_test_1200);
    tcase_add_test(tc1_1, sprintf_test_1209);
    tcase_add_test(tc1_1, sprintf_test_1210);
    tcase_add_test(tc1_1, sprintf_test_1211);
    tcase_add_test(tc1_1, sprintf_test_1212);
    tcase_add_test(tc1_1, sprintf_test_1217);
    tcase_add_test(tc1_1, sprintf_test_1218);
    tcase_add_test(tc1_1, sprintf_test_1219);
    tcase_add_test(tc1_1, sprintf_test_1220);
    tcase_add_test(tc1_1, sprintf_test_1221);
    tcase_add_test(tc1_1, sprintf_test_1222);
    tcase_add_test(tc1_1, sprintf_test_1223);
    tcase_add_test(tc1_1, sprintf_test_1224);
    tcase_add_test(tc1_1, sprintf_test_1225);
    tcase_add_test(tc1_1, sprintf_test_1226);
    tcase_add_test(tc1_1, sprintf_test_1227);
    tcase_add_test(tc1_1, sprintf_test_1228);
    tcase_add_test(tc1_1, sprintf_test_1249);
    tcase_add_test(tc1_1, sprintf_test_1250);
    tcase_add_test(tc1_1, sprintf_test_1251);
    tcase_add_test(tc1_1, sprintf_test_1252);
    tcase_add_test(tc1_1, sprintf_test_1257);
    tcase_add_test(tc1_1, sprintf_test_1258);
    tcase_add_test(tc1_1, sprintf_test_1259);
    tcase_add_test(tc1_1, sprintf_test_1260);
    tcase_add_test(tc1_1, sprintf_test_1269);
    tcase_add_test(tc1_1, sprintf_test_1270);
    tcase_add_test(tc1_1, sprintf_test_1271);
    tcase_add_test(tc1_1, sprintf_test_1272);
    tcase_add_test(tc1_1, sprintf_test_1281);
    tcase_add_test(tc1_1, sprintf_test_1282);
    tcase_add_test(tc1_1, sprintf_test_1283);
    tcase_add_test(tc1_1, sprintf_test_1284);
    tcase_add_test(tc1_1, sprintf_test_1285);
    tcase_add_test(tc1_1, sprintf_test_1286);
    tcase_add_test(tc1_1, sprintf_test_1287);
    tcase_add_test(tc1_1, sprintf_test_1288);
    tcase_add_test(tc1_1, sprintf_test_1289);
    tcase_add_test(tc1_1, sprintf_test_1290);
    tcase_add_test(tc1_1, sprintf_test_1291);
    tcase_add_test(tc1_1, sprintf_test_1292);
    tcase_add_test(tc1_1, sprintf_test_1293);
    tcase_add_test(tc1_1, sprintf_test_1294);
    tcase_add_test(tc1_1, sprintf_test_1295);
    tcase_add_test(tc1_1, sprintf_test_1296);
    tcase_add_test(tc1_1, sprintf_test_1297);
    tcase_add_test(tc1_1, sprintf_test_1298);
    tcase_add_test(tc1_1, sprintf_test_1299);
    tcase_add_test(tc1_1, sprintf_test_1300);
    tcase_add_test(tc1_1, sprintf_test_1301);
    tcase_add_test(tc1_1, sprintf_test_1302);
    tcase_add_test(tc1_1, sprintf_test_1303);
    tcase_add_test(tc1_1, sprintf_test_1304);
    tcase_add_test(tc1_1, sprintf_test_1305);
    tcase_add_test(tc1_1, sprintf_test_1306);
    tcase_add_test(tc1_1, sprintf_test_1307);
    tcase_add_test(tc1_1, sprintf_test_1308);
    tcase_add_test(tc1_1, sprintf_test_1309);
    tcase_add_test(tc1_1, sprintf_test_1310);
    tcase_add_test(tc1_1, sprintf_test_1311);
    tcase_add_test(tc1_1, sprintf_test_1312);
    tcase_add_test(tc1_1, sprintf_test_1313);
    tcase_add_test(tc1_1, sprintf_test_1314);
    tcase_add_test(tc1_1, sprintf_test_1315);
    tcase_add_test(tc1_1, sprintf_test_1325);
    tcase_add_test(tc1_1, sprintf_test_1326);
    tcase_add_test(tc1_1, sprintf_test_1327);
    tcase_add_test(tc1_1, sprintf_test_1328);
    tcase_add_test(tc1_1, sprintf_test_1329);
    tcase_add_test(tc1_1, sprintf_test_1330);
    tcase_add_test(tc1_1, sprintf_test_1331);
    tcase_add_test(tc1_1, sprintf_test_1332);
    tcase_add_test(tc1_1, sprintf_test_1333);
    tcase_add_test(tc1_1, sprintf_test_1334);
    tcase_add_test(tc1_1, sprintf_test_1335);
    tcase_add_test(tc1_1, sprintf_test_1336);
    tcase_add_test(tc1_1, sprintf_test_1337);
    tcase_add_test(tc1_1, sprintf_test_1338);
    tcase_add_test(tc1_1, sprintf_test_1339);
    tcase_add_test(tc1_1, sprintf_test_1340);
    tcase_add_test(tc1_1, sprintf_test_1341);
    tcase_add_test(tc1_1, sprintf_test_1342);
    tcase_add_test(tc1_1, sprintf_test_1343);
    tcase_add_test(tc1_1, sprintf_test_1344);
    tcase_add_test(tc1_1, sprintf_test_1345);
    tcase_add_test(tc1_1, sprintf_test_1346);
    tcase_add_test(tc1_1, sprintf_test_1347);
    tcase_add_test(tc1_1, sprintf_test_1348);
    tcase_add_test(tc1_1, sprintf_test_1349);
    tcase_add_test(tc1_1, sprintf_test_1350);
    tcase_add_test(tc1_1, sprintf_test_1351);
    tcase_add_test(tc1_1, sprintf_test_1352);
    tcase_add_test(tc1_1, sprintf_test_1353);
    tcase_add_test(tc1_1, sprintf_test_1354);
    tcase_add_test(tc1_1, sprintf_test_1355);
    tcase_add_test(tc1_1, sprintf_test_1356);
    tcase_add_test(tc1_1, sprintf_test_1357);
    tcase_add_test(tc1_1, sprintf_test_1358);
    tcase_add_test(tc1_1, sprintf_test_1359);
    tcase_add_test(tc1_1, sprintf_test_1360);
    tcase_add_test(tc1_1, sprintf_test_1361);
    tcase_add_test(tc1_1, sprintf_test_1362);
    tcase_add_test(tc1_1, sprintf_test_1363);
    tcase_add_test(tc1_1, sprintf_test_1364);
    tcase_add_test(tc1_1, sprintf_test_1365);
    tcase_add_test(tc1_1, sprintf_test_1366);
    tcase_add_test(tc1_1, sprintf_test_1367);
    tcase_add_test(tc1_1, sprintf_test_1368);
    tcase_add_test(tc1_1, sprintf_test_1369);
    tcase_add_test(tc1_1, sprintf_test_1370);
    tcase_add_test(tc1_1, sprintf_test_1371);
    tcase_add_test(tc1_1, sprintf_test_1372);
    tcase_add_test(tc1_1, sprintf_test_1373);
    tcase_add_test(tc1_1, sprintf_test_1374);
    tcase_add_test(tc1_1, sprintf_test_1375);
    tcase_add_test(tc1_1, sprintf_test_1376);
    tcase_add_test(tc1_1, sprintf_test_1377);
    tcase_add_test(tc1_1, sprintf_test_1378);
    tcase_add_test(tc1_1, sprintf_test_1424);
    tcase_add_test(tc1_1, sprintf_test_1425);
    tcase_add_test(tc1_1, sprintf_test_1426);
    tcase_add_test(tc1_1, sprintf_test_1427);
    tcase_add_test(tc1_1, sprintf_test_1428);
    tcase_add_test(tc1_1, sprintf_test_1429);
    tcase_add_test(tc1_1, sprintf_test_1430);
    tcase_add_test(tc1_1, sprintf_test_1431);
    tcase_add_test(tc1_1, sprintf_test_1432);
    tcase_add_test(tc1_1, sprintf_test_1433);
    tcase_add_test(tc1_1, sprintf_test_1434);
    tcase_add_test(tc1_1, sprintf_test_1435);
    tcase_add_test(tc1_1, sprintf_test_1436);
    tcase_add_test(tc1_1, sprintf_test_1437);
    tcase_add_test(tc1_1, sprintf_test_1438);
    tcase_add_test(tc1_1, sprintf_test_1439);
    tcase_add_test(tc1_1, sprintf_test_1440);
    tcase_add_test(tc1_1, sprintf_test_1441);
    tcase_add_test(tc1_1, sprintf_test_1442);
    tcase_add_test(tc1_1, sprintf_test_1443);
    tcase_add_test(tc1_1, sprintf_test_1444);
    tcase_add_test(tc1_1, sprintf_test_1445);
    tcase_add_test(tc1_1, sprintf_test_1446);
    tcase_add_test(tc1_1, sprintf_test_1447);
    tcase_add_test(tc1_1, sprintf_test_1448);
    tcase_add_test(tc1_1, sprintf_test_1449);
    tcase_add_test(tc1_1, sprintf_test_1450);
  }
  srunner_run_all(sr, CK_ENV);
  // int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  Suite *ss1 = suite_create("Core1");
  TCase *ttc1_1 = tcase_create("Core");
  SRunner *ssr = srunner_create(ss1);
  suite_add_tcase(ss1, ttc1_1);
  {
    tcase_add_test(ttc1_1, one_sscanf);
    tcase_add_test(ttc1_1, two_sscanf);
    tcase_add_test(ttc1_1, tree_sscanf);
    tcase_add_test(ttc1_1, fore_sscanf);
    tcase_add_test(ttc1_1, five_sscanf);
    // tcase_add_test(ttc1_1, six_sscanf);
    // tcase_add_test(ttc1_1, seven_sscanf);
    tcase_add_test(ttc1_1, eight_sscanf);
    tcase_add_test(ttc1_1, symbol_sscanf);
    tcase_add_test(ttc1_1, n_sscanf);
    tcase_add_test(ttc1_1, proc_sscanf);
    tcase_add_test(ttc1_1, f_one_sscanf);
    tcase_add_test(ttc1_1, f_two_sscanf);
    tcase_add_test(ttc1_1, f_tree_sscanf);
    tcase_add_test(ttc1_1, f_fore_sscanf);
    tcase_add_test(ttc1_1, f_five_sscanf);
    tcase_add_test(ttc1_1, f_six_sscanf);
    tcase_add_test(ttc1_1, f_seven_sscanf);
    tcase_add_test(ttc1_1, f_eight_sscanf);
    tcase_add_test(ttc1_1, f_nine_sscanf);
    tcase_add_test(ttc1_1, f_ten_sscanf);
    tcase_add_test(ttc1_1, o_one_sscanf);
    tcase_add_test(ttc1_1, o_two_sscanf);
    tcase_add_test(ttc1_1, o_tree_sscanf);
    // tcase_add_test(ttc1_1, o_fore_sscanf);
    tcase_add_test(ttc1_1, o_five_sscanf);
    // tcase_add_test(ttc1_1, o_six_sscanf);
    // tcase_add_test(ttc1_1, o_seven_sscanf);
    tcase_add_test(ttc1_1, o_eight_sscanf);
    tcase_add_test(ttc1_1, x_one_sscanf);
    tcase_add_test(ttc1_1, x_two_sscanf);
    tcase_add_test(ttc1_1, x_tree_sscanf);
    // tcase_add_test(ttc1_1, x_fore_sscanf);
    tcase_add_test(ttc1_1, x_five_sscanf);
    // tcase_add_test(ttc1_1, x_six_sscanf);
    // tcase_add_test(ttc1_1, x_seven_sscanf);
    tcase_add_test(ttc1_1, u_sscanf);
    // tcase_add_test(ttc1_1, hh_sscanf);
    // tcase_add_test(ttc1_1, ll_sscanf);
    // tcase_add_test(ttc1_1, nu_sscanf);
    tcase_add_test(ttc1_1, i_sscanf);
    tcase_add_test(ttc1_1, ix_sscanf);
    tcase_add_test(ttc1_1, id_sscanf);
    tcase_add_test(ttc1_1, id_minus_sscanf);
    tcase_add_test(ttc1_1, p_sscanf);
    tcase_add_test(ttc1_1, pn_sscanf);
    // tcase_add_test(ttc1_1, string_sscanf);
    tcase_add_test(ttc1_1, dot_sscanf);
    tcase_add_test(ttc1_1, dot_2_sscanf);
  }

  srunner_run_all(ssr, CK_ENV);
  // int nf = srunner_ntests_failed(sr);
  srunner_free(ssr);

  return (cnt_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
