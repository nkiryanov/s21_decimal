#include <math.h>

#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  s21_decimal decimal = {0};

  if (src < 0) {
    s21_change_sign(&decimal);
    src = -src;
  }

  decimal.bits[2] = src;

  *dst = decimal;

  return 0;
}
