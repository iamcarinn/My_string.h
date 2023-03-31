#include "test.h"

// STRLEN

START_TEST(STRLENTest1) {
  char str[] = "Hello";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 1");
}
END_TEST

START_TEST(STRLENTest2) {
  char str[] = "Hegd    llo";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 2");
}
END_TEST

START_TEST(STRLENTest3) {
  char str[] = "";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 3");
}
END_TEST

START_TEST(STRLENTest4) {
  char str[] = "lorem\\tipsum\\tdolor\\sit\\amet\\ ";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 4");
}
END_TEST
START_TEST(STRLENTest5) {
  char str[] = "  \f\r\t";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 5");
}
END_TEST
START_TEST(STRLENTest6) {
  char str[] = "     ";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 6");
}
END_TEST
START_TEST(STRLENTest7) {
  char str[] = "Hi\0bye";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 7");
}
END_TEST
START_TEST(STRLENTest8) {
  char str[] = "Hi\0bye\n";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 8");
}
END_TEST
START_TEST(STRLENTest9) {
  char str[] = "Hi\nbye";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 9");
}
END_TEST
START_TEST(STRLENTest10) {
  char str[] = "Hi\tbye";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 10");
}
END_TEST
START_TEST(STRLENTest11) {
  char str[] = "12345679876543565432344*+-++18=49894";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 11");
}
END_TEST
START_TEST(STRLENTest12) {
  char str[] = "ytsrytrytrypjosrikd[aerokrhmg woerk o";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 12");
}
END_TEST
START_TEST(STRLENTest13) {
  char str[] = "hhbwiuhqpeiru437501/0qwer*------ *****";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 13");
}
END_TEST
START_TEST(STRLENTest14) {
  char str[] = "\t\v\t\t\t\t\tt\t0\n";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Failed on 14");
}
END_TEST
// // STRCHR

START_TEST(STRCHRTest1) {
  char str[] = "Hello world";
  int ch = 'w';
  ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest2) {
  char str[] = "Hello world";
  int ch = 'o';
  ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest3) {
  char str[] = "Hello world";
  int ch = 'c';
  ck_assert_ptr_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest4) {
  char str[] = "Hello world";
  int ch = 'H';
  ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest5) {
  char str[] = "Hello world";
  int ch = '\0';
  ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest6) {
  char str[] = "";
  int ch = '\0';
  ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest7) {
  char str[] = "Hello\tworld";
  int ch = '\0';
  ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST

START_TEST(STRCHRTest8) {
  char str[] = "Hello, world!";
  int ch = 33;
  ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST
START_TEST(STRCHRTest9) {
  char str[] = "Hello, world!";
  int ch = 'A';
  ck_assert_pstr_eq(s21_strchr(str, ch), strchr(str, ch));
}
END_TEST
START_TEST(STRCHRTest10) {
  char str[] = "\0Hello, world!\0";
  int ch = 'l';
  ck_assert_pstr_eq(s21_strchr(str, ch), strchr(str, ch));
}
// // STRSPN

START_TEST(STRSPNTest1) {
  char *str1 = "12345";
  char *str2 = "123";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 1");
}
END_TEST

START_TEST(STRSPNTest2) {
  char *str1 = "12345";
  char *str2 = "12sd34";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 2");
}
END_TEST

START_TEST(STRSPNTest3) {
  char *str1 = "12345";
  char *str2 = "12sdf4";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 3");
}
END_TEST

START_TEST(STRSPNTest4) {
  char *str1 = "12345";
  char *str2 = "kbf";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 4");
}
END_TEST

START_TEST(STRSPNTest5) {
  char *str1 = "12345";
  char *str2 = "54321";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 5");
}
END_TEST

START_TEST(STRSPNTest6) {
  char *str1 = "12345";
  char *str2 = "5qw4w3qwe2qweqw1";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 6");
}
END_TEST

START_TEST(STRSPNTest7) {
  char *str1 = "12345";
  char *str2 = " ";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 7");
}
END_TEST

START_TEST(STRSPNTest8) {
  char *str1 = "12345";
  char *str2 = " 1";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 8");
}
END_TEST
START_TEST(STRSPNTest9) {
  char *str1 = "12345";
  char *str2 = " /0";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 9");
}
END_TEST
START_TEST(STRSPNTest10) {
  char *str1 = "Hello, world!";
  char *str2 = " world";
  ck_assert_msg(s21_strspn(str1, str2) == strspn(str1, str2), "Failed on 10");
}
END_TEST
// // STRCSPN

START_TEST(STRCSPNTest1) {
  char *src = "0123456789";
  char *str = "54";
  ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on 4");
}
END_TEST

START_TEST(STRCSPNTest2) {
  char *src = "0123456789";
  char *str = "e";
  ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on 0");
}
END_TEST

START_TEST(STRCSPNTest3) {
  char *src = "46";
  char *str = "123";
  ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on 2");
}
END_TEST

START_TEST(STRCSPNTest4) {
  char *src = "HELLO";
  char *str = "HELLO";
  ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on 0");
}
END_TEST

START_TEST(STRCSPNTest5) {
  char *src = "";
  char *str = "hi";
  ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on 0");
}
END_TEST
START_TEST(STRCSPNTest6) {
  char *src = "\0";
  char *str = "\0";
  ck_assert_msg(s21_strcspn(src, str) == strcspn(src, str), "Failed on 0");
}
END_TEST

// // MEMCPY

START_TEST(MEMCPYTest1) {
  char *src = "HELLO WORLD";
  char dest[15];
  char dest2[15];
  ck_assert_mem_eq(s21_memcpy(dest, src, 11), memcpy(dest2, src, 11), 11);
}
END_TEST

START_TEST(MEMCPYTest2) {
  char *src = "HELLO";
  char dest[5];
  char dest2[5];
  ck_assert_mem_eq(s21_memcpy(dest, src, 5), memcpy(dest2, src, 5), 5);
}
END_TEST

START_TEST(MEMCPYTest3) {
  char *src = "HELLO";
  char dest[5];
  char dest2[5];
  ck_assert_mem_eq(s21_memcpy(dest, src, 5), memcpy(dest2, src, 5), 0);
}
END_TEST

START_TEST(MEMCPYTest4) {
  char *src = "zy\0xw";
  char dest[5];
  char dest2[5];
  ck_assert_mem_eq(s21_memcpy(dest, src, 5), memcpy(dest2, src, 5), 0);
}
END_TEST

START_TEST(MEMCPYTest5) {
  char *src = "zy\0xw";
  char dest[5];
  char dest2[5];
  ck_assert_mem_eq(s21_memcpy(dest, src, 5), memcpy(dest2, src, 5), 0);
}
END_TEST

START_TEST(MEMCPYTest6) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Good";
  s21_size_t n = 4;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(MEMCPYTest7) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(MEMCPYTest8) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(MEMCPYTest9) {
  char s1[] = "new_strnew_string";
  char s2[] = "new_strnew_string";
  char s3[] = "new_string";
  s21_size_t n = strlen(s3);
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(MEMCPYTest10) {
  char s1[] = "699\017020";
  char s2[] = "699\017020";
  char s3[] = "com";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(MEMCPYTest11) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  char s3[] = "com";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

// STRCAT
START_TEST(STRCATTest1) {
  char app[1024] = "вторая строка ";
  char dst[1024] = "первая строка ";
  ck_assert_str_eq(s21_strcat(dst, app), strcat(dst, app));
}
END_TEST

START_TEST(STRCATTest2) {
  char app[1024] = " ";
  char dst[1024] = "   ";
  ck_assert_str_eq(s21_strcat(dst, app), strcat(dst, app));
}
END_TEST

START_TEST(STRCATTest3) {
  char app[1024] = "s s d";
  char dst[1024] = " s  s  s  sd aff   ";
  ck_assert_str_eq(s21_strcat(dst, app), strcat(dst, app));
}
END_TEST

START_TEST(STRCATTest4) {
  char app[1024] = "sdddadasdsa";
  char dst[1024] = "s                              ";
  ck_assert_str_eq(s21_strcat(dst, app), strcat(dst, app));
}
END_TEST

START_TEST(STRCATTest5) {
  char app[1024] = "\0";
  char dst[1024] = " \0";
  ck_assert_str_eq(s21_strcat(dst, app), strcat(dst, app));
}
END_TEST

START_TEST(STRCATTest6) {
  char app[1024] = "\0 hi";
  char dst[1024] = " hi\0";
  ck_assert_str_eq(s21_strcat(dst, app), strcat(dst, app));
}
END_TEST

START_TEST(STRCATTest7) {
  char app[1024] = "hi";
  char dst[1024] = "\t\0\n\t\t\t\t";
  ck_assert_str_eq(s21_strcat(dst, app), strcat(dst, app));
}
END_TEST

START_TEST(STRCATTest8) {
  char s1[100] = "Hello\0world!";
  char s2[100] = "Hello\0world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(STRCATTest9) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\n\0\\d\f\\g\7";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST
// // MEMCMP
START_TEST(MEMCMPTest1) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  int n = 6;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(MEMCMPTest2) {
  char str1[] = "Hello";
  char str2[] = "Help";
  int n = 4;
  ck_assert_int_lt(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(MEMCMPTest3) {
  char str1[] = "Help";
  char str2[] = "Hello";
  int n = 4;
  ck_assert_int_gt(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(MEMCMPTest4) {
  char str1[] = "Help";
  char str2[] = "Hello";
  int n = 3;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(MEMCMPTest5) {
  char str1[] = "Hello";
  char str2[] = "";
  int n = 4;
  ck_assert_int_gt(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(MEMCMPTest6) {
  char str1[] = "";
  char str2[] = "";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(MEMCMPTest7) {
  char str1[] = "gsafh";
  char str2[] = "dhkjfhs";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(MEMCMPTest8) {
  char str1[] = "test\0test";
  char str2[] = "test";
  int n = 10;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(MEMCMPTest9) {
  char str1[] = "test";
  char str2[] = "teSt";
  int n = 4;
  ck_assert_int_gt(s21_memcmp(str1, str2, n), 0);
}
END_TEST

START_TEST(MEMCMPTest10) {
  char str1[] = "t\200";
  char str2[] = "t\0";
  int n = 2;
  ck_assert_int_gt(s21_memcmp(str1, str2, n), 0);
}
END_TEST

// STRNCAT
START_TEST(STRNCATTest1) {
  char str1[1024] = "Hello";
  char str2[] = " World";
  int n = 6;
  ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST

START_TEST(STRNCATTest2) {
  char str1[1024] = "Hello";
  char str2[] = " World";
  int n = 4;
  ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST

START_TEST(STRNCATTest3) {
  char str1[1024] = "";
  char str2[] = " HELLO";
  int n = 5;
  ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST

START_TEST(STRNCATTest4) {
  char str1[1024] = "HI, ";
  char str2[] = "HELL\0O";
  int n = 5;
  ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST

START_TEST(STRNCATTest5) {
  char str1[1024] = "\0";
  char str2[] = "H";
  int n = 5;
  ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST

START_TEST(STRNCATTest6) {
  char str1[1024] = "\0";
  char str2[] = "\0\t\0";
  int n = 3;
  ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST

START_TEST(STRNCATTest7) {
  char str1[1024] = "Hello ";
  char str2[] = "\t world";
  int n = 2;
  ck_assert_str_eq(s21_strncat(str1, str2, n), strncat(str1, str2, n));
}
END_TEST

// // STRNCPY

START_TEST(STRNCPYTest1) {
  char str1[1024] = "Hello";
  char str2[] = " World";
  int n = 6;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(STRNCPYTest2) {
  char str1[1024] = "Hello";
  char str2[] = " World";
  int n = 4;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(STRNCPYTest3) {
  char str1[1024] = "";
  char str2[] = " HELLO";
  int n = 5;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(STRNCPYTest4) {
  char str1[1024] = "HI, ";
  char str2[] = " HELL\0O";
  int n = 5;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(STRNCPYTest5) {
  char str1[1024] = "HI, ";
  char str2[] = " HELLO";
  int n = 20;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(STRNCPYTest6) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "fг-аг-аг";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(STRNCPYTest7) {
  char s1[70] = "";
  char s2[70] = "";
  char s3[] = "sdfjskfepwo;sdlfkj!!!!!!!!!!!!!!!!";
  s21_size_t n = strlen(s3);
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(STRNCPYTest8) {
  char str1[1024] = "\0\0\0\t, ";
  char str2[] = "hiiiiii\tgggg";
  int n = 10;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

// // STRRCHR
START_TEST(STRRCHRTest1) {
  char str1[] = "Hello, Mel";
  int c = 'e';
  ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST

START_TEST(STRRCHRTest2) {
  char str1[] = "Hello, Mel";
  int c = 'p';
  ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST

START_TEST(STRRCHRTest3) {
  char str1[] = "";
  int c = 'l';
  ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST

START_TEST(STRRCHRTest4) {
  char str1[] = "Hello";
  int c = 0;
  ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST

START_TEST(STRRCHRTest5) {
  char str1[] = "Hello";
  int c = 'o';
  ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST

START_TEST(STRRCHRTest6) {
  char str1[] = "Hello";
  int c = '\0';
  ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST

START_TEST(STRRCHRTest7) {
  char str1[] = "Hello";
  int c = 32;
  ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST

// // MEMMOVE

START_TEST(MEMMOVETest1) {
  char dest1[10] = "fd";
  char dest2[10] = "fd";
  char src[20] = "hello";
  ck_assert_mem_eq(s21_memmove(dest1 + 2, src + 2, 3),
                   memmove(dest2, src + 2, 3), 5);
}
END_TEST

START_TEST(MEMMOVETest2) {
  char dest1[10] = "fd";
  char dest2[10] = "fd";
  char src[20] = "hello";
  ck_assert_mem_eq(s21_memmove(dest1, src, 0), memmove(dest2, src, 0), 0);
}
END_TEST

START_TEST(MEMMOVETest3) {
  char dest1[10] = "fd";
  char dest2[10] = "fd";
  char src[20] = "hello";
  ck_assert_mem_eq(s21_memmove(dest1, src, 9), memmove(dest2, src, 9), 0);
}
END_TEST

START_TEST(MEMMOVETest4) {
  char dest1[10] = "";
  char dest2[10] = "";
  char src[20] = "so\0";
  ck_assert_mem_eq(s21_memmove(dest1, src, 10), memmove(dest2, src, 10), 0);
}
END_TEST

START_TEST(MEMMOVETest5) {
  char str[] = "iloveworld";
  char str_test[] = "iloveworld";
  s21_memmove(str, str + 5, 5);
  memmove(str_test, str_test + 5, 5);
  ck_assert_str_eq(str, str_test);
}
END_TEST

START_TEST(MEMMOVETest6) {
  char str[] = "iloveworld";
  char str_test[] = "iloveworld";
  s21_memmove(str + 5, str, 5);
  memmove(str_test + 5, str_test, 5);
  ck_assert_str_eq(str, str_test);
}
END_TEST

START_TEST(MEMMOVETest7) {
  char str[] = "iloveworld";
  char str_test[] = "iloveworld";
  s21_memmove(str, str + 4, 7);
  memmove(str_test, str_test + 4, 7);
  ck_assert_str_eq(str, str_test);
}
END_TEST

START_TEST(MEMMOVETest8) {
  char str[] = "iloveworld";
  char str_test[] = "iloveworld";
  s21_memmove(str + 3, str, 5);
  memmove(str_test + 3, str_test, 5);
  ck_assert_str_eq(str, str_test);
}
END_TEST

START_TEST(MEMMOVETest9) {
  char str[] = "iloveworld";
  char str_test[] = "iloveworld";
  s21_memmove(str + 4, str + 3, 3);
  memmove(str_test + 4, str_test + 3, 3);
  ck_assert_str_eq(str, str_test);
}
END_TEST

START_TEST(MEMMOVETest10) {
  char str[] = "iloveworld";
  char str_test[] = "iloveworld";
  s21_memmove(str, str, 3);
  memmove(str_test, str_test, 3);
  ck_assert_str_eq(str, str_test);
}
END_TEST

// // STRSTR

START_TEST(STRSTRTest1) {
  char str1[10] = "hello";
  char str2[10] = "he";
  ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST(STRSTRTest2) {
  char str1[10] = "hello";
  char str2[10] = "";
  ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST(STRSTRTest3) {
  char str1[10] = "hello";
  char str2[10] = "qw";
  ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST(STRSTRTest4) {
  char str1[10] = "hello";
  char str2[10] = "hellp";
  ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST(STRSTRTest5) {
  char str1[1024] = "hello sweet hello";
  char str2[10] = "hello";
  ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST(STRSTRTest6) {
  char str1[1024] = "hello sweet hello";
  char str2[10] = "";
  ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST(STRSTRTest7) {
  char str1[1024] = "1   345 345 345 345 345";
  char str2[10] = "345";
  ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST(STRSTRTest8) {
  char str1[1024] = "sususususpicioussusususpicious";
  char str2[10] = "susp";
  ck_assert_msg(s21_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

// // STRCMP

START_TEST(STRCMPTest1) {
  char str1[10] = "hello";
  char str2[10] = "hello";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(STRCMPTest2) {
  char str1[10] = "hello";
  char str2[10] = "hellq";
  ck_assert_int_lt(s21_strcmp(str1, str2), 0);
}
END_TEST

START_TEST(STRCMPTest3) {
  char str1[10] = "hello";
  char str2[10] = "helle";
  ck_assert_int_gt(s21_strcmp(str1, str2), 0);
}
END_TEST

START_TEST(STRCMPTest4) {
  char str1[10] = "hello";
  char str2[10] = "";
  ck_assert_int_gt(s21_strcmp(str1, str2), 0);
}
END_TEST

START_TEST(STRCMPTest5) {
  char str1[10] = "";
  char str2[10] = "hello";
  ck_assert_int_lt(s21_strcmp(str1, str2), 0);
}
END_TEST

START_TEST(STRCMPTest6) {
  char str1[10] = "";
  char str2[10] = "";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(STRCMPTest7) {
  char str1[10] = "hello";
  char str2[10] = "hello";

  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(STRCMPTest8) {
  char str1[] = "wertyuiolkjhgfxcvbhjk";
  char str2[] = "wertyuiolkjhgfxcvbhjk";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

// // MEMCHR

START_TEST(MEMCHRTest1) {
  char str1[10] = "Hello";
  ck_assert_mem_eq(s21_memchr(str1, 'H', 5), memchr(str1, 'H', 5), 5);
}
END_TEST

START_TEST(MEMCHRTest2) {
  char str1[10] = "Hello";
  ck_assert_msg(s21_memchr(str1, 'h', 5) == S21_NULL,
                "Failed: Str == S21_NULL");
}
END_TEST

START_TEST(MEMCHRTest3) {
  char str1[10] = "Hellosdsfq";
  ck_assert_msg(s21_memchr(str1, 'h', 5) == S21_NULL, "Failed: Str ==S21_NULL");
}
END_TEST

START_TEST(MEMCHRTest4) {
  char str1[10] = "Hellosdsfq";
  ck_assert_mem_eq(s21_memchr(str1, 'l', 5), memchr(str1, 'l', 5), 3);
}
END_TEST

START_TEST(MEMCHRTest5) {
  char str1[10] = "Hellosdsfq";
  ck_assert_mem_eq(s21_memchr(str1, 'l', 0), memchr(str1, 'l', 0), 0);
}
END_TEST

START_TEST(MEMCHRTest6) {
  char str[] = "Hello, world!";
  int ch = 65;
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(MEMCHRTest7) {
  char str[] = "69917020";
  int ch = '\0';
  s21_size_t len = 9;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(MEMCHRTest8) {
  char str[] = "Hello, world!";
  int ch = 65;
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

// STRCPY

START_TEST(STRCPYTest1) {
  char str[] = "Hello";
  char str1[15];
  char str2[15];
  s21_strcpy(str1, str);
  strcpy(str2, str);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(STRCPYTest2) {
  char str[] = "";
  char str1[15];
  char str2[15];
  s21_strcpy(str1, str);
  strcpy(str2, str);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(STRCPYTest3) {
  char str[] = "";
  char str1[15] = "test";
  char str2[15] = "test";
  s21_strcpy(str1, str);
  strcpy(str2, str);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(STRCPYTest4) {
  char str[] = "Test";
  char str1[1024];
  char str2[1024];
  s21_strcpy(str1, str);
  strcpy(str2, str);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(STRCPYTest5) {
  char str1[100] = "testing\nthis";
  char str2[] = "testing_this";
  char str3[100] = "testing\nthis";
  ck_assert_pstr_eq(strcpy(str1, str2), s21_strcpy(str3, str2));
}
END_TEST

START_TEST(STRCPYTest6) {
  char str1[100] = "testing_this";
  char str2[] = "testing\0this";
  char str3[100] = "testing_this";
  ck_assert_pstr_eq(strcpy(str1, str2), s21_strcpy(str3, str2));
}
END_TEST

START_TEST(STRCPYTest7) {
  char str1[100] = "\0";
  char str2[] = "testing_this";
  char str3[100] = "\0";
  ck_assert_pstr_eq(strcpy(str1, str2), s21_strcpy(str3, str2));
}
END_TEST

START_TEST(STRCPYTest8) {
  char str1[100] = "this\0\0\0";
  char str2[] = "\0this\0";
  char str3[100] = "this\0\0\0";
  ck_assert_pstr_eq(strcpy(str1, str2), s21_strcpy(str3, str2));
}
END_TEST

START_TEST(STRCPYTest9) {
  char str1[100] = "thi00s";
  char str2[] = "\0testing_this";
  char str3[100] = "thi00s";
  ck_assert_pstr_eq(strcpy(str1, str2), s21_strcpy(str3, str2));
}
END_TEST

START_TEST(STRCPYTest10) {
  char str1[100] = "";
  char str2[] = " ";
  char str3[100] = "";
  ck_assert_pstr_eq(strcpy(str1, str2), s21_strcpy(str3, str2));
}
END_TEST
// // STRPBRK

START_TEST(STRPBRKTest1) {
  char *str = "this is a test";
  char *str1 = "this is a test";
  str1 = strpbrk(str1, "this");
  str = s21_strpbrk(str, "this");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(STRPBRKTest2) {
  char *str = "this is a test";
  char *str1 = "this is a test";
  str1 = strpbrk(str1, " ");
  str = s21_strpbrk(str, " ");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(STRPBRKTest3) {
  char *str = "this is a test, this is ...";
  char *str1 = "this is a test, this is ...";
  str1 = strpbrk(str1, "this");
  str = s21_strpbrk(str, "this");
  ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(STRPBRKTest4) {
  char *str = "this is a test, this is ...";
  char *str1 = "this is a test, this is ...";
  ck_assert_ptr_eq(s21_strpbrk(str, "prom"), strpbrk(str1, "prom"));
}
END_TEST

START_TEST(STRPBRKTest5) {
  char s1[] = "Hello, world!";
  char s2[] = "!";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST
START_TEST(STRPBRKTest6) {
  char s1[] = "";
  char s2[] = "He";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST
START_TEST(STRPBRKTest7) {
  char s1[] = "\0";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

// // STRNCMP

START_TEST(STRNCMPTest1) {
  char *str1 = "1234567890";
  char *str2 = "1234567890";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(STRNCMPTest2) {
  char *str1 = "1234567890";
  char *str2 = "1224567890";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(STRNCMPTest3) {
  char *str1 = "1224567890";
  char *str2 = "1234567890";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(STRNCMPTest4) {
  char *str1 = "";
  char *str2 = "";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(STRNCMPTest5) {
  char *str1 = "1224567890";
  char *str2 = "";
  ck_assert_int_gt(s21_strncmp(str1, str2, 5), 0);
}
END_TEST

START_TEST(STRNCMPTest6) {
  char *str1 = "122";
  char *str2 = "345";
  ck_assert_int_lt(s21_strncmp(str1, str2, 5), 0);
}
END_TEST

START_TEST(STRNCMPTest7) {
  char *str1 = "test\0abc";
  char *str2 = "test\0";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(STRNCMPTest8) {
  char *str1 = "1224567890";
  char *str2 = "02";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

// // MEMSET

START_TEST(MEMSETTest1) {
  char str1[15] = "1234567890";
  char str2[15] = "1234567890";
  int c = '1';
  int n = 10;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(MEMSETTest2) {
  char str1[15] = "1234567890";
  char str2[15] = "5432167890";
  int c = '1';
  int n = 10;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(MEMSETTest3) {
  char str1[15] = "1234567890";
  char str2[15] = "5432167890";
  int c = 'q';
  int n = 10;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(MEMSETTest4) {
  char str1[15] = "1234567890";
  char str2[15] = "5432167890";
  int c = '1';
  int n = 5;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 5);
}
END_TEST

START_TEST(MEMSETTest5) {
  char str1[15] = "qweqweqweqwe";
  char str2[15] = "ewqewqewqewq";
  int c = '1';
  int n = 10;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(MEMSETTest6) {
  char str1[15] = "qweqweqweqwe";
  char str2[15] = "qweqweqweqwe";
  int c = '\0';
  int n = 5;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(MEMSETTest7) {
  char str1[15] = "qweqweqweqwe";
  char str2[15] = "qweqweqweqwe";
  int c = ' ';
  int n = 5;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

// // STRTOK

START_TEST(STRTOKTest2) {
  char str[30] = "test1/test2/test3/test4";
  char *delim = ",";
  ck_assert_msg(s21_strtok(str, delim) == strtok(str, delim), "Failed on 2");
}
END_TEST

START_TEST(STRTOKTest3) {
  char *s1 = S21_NULL;
  char *s2 = S21_NULL;
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(STRTOKTest4) {
  char str[30] = "AadacAdxa";
  char *delim = "a";
  ck_assert_msg(s21_strtok(str, delim) == strtok(str, delim), "Failed on 4");
}
END_TEST

START_TEST(STRTOKTest5) {
  char str[30] = "ased dse c sze wsew";
  char *delim = "e";
  ck_assert_msg(s21_strtok(str, delim) == strtok(str, delim), "Failed on 5");
}
END_TEST

START_TEST(STRTOKTest6) {
  char dest8[] = "test1/test2/test3/test4";
  char orig8[] = "test1/test2/test3/test4";
  ck_assert_str_eq(s21_strtok(dest8, "/"), strtok(orig8, "/"));
  ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  ck_assert_ptr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));

  char dest9[] = "test1/test2/test3///";
  char orig9[] = "test1/test2/test3///";
  ck_assert_str_eq(s21_strtok(dest9, "/"), strtok(orig9, "/"));
  ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  ck_assert_ptr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));

  char dest10[] = "///test1///test2/test3/";
  char orig10[] = "///test1///test2/test3/";
  ck_assert_str_eq(s21_strtok(dest10, "/"), strtok(orig10, "/"));
  ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
  ck_assert_ptr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
}
END_TEST

// // STRERROR

START_TEST(STRERRORTest1) {
  for (int i = 0; i < 107; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(STRERRORTest2) {
  for (int i = 134; i < 234; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(STRERRORTest3) {
  for (int i = 0; i <= 7; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(STRERRORTest4) {
  for (int i = 134; i < 300; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(STRERRORTest5) {
  for (int i = 1; i <= 3; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

// TO_UPPER
START_TEST(TOUPPERTest1) {
  char str[4] = "abc";
  char *str1 = (char *)s21_to_upper(str);
  ck_assert_str_eq(str1, "ABC");
  free(str1);
}
END_TEST

START_TEST(TOUPPERTest2) {
  char str[12] = "Hello World";
  char *str1 = (char *)s21_to_upper(str);
  ck_assert_str_eq(str1, "HELLO WORLD");
  free(str1);
}
END_TEST

START_TEST(TOUPPERTest3) {
  char str[1] = "";
  char *str1 = (char *)s21_to_upper(str);
  ck_assert_str_eq(str1, "");
  free(str1);
}
END_TEST

START_TEST(TOUPPERTest4) {
  char str[4] = "ABC";
  char *str1 = (char *)s21_to_upper(str);
  ck_assert_str_eq(str1, "ABC");
  free(str1);
}
END_TEST

START_TEST(TOUPPERTest5) {
  char str[6] = "1234a";
  char *str1 = (char *)s21_to_upper(str);
  ck_assert_str_eq(str1, "1234A");
  free(str1);
}
END_TEST

START_TEST(TOUPPERTest6) {
  char *str = S21_NULL;
  char *str1 = (char *)s21_to_upper(str);
  ck_assert_ptr_eq(str1, S21_NULL);
  free(str1);
}
END_TEST

START_TEST(TOUPPERTest7) {
  char str[12] = "abc\0hello";
  char *str1 = (char *)s21_to_upper(str);
  ck_assert_str_eq(str1, "ABC");
  free(str1);
}
END_TEST

START_TEST(TOUPPERTest8) {
  char s1[30] = "ALREADY UPPER";
  char *s2 = s21_to_upper(s1);
  char s3[] = "ALREADY UPPER";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(TOUPPERTest9) {
  char s1[30] = "_?};!234";
  char *s2 = s21_to_upper(s1);
  char s3[] = "_?};!234";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(TOUPPERTest10) {
  char *s1 = S21_NULL;
  char *s2 = s21_to_upper(s1);
  char *s3 = S21_NULL;
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

// TO_LOWER
START_TEST(TOLOWERTest1) {
  char str[4] = "abc";
  char *str2 = (char *)s21_to_lower(str);
  ck_assert_str_eq(str2, "abc");
  free(str2);
}
END_TEST

START_TEST(TOLOWERTest2) {
  char str[12] = "Hello World";
  char *str2 = (char *)s21_to_lower(str);
  ck_assert_str_eq(str2, "hello world");
  free(str2);
}
END_TEST

START_TEST(TOLOWERTest3) {
  char str[1] = "";
  char *str2 = (char *)s21_to_lower(str);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(TOLOWERTest4) {
  char str[4] = "ABC";
  char *str2 = (char *)s21_to_lower(str);
  ck_assert_str_eq(str2, "abc");
  free(str2);
}
END_TEST

START_TEST(TOLOWERTest5) {
  char str[6] = "1234a";
  char *str2 = (char *)s21_to_lower(str);
  ck_assert_str_eq(str2, "1234a");
  free(str2);
}
END_TEST

START_TEST(TOLOWERTest6) {
  char *str = S21_NULL;
  char *str2 = (char *)s21_to_lower(str);
  ck_assert_ptr_eq(str2, S21_NULL);
  free(str2);
}
END_TEST

START_TEST(TOLOWERTest7) {
  char *str = "WoW\0, I love it!";
  char *str2 = (char *)s21_to_lower(str);
  ck_assert_str_eq(str2, "wow");
  free(str2);
}
END_TEST

START_TEST(TOLOWERTest8) {
  char s1[30] = "already lower";
  char s3[] = "already lower";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(TOLOWERTest9) {
  char s1[30] = "\nh\t\\g123123";
  char s3[] = "\nH\t\\G123123";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(TOLOWERTest10) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(TOLOWERTest11) {
  char s1[30] = "_?};!234";
  char s3[] = "_?};!234";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST
// INSERT
START_TEST(INSERTTest1) {
  char s1[] = "wtf";
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(INSERTTest2) {
  char s1[] = "";
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s2, s4);
  if (s2) free(s2);
}
END_TEST

START_TEST(INSERTTest3) {
  char str1[10] = "1234";
  char str2[10] = " ";
  char *str3 = (char *)s21_insert(str1, str2, 1);
  ck_assert_str_eq(str3, "1 234");
  free(str3);
}
END_TEST

START_TEST(INSERTTest4) {
  char str1[4] = "abc";
  char str2[2] = " ";
  char *str3 = (char *)s21_insert(str1, str2, 2);
  ck_assert_str_eq(str3, "ab c");
  free(str3);
}
END_TEST

START_TEST(INSERTTest6) {
  char str1[4] = "abc";
  char str2[5] = "1234";
  char *str3 = (char *)s21_insert(str1, str2, 0);
  ck_assert_str_eq(str3, "1234abc");
  free(str3);
}
END_TEST

START_TEST(INSERTTest7) {
  char *str1 = S21_NULL;
  char str2[5] = "1234";
  char *str3 = (char *)s21_insert(str1, str2, 0);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(INSERTTest8) {
  char s1[30] = "abcdefghij";
  char s3[] = "\'I WAS HERE\'";
  char s4[] = "abc\'I WAS HERE\'defghij";
  s21_size_t num = 3;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(INSERTTest9) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = S21_NULL;
  s21_size_t num = 10;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(INSERTTest10) {
  char *str1 = S21_NULL;
  char str2[5] = "1234";
  char *str3 = (char *)s21_insert(str1, str2, 0);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(INSERTTest11) {
  char *s1 = S21_NULL;
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST
// TRIM

START_TEST(TRIMTest1) {
  char *res = s21_trim("testc", "c");
  ck_assert_str_eq(res, "test");
  free(res);

  res = s21_trim(" test ", " ");
  ck_assert_str_eq(res, "test");
  free(res);

  res = s21_trim(" ", " ");
  ck_assert_str_eq(res, "");
  free(res);

  res = s21_trim("*te*st*", "*");
  ck_assert_str_eq(res, "te*st");
  free(res);

  res = s21_trim(" te st001", " ");
  ck_assert_str_eq(res, "te st001");
  free(res);

  res = s21_trim(" /*()", ")(/ *");
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(TRIMTest2) {
  char s1[30] = "-?hello, world!";
  char s3[] = "!?-";
  char s4[] = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(TRIMTest3) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = "abc";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(TRIMTest4) {
  char *s1 = S21_NULL;
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(TRIMTest5) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(TRIMTest6) {
  char s1[] = " wtf ";
  char *s3 = S21_NULL;
  char *s4 = " wtf ";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(TRIMTest7) {
  char s1[] = " wtf ";
  char *s3 = "";
  char *s4 = " wtf ";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST
// функция для suite
Suite *s21_string_suite() {
  Suite *s1 = suite_create("Test_string");
  TCase *StrLenTest = tcase_create("STRLEN");
  TCase *StrChrTest = tcase_create("STRCHR");
  TCase *StrSpnTest = tcase_create("STRSPN");
  TCase *StrcSpnTest = tcase_create("STRСSPN");
  TCase *MemCpyTest = tcase_create("MEMCPY");
  TCase *StrCatTest = tcase_create("STRCAT");
  TCase *MemcmpTest = tcase_create("MEMCMP");
  TCase *StrncatTest = tcase_create("STRNCAT");
  TCase *StrncpyTest = tcase_create("STRNCPY");
  TCase *StrrchrTest = tcase_create("STRRCHR");
  TCase *memmovetest = tcase_create("MEMMOVE");
  TCase *strstrtest = tcase_create("STRSTR");
  TCase *strcmptest = tcase_create("STRCMP");
  TCase *memchrtest = tcase_create("MEMCHR");
  TCase *strcpytest = tcase_create("STRCPY");
  TCase *strpbrktest = tcase_create("STRPBRK");
  TCase *StrnCmpTest = tcase_create("STRNCMP");
  TCase *MemSetTest = tcase_create("MEMSET");
  TCase *StrTokTest = tcase_create("STRTOK");
  TCase *strerrortest = tcase_create("STRERROR");
  TCase *to_uppertest = tcase_create("TOUPPER");
  TCase *inserttest = tcase_create("INSERT");
  TCase *to_lowertest = tcase_create("TOLOWER");
  TCase *trimtest = tcase_create("TRIM");
  suite_add_tcase(s1, StrLenTest);
  tcase_add_test(StrLenTest, STRLENTest1);
  tcase_add_test(StrLenTest, STRLENTest2);
  tcase_add_test(StrLenTest, STRLENTest3);
  tcase_add_test(StrLenTest, STRLENTest4);
  tcase_add_test(StrLenTest, STRLENTest5);
  tcase_add_test(StrLenTest, STRLENTest6);
  tcase_add_test(StrLenTest, STRLENTest7);
  tcase_add_test(StrLenTest, STRLENTest8);
  tcase_add_test(StrLenTest, STRLENTest9);
  tcase_add_test(StrLenTest, STRLENTest10);
  tcase_add_test(StrLenTest, STRLENTest11);
  tcase_add_test(StrLenTest, STRLENTest12);
  tcase_add_test(StrLenTest, STRLENTest13);
  tcase_add_test(StrLenTest, STRLENTest14);
  suite_add_tcase(s1, StrChrTest);
  tcase_add_test(StrChrTest, STRCHRTest1);
  tcase_add_test(StrChrTest, STRCHRTest2);
  tcase_add_test(StrChrTest, STRCHRTest3);
  tcase_add_test(StrChrTest, STRCHRTest4);
  tcase_add_test(StrChrTest, STRCHRTest5);
  tcase_add_test(StrChrTest, STRCHRTest6);
  tcase_add_test(StrChrTest, STRCHRTest7);
  tcase_add_test(StrChrTest, STRCHRTest8);
  tcase_add_test(StrChrTest, STRCHRTest9);
  tcase_add_test(StrChrTest, STRCHRTest10);
  suite_add_tcase(s1, StrSpnTest);
  tcase_add_test(StrSpnTest, STRSPNTest1);
  tcase_add_test(StrSpnTest, STRSPNTest2);
  tcase_add_test(StrSpnTest, STRSPNTest3);
  tcase_add_test(StrSpnTest, STRSPNTest4);
  tcase_add_test(StrSpnTest, STRSPNTest5);
  tcase_add_test(StrSpnTest, STRSPNTest6);
  tcase_add_test(StrSpnTest, STRSPNTest7);
  tcase_add_test(StrSpnTest, STRSPNTest8);
  tcase_add_test(StrSpnTest, STRSPNTest9);
  tcase_add_test(StrSpnTest, STRSPNTest10);
  suite_add_tcase(s1, StrcSpnTest);
  tcase_add_test(StrcSpnTest, STRCSPNTest1);
  tcase_add_test(StrcSpnTest, STRCSPNTest2);
  tcase_add_test(StrcSpnTest, STRCSPNTest3);
  tcase_add_test(StrcSpnTest, STRCSPNTest4);
  tcase_add_test(StrcSpnTest, STRCSPNTest5);
  tcase_add_test(StrcSpnTest, STRCSPNTest6);
  suite_add_tcase(s1, MemCpyTest);
  tcase_add_test(MemCpyTest, MEMCPYTest1);
  tcase_add_test(MemCpyTest, MEMCPYTest2);
  tcase_add_test(MemCpyTest, MEMCPYTest3);
  tcase_add_test(MemCpyTest, MEMCPYTest4);
  tcase_add_test(MemCpyTest, MEMCPYTest5);
  tcase_add_test(MemCpyTest, MEMCPYTest6);
  tcase_add_test(MemCpyTest, MEMCPYTest7);
  tcase_add_test(MemCpyTest, MEMCPYTest8);
  tcase_add_test(MemCpyTest, MEMCPYTest9);
  tcase_add_test(MemCpyTest, MEMCPYTest10);
  tcase_add_test(MemCpyTest, MEMCPYTest11);

  suite_add_tcase(s1, StrCatTest);
  tcase_add_test(StrCatTest, STRCATTest1);
  tcase_add_test(StrCatTest, STRCATTest2);
  tcase_add_test(StrCatTest, STRCATTest3);
  tcase_add_test(StrCatTest, STRCATTest4);
  tcase_add_test(StrCatTest, STRCATTest5);
  tcase_add_test(StrCatTest, STRCATTest6);
  tcase_add_test(StrCatTest, STRCATTest7);
  tcase_add_test(StrCatTest, STRCATTest8);
  tcase_add_test(StrCatTest, STRCATTest9);

  suite_add_tcase(s1, MemcmpTest);
  tcase_add_test(MemcmpTest, MEMCMPTest1);
  tcase_add_test(MemcmpTest, MEMCMPTest2);
  tcase_add_test(MemcmpTest, MEMCMPTest3);
  tcase_add_test(MemcmpTest, MEMCMPTest4);
  tcase_add_test(MemcmpTest, MEMCMPTest5);
  tcase_add_test(MemcmpTest, MEMCMPTest6);
  tcase_add_test(MemcmpTest, MEMCMPTest7);
  tcase_add_test(MemcmpTest, MEMCMPTest8);
  tcase_add_test(MemcmpTest, MEMCMPTest9);
  tcase_add_test(MemcmpTest, MEMCMPTest10);
  suite_add_tcase(s1, StrncatTest);
  tcase_add_test(StrncatTest, STRNCATTest1);
  tcase_add_test(StrncatTest, STRNCATTest2);
  tcase_add_test(StrncatTest, STRNCATTest3);
  tcase_add_test(StrncatTest, STRNCATTest4);
  tcase_add_test(StrncatTest, STRNCATTest5);
  tcase_add_test(StrncatTest, STRNCATTest6);
  tcase_add_test(StrncatTest, STRNCATTest7);
  suite_add_tcase(s1, StrncpyTest);
  tcase_add_test(StrncpyTest, STRNCPYTest1);
  tcase_add_test(StrncpyTest, STRNCPYTest2);
  tcase_add_test(StrncpyTest, STRNCPYTest3);
  tcase_add_test(StrncpyTest, STRNCPYTest4);
  tcase_add_test(StrncpyTest, STRNCPYTest5);
  tcase_add_test(StrncpyTest, STRNCPYTest6);
  tcase_add_test(StrncpyTest, STRNCPYTest7);
  tcase_add_test(StrncpyTest, STRNCPYTest8);
  suite_add_tcase(s1, StrrchrTest);
  tcase_add_test(StrrchrTest, STRRCHRTest1);
  tcase_add_test(StrrchrTest, STRRCHRTest2);
  tcase_add_test(StrrchrTest, STRRCHRTest3);
  tcase_add_test(StrrchrTest, STRRCHRTest4);
  tcase_add_test(StrrchrTest, STRRCHRTest5);
  tcase_add_test(StrrchrTest, STRRCHRTest6);
  tcase_add_test(StrrchrTest, STRRCHRTest7);
  suite_add_tcase(s1, memmovetest);
  tcase_add_test(memmovetest, MEMMOVETest1);
  tcase_add_test(memmovetest, MEMMOVETest2);
  tcase_add_test(memmovetest, MEMMOVETest3);
  tcase_add_test(memmovetest, MEMMOVETest4);
  tcase_add_test(memmovetest, MEMMOVETest5);
  tcase_add_test(memmovetest, MEMMOVETest6);
  tcase_add_test(memmovetest, MEMMOVETest7);
  tcase_add_test(memmovetest, MEMMOVETest8);
  tcase_add_test(memmovetest, MEMMOVETest9);
  tcase_add_test(memmovetest, MEMMOVETest10);
  suite_add_tcase(s1, strstrtest);
  tcase_add_test(strstrtest, STRSTRTest1);
  tcase_add_test(strstrtest, STRSTRTest2);
  tcase_add_test(strstrtest, STRSTRTest3);
  tcase_add_test(strstrtest, STRSTRTest4);
  tcase_add_test(strstrtest, STRSTRTest5);
  tcase_add_test(strstrtest, STRSTRTest6);
  tcase_add_test(strstrtest, STRSTRTest7);
  tcase_add_test(strstrtest, STRSTRTest8);
  suite_add_tcase(s1, strcmptest);
  tcase_add_test(strcmptest, STRCMPTest1);
  tcase_add_test(strcmptest, STRCMPTest2);
  tcase_add_test(strcmptest, STRCMPTest3);
  tcase_add_test(strcmptest, STRCMPTest4);
  tcase_add_test(strcmptest, STRCMPTest5);
  tcase_add_test(strcmptest, STRCMPTest6);
  tcase_add_test(strcmptest, STRCMPTest7);
  tcase_add_test(strcmptest, STRCMPTest8);
  suite_add_tcase(s1, memchrtest);
  tcase_add_test(memchrtest, MEMCHRTest1);
  tcase_add_test(memchrtest, MEMCHRTest2);
  tcase_add_test(memchrtest, MEMCHRTest3);
  tcase_add_test(memchrtest, MEMCHRTest4);
  tcase_add_test(memchrtest, MEMCHRTest5);
  tcase_add_test(memchrtest, MEMCHRTest6);
  tcase_add_test(memchrtest, MEMCHRTest7);
  tcase_add_test(memchrtest, MEMCHRTest8);
  suite_add_tcase(s1, strcpytest);
  tcase_add_test(strcpytest, STRCPYTest1);
  tcase_add_test(strcpytest, STRCPYTest2);
  tcase_add_test(strcpytest, STRCPYTest3);
  tcase_add_test(strcpytest, STRCPYTest4);
  tcase_add_test(strcpytest, STRCPYTest5);
  tcase_add_test(strcpytest, STRCPYTest6);
  tcase_add_test(strcpytest, STRCPYTest7);
  tcase_add_test(strcpytest, STRCPYTest8);
  tcase_add_test(strcpytest, STRCPYTest9);
  tcase_add_test(strcpytest, STRCPYTest10);
  suite_add_tcase(s1, strpbrktest);
  tcase_add_test(strpbrktest, STRPBRKTest1);
  tcase_add_test(strpbrktest, STRPBRKTest2);
  tcase_add_test(strpbrktest, STRPBRKTest3);
  tcase_add_test(strpbrktest, STRPBRKTest4);
  tcase_add_test(strpbrktest, STRPBRKTest5);
  tcase_add_test(strpbrktest, STRPBRKTest6);
  tcase_add_test(strpbrktest, STRPBRKTest7);
  suite_add_tcase(s1, StrnCmpTest);
  tcase_add_test(StrnCmpTest, STRNCMPTest1);
  tcase_add_test(StrnCmpTest, STRNCMPTest2);
  tcase_add_test(StrnCmpTest, STRNCMPTest3);
  tcase_add_test(StrnCmpTest, STRNCMPTest4);
  tcase_add_test(StrnCmpTest, STRNCMPTest5);
  tcase_add_test(StrnCmpTest, STRNCMPTest6);
  tcase_add_test(StrnCmpTest, STRNCMPTest7);
  tcase_add_test(StrnCmpTest, STRNCMPTest8);
  suite_add_tcase(s1, MemSetTest);
  tcase_add_test(MemSetTest, MEMSETTest1);
  tcase_add_test(MemSetTest, MEMSETTest2);
  tcase_add_test(MemSetTest, MEMSETTest3);
  tcase_add_test(MemSetTest, MEMSETTest4);
  tcase_add_test(MemSetTest, MEMSETTest5);
  tcase_add_test(MemSetTest, MEMSETTest6);
  tcase_add_test(MemSetTest, MEMSETTest7);
  suite_add_tcase(s1, StrTokTest);
  tcase_add_test(StrTokTest, STRTOKTest2);
  tcase_add_test(StrTokTest, STRTOKTest3);
  tcase_add_test(StrTokTest, STRTOKTest4);
  tcase_add_test(StrTokTest, STRTOKTest5);
  tcase_add_test(StrTokTest, STRTOKTest6);
  suite_add_tcase(s1, strerrortest);
  tcase_add_test(strerrortest, STRERRORTest1);
  tcase_add_test(strerrortest, STRERRORTest2);
  tcase_add_test(strerrortest, STRERRORTest3);
  tcase_add_test(strerrortest, STRERRORTest4);
  tcase_add_test(strerrortest, STRERRORTest5);
  suite_add_tcase(s1, to_uppertest);
  tcase_add_test(to_uppertest, TOUPPERTest1);
  tcase_add_test(to_uppertest, TOUPPERTest2);
  tcase_add_test(to_uppertest, TOUPPERTest3);
  tcase_add_test(to_uppertest, TOUPPERTest4);
  tcase_add_test(to_uppertest, TOUPPERTest5);
  tcase_add_test(to_uppertest, TOUPPERTest6);
  tcase_add_test(to_uppertest, TOUPPERTest7);
  tcase_add_test(to_uppertest, TOUPPERTest8);
  tcase_add_test(to_uppertest, TOUPPERTest9);
  tcase_add_test(to_uppertest, TOUPPERTest10);
  suite_add_tcase(s1, inserttest);
  tcase_add_test(inserttest, INSERTTest1);
  tcase_add_test(inserttest, INSERTTest2);
  tcase_add_test(inserttest, INSERTTest3);
  tcase_add_test(inserttest, INSERTTest4);
  tcase_add_test(inserttest, INSERTTest6);
  tcase_add_test(inserttest, INSERTTest7);
  tcase_add_test(inserttest, INSERTTest8);
  tcase_add_test(inserttest, INSERTTest9);
  tcase_add_test(inserttest, INSERTTest10);
  tcase_add_test(inserttest, INSERTTest11);
  suite_add_tcase(s1, to_lowertest);
  tcase_add_test(to_lowertest, TOLOWERTest1);
  tcase_add_test(to_lowertest, TOLOWERTest2);
  tcase_add_test(to_lowertest, TOLOWERTest3);
  tcase_add_test(to_lowertest, TOLOWERTest4);
  tcase_add_test(to_lowertest, TOLOWERTest5);
  tcase_add_test(to_lowertest, TOLOWERTest6);
  tcase_add_test(to_lowertest, TOLOWERTest7);
  tcase_add_test(to_lowertest, TOLOWERTest8);
  tcase_add_test(to_lowertest, TOLOWERTest9);
  tcase_add_test(to_lowertest, TOLOWERTest10);
  tcase_add_test(to_lowertest, TOLOWERTest11);
  suite_add_tcase(s1, trimtest);

  tcase_add_test(trimtest, TRIMTest1);
  tcase_add_test(trimtest, TRIMTest2);
  tcase_add_test(trimtest, TRIMTest3);
  tcase_add_test(trimtest, TRIMTest4);
  tcase_add_test(trimtest, TRIMTest5);
  tcase_add_test(trimtest, TRIMTest6);
  tcase_add_test(trimtest, TRIMTest7);
  return s1;
}
