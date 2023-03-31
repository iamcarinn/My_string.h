#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list va;
  va_start(va, format);
  int error = 1;
  int processed = 0;
  struct PreparedFormatData prepared_format_data = {0};
  str[0] = '\0';
  while (*format) {
    if (error) {
      s21_memset(&prepared_format_data, 0, sizeof(prepared_format_data));
      if (*format == '%') {
        format++;
        format = sprintf_parser(format, &prepared_format_data, &error, va);
        specifier_handler(&str, &prepared_format_data, va, processed);
        processed += prepared_format_data.counter;
      } else {
        write_to_str(str, format);
        processed++;
        format++;
      }
    } else {
      printf("error");
      *str = '\0';
      break;
    }
  }
  va_end(va);
  return processed;
}

const char *sprintf_parser(const char *format,
                           struct PreparedFormatData *prepared_format_data,
                           int *error, va_list va) {
  format = get_flags(format, prepared_format_data);
  format = get_width(format, prepared_format_data, va);
  format = get_precision(format, prepared_format_data, va);
  format = get_length(format, prepared_format_data);
  format = get_specifier(format, prepared_format_data, error);

  return format;
}

const char *get_flags(const char *format,
                      struct PreparedFormatData *prepared_format_data) {
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '#' ||
         *format == '0') {
    switch (*format) {
      case '-':
        prepared_format_data->flags.minus++;
        format++;
        break;
      case '+':
        prepared_format_data->flags.plus++;
        format++;
        break;
      case ' ':
        prepared_format_data->flags.spase++;
        format++;
        break;
      case '#':
        prepared_format_data->flags.sharp++;
        format++;
        break;
      case '0':
        prepared_format_data->flags.zero++;
        format++;
        break;
    }
  }
  return format;
}

const char *get_width(const char *format,
                      struct PreparedFormatData *prepared_format_data,
                      va_list va) {
  if (*format == '*') {
    prepared_format_data->width = va_arg(va, int);
    format++;
  } else {
    char widthBuff[1024] = "";
    int k = 0;
    while (*format >= '0' && *format <= '9') {
      widthBuff[k] = *format;
      k++;
      format++;
    }
    prepared_format_data->width = s21_atoi(widthBuff);
  }
  return format;
}

const char *get_precision(const char *format,
                          struct PreparedFormatData *prepared_format_data,
                          va_list va) {
  if (*format == '.') {
    prepared_format_data->has_precision = 1;
    format++;
    if (*format == '*') {
      prepared_format_data->precision = va_arg(va, int);
      format++;
    } else {
      char precisionBuff[1024] = "";
      int i = 0;
      while (*format >= '0' && *format <= '9') {
        precisionBuff[i] = *format;
        i++;
        format++;
      }
      prepared_format_data->precision = s21_atoi(precisionBuff);
    }
  }
  return format;
}

const char *get_length(const char *format,
                       struct PreparedFormatData *prepared_format_data) {
  if (*format == 'h' || *format == 'l' || *format == 'L') {
    prepared_format_data->length = *format++;
  }
  return format;
}

const char *get_specifier(const char *format,
                          struct PreparedFormatData *prepared_format_data,
                          int *error) {
  char tmp = *format;
  if (tmp != '\0') {
    char *pattern = "cdieEfgGosuxXpn";
    if (s21_strchr(pattern, tmp) != S21_NULL) {
      prepared_format_data->specifier = *format++;
    } else if (tmp == '%') {
      prepared_format_data->specifier = *format++;
    } else {
      *error = 0;
    }
  }
  return format;
}

int specifier_handler(char **str,
                      struct PreparedFormatData *prepared_format_data,
                      va_list va, int processed) {
  switch (prepared_format_data->specifier) {
    case 'c':
    case '%':
      char_handler(str, va, prepared_format_data);
      break;
    case 'd':
    case 'i':
      integer_handler(*str, prepared_format_data, va);
      break;
    case 's':
      string_handler(*str, va, prepared_format_data);
      break;
    case 'f':
    case 'e':
    case 'E':
    case 'g':
    case 'G':
      double_handler(*str, prepared_format_data, va);
      break;
    case 'u':
    case 'x':
    case 'X':
    case 'o':
      unsigned_handler(*str, prepared_format_data, va);
      break;
    case 'n':
      n_handler(va, processed);
      break;
    case 'p':
      pointer_handler(*str, prepared_format_data, va);
      break;
  }
  return 0;
}

int double_handler(char *str, struct PreparedFormatData *prepared_format_data,
                   va_list va) {
  long double value = 0;

  switch (prepared_format_data->length) {
    case 'l':
      value = (double)va_arg(va, double);
      break;
    case '\0':
      value = va_arg(va, double);
      break;
    case 'L':
      value = (long double)va_arg(va, long double);
      break;
    default:
      break;
  }
  switch (prepared_format_data->specifier) {
    case 'f':
      write_float(str, prepared_format_data, value);
      break;
    case 'e':
    case 'E':
      write_e(str, prepared_format_data, value);
      break;
    case 'g':
    case 'G':
      write_g(str, prepared_format_data, value);
      break;
  }

  return 0;
}

int char_handler(char **str, va_list va,
                 struct PreparedFormatData *prepared_format_data) {
  char c;
  if (prepared_format_data->specifier == '%') {
    c = '%';
  } else {
    c = va_arg(va, int);
  }

  char *pointer = *str;

  while (*pointer) {
    pointer++;
  }

  prepared_format_data->width--;

  if (prepared_format_data->flags.minus != 0) {
    *pointer = c;
    pointer++;
    prepared_format_data->counter++;
    *pointer = '\0';
    *str = pointer;
    write_space(*str, prepared_format_data);
    write_zero(*str, prepared_format_data);
  } else {
    write_space(*str, prepared_format_data);
    write_zero(*str, prepared_format_data);

    while (*pointer) {
      pointer++;
    }

    *pointer++ = c;
    prepared_format_data->counter++;
    *pointer = '\0';
    *str = pointer;
  }
  return 0;
}

int string_handler(char *str, va_list va,
                   struct PreparedFormatData *prepared_format_data) {
  char *s = va_arg(va, char *);

  if (prepared_format_data->has_precision == 0) {
    prepared_format_data->precision = s21_strlen(s);
  }

  if (prepared_format_data->width > 0 &&
      (prepared_format_data->width - prepared_format_data->precision) <= 0 &&
      prepared_format_data->has_precision != 0) {
    if (prepared_format_data->width > (int)s21_strlen(s)) {
      prepared_format_data->width -= (int)s21_strlen(s);
    } else {
      prepared_format_data->width = 0;
    }

    prepared_format_data->counter = s21_strlen(s);
  } else {
    prepared_format_data->width -= prepared_format_data->precision;
    prepared_format_data->counter += prepared_format_data->precision;
  }

  if (prepared_format_data->flags.minus != 0) {
    s21_strncat(str, s, prepared_format_data->precision);
    write_space(str, prepared_format_data);
    write_zero(str, prepared_format_data);
  } else {
    write_space(str, prepared_format_data);
    write_zero(str, prepared_format_data);
    s21_strncat(str, s, prepared_format_data->precision);
  }

  return 0;
}

int pointer_handler(char *str, struct PreparedFormatData *prepared_format_data,
                    va_list va) {
  char value_str[1024] = {'\0'};
  long long unsigned int value =
      (long long unsigned int)va_arg(va, long long unsigned int);
  decimal_to_hexoct(value_str, value, prepared_format_data, 16);
  int value_len = s21_strlen(value_str) + 2;
  prepared_format_data->precision -= value_len - 2;

  if (prepared_format_data->precision <= 0) {
    prepared_format_data->width -= value_len;
  } else {
    prepared_format_data->width -= value_len + prepared_format_data->precision;
  }

  prepared_format_data->counter += value_len;

  if (prepared_format_data->flags.minus != 0) {
    s21_strcat(str, "0x");
    write_zeroes(str, prepared_format_data);
    s21_strcat(str, value_str);
    write_space(str, prepared_format_data);
  } else {
    write_space(str, prepared_format_data);
    s21_strcat(str, "0x");
    write_zeroes(str, prepared_format_data);
    s21_strcat(str, value_str);
  }
  return 0;
}

int integer_handler(char *str, struct PreparedFormatData *prepared_format_data,
                    va_list va) {
  long long value = 0;

  switch (prepared_format_data->length) {
    case 'h':
      value = (short int)va_arg(va, int);
      break;
    case '\0':
      value = (int)va_arg(va, int);
      break;
    case 'l':
      value = (long long)va_arg(va, long long int);
      break;
  }

  write_int(str, prepared_format_data, value);
  return 0;
}

int minus_handler(char *str, char *value_str,
                  struct PreparedFormatData *prepared_format_data,
                  long double value) {
  if (prepared_format_data->flags.minus != 0) {
    write_sign(str, value, prepared_format_data);
    decrease_sign_width(value, prepared_format_data);
    write_zeroes(str, prepared_format_data);
    decrease_zeroes_width(prepared_format_data);
    write_zero(str, prepared_format_data);
    s21_strcat(str, value_str);
    write_space(str, prepared_format_data);
  } else {
    decrease_sign_width(value, prepared_format_data);
    decrease_zeroes_width(prepared_format_data);
    write_space(str, prepared_format_data);
    write_sign(str, value, prepared_format_data);
    write_zeroes(str, prepared_format_data);
    write_zero(str, prepared_format_data);
    s21_strcat(str, value_str);
  }
  return 0;
}

int unsigned_handler(char *str, struct PreparedFormatData *prepared_format_data,
                     va_list va) {
  unsigned long long value = 0;

  switch (prepared_format_data->length) {
    case 'h':
      value = (short unsigned)va_arg(va, unsigned int);
      break;
    case '\0':
      value = (unsigned)va_arg(va, unsigned int);
      break;
    case 'l':
      value = (unsigned long)va_arg(va, unsigned long int);
      break;
    default:
      break;
  }

  switch (prepared_format_data->specifier) {
    case 'u':
      write_unsigned(str, prepared_format_data, value);
      break;
    case 'x':
    case 'X':
      x_handler(str, prepared_format_data, value);
      break;
    case 'o':
      o_handler(str, prepared_format_data, value);
      break;
  }

  return 0;
}

int o_handler(char *str, struct PreparedFormatData *prepared_format_data,
              unsigned long long value) {
  char value_str[1024] = {'\0'};
  decimal_to_hexoct(value_str, value, prepared_format_data, 8);
  int value_len = s21_strlen(value_str);
  prepared_format_data->precision -= value_len;

  if (prepared_format_data->precision <= 0) {
    prepared_format_data->width -= value_len;
  } else {
    prepared_format_data->width -= value_len + prepared_format_data->precision;
  }

  prepared_format_data->counter += value_len;

  if (prepared_format_data->flags.minus != 0) {
    write_prefix_spaces(&str, prepared_format_data, value);
    write_zeroes(str, prepared_format_data);
    write_zero(str, prepared_format_data);
    s21_strcat(str, value_str);
    write_space(str, prepared_format_data);
  } else {
    write_prefix_spaces(&str, prepared_format_data, value);
    write_zeroes(str, prepared_format_data);
    write_zero(str, prepared_format_data);
    s21_strcat(str, value_str);
  }
  return 0;
}

int n_handler(va_list va, int processed) {
  int *value = va_arg(va, int *);
  *value = processed;

  return 0;
}

int x_handler(char *str, struct PreparedFormatData *prepared_format_data,
              unsigned long value) {
  char value_str[1024] = {'\0'};
  decimal_to_hexoct(value_str, value, prepared_format_data, 16);

  if (prepared_format_data->specifier == 'X') {
    x_to_upper(value_str);
  }

  int value_len = s21_strlen(value_str);
  prepared_format_data->precision -= value_len;

  if (prepared_format_data->precision <= 0) {
    prepared_format_data->width -= value_len;
  } else {
    prepared_format_data->width -= value_len + prepared_format_data->precision;
  }

  prepared_format_data->counter += value_len;

  if (prepared_format_data->flags.minus != 0) {
    write_prefix_spaces(&str, prepared_format_data, value);
    write_zeroes(str, prepared_format_data);
    write_zero(str, prepared_format_data);
    s21_strcat(str, value_str);
    write_space(str, prepared_format_data);
  } else {
    write_prefix_spaces(&str, prepared_format_data, value);
    write_zeroes(str, prepared_format_data);
    write_zero(str, prepared_format_data);
    s21_strcat(str, value_str);
  }
  return 0;
}

int write_to_str(char *str, const char *format) {
  char *end_index = str;
  while (*end_index) {
    end_index++;
  }
  *end_index++ = *format;
  *end_index = '\0';

  return 0;
}

int write_g(char *str, struct PreparedFormatData *prepared_format_data,
            long double value) {
  if (prepared_format_data->has_precision == 0) {
    prepared_format_data->precision = 6;
  }
  prepared_format_data->has_precision = 1;
  if ((fabsl(value) / powl(10, prepared_format_data->precision) > 1) ||
      (((fabsl(value) * (powl(10, 4))) < 1) && value != 0)) {
    if (prepared_format_data->precision != 0) {
      prepared_format_data->precision--;
    }
    write_e(str, prepared_format_data, value);
  } else {
    if (fabsl(value) < 0.1 && value != 0) {
      int i = 1;
      if (prepared_format_data->precision == 0) {
        prepared_format_data->precision++;
      }
      while ((fabsl(value) * (powl(10, i))) < 1) {
        prepared_format_data->precision++;
        i++;
      }
    } else if (value != 0) {
      if (prepared_format_data->precision == 0) {
        prepared_format_data->precision++;
      } else {
        prepared_format_data->precision -= double_length(value);
      }
    } else {
      prepared_format_data->precision--;
    }
    write_float(str, prepared_format_data, value);
  }
  return 0;
}

int write_e(char *str, struct PreparedFormatData *prepared_format_data,
            long double value) {
  char valueStr[1024] = {'\0'};
  int power = 0;
  int infNan = is_NaN_or_INF(valueStr, prepared_format_data, value);
  if (fabsl(value) >= 1.0 && infNan == 0) {
    while (floorl(fabsl(
               roundl(value * powl(10, prepared_format_data->precision + 1)) /
               powl(10, prepared_format_data->precision + 1))) >= 10) {
      value = value / 10;
      power++;
    }
  } else if (value != 0 && infNan == 0) {
    while (fabsl(value) < 1) {
      value = value * 10;
      power--;
    }
  }
  if (infNan == 0) {
    ftoa(valueStr, prepared_format_data, value);
    remove_zeroes_in_g(valueStr, prepared_format_data);  //-g-G
    if (s21_strchr("gG", prepared_format_data->specifier) != S21_NULL) {
      if (prepared_format_data->specifier == 'g') {
        prepared_format_data->specifier = 'e';
      } else {
        prepared_format_data->specifier = 'E';
      }
    }
    write_exponent(valueStr, prepared_format_data, power);
  }
  minus_handler(str, valueStr, prepared_format_data, value);

  return 0;
}

int write_float(char *str, struct PreparedFormatData *prepared_format_data,
                long double value) {
  char value_str[1024] = {'\0'};
  int infNan = is_NaN_or_INF(value_str, prepared_format_data, value);

  if (infNan == 0) {
    ftoa(value_str, prepared_format_data, value);
    remove_zeroes_in_g(value_str, prepared_format_data);  //-g-G
  }

  minus_handler(str, value_str, prepared_format_data, value);

  return 0;
}

int write_double(char *value_str, long double value,
                 struct PreparedFormatData *prepared_format_data) {
  if (value == 0.0 && (prepared_format_data->has_precision == 0 ||
                       (prepared_format_data->has_precision &&
                        prepared_format_data->precision != 0))) {
    value_str[0] = '0';
    prepared_format_data->precision--;
    prepared_format_data->counter++;

  } else {
    int i = 0;
    int sign = 1;
    if (value < 0.0) {
      sign *= -1;
    }
    int length = double_length(value);
    i += length - 1;
    prepared_format_data->precision -= length;

    while (fabsl(value) >= 1) {
      char residue = ((int)fmodl(value, 10)) * sign + 48;
      value_str[i] = residue;
      value /= 10;
      i--;
      prepared_format_data->counter++;
    }
  }
  prepared_format_data->width -= s21_strlen(value_str);

  return 0;
}

int write_dot(char **value_str,
              struct PreparedFormatData *prepared_format_data) {
  while (**value_str) {
    (*value_str)++;
  }
  **value_str = '.';
  (*value_str)++;
  **value_str = '\0';
  prepared_format_data->counter++;
  prepared_format_data->width--;
  prepared_format_data->precision--;

  return 0;
}

int write_prefix_spaces(char **str,
                        struct PreparedFormatData *prepared_format_data,
                        unsigned long long value) {
  if (prepared_format_data->specifier != 'o') {
    if (prepared_format_data->flags.minus != 0) {
      if (prepared_format_data->flags.sharp == 1 && value != 0) {
        prepared_format_data->width -= 2;
        prepared_format_data->counter += 2;
        if (prepared_format_data->specifier == 'x') {
          s21_strcat(*str, "0x");
        } else {
          s21_strcat(*str, "0X");
        }
      }
    } else {
      if (prepared_format_data->flags.sharp == 1 && value != 0) {
        prepared_format_data->width -= 2;
        prepared_format_data->counter += 2;
        write_space(*str, prepared_format_data);
        if (prepared_format_data->specifier == 'x') {
          s21_strcat(*str, "0x");
        } else {
          s21_strcat(*str, "0X");
        }
      } else {
        write_space(*str, prepared_format_data);
      }
    }
  } else {
    if (prepared_format_data->flags.minus != 0) {
      if (prepared_format_data->flags.sharp == 1 &&
          prepared_format_data->precision < 0 && value != 0) {
        prepared_format_data->width--;
        prepared_format_data->counter++;
        s21_strcat(*str, "0");
      }
    } else {
      if (prepared_format_data->flags.sharp == 1 && value != 0) {
        write_space(*str, prepared_format_data);
        prepared_format_data->width--;
        prepared_format_data->counter++;
        prepared_format_data->precision--;
        s21_strcat(*str, "0");
      } else {
        write_space(*str, prepared_format_data);
      }
    }
  }
  return 0;
}

int write_zero(char *str, struct PreparedFormatData *prepared_format_data) {
  if (prepared_format_data->flags.zero != 0 &&
      prepared_format_data->flags.minus == 0) {
    while (prepared_format_data->width > 0) {
      s21_strcat(str, "0");
      prepared_format_data->counter++;
      prepared_format_data->width--;
    }
  }
  return 0;
}

int write_exponent(char *value_str,
                   struct PreparedFormatData *prepared_format_data, int power) {
  while (*value_str) {
    value_str++;
  }
  char *start_position = value_str;
  *value_str = prepared_format_data->specifier;
  value_str++;
  if (power < 0) {
    *value_str = '-';
  } else {
    *value_str = '+';
  }
  value_str++;
  if (abs(power) < 10) {
    *value_str = '0';
    value_str++;
    if (power == 0) {
      *value_str = '0';
      value_str++;
    }
  }
  prepared_format_data->counter += value_str - start_position;
  prepared_format_data->width -= value_str - start_position;
  int i = 0;
  int sign = 1;
  if (power < 0) {
    sign *= -1;
  }
  int num = integer_length(power);
  i += num - 1;
  while (power != 0) {
    char ost = (power % 10) * sign + 48;
    value_str[i] = ost;
    power /= 10;
    i--;
    prepared_format_data->counter++;
    prepared_format_data->width--;
  }
  return 0;
}

long double mantissa(char **valueStr, long double exponent,
                     long long *precision,
                     struct PreparedFormatData *prepared_format_data) {
  long double mantissa = fabsl(exponent) * powl(10, *precision);

  if (mantissa != 0) {
    long double tmp = fabsl(exponent) * 10;

    while (tmp < 1 && (*precision) > 0) {
      tmp = tmp * 10;
      **valueStr = '0';
      (*valueStr)++;
      prepared_format_data->counter++;
      prepared_format_data->width--;
      (*precision)--;
    }
  }
  if (double_length(roundl(mantissa)) > double_length(mantissa)) {
    mantissa = 0;
  } else {
    mantissa = roundl(mantissa);
  }
  return mantissa;
}

int write_space(char *str, struct PreparedFormatData *prepared_format_data) {
  if (prepared_format_data->flags.zero == 0 ||
      prepared_format_data->flags.minus != 0) {
    while (prepared_format_data->width > 0) {
      s21_strcat(str, " ");
      prepared_format_data->counter++;
      prepared_format_data->width--;
    }
  }
  return 0;
}

int write_int(char *str, struct PreparedFormatData *prepared_format_data,
              long long value) {
  char valueStr[1024] = {'\0'};
  itoa(valueStr, value, prepared_format_data);
  minus_handler(str, valueStr, prepared_format_data, (long double)value);

  return 0;
}

int write_unsigned(char *str, struct PreparedFormatData *prepared_format_data,
                   unsigned long long value) {
  char valueStr[1024] = {'\0'};
  utoa(valueStr, value, prepared_format_data);
  minus_handler(str, valueStr, prepared_format_data, (long double)value);

  return 0;
}

int write_zeroes(char *str, struct PreparedFormatData *prepared_format_data) {
  int tmp = prepared_format_data->precision;

  const char ignore[] = "feEgG";
  while (tmp > 0 &&
         s21_strchr(ignore, prepared_format_data->specifier) == S21_NULL) {
    s21_strcat(str, "0");
    prepared_format_data->counter++;
    tmp--;
  }
  return 0;
}

int write_sign(char *str, long double value,
               struct PreparedFormatData *prepared_format_data) {
  if (prepared_format_data->specifier != 'u') {
    if (value < 0) {
      s21_strcat(str, "-");
      prepared_format_data->counter++;
    } else if (prepared_format_data->flags.plus != 0) {
      s21_strcat(str, "+");
      prepared_format_data->counter++;
    } else if (prepared_format_data->flags.spase != 0) {
      s21_strcat(str, " ");
      prepared_format_data->counter++;
    }
  }
  return 0;
}

int remove_zero(char *str, struct PreparedFormatData *prepared_format_data) {
  int end_position = (int)s21_strlen(str) - 1;
  if (end_position > 0) {
    while (str[end_position] == '0' && !prepared_format_data->flags.sharp &&
           prepared_format_data->has_precision) {
      str[end_position] = '\0';
      end_position--;
      prepared_format_data->counter--;
      prepared_format_data->width++;
    }
    if (!prepared_format_data->flags.sharp && str[end_position] == '.') {
      str[end_position] = '\0';
      prepared_format_data->counter--;
      prepared_format_data->width++;
    }
  }
  return 0;
}

int remove_zeroes_in_g(char *value_str,
                       struct PreparedFormatData *prepared_format_data) {
  if (s21_strchr("gG", prepared_format_data->specifier) != S21_NULL) {
    remove_zero(value_str, prepared_format_data);
  }
  return 0;
}

int decrease_zeroes_width(struct PreparedFormatData *PreparedFormatData) {
  if (PreparedFormatData->precision > 0) {
    PreparedFormatData->width -= PreparedFormatData->precision;
  }
  return 0;
}

int decrease_sign_width(long double value,
                        struct PreparedFormatData *prepared_format_data) {
  if (prepared_format_data->specifier != 'u') {
    if (value < 0 || (prepared_format_data->flags.plus != 0 && value >= 0) ||
        prepared_format_data->flags.spase != 0) {
      prepared_format_data->width--;
    }
  }
  return 0;
}

int double_length(long double value) {
  int length = 0;
  while (fabsl(value) >= 1) {
    length++;
    value /= 10;
  }
  return length;
}

int integer_length(long long int value) {
  int length = 0;
  while (value != 0) {
    length++;
    value /= 10;
  }
  return length;
}

int unsigned_length(unsigned long long value) {
  int length = 0;
  while (value != 0) {
    length++;
    value /= 10;
  }

  return length;
}

int is_NaN_or_INF(char *value_str,
                  struct PreparedFormatData *PreparedFormatData,
                  long double value) {
  int is_nanInf = 0;
  if (fabsl(value) == INFINITY) {
    value_str[0] = 'i';
    value_str[1] = 'n';
    value_str[2] = 'f';
    PreparedFormatData->counter += 3;
    PreparedFormatData->width -= 3;
    PreparedFormatData->precision = 0;
    is_nanInf = 1;
  } else if (s21_isNan(value)) {
    value_str[0] = 'n';
    value_str[1] = 'a';
    value_str[2] = 'n';

    PreparedFormatData->counter += 3;
    PreparedFormatData->width -= 3;
    PreparedFormatData->precision = 0;
    is_nanInf = 1;
  }
  return is_nanInf;
}

int x_to_upper(char *value_str) {
  for (s21_size_t i = 0; i < s21_strlen(value_str); i++) {
    if (value_str[i] >= 'a' && value_str[i] <= 'z') {
      value_str[i] -= 32;
    }
  }
  return 0;
}

int s21_atoi(char *str) {
  int result = 0;
  int sign = 1;
  str += s21_strspn(str, " \n\t\v\f\r");
  if (*str == '+') {
    str++;
  }
  if (*str == '-') {
    sign = -1;
    str++;
  }
  while (*str >= '0' && *str <= '9') {
    result = result * 10 + *str++ - '0';
  }
  return result * sign;
}

int utoa(char *value_str, unsigned long long value,
         struct PreparedFormatData *prepared_format_data) {
  if (value == 0 && (prepared_format_data->has_precision == 0 ||
                     (prepared_format_data->has_precision &&
                      prepared_format_data->precision != 0))) {
    value_str[0] = '0';
    prepared_format_data->precision--;
    prepared_format_data->counter++;
  } else {
    int i = 0;
    int length = unsigned_length(value);
    i += length - 1;
    prepared_format_data->precision -= length;

    while (value != 0) {
      char residue = (value % 10) + 48;
      value_str[i] = residue;
      value /= 10;
      i--;
      prepared_format_data->counter++;
    }
  }
  prepared_format_data->width -= s21_strlen(value_str);

  return 0;
}

int decimal_to_hexoct(char *value_str, unsigned long long value,
                      struct PreparedFormatData *prepared_format_data,
                      int base) {
  const char pattern[17] = {"0123456789abcdef"};
  char str[1024] = {'\0'};
  int i = 0;
  int residue = 0;
  if (value == 0 && ((prepared_format_data->has_precision == 1 &&
                      prepared_format_data->precision > 0) ||
                     (prepared_format_data->has_precision == 0))) {
    residue = value % base;
    value = value / base;
    str[i++] = pattern[residue];
  } else if (value == 0 && prepared_format_data->specifier == 'o' &&
             ((prepared_format_data->has_precision == 1 &&
               prepared_format_data->precision > 0) ||
              (prepared_format_data->has_precision == 0))) {
    str[i++] = '0';
  }

  while (value != 0) {
    residue = value % base;
    value = value / base;
    str[i++] = pattern[residue];
  }
  i--;

  int j = 0;
  while (i >= 0) {
    value_str[j++] = str[i--];
  }
  return 0;
}

int ftoa(char *value_str, struct PreparedFormatData *prepared_format_data,
         long double value) {
  long double tmp = floorl(fabsl(value));
  if (value < 0) {
    tmp = -tmp;
  }
  long double exponent = value - tmp;
  long long precision = 6;
  int has_precision = 1;

  if (prepared_format_data->has_precision != 0) {
    precision = prepared_format_data->precision;

    if (prepared_format_data->precision == 0) {
      prepared_format_data->has_precision = 0;
      tmp = roundl(value);
      has_precision = 0;
    } else {
      tmp = floorl(fabsl(roundl(value * powl(10, precision + 1)) /
                         powl(10, precision + 1)));
      if (value < 0) {
        tmp = -tmp;
      }
    }
  }
  write_double(value_str, tmp, prepared_format_data);

  if (has_precision == 1) {
    write_dot(&value_str, prepared_format_data);
    tmp = mantissa(&value_str, exponent, &precision, prepared_format_data);

    if (tmp == 0) {
      for (int i = 0; i < precision; i++) {
        *value_str = '0';
        prepared_format_data->counter++;
        prepared_format_data->width--;
        prepared_format_data->precision--;
        value_str++;
      }
    } else {
      write_double(value_str, tmp, prepared_format_data);
    }

  } else if (prepared_format_data->flags.sharp == 1) {
    write_dot(&value_str, prepared_format_data);
  }
  return 0;
}

int itoa(char *value_str, long long int value,
         struct PreparedFormatData *prepared_format_data) {
  if (value == 0 && (prepared_format_data->has_precision == 0 ||
                     (prepared_format_data->has_precision &&
                      prepared_format_data->precision != 0))) {
    value_str[0] = '0';
    prepared_format_data->precision--;
    prepared_format_data->counter++;
  } else {
    int i = 0;
    int sign = 1;
    if (value < 0) {
      sign = -1;
    }
    int length = integer_length(value);
    i += length - 1;
    prepared_format_data->precision -= length;

    while (value != 0) {
      char residue = (value % 10) * sign + 48;
      value_str[i] = residue;
      value /= 10;
      i--;
      prepared_format_data->counter++;
    }
  }
  prepared_format_data->width -= s21_strlen(value_str);
  return 0;
}
