#include <stdlib.h>
#include <stdio.h>

#include "s21_decimal.h"

void print_bits(size_t size, void *value_ptr) {
  // Assume we work with little endian
  char byte_bits;
  unsigned char *value_as_bytes;

  value_as_bytes = (unsigned char *)value_ptr;

  for (size_t byte_number = size; byte_number > 0; byte_number--) {
    byte_bits = value_as_bytes[byte_number - 1];

    for (char bit_number = 7; bit_number >= 0; bit_number--) {
      char bit_value;
      bit_value = (byte_bits >> bit_number) & 1;
      printf("%d", bit_value);
    }
    printf("       ");
  }

  printf("\n");

  for (size_t byte_number = size; byte_number > 0; byte_number--) {
    printf("%10p", value_as_bytes + byte_number - 1);

    if (byte_number != 0) printf(" ");
  }
  printf("\n");
}

int main() {
  s21_decimal decimal = {0};
  s21_decimal decimal_2 = {0};
  print_bits(sizeof(decimal), &decimal);

  s21_change_sign(&decimal);

  printf("changed bits=\n");
  print_bits(sizeof(decimal), &decimal);
}
