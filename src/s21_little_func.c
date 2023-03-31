#include "s21_sscanf.h"

void stars(char **temp_f, int *is_star) {
  while (**temp_f == '*') {
    (*temp_f)++;
    (*is_star)++;  // В sscanf знак *, помещенный после % и перед спецификатором
                   // формата, считывает данные указанного типа, но подавляет их
                   // присваивание.
  }
}

int letter(int c) {
  return ((c >= 65 && c <= 70) || (c >= 97 && c <= 102)) ? 1 : 0;
}
int digit(int d) { return (d >= 48 && d <= 57) ? 1 : 0; }
int digit_eight(int d) { return (d >= 48 && d <= 55) ? 1 : 0; }
int is_e(int d) { return ((d == 69) || (d == 101)) ? 1 : 0; }
int is_x(int d) { return ((d == 88) || (d == 120)) ? 1 : 0; }
int is_hl(int d) {
  return ((d == 76) || (d == 108) || (d == 104)) ? 1 : 0;
}  // L l h

int find_sign(char **str, struct characteristic C, int *sign) {
  int res = 0;
  if (**str == '-') {
    *sign = -1;
    (*str)++;
    if (C.width != 0) res++;
  } else if (**str == '+') {
    (*str)++;
    if (C.width != 0) res++;
  }
  return res;
}

int skip_space(char **temp_s, char **temp_f) {
  int res = 0;
  if (*(*temp_f) != '\0') {
    while (**temp_s == ' ' || **temp_s == '\n' || **temp_s == '\t' ||
           **temp_s == '\r' || **temp_s == '\f' || **temp_s == '\v') {
      if (*(*temp_f + 1) == 'c') {
        break;
      }
      (*temp_s)++;
      res = 1;
    }
  }
  return res;
}

int find_space(char **temp_s, int i) {
  int res = 1;
  *(temp_s) += i;
  if (**temp_s == ' ' || **temp_s == '\n' || **temp_s == '\t' ||
      **temp_s == '\r' || **temp_s == '\f' || **temp_s == '\v') {
    res = 0;
  }
  *(temp_s) -= i;
  return res;
}

int define_long(char **temp_f, struct characteristic C) {
  switch (**temp_f) {
    case 'L':
      C.len = 1;
      break;
    case 'l':
      C.len = 2;
      if (*(*temp_f + 1) == 'l') {
        C.len = 5;
        (*temp_f)++;
      }
      break;
    case 'h':
      C.len = 3;
      if (*(*temp_f + 1) == 'h') {
        C.len = 4;
        (*temp_f)++;
      }
      break;
  }
  (*temp_f)++;
  return C.len;
}

int check_inf_nan(char **str, long double *res, struct characteristic *C) {
  char temp[20] = {0};
  int check = 1;
  s21_strncpy(temp, *str, 10);
  char *low_temp = s21_to_lower(temp);
  if (C->width > 2 && !s21_strncmp(low_temp, "nan", 3)) {
    *res = 0.0 / 0.0;
    *str += 3;
    C->width -= 3;
  } else if (C->width > 7 && !s21_strncmp(low_temp, "infinity", 8)) {
    *res = 1.0 / 0.0;
    *str += 8;
    C->width -= 8;
  } else if (C->width > 2 && !s21_strncmp(low_temp, "inf", 3)) {
    *res = 1.0 / 0.0;
    *str += 3;
    C->width -= 3;
  } else {
    check = 0;
  }
  free(low_temp);
  return check;
}

char *s21_strcpy_govno(char *dest, const char *src) {
  char *ret = dest;
  while (*src != '\0') {
    *dest = *src;
    ++dest;
    ++src;
  }
  return ret;
}