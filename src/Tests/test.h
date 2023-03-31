#ifndef C2_S21_STRINGPLUS_0_SRC_TESTS_TEST_H_
#define C2_S21_STRINGPLUS_0_SRC_TESTS_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../s21_string.h"
#include "check.h"
#include "limits.h"
// #include "test_me.h"
#define SIZE 256

Suite *s21_string_suite(void);
Suite *sprintf_suite(void);
Suite *s21_sscanf_suite(void);
// Suite *test_s21_sscanf(void);

#endif  // C2_S21_STRINGPLUS_0_SRC_TESTS_TEST_H_
