#include "s21_sscanf.h"

long long int transfer_i(char **temp_s, struct characteristic C, int *mistake) {
  long long int result = 0;
  int base = 10, k = 0, sign = 1, full = 0;
  if (C.width == 0) C.width = INT_MAX;
  if (find_sign(temp_s, C, &sign)) C.width -= 1;
  if (**temp_s == '0') base = 8;
  if (**temp_s == '0' && is_x(*(*temp_s + 1))) base = 16;
  if (base == 16 && (C.width > 2)) {
    C.width -= 2;
    (*temp_s) += 2;
  }
  int i = 0;
  for (; i < C.width && !full &&
         ((digit(**temp_s) && base == 10) ||
          (digit_eight(**temp_s) && base == 8) ||
          ((digit(**temp_s) || letter(**temp_s)) && base == 16));
       i++, (*temp_s)++) {
    k = **temp_s;
    if (k >= 65 && k <= 70 && base == 16) {
      k -= 7;
    } else if (k >= 97 && k <= 102 && base == 16) {
      k -= 39;
    }
    k -= '0';
    if (!full &&
        ((result * base + k >= result) && (result * base + k <= LONG_MAX))) {
      result = result * base + k;
    } else if (!full) {
      sign == 1 ? (result = LONG_MAX) : (result = LONG_MIN);
      full = 1;
    }
  }
  if (i == 0) *mistake = -1;
  return full ? result : result * sign;
}
