
#include <check.h>
#include <stdlib.h>

#include "test_cases.h"

Suite *suite_s21_decimal(void) {
  Suite *suite;

  suite = suite_create("Tests s21_decimal");
  suite_add_tcase(suite, tcase_s21_change_sign());

  return suite;
}

int main(void) {
  int number_failed;
  SRunner *sr;

  sr = srunner_create(suite_s21_decimal());

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
