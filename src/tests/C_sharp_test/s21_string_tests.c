#include "s21_string_tests.h"

int main(void) {
  // setenv("CK_DEFAULT_TIMEOUT", "0.1", 1);
  int cnt_failed = 0;

  // SRunner *s21_string_runner = srunner_create(to_upper_suite());
  // srunner_add_suite(s21_string_runner, to_lower_suite());
  // srunner_add_suite(s21_string_runner, insert_suite());
  // srunner_add_suite(s21_string_runner, trim_suite());

  Suite *suite = to_upper_suite();
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

  printf("\nNumber of failed tests is %d \n", cnt_failed);
  // return 0;
  return (cnt_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}