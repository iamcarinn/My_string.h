#include "s21_sscanf.h"

long double s21_atof(char **str, struct characteristic C, int *mistake) {
  int sign = 1, i = 0, full = 0, point = 0, check = 0;
  long double base = 10, result = 0;
  if (C.width == 0) C.width = INT_MAX;
  int marker_sign = find_sign(str, C, &sign);
  if (marker_sign) C.width--;
  check = check_inf_nan(str, &result, &C);
  if (is_e(**str) == 0 && check != 1) {
    for (; (i < C.width) && (digit(**str) || **str == 46 || is_e(**str));
         (*str)++, i++) {
      if (!full && **str == 46) {
        point = 1;
      } else if (!full && is_e(**str)) {
        C.width = (C.width - i - 1);
        if (C.width == 0 ||
            (C.width == 1 && (*(*str + 1) == '+' || *(*str + 1) == '-')))
          break;
        e_calulation(str, &result, C);
      } else if (!full && !point &&
                 ((result * base + (**str - 48) >= result) &&
                  (result * base + (**str - 48) <= LONG_MAX))) {
        result = result * base + (**str - 48);
      } else if (!full && point && (result + ((**str - 48) / base) >= result) &&
                 (result + ((**str - 48) / base) <= LONG_MAX)) {
        result = result + ((**str - 48) / base);
        base *= 10;
      } else if (!full) {
        sign == 1 ? (result = LONG_MAX) : (result = LONG_MIN);
        full = 1;
      }
    }
  } else if (check == 0) {
    (*str) += 1;
  }
  if (i == 0 && check == 0) *mistake = -1;
  return full ? result : result * sign;
}

void e_calulation(char **str, long double *result, struct characteristic C) {
  long double e_base = 0;
  (*str)++;
  int mistake = 0, full = 0, base = 10;
  if (**str == 43) {
    e_base = 10;
    (*str)++;
    mistake = !(digit(**str));
  } else if (**str == 45) {
    e_base = 0.1;
    (*str)++;
    mistake = !(digit(**str));
  } else if (digit(**str)) {
    e_base = 10;
  } else {
    mistake = 1;
  }
  if (!mistake) {
    long double exponenta = 0;
    for (int i = 0; i < C.width && digit(**str); (*str)++, i++) {
      if (!full && exponenta * base + (**str - 48) <= LONG_MAX &&
          exponenta * base + (**str - 48) >= 0) {
        exponenta = exponenta * base + (**str - 48);
      } else if (!full) {
        exponenta = LONG_MAX;
        full = 1;
      }
    }
    (*str)--;
    *result = (*result) * pow(e_base, exponenta);
  }
}
