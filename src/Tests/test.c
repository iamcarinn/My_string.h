#include "test.h"
// #include "test_me.h"

int run_tests(Suite *test_case) {
  int number_failed;
  SRunner *sr = srunner_create(test_case);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}

int main() {
  int number_failed = 0;

  Suite *suites_list[] = {s21_string_suite(), sprintf_suite(),
                          s21_sscanf_suite(), NULL};
  for (Suite **current = suites_list; *current != NULL; current++) {
    printf("_________________________________________\n");
    number_failed += run_tests(*current);
  }
  return 0;
}