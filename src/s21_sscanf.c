#include "s21_string.h"

int s21_sscanf(const char *str1, const char *format1, ...) {
  char str[2048];
  s21_strcpy(str, str1);
  char format[2048];
  s21_strcpy(format, format1);
  long int result = 0;
  int empty_string = 0;
  int mistake = 0;
  int space_f = 0;
  char *temp_s = (char *)str, *temp_f = (char *)format;
  va_list ap;
  va_start(ap, format1);
  int is_star = 0;
  while (*temp_f != '\0' && mistake != -1) {
    if (skip_space(&temp_f, &temp_f)) space_f = 1;
    if (*temp_f == '%') {
      temp_f += 1;
      struct characteristic C = {0};
      while (digit(*temp_f) || (*temp_f == '*') || is_hl(*temp_f)) {
        stars(&temp_f, &is_star);
        if (digit(*temp_f))
          C.width = s21_atod(&temp_f, C, 100, &mistake);  // вложенность циклов
        if (is_hl(*temp_f)) C.len = define_long(&temp_f, C);
      }
      if ((*temp_f != 'c') || (space_f)) skip_space(&temp_s, &temp_f);
      if (*temp_s || *temp_f == 'n') {
        parser_scanf(&temp_f, &temp_s, &result, ap, &mistake, C, str, is_star);
      } else if (!result) {
        empty_string = -1;
      }
      if (*temp_f) temp_f += 1;
      is_star = 0;
    } else if (*temp_s == *temp_f ||
               ((skip_space(&temp_s, &temp_f)) && *temp_s == *temp_f)) {
      temp_s++;
      if (*temp_f != '\0') temp_f++;
    } else {
      if (*temp_f != '\0') temp_f += 1;
      mistake = -1;
    }
    space_f = 0;
  }
  if (empty_string == -1) {
    result = -1;
  }
  va_end(ap);
  return result;
}

void parser_scanf(char **temp_f, char **temp_s, long int *result, va_list ap,
                  int *mistake, struct characteristic C, const char *str,
                  const int is_star) {
  long double final_value = 0;
  long long final_value_int = 0, n_counter = 0;
  unsigned long long final_value_uint = 0;
  char s_result[1024] = {0};
  int ox_read = 0;
  int sign = 1;
  switch (**temp_f) {
    case '%':
      count_(temp_s, mistake);
      break;
    case 'c':
      count_c(temp_s, s_result, C, ap, is_star, result);
      break;
    case 'd':
    case 'i':
      count_di(temp_s, temp_f, final_value_int, C, ap, mistake, is_star,
               result);
      break;
    case 'u':
    case 'o':
      count_uo(temp_s, temp_f, final_value_uint, C, ap, mistake, is_star,
               result);
      break;
    case 'X':
    case 'x':
    case 'p':
      count_xp(temp_s, final_value_uint, &C, ap, mistake, temp_f, is_star,
               result, &sign, &ox_read);
      break;
    case 'e':
    case 'E':
    case 'g':
    case 'G':
    case 'f':
      count_f(temp_s, final_value, C, ap, mistake, is_star, result);
      break;
    case 'n':
      count_n(temp_s, n_counter, C, ap, mistake, temp_f, is_star, str, result);
      break;
    case 's':
      count_s(temp_s, C, ap, s_result, mistake, temp_f, is_star, result);
      break;
    default:
      *mistake = -1;
      break;
  }
}

void count_(char **temp_s, int *mistake) {
  if (**temp_s == '%') {
    (*temp_s)++;
  } else
    *mistake = -1;
}

void count_c(char **temp_s, char *s_result, struct characteristic C, va_list ap,
             int is_star, long int *result) {
  if (!is_star) {
    if (C.width == 0) {
      *va_arg(ap, char *) = **temp_s;
    } else if (C.width > 0) {
      int i = 0;
      for (; C.width > 0; C.width--, i++) {
        s_result[i] = (*temp_s)[i];
      }
      s21_strcpy_govno(va_arg(ap, char *), s_result);
    }
    (*result)++;
  }
  (*temp_s)++;
}

void count_di(char **temp_s, char **temp_f, long long final_value_int,
              struct characteristic C, va_list ap, int *mistake, int is_star,
              long int *result) {
  if ((**temp_f) == 'd') {
    final_value_int = s21_atod(temp_s, C, **temp_f, mistake);
    if (!is_star && (*mistake) == 0)
      final_format_int(temp_f, &final_value_int, ap, mistake, result, C);
  } else if ((**temp_f) == 'i') {
    final_value_int = transfer_i(temp_s, C, mistake);
    if (!is_star)
      final_format_int(temp_f, &final_value_int, ap, mistake, result, C);
  }
}

void count_uo(char **temp_s, char **temp_f, unsigned long long final_value_uint,
              struct characteristic C, va_list ap, int *mistake, int is_star,
              long int *result) {
  if ((**temp_f) == 'u') {
    final_value_uint = transfer(temp_s, 10, C, mistake, 0);
    if (!is_star)
      final_format_uint(temp_f, &final_value_uint, ap, mistake, result, C);
  } else if ((**temp_f) == 'o') {
    final_value_uint = transfer(temp_s, 8, C, mistake, 0);
    if (!is_star)
      final_format_oxpint(temp_f, &final_value_uint, ap, mistake, result, C);
  }
}

void count_xp(char **temp_s, unsigned long long final_value_uint,
              struct characteristic *C, va_list ap, int *mistake, char **temp_f,
              int is_star, long *result, int *sign, int *ox_read) {
  if (*(*temp_s) == '-') {
    (*temp_s) += 1;
    (*sign) *= -1;
  }
  if (*(*temp_s) == '0' && is_x(*(*temp_s + 1))) {
    (*temp_s) += 2;
    (*ox_read) += 1;
    if (C->width != 0) {
      C->width -= 2;
      if (C->width == 0) {
        C->width -= 1;
      }
    }
  }
  if (*sign < 0) {
    (*temp_s) -= 1;
    *(*temp_s) = '-';
  }
  final_value_uint = transfer(temp_s, 16, *C, mistake, *ox_read);
  if (!is_star)
    final_format_oxpint(temp_f, &final_value_uint, ap, mistake, result, *C);
}

void count_f(char **temp_s, long double final_value, struct characteristic C,
             va_list ap, int *mistake, int is_star, long int *result) {
  final_value = s21_atof(temp_s, C, mistake);
  if (!is_star && (*mistake) == 0)
    final_format_float(&final_value, ap, mistake, result, C);
}

void count_n(char **temp_s, long long n_counter, struct characteristic C,
             va_list ap, int *mistake, char **temp_f, int is_star,
             const char *str, long int *result) {
  n_counter = ((*temp_s) - str);
  if (!n_counter) *mistake = 2323;
  if (!is_star) final_format_int(temp_f, &n_counter, ap, mistake, result, C);
}

void count_s(char **temp_s, struct characteristic C, va_list ap, char *s_result,
             int *mistake, char **temp_f, int is_star, long int *result) {
  s21_atos(temp_s, C, s_result, mistake, temp_f);
  if (!is_star) {
    s21_strcpy(va_arg(ap, char *), s_result);
  }
  if (!*mistake && !is_star) (*result)++;
  (*temp_s) += s21_strlen(s_result);
}