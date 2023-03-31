#include "s21_sscanf.h"

long long int s21_atod(char **str, struct characteristic C, char c,
                       int *mistake) {
  long long int result = 0;
  int sign = 1, base = 10, i = 0, full = 0;
  if (C.width == 0) C.width = INT_MAX;
  if (find_sign(str, C, &sign)) C.width--;
  for (; i < C.width && digit(**str); (*str)++, i++) {
    if (!full && ((result * base + (**str - 48) >= result) &&
                  (result * base + (**str - 48) <= LONG_MAX))) {
      result = result * base + (**str - 48);
    } else if (!full && c == 100) {
      sign == 1 ? (result = LONG_MAX) : (result = LONG_MIN);
      full = 1;
    }
  }
  if (i == 0) *mistake = -1;
  return full ? result : result * sign;
}
