#include "s21_sscanf.h"

unsigned long long transfer(char **number, int system, struct characteristic C,
                            int *mistake, int result) {
  long long unsigned int res = 0;
  int k = 0, sign = 1;
  if (C.width == 0) C.width = INT_MAX;
  if (find_sign(number, C, &sign)) C.width -= 1;
  int i = 0;
  for (;
       i < C.width && ((digit(**number) && (system == 10)) ||
                       (digit_eight(**number) && system == 8) ||
                       ((letter(**number) || digit(**number)) && system == 16));
       i++, (*number)++) {
    k = **number;
    if (system == 16) {
      if (k >= 65 && k <= 70) {
        k -= 7;
      } else if (k >= 97 && k <= 102) {
        k -= 39;
      }
    }
    k -= '0';
    // перевод в 10-ую систему
    if ((ULLONG_MAX / 10) != res) {
      res = res * system + k;
    } else {
      res = ULLONG_MAX;
    }
  }
  if (i == 0 && result == 0) *mistake = -1;
  return sign * res;
}
