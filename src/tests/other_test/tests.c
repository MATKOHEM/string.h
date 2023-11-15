#include "tests.h"

START_TEST(test_memchr) {
  // Нужная цифра есть в строке
  char src[15] = "1234567890";
  char *sym;
  char *s21_sym;
  sym = memchr(src, '4', 10);
  s21_sym = s21_memchr(src, '4', 10);
  ck_assert_ptr_eq(sym, s21_sym);

  // Нужной цифры в строке нет
  s21_strncpy(src, "1230567890", 11);
  sym = memchr(src, '4', 10);
  s21_sym = s21_memchr(src, '4', 10);
  ck_assert_ptr_eq(sym, s21_sym);

  // поиск шире, чем строка
  s21_strncpy(src, "1230567890", 11);
  sym = memchr(src, '4', 15);
  s21_sym = s21_memchr(src, '4', 15);
  ck_assert_ptr_eq(sym, s21_sym);
}
END_TEST

START_TEST(test_memcmp) {
  // Строки одинаковые
  char str1[15] = "1234567890";
  char str2[15] = "1234567890";
  ck_assert_int_eq(memcmp(str1, str2, 10), s21_memcmp(str1, str2, 10));

  /*Различия за пределами теста функции
  (поиск на 3 байта, отличия на 6-м)*/
  char str3[15] = "Hello";
  char str4[15] = "Helll";
  ck_assert_int_eq(memcmp(str3, str4, 3), s21_memcmp(str3, str4, 3));

  // Разные строки
  char str5[15] = "Hello";
  char str6[15] = "World";
  ck_assert_int_eq(memcmp(str5, str6, 6), s21_memcmp(str5, str6, 6));

  // Пустая строка
  char str7[15] = "Hello";
  char str8[15] = "";
  ck_assert_int_eq(memcmp(str7, str8, 6), s21_memcmp(str7, str8, 6));
}
END_TEST

START_TEST(test_memcpy) {
  char src[10] = "123456";
  char dst[10] = "";
  char s21_src[10] = "123456";
  char s21_dst[10] = "";
  memcpy(dst, src, 6);
  s21_memcpy(s21_dst, s21_src, 6);
  ck_assert_str_eq(dst, s21_dst);

  char src2[10] = "12345\0006789";
  char dst2[10] = "1111111111";
  char dst3[10] = "1111111111";
  char s21_src2[10] = "12345\0006789";
  char s21_dst2[10] = "1111111111";
  char s21_dst3[10] = "1111111111";
  memcpy(dst2, src2, 3);
  memcpy(dst3, src2, 9);
  s21_memcpy(s21_dst2, s21_src2, 3);
  s21_memcpy(s21_dst3, s21_src2, 9);
  ck_assert_str_eq(dst2, s21_dst2);
  ck_assert_str_eq(dst3, s21_dst3);
}

START_TEST(test_memset) {
  char src[15] = "1234567890";
  char src2[15] = "1234567890";
  memset(src, '1', 10);
  s21_memset(src2, '1', 10);
  ck_assert_str_eq(src, src2);
}
END_TEST

START_TEST(test_strncat) {
  char str1[15] = "Hello";
  char str2[15] = "World!";
  char copy_str[50];
  char s21_copy_str[50];

  s21_strncpy(copy_str, str1, 6);
  strncat(copy_str, str2, 8);

  s21_strncpy(s21_copy_str, str1, 6);
  s21_strncat(s21_copy_str, str2, 8);
  ck_assert_str_eq(copy_str, s21_copy_str);

  s21_strncpy(copy_str, str1, 6);
  strncat(copy_str, str2, 3);

  s21_strncpy(s21_copy_str, str1, 6);
  s21_strncat(s21_copy_str, str2, 3);
  ck_assert_str_eq(copy_str, s21_copy_str);
}
END_TEST

START_TEST(test_strchr) {
  char str1[100] = "Hello";
  int ch = 101;
  char *res = strchr(str1, ch);
  char *res_s21 = s21_strchr(str1, ch);
  ck_assert_str_eq(res, res_s21);
}

START_TEST(test_strncmp) {
  ck_assert_int_eq(strncmp("12345", "12345", 5),
                   s21_strncmp("12345", "12345", 5));
  ck_assert_int_eq(strncmp("12345", "12334", 5),
                   s21_strncmp("12345", "12334", 5));
}
END_TEST

START_TEST(test_strncpy) {
  char src[100] = "12345\0006789";
  char dst1[100] = "1111111111";
  char dst2[100] = "1111111111";
  ck_assert_str_eq(strncpy(dst1, src, 3), s21_strncpy(dst2, src, 3));

  char src2[100] = "12345\0006789";
  char dst3[100] = "1111111111";
  char dst4[100] = "1111111111";
  ck_assert_str_eq(strncpy(dst3, src2, 9), s21_strncpy(dst4, src2, 9));
}
END_TEST

START_TEST(test_strcspn) {
  // int size1;
  // int size2;

  char str1[] = "School21 is the greatest school in the world";
  char str2[] = "rock";
  ck_assert_uint_eq(strcspn(str1, str2), s21_strcspn(str1, str2));

  char str[10] = "0123456789";
  char sym[10] = "9876";
  ck_assert_uint_eq(strcspn(str, sym), s21_strcspn(str, sym));
}
END_TEST

START_TEST(test_strlen) {
  ck_assert_uint_eq(s21_strlen("Hello"), strlen("Hello"));
  ck_assert_uint_eq(s21_strlen(""), strlen(""));
  ck_assert_uint_eq(s21_strlen("Hello, World"), strlen("Hello, World"));
}
END_TEST

START_TEST(test_strerror_1) {
  char *s1 = (char *)strerror(150);
  char *s2 = (char *)s21_strerror(150);
  ck_assert_str_eq(s1, s2);
  free(s2);
}
END_TEST

START_TEST(test_strerror_2) {
  char *s1 = (char *)strerror(10);
  char *s2 = (char *)s21_strerror(10);
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(test_strerror_3) {
  char *s1 = (char *)strerror(-5);
  char *s2 = (char *)s21_strerror(-5);
  ck_assert_str_eq(s1, s2);
  free(s2);
}
END_TEST

START_TEST(test_strerror_4) {
  char *s1 = (char *)strerror(33);
  char *s2 = (char *)s21_strerror(33);
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(test_strerror_5) {
  char *s1 = (char *)strerror(0);
  char *s2 = (char *)s21_strerror(0);
  ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(test_strpbrk) {
  char str[11] = "0123456789";
  char sym[10] = "369";
  ck_assert_ptr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));

  char str1[] = "School21";
  char str2[] = "Hi";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strrchr) {
  char str[11] = "0163456769";
  ck_assert_ptr_eq(strrchr(str, 6), s21_strrchr(str, 6));

  char str2[11] = "0123456769";
  ck_assert_ptr_eq(strrchr(str2, 6), s21_strrchr(str2, 6));

  char str3[] = "School21";
  ck_assert_ptr_eq(strrchr(str3, 'l'), s21_strrchr(str3, 'l'));
  ck_assert_ptr_eq(strrchr(str3, 'h'), s21_strrchr(str3, 'h'));
}
END_TEST

START_TEST(test_strstr) {
  char str[11] = "0123456789";
  ck_assert_ptr_eq(strstr(str, "345"), s21_strstr(str, "345"));
  ck_assert_ptr_eq(strstr(str, "abc"), s21_strstr(str, "abc"));
  ck_assert_ptr_eq(strstr(str, ""), s21_strstr(str, ""));
  ck_assert_ptr_eq(strstr(str, "354"), s21_strstr(str, "354"));
}
END_TEST

// START_TEST(test_strtok_1) {
//   char *str__ = s21_strtok(s21_NULL, "");
//   char *str33 = strtok(s21_NULL, "");
//   ck_assert_ptr_null(str__);
//   ck_assert_ptr_null(str33);
// }
// END_TEST
START_TEST(test_strtok_2) {
  char str[24] = "test1/test2/test3/test4";
  char *temp1 = strtok(str, "/");
  char *temp2 = s21_strtok(str, "/");
  ck_assert_str_eq(temp1, temp2);
}
END_TEST

START_TEST(test_strtok_3) {
  char str2[100] = "";
  char *temp1 = strtok(str2, "2");
  char *temp2 = s21_strtok(str2, "2");
  ck_assert_ptr_null(temp1);
  ck_assert_ptr_null(temp2);
}
END_TEST

START_TEST(test_strtok_4) {
  char str3[100] = "////////test1/test2/test3/test4//////////";
  char *temp1 = strtok(str3, "/");
  char *temp2 = s21_strtok(str3, "/");
  ck_assert_str_eq(temp1, temp2);
}
END_TEST

START_TEST(test_strtok_5) {
  char str4[100] = "///";
  char *temp1 = strtok(str4, "///");
  char *temp2 = s21_strtok(str4, "///");
  ck_assert_ptr_eq(temp1, temp2);
}
END_TEST

START_TEST(test_strtok_6) {
  char str_[] = "School21 is the greatest school in the world!?! ";
  char *str_1 = "?!?";
  char *temp1 = s21_strtok(str_, str_1);
  char *temp2 = strtok(str_, str_1);
  ck_assert_str_eq(temp1, temp2);
}
END_TEST

Suite *s21_memchr_test() {
  Suite *suite = suite_create("s21_memchr:");
  TCase *tc_memchr = tcase_create("s21_memchr test");
  tcase_add_test(tc_memchr, test_memchr);
  suite_add_tcase(suite, tc_memchr);
  return suite;
}

Suite *s21_memcmp_test() {
  Suite *suite = suite_create("s21_memcmp:");
  TCase *tc_memcmp = tcase_create("s21_memcmp test");
  tcase_add_test(tc_memcmp, test_memcmp);
  suite_add_tcase(suite, tc_memcmp);
  return suite;
}

Suite *s21_memcpy_test() {
  Suite *suite = suite_create("s21_memcpy:");
  TCase *tc_memcpy = tcase_create("s21_memcpy test");
  tcase_add_test(tc_memcpy, test_memcpy);
  suite_add_tcase(suite, tc_memcpy);
  return suite;
}

Suite *s21_memset_test() {
  Suite *suite = suite_create("s21_memset:");
  TCase *tc_memset = tcase_create("s21_memset test");
  tcase_add_test(tc_memset, test_memset);
  suite_add_tcase(suite, tc_memset);
  return suite;
}

Suite *s21_strncat_test() {
  Suite *suite = suite_create("s21_srtncat:");
  TCase *tc_strncat = tcase_create("s21_strncat test");
  tcase_add_test(tc_strncat, test_strncat);
  suite_add_tcase(suite, tc_strncat);
  return suite;
}

Suite *s21_strchr_test() {
  Suite *suite = suite_create("s21_strchr:");
  TCase *tc_strchr = tcase_create("s21_strchr test");
  tcase_add_test(tc_strchr, test_strchr);
  suite_add_tcase(suite, tc_strchr);
  return suite;
}

Suite *s21_strncmp_test() {
  Suite *suite = suite_create("s21_strncmp:");
  TCase *tc_strncmp = tcase_create("s21_strncmp test");
  tcase_add_test(tc_strncmp, test_strncmp);
  suite_add_tcase(suite, tc_strncmp);
  return suite;
}

Suite *s21_strncpy_test() {
  Suite *suite = suite_create("s21_strncpy:");
  TCase *tc_strncpy = tcase_create("s21_strncpy test");
  tcase_add_test(tc_strncpy, test_strncpy);
  suite_add_tcase(suite, tc_strncpy);
  return suite;
}

Suite *s21_strcspn_test() {
  Suite *suite = suite_create("s21_strcspn:");
  TCase *tc_strcspn = tcase_create("s21_strcspn test");
  tcase_add_test(tc_strcspn, test_strcspn);
  suite_add_tcase(suite, tc_strcspn);
  return suite;
}

Suite *s21_strlen_test() {
  Suite *suite = suite_create("s21_strlen:");
  TCase *tc_strlen = tcase_create("s21_strlen test");
  tcase_add_test(tc_strlen, test_strlen);
  suite_add_tcase(suite, tc_strlen);
  return suite;
}

Suite *s21_strerror_test() {
  Suite *suite = suite_create("s21_strerror:");
  TCase *tc_strerror = tcase_create("s21_strerror test");
  tcase_add_test(tc_strerror, test_strerror_1);
  tcase_add_test(tc_strerror, test_strerror_2);
  tcase_add_test(tc_strerror, test_strerror_3);
  tcase_add_test(tc_strerror, test_strerror_4);
  tcase_add_test(tc_strerror, test_strerror_5);
  suite_add_tcase(suite, tc_strerror);
  return suite;
}

Suite *s21_strpbrk_test() {
  Suite *suite = suite_create("s21_strpbrk:");
  TCase *tc_strpbrk = tcase_create("s21_strpbrk test");
  tcase_add_test(tc_strpbrk, test_strpbrk);
  suite_add_tcase(suite, tc_strpbrk);
  return suite;
}

Suite *s21_strrchr_test() {
  Suite *suite = suite_create("s21_strrchr:");
  TCase *tc_strrchr = tcase_create("s21_strrchr test");
  tcase_add_test(tc_strrchr, test_strrchr);
  suite_add_tcase(suite, tc_strrchr);
  return suite;
}

Suite *s21_strstr_test() {
  Suite *suite = suite_create("s21_strstr:");
  TCase *tc_strstr = tcase_create("s21_strstr test");
  tcase_add_test(tc_strstr, test_strstr);
  suite_add_tcase(suite, tc_strstr);
  return suite;
}

Suite *s21_strtok_test() {
  Suite *suite = suite_create("s21_strtok:");
  TCase *tc_strtok = tcase_create("s21_strtok test");
  // tcase_add_test(tc_strtok, test_strtok_1);
  tcase_add_test(tc_strtok, test_strtok_2);
  tcase_add_test(tc_strtok, test_strtok_3);
  tcase_add_test(tc_strtok, test_strtok_4);
  tcase_add_test(tc_strtok, test_strtok_5);
  tcase_add_test(tc_strtok, test_strtok_6);
  suite_add_tcase(suite, tc_strtok);
  return suite;
}
