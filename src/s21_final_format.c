#include "s21_sscanf.h"

void final_format_int(char **temp_f, long long int *final_value, va_list ap,
                      int *mistake, long int *result, struct characteristic C) {
  if (C.len == 0) *va_arg(ap, int *) = (int)*final_value;
  if (C.len == 2) *va_arg(ap, long int *) = (long int)*final_value;
  if (C.len == 3) *va_arg(ap, short int *) = (short int)*final_value;
  if (C.len == 4) *va_arg(ap, char *) = (char)*final_value;
  if (C.len == 5) *va_arg(ap, long long int *) = (long long int)*final_value;
  if (!*mistake && **temp_f != 'n') (*result)++;
}

void final_format_oxpint(char **temp_f, unsigned long long int *final_value,
                         va_list ap, int *mistake, long int *result,
                         struct characteristic C) {
  if (**temp_f == 'p') {
    *va_arg(ap, unsigned long int *) = (unsigned long int)*final_value;
  } else if (C.len == 0) {
    *va_arg(ap, unsigned int *) = (unsigned int)*final_value;
  } else if (C.len == 3) {
    *va_arg(ap, unsigned short int *) = (unsigned short int)*final_value;
  } else if (C.len == 2) {
    *va_arg(ap, unsigned long int *) = (unsigned long int)*final_value;
  } else if (C.len == 4) {
    *va_arg(ap, char *) = (char)*final_value;
  } else if (C.len == 5) {
    *va_arg(ap, long long int *) = (long long int)*final_value;
  }
  if (!*mistake && **temp_f != 'n') (*result)++;
}

void final_format_uint(char **temp_f, unsigned long long int *final_value,
                       va_list ap, int *mistake, long int *result,
                       struct characteristic C) {
  if (C.len == 0) *va_arg(ap, unsigned int *) = (unsigned int)*final_value;
  if (C.len == 3)
    *va_arg(ap, unsigned short int *) = (unsigned short int)*final_value;
  if (C.len == 2)
    *va_arg(ap, unsigned long int *) = (unsigned long int)*final_value;
  if (C.len == 4) *va_arg(ap, unsigned char *) = (unsigned char)*final_value;
  if (C.len == 5)
    *va_arg(ap, long long unsigned int *) =
        (long long unsigned int)*final_value;
  if (!*mistake && **temp_f != 'n') (*result)++;
}

void final_format_float(long double *final_value, va_list ap, int *mistake,
                        long int *result, struct characteristic C) {
  if (C.len == 0) *va_arg(ap, float *) = (float)*final_value;
  if (C.len == 1) *va_arg(ap, long double *) = (long double)*final_value;
  if (C.len == 2) *va_arg(ap, double *) = (double)*final_value;
  if (!*mistake) (*result)++;
}