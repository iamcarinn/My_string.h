#ifndef SRC_HEADERS_S21_SPRINTF_H_
#define SRC_HEADERS_S21_SPRINTF_H_

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

struct Flags {
  int plus;
  int minus;
  int spase;
  int sharp;
  int zero;
};

struct PreparedFormatData {
  struct Flags flags;
  int counter;
  int width;
  int precision;
  int has_precision;
  char length;
  char specifier;
};

int s21_sprintf(char *str, const char *format, ...);
const char *sprintf_parser(const char *format,
                           struct PreparedFormatData *prepared_format_data,
                           int *error, va_list va);
const char *get_flags(const char *format,
                      struct PreparedFormatData *prepared_format_data);
const char *get_width(const char *format,
                      struct PreparedFormatData *prepared_format_data,
                      va_list va);
const char *get_precision(const char *format,
                          struct PreparedFormatData *prepared_format_data,
                          va_list va);
const char *get_length(const char *format,
                       struct PreparedFormatData *prepared_format_data);
const char *get_specifier(const char *format,
                          struct PreparedFormatData *prepared_format_data,
                          int *error);
int write_to_str(char *str, const char *format);
int write_space(char *str, struct PreparedFormatData *prepared_format_data);
int write_sign(char *str, long double value,
               struct PreparedFormatData *prepared_format_data);
int write_zero(char *str, struct PreparedFormatData *prepared_format_data);
int write_int(char *str, struct PreparedFormatData *prepared_format_data,
              long long value);
int write_dot(char **value_str,
              struct PreparedFormatData *prepared_format_data);
int write_float(char *str, struct PreparedFormatData *prepared_format_data,
                long double value);
int write_double(char *value_str, long double value,
                 struct PreparedFormatData *prepared_format_data);
int write_zeroes(char *str, struct PreparedFormatData *prepared_format_data);
int write_unsigned(char *str, struct PreparedFormatData *prepared_format_data,
                   unsigned long long value);
int write_prefix_spaces(char **str,
                        struct PreparedFormatData *prepared_format_data,
                        unsigned long long value);
int write_e(char *str, struct PreparedFormatData *prepared_format_data,
            long double value);
int write_g(char *str, struct PreparedFormatData *prepared_format_data,
            long double value);
int write_exponent(char *value_str,
                   struct PreparedFormatData *prepared_format_data, int power);
int decrease_sign_width(long double value,
                        struct PreparedFormatData *prepared_format_data);
int decrease_zeroes_width(struct PreparedFormatData *prepared_format_data);
int specifier_handler(char **str,
                      struct PreparedFormatData *prepared_format_data,
                      va_list va, int processed);
int char_handler(char **str, va_list va,
                 struct PreparedFormatData *prepared_format_data);
int string_handler(char *str, va_list va,
                   struct PreparedFormatData *prepared_format_data);
int unsigned_handler(char *str, struct PreparedFormatData *prepared_format_data,
                     va_list va);
int double_handler(char *str, struct PreparedFormatData *prepared_format_data,
                   va_list va);
int integer_handler(char *str, struct PreparedFormatData *prepared_format_data,
                    va_list va);
int n_handler(va_list va, int processed);
int x_handler(char *str, struct PreparedFormatData *prepared_format_data,
              unsigned long value);
int o_handler(char *str, struct PreparedFormatData *prepared_format_data,
              unsigned long long value);
int pointer_handler(char *str, struct PreparedFormatData *prepared_format_data,
                    va_list va);
int minus_handler(char *str, char *value_str,
                  struct PreparedFormatData *prepared_format_data,
                  long double value);
int remove_zero(char *str, struct PreparedFormatData *prepared_format_data);
int remove_zeroes_in_g(char *value_str,
                       struct PreparedFormatData *prepared_format_data);
int integer_length(long long int value);
int double_length(long double value);
int unsigned_length(unsigned long long value);
int x_to_upper(char *value_str);
int is_NaN_or_INF(char *value_str,
                  struct PreparedFormatData *prepared_format_data,
                  long double value);
int decimal_to_hexoct(char *value_str, unsigned long long value,
                      struct PreparedFormatData *prepared_format_data,
                      int base);
int itoa(char *value_str, long long int value,
         struct PreparedFormatData *prepared_format_data);
int ftoa(char *value_str, struct PreparedFormatData *prepared_format_data,
         long double value);
int utoa(char *value_str, unsigned long long value,
         struct PreparedFormatData *prepared_format_data);
int s21_atoi(char *str);
long double mantissa(char **valueStr, long double exponent,
                     long long *precision,
                     struct PreparedFormatData *prepared_format_data);

#endif  //  SRC_HEADERS_S21_SPRINTF_H_
