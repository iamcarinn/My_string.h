#ifndef SRC_HEADERS_S21_SSCANF_H_
#define SRC_HEADERS_S21_SSCANF_H_

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

struct characteristic {
  int width;
  int len;
};

int s21_sscanf(const char *str, const char *format, ...);
void parser_scanf(char **temp_f, char **temp_s, long int *result, va_list ap,
                  int *mistake, struct characteristic C, const char *str,
                  const int is_star);

long long int s21_atod(char **str, struct characteristic C, char c,
                       int *mistake);
long double s21_atof(char **str, struct characteristic C, int *mistake);
void e_calulation(char **str, long double *result, struct characteristic C);
char *s21_atos(char **temp_s, struct characteristic C, char *s_result,
               int *mistake, char **temp_f);
unsigned long long transfer(char **number, int system, struct characteristic C,
                            int *mistake, int result);
long long int transfer_i(char **temp_s, struct characteristic C, int *mistake);

void stars(char **temp_f, int *is_star);
int digit(int d);
int digit_eight(int d);
int find_sign(char **str, struct characteristic C, int *sign);
int skip_space(char **temp_s, char **temp_f);
char *s21_strcpy_govno(char *dest, const char *src);

int is_x(int d);
int is_e(int d);
int is_hl(int d);
int is_float(int d);
int is_int(int d);
int letter(int c);
int define_long(char **temp_f, struct characteristic C);
int check_inf_nan(char **str, long double *res, struct characteristic *C);
int find_space(char **temp_s, int i);

void final_format_int(char **temp_f, long long int *final_value, va_list ap,
                      int *mistake, long int *result, struct characteristic C);
void final_format_float(long double *final_value, va_list ap, int *mistake,
                        long int *result, struct characteristic C);
void final_format_uint(char **temp_f, unsigned long long int *final_value,
                       va_list ap, int *mistake, long int *result,
                       struct characteristic C);
void final_format_oxpint(char **temp_f, unsigned long long int *final_value,
                         va_list ap, int *mistake, long int *result,
                         struct characteristic C);

void count_(char **temp_s, int *mistake);
void count_c(char **temp_s, char *s_result, struct characteristic C, va_list ap,
             int is_star, long int *result);
void count_di(char **temp_s, char **temp_f, long long final_value_int,
              struct characteristic C, va_list ap, int *mistake, int is_star,
              long int *result);
void count_uo(char **temp_s, char **temp_f, unsigned long long final_value_uint,
              struct characteristic C, va_list ap, int *mistake, int is_star,
              long int *result);
void count_xp(char **temp_s, unsigned long long final_value_uint,
              struct characteristic *C, va_list ap, int *mistake, char **temp_f,
              int is_star, long int *result, int *sign, int *ox_read);
void count_f(char **temp_s, long double final_value, struct characteristic C,
             va_list ap, int *mistake, int is_star, long int *result);
void count_n(char **temp_s, long long n_counter, struct characteristic C,
             va_list ap, int *mistake, char **temp_f, int is_star,
             const char *str, long int *result);
void count_s(char **temp_s, struct characteristic C, va_list ap, char *s_result,
             int *mistake, char **temp_f, int is_star, long int *result);

#endif