#include "s21_sscanf.h"
char *s21_atos(char **temp_s, struct characteristic C, char *s_result,
               int *mistake, char **temp_f) {
  skip_space(temp_s, temp_f);
  if (C.width == 0) C.width = INT_MAX;
  int i = 0;
  for (; i < C.width && *(*(temp_s) + i) != '\0' && find_space(temp_s, i);
       i++) {
    *(s_result + i) = *(*(temp_s) + i);
  }
  *(s_result + i) = '\0';
  if (i == 0) *mistake = -1;
  return s_result;
}