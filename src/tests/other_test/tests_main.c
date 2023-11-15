#include "tests.h"

int main() {
  int cnt_failed = 0;

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

  return (cnt_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}