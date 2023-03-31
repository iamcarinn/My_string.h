#include "test.h"

START_TEST(test_skip) {
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
  int their =
      sscanf("345VEEEERRRTTTEERRR346", "%dVEEEERRRTTTEERRR%d", &a1, &a3);
  int our =
      s21_sscanf("345VEEEERRRTTTEERRR346", "%dVEEEERRRTTTEERRR%d", &a2, &a4);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(a3, a4);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_e) {
  float a1 = 0, a2 = 0;
  int their = sscanf("123e34", "%e", &a1);
  int our = s21_sscanf("123e34", "%e", &a2);
  ck_assert_float_eq(a1, a2);
  ck_assert_int_eq(their, our);

  their = sscanf("12e34", "%e", &a1);
  our = s21_sscanf("12e34", "%e", &a2);
  ck_assert_float_eq(a1, a2);
  ck_assert_int_eq(their, our);

  their = sscanf("123.345e-34", "%9e", &a1);
  our = s21_sscanf("123.345e-34", "%9e", &a2);
  ck_assert_float_eq(a1, a2);
  ck_assert_int_eq(their, our);

  their = sscanf("123.345e34", "%8e", &a1);
  our = s21_sscanf("123.345e34", "%8e", &a2);
  ck_assert_float_eq(a1, a2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_e_1) {
  float a1 = 0, a2 = 0;
  int their = sscanf("inf", "%e", &a1);
  int our = s21_sscanf("inf", "%e", &a2);
  ck_assert_float_eq(a1, a2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_e_2) {
  float a1 = 0, a2 = 0;
  int their = sscanf("10e10000", "%e", &a1);
  int our = s21_sscanf("10e10000", "%e", &a2);
  ck_assert_float_eq(a1, a2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_Lf1) {
  long double a1 = 0, a2 = 0;
  int their = sscanf("Nan", "%Lf", &a1);
  int our = s21_sscanf("Nan", "%Lf", &a2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_u) {
  unsigned int u1 = 0, u2 = 0;

  int their = sscanf("", "%u", &u1);
  int our = s21_sscanf("", "%u", &u2);
  ck_assert_uint_eq(u1, u2);
  ck_assert_int_eq(their, our);

  their = sscanf("43534534564356", "%u", &u1);
  our = s21_sscanf("43534534564356", "%u", &u2);
  ck_assert_uint_eq(u1, u2);
  ck_assert_int_eq(their, our);

  their = sscanf("123.456", "%u", &u1);
  our = s21_sscanf("123.456", "%u", &u2);
  ck_assert_uint_eq(u1, u2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_u_hard) {
  unsigned u1 = 0, u2 = 0;
  char *str1 = "0    3147483647";
  char *str2 = "123456";

  int their = sscanf(str1, "%*u%u", &u1);
  int our = s21_sscanf(str1, "%*u%u", &u2);
  ck_assert_uint_eq(u1, u2);
  ck_assert_int_eq(their, our);

  their = sscanf("", "%u", &u1);
  our = s21_sscanf("", "%u", &u2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(their, our);

  their = sscanf(str2, "%u", &u1);
  our = s21_sscanf(str2, "%u", &u2);
  ck_assert_uint_eq(u1, u2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_u_owerfl) {
  char c1 = 0, c2 = 0;
  long long unsigned int u1 = 0, u2 = 0;

  int their = sscanf("D thg 18446744073709551616", "%c thg %llu", &c1, &u1);
  int our = s21_sscanf("D thg 18446744073709551616", "%c thg %llu", &c2, &u2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(u1, u2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_u_owerfl_minus) {
  char c1 = 0, c2 = 0;
  long long unsigned int u1 = 0, u2 = 0;

  int their = sscanf("D thg -18446744073709551616", "%c ppc %llu", &c1, &u1);
  int our = s21_sscanf("D thg -18446744073709551616", "%c ppc %llu", &c2, &u2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(u1, u2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_o_owerfl_minus) {
  char c1 = 0, c2 = 0;
  long long unsigned int u1 = 0, u2 = 0;

  int their =
      sscanf(" D thg -7777777777777777777753479797", "%c ppc %llo", &c1, &u1);
  int our = s21_sscanf(" D thg -7777777777777777777753479797", "%c ppc %llo",
                       &c2, &u2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(u1, u2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_h) {
  unsigned short hu1 = 0, hu2 = 0;

  int their = sscanf("-12", "%hu", &hu1);
  int our = s21_sscanf("-12", "%hu", &hu2);
  ck_assert_uint_eq(hu1, hu2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_s) {
  char s1[100], s2[100];

  int their = sscanf("Hello Bob!", "%*s%2s", s1);
  int our = s21_sscanf("Hello Bob!", "%*s%2s", s2);

  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_s_hard) {
  char str1[100] = "", str2[100] = "";

  int their = sscanf(" Hi my, name is Bob", "%*s%*s%10s%*s", str1);
  int our = s21_sscanf(" Hi my, name is Bob", "%*s%*s%10s%*s", str2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(their, our);

  their = sscanf("\n", "%10s", str1);
  our = s21_sscanf("\n", "%10s", str2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(their, our);
}

START_TEST(test_f) {
  float f1 = 0, f2 = 0;

  int their = sscanf("12e-2", "%f", &f1);
  int our = s21_sscanf("12e-2", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(their, our);

  their = sscanf("-123.35", "%f", &f1);
  our = s21_sscanf("-123.35", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(their, our);

  their = sscanf("-12.645", "%5f", &f1);
  our = s21_sscanf("-12.645", "%5f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(their, our);

  their = sscanf("12.745", "%5f", &f1);
  our = s21_sscanf("12.745", "%5f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_double) {
  double fl1 = 0, fl2 = 0;
  double dbl1 = 0, dbl2 = 0;
  char *str1 = "-876.214235  2145.93560734567  324.21427 ";
  char *str2 = "Bili_Buu35634.34";

  int their = sscanf(str1, "%lf%lf%*f", &fl1, &dbl1);
  int our = s21_sscanf(str1, "%lf%lf%*f", &fl2, &dbl2);
  ck_assert_double_eq(fl1, fl2);
  ck_assert_double_eq(dbl1, dbl2);
  ck_assert_int_eq(their, our);

  their = sscanf("", "%lf", &dbl1);
  our = s21_sscanf("", "%lf", &dbl2);
  ck_assert_double_eq(dbl1, dbl2);
  ck_assert_int_eq(their, our);

  their = sscanf(str2, "%lf", &dbl1);
  our = s21_sscanf(str2, "%lf", &dbl2);
  ck_assert_double_eq(dbl1, dbl2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_o) {
  unsigned int o1 = 0, o2 = 0;
  char *str1 = "12345678";
  char *str2 = "18446744073709551615";
  char *str3 = "123.456";

  int their = sscanf(str1, "%3o", &o1);
  int our = s21_sscanf(str1, "%3o", &o2);
  ck_assert_uint_eq(o1, o2);
  ck_assert_int_eq(their, our);

  their = sscanf(str2, "%9o", &o1);
  our = s21_sscanf(str2, "%9o", &o2);
  ck_assert_uint_eq(o1, o2);
  ck_assert_int_eq(their, our);

  their = sscanf(str2, "%o", &o1);
  our = s21_sscanf(str2, "%o", &o2);
  ck_assert_uint_eq(o1, o2);
  ck_assert_int_eq(their, our);

  their = sscanf(str3, "%o", &o1);
  our = s21_sscanf(str3, "%o", &o2);
  ck_assert_uint_eq(o1, o2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_o_1) {
  long unsigned int a1 = 0, a2 = 0;
  const char s1[] = "0777777777777777";
  int their = sscanf(s1, "%lo", &a1);
  int our = s21_sscanf(s1, "%lo", &a2);

  ck_assert_int_eq(their, our);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_x) {
  unsigned int x1 = 0, x2 = 0;

  int their = sscanf("0x12345", "%2x", &x1);
  int our = s21_sscanf("0x12345", "%2x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(their, our);

  their = sscanf("KARL!", "%x", &x1);
  our = s21_sscanf("KARL!", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(their, our);

  their = sscanf("alla!", "%x", &x1);
  our = s21_sscanf("alla!", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(their, their);

  their = sscanf("0x123456789", "%1x", &x1);
  our = s21_sscanf("0x123456789", "%1x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(their, our);

  their = sscanf("0x123", "%19x", &x1);
  our = s21_sscanf("0x123", "%19x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(their, our);

  their = sscanf("1234f56", "%x", &x1);
  our = s21_sscanf("1234f56", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(their, our);
}

START_TEST(test_x_hard) {
  unsigned u1 = 0, u2 = 0, u3 = 0, u4 = 0;
  char *str1 = " 123123  3147487 123 123";

  int their = sscanf(str1, "%*x%x%X%*X", &u1, &u3);
  int our = s21_sscanf(str1, "%*x%x%X%*X", &u2, &u4);
  ck_assert_uint_eq(u1, u2);
  ck_assert_uint_eq(u3, u4);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_i) {
  int i1 = 0, i2 = 0;

  int their = sscanf("0123", "%i", &i1);
  int our = s21_sscanf("0123", "%i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(their, our);

  their = sscanf("0x1234567", "%4i", &i1);
  our = s21_sscanf("0x123567", "%4i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_i_hard) {
  int x1 = 0, x2 = 0;
  int o1 = 0, o2 = 0;
  int d1 = 0, d2 = 0;
  char *str1 = "  0x3F5  0600 -12345 987";
  char *str2 = "  0000xFF5  ";

  int their = sscanf(str1, "%i%i%i%*i", &x1, &o1, &d1);
  int our = s21_sscanf(str1, "%i%i%i%*i", &x2, &o2, &d2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(their, our);

  their = sscanf("", "%i", &d1);
  our = s21_sscanf("", "%i", &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(their, our);
  x1 = 0, x2 = 0;
  their = sscanf(str2, "%i", &x1);
  our = s21_sscanf(str2, "%i", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_proc) {
  char proc1[100] = {0}, proc2[100] = {0};

  int their = sscanf("%ZVBilli hi", "%%%9s", proc1);
  int our = s21_sscanf("%ZVBilli hi", "%%%9s", proc2);
  ck_assert_str_eq(proc1, proc2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_ptr) {
  void *p1 = 0, *p2 = 0;

  int their = sscanf("fas", "%4p", &p1);
  int our = s21_sscanf("fas", "%4p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(their, our);

  their = sscanf("0xffdd", "%p", &p1);
  our = s21_sscanf("0xffdd", "%p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(their, our);

  their = sscanf("123.456", "%p", &p1);
  our = s21_sscanf("123.456", "%p", &p2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_n) {
  int n1 = 0, n2 = 0;
  int a1 = 0, a2 = 0;
  int their = sscanf("1234 6", "%3d%n", &a1, &n1);
  int our = s21_sscanf("1234 6", "%3d%n", &a2, &n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(their, our);
}
END_TEST
START_TEST(test_n1) {
  int n1 = 1, n2 = 5;

  char s1[100] = {'\0'}, s2[100] = {'\0'}, s3[100] = {'\0'}, s4[100] = {'\0'},
       s5[100] = {'\0'}, s6[100] = {'\0'};

  const char str[] =
      "csdsfsdf f23424 asdfasdsdfflkasdf asdfasdf asdfasdfgfddf 23";
  const char fstr[] = "%s %s %n %s";

  int their = s21_sscanf(str, fstr, s1, s2, &n1, s3);
  int our = sscanf(str, fstr, s4, s5, &n2, s6);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(s1, s4);
  ck_assert_str_eq(s2, s5);
  ck_assert_str_eq(s3, s6);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_d) {
  int d1 = 0, d2 = 0;

  int their = sscanf("123", "%002d", &d1);
  int our = s21_sscanf("123", "%002d", &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(their, our);

  their = sscanf("  123   -123   567  32368  ", "%*d%d%*d%*d", &d1);
  our = s21_sscanf("  123   -123   567  32368  ", "%*d%d%*d%*d", &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(their, our);

  their = sscanf("", "%d", &d1);
  our = s21_sscanf("", "%d", &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(their, our);

  their = sscanf(" abc 324 ", "%d", &d1);
  our = s21_sscanf(" abc 324 ", "%d", &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_d_1) {
  long long int d1 = 0, d2 = 0;

  int their = sscanf("-92233720368547758078", "%lld", &d1);
  int our = s21_sscanf("-9223372036854775808", "%lld", &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_d_hard) {
  int d1 = 0, d2 = 0;
  char *str1 = "  123   -123   567  32368  ";
  char *str2 = " abc 324 ";

  int their = sscanf(str1, "%*d%d%*d%*d", &d1);
  int our = s21_sscanf(str1, "%*d%d%*d%*d", &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(their, our);

  their = sscanf("", "%d", &d1);
  our = s21_sscanf("", "%d", &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(their, our);

  their = sscanf(str2, "%d", &d1);
  our = s21_sscanf(str2, "%d", &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_c) {
  char c1 = 0, c2 = 0;

  int their = sscanf("abca", "%*c%*c%*c%c", &c1);
  int our = s21_sscanf("abca", "%*c%*c%*c%c", &c2);
  ck_assert_int_eq(their, our);
  ck_assert_int_eq(c1, c2);

  their = sscanf("", "%c", &c1);
  our = s21_sscanf("", "%c", &c2);
  ck_assert_int_eq(their, our);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(test_g) {
  double e1 = 0, e2 = 0, g1 = 0, g2 = 0;
  char *s1 = "  0.08762147E+03  1446567457.024E-11 0E+02";
  char *s2 = "  Bili?35634E+02";

  int their = sscanf(s1, "%lE%lG%*e", &e1, &g1);
  int our = s21_sscanf(s1, "%lE%lG%*e", &e2, &g2);
  ck_assert_float_eq(e1, e2);
  ck_assert_float_eq(g1, g2);
  ck_assert_int_eq(their, our);

  their = sscanf("", "%le", &e1);
  our = s21_sscanf("", "%le", &e2);
  ck_assert_int_eq(e1, e2);
  ck_assert_int_eq(their, our);

  their = sscanf(s2, "%lg", &g1);
  our = s21_sscanf(s2, "%lg", &g2);
  ck_assert_float_eq(g1, g2);
  ck_assert_int_eq(their, our);
}
END_TEST
START_TEST(test_g_1) {
  double e1 = 0, e2 = 0, g1 = 0, g2 = 0;
  char *s1 = "-34.46e15 -+34.46.e15\t\t +-56.34";

  int their = sscanf(s1, "%lE%lG%*e", &e1, &g1);
  int our = s21_sscanf(s1, "%lE%lG%*e", &e2, &g2);
  ck_assert_float_eq(e1, e2);
  ck_assert_float_eq(g1, g2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(d) {
  int d1 = 0, d2 = 0;
  int their = sscanf("123", "%d", &d1);
  int our = s21_sscanf("123", "%d", &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(d_s) {
  int d1 = 0, d2 = 0;
  char s1[100] = {0}, s2[100] = {0};
  int their = sscanf("123 BiliBob", "%d%9s", &d1, s1);
  int our = s21_sscanf("123 BiliBob", "%d%9s", &d2, s2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(d_s_c) {
  int d1 = 0, d2 = 0;
  char s1[100] = {0}, s2[100] = {0};
  char c1 = 0, c2 = 0;
  int their = sscanf("123 Bili L", "%d%9s%c", &d1, s1, &c1);
  int our = s21_sscanf("123 Bili L", "%d%9s%c", &d2, s2, &c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(i_d_s_c) {
  int i1 = 0, i2 = 0;
  int d1 = 0, d2 = 0;
  char s1[100] = {0}, s2[100] = {0};
  char c1 = 0, c2 = 0;
  int their = sscanf("4 123 Bili L", "%i%d%4s%c", &i1, &d1, s1, &c1);
  int our = s21_sscanf("4 123 Bili L", "%i%d%4s%c", &i2, &d2, s2, &c2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(i_d_s_c_e) {
  float e1 = 0, e2 = 0;
  int i1 = 0, i2 = 0;
  int d1 = 0, d2 = 0;
  char s1[100] = {0}, s2[100] = {0};
  char c1 = 0, c2 = 0;
  int their =
      sscanf("4 123 BiliL 12e34", "%i%d%4s%c%e", &i1, &d1, s1, &c1, &e1);
  int our =
      s21_sscanf("4 123 BiliL 12e34", "%i%d%4s%c%e", &i2, &d2, s2, &c2, &e2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_float_eq(e1, e2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(i_d_s_c_e_g) {
  float e1 = 0, e2 = 0, f1 = 0, f2 = 0;
  int i1 = 0, i2 = 0;
  int d1 = 0, d2 = 0;
  char s1[100] = {0}, s2[100] = {0};
  char c1 = 0, c2 = 0;
  int their = sscanf("4 123 BiliL 12e34 13.37", "%i%d%4s%c%e%g", &i1, &d1, s1,
                     &c1, &e1, &f1);
  int our = s21_sscanf("4 123 BiliL 12e34 13.37", "%i%d%4s%c%e%g", &i2, &d2, s2,
                       &c2, &e2, &f2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_float_eq(e1, e2);
  ck_assert_float_eq(f1, f2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(i_d_s_c_e_g_f) {
  float e1 = 0, e2 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
  int i1 = 0, i2 = 0;
  int d1 = 0, d2 = 0;
  char s1[100] = {0}, s2[100] = {0};
  char c1 = 0, c2 = 0;
  int their = sscanf("4 123 BiliL 12e34 13.37 .2345", "%i %d %4s %c %e %g %f",
                     &i1, &d1, s1, &c1, &e1, &f1, &f3);
  int our = s21_sscanf("4 123 BiliL 12e34 13.37 .2345", "%i %d %4s %c %e %g %f",
                       &i2, &d2, s2, &c2, &e2, &f2, &f4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_float_eq(e1, e2);
  ck_assert_float_eq(f1, f2);
  ck_assert_float_eq(f3, f4);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(i_d_s_c_e_g_f_o) {
  float e1 = 0, e2 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
  int i1 = 0, i2 = 0;
  int d1 = 0, d2 = 0;
  char s1[100] = {0}, s2[100] = {0};
  char c1 = 0, c2 = 0;
  unsigned int o1 = 0, o2 = 0;
  int their =
      sscanf("4 123 BiliL 12e34 13.37 .2345 345", "%i %d %4s %c %e %g %f %2o",
             &i1, &d1, s1, &c1, &e1, &f1, &f3, &o1);
  int our = s21_sscanf("4 123 BiliL 12e34 13.37 .2345 345",
                       "%i %d %4s %c %e %g %f %2o", &i2, &d2, s2, &c2, &e2, &f2,
                       &f4, &o2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_float_eq(e1, e2);
  ck_assert_float_eq(f1, f2);
  ck_assert_float_eq(f3, f4);
  ck_assert_uint_eq(o1, o2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(i_d_s_c_e_g_f_o_x) {
  float e1 = 0, e2 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
  int i1 = 0, i2 = 0, x1 = 0, x2 = 0;
  int d1 = 0, d2 = 0;
  char s1[100] = {0}, s2[100] = {0};
  char c1 = 0, c2 = 0;
  unsigned int o1 = 0, o2 = 0;
  int their = sscanf("4 123 BiliL 12e34 13.37 .2345 345 0x345f",
                     "%i %d %4s %c %e %g %f %2o %x", &i1, &d1, s1, &c1, &e1,
                     &f1, &f3, &o1, &x1);
  int our = s21_sscanf("4 123 BiliL 12e34 13.37 .2345 345 0x345f ",
                       "%i %d %4s %c %e %g %f %2o %x", &i2, &d2, s2, &c2, &e2,
                       &f2, &f4, &o2, &x2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_float_eq(e1, e2);
  ck_assert_float_eq(f1, f2);
  ck_assert_float_eq(f3, f4);
  ck_assert_uint_eq(o1, o2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(i_d_s_c_e_g_f_o_x_proc_n) {
  float e1 = 0, e2 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
  int i1 = 0, i2 = 0, x1 = 0, x2 = 0, n1 = 0, n2 = 0;
  int d1 = 0, d2 = 0;
  char s1[100] = {0}, s2[100] = {0};
  char c1 = 0, c2 = 0;
  unsigned int o1 = 0, o2 = 0;
  int their = sscanf("4 123 BiliL 12e34 13.37 .2345 345 0x345f%",
                     "%i %d %4s %c %e %g %f %2o %x %% %n", &i1, &d1, s1, &c1,
                     &e1, &f1, &f3, &o1, &x1, &n1);
  int our = s21_sscanf("4 123 BiliL 12e34 13.37 .2345 345 0x345f%",
                       "%i %d %4s %c %e %g %f %2o %x %% %n", &i2, &d2, s2, &c2,
                       &e2, &f2, &f4, &o2, &x2, &n2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_float_eq(e1, e2);
  ck_assert_float_eq(f1, f2);
  ck_assert_float_eq(f3, f4);
  ck_assert_uint_eq(o1, o2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(i_d_s_c_e_g_f_o_x_proc_n_u) {
  float e1 = 0, e2 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
  int i1 = 0, i2 = 0, x1 = 0, x2 = 0, n1 = 0, n2 = 0;
  int d1 = 0, d2 = 0;
  char s1[100] = {0}, s2[100] = {0};
  char c1 = 0, c2 = 0;
  unsigned int o1 = 0, o2 = 0, u1 = 0, u2 = 0;
  int their = sscanf("4 123 BiliL 12e34 13.37 .2345 345 0x345f% 453478",
                     "%i %d %4s %c %e %g %f %2o %x %% %n %3u", &i1, &d1, s1,
                     &c1, &e1, &f1, &f3, &o1, &x1, &n1, &u1);
  int our = s21_sscanf("4 123 BiliL 12e34 13.37 .2345 345 0x345f% 453478",
                       "%i %d %4s %c %e %g %f %2o %x %% %n %3u", &i2, &d2, s2,
                       &c2, &e2, &f2, &f4, &o2, &x2, &n2, &u2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_float_eq(e1, e2);
  ck_assert_float_eq(f1, f2);
  ck_assert_float_eq(f3, f4);
  ck_assert_uint_eq(o1, o2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(n1, n2);
  ck_assert_uint_eq(u1, u2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(i_d_s_c_e_g_f_o_x_proc_n_u_p) {
  float e1 = 0, e2 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
  int i1 = 0, i2 = 0, x1 = 0, x2 = 0, n1 = 0, n2 = 0;
  int d1 = 0, d2 = 0;
  char s1[100] = {0}, s2[100] = {0};
  char c1 = 0, c2 = 0;
  unsigned int o1 = 0, o2 = 0, u1 = 0, u2 = 0;
  int *p1 = 0, *p2 = 0;
  int their =
      sscanf("4 123 BiliL 12e34 13.37 .2345 345 0x345f% 453478 0x57890ff",
             "%i %d %4s %c %e %g %f %2o %x %% %n %3u %p", &i1, &d1, s1, &c1,
             &e1, &f1, &f3, &o1, &x1, &n1, &u1, &p1);
  int our =
      s21_sscanf("4 123 BiliL 12e34 13.37 .2345 345 0x345f% 453478 0x57890ff",
                 "%i %d %4s %c %e %g %f %2o %x %% %n %3u %p", &i2, &d2, s2, &c2,
                 &e2, &f2, &f4, &o2, &x2, &n2, &u2, &p2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_float_eq(e1, e2);
  ck_assert_float_eq(f1, f2);
  ck_assert_float_eq(f3, f4);
  ck_assert_uint_eq(o1, o2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(n1, n2);
  ck_assert_uint_eq(u1, u2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(all) {
  float e1 = 0, e2 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, E1 = 0, E2 = 0, G1 = 0,
        G2 = 0;
  int i1 = 0, i2 = 0, x1 = 0, x2 = 0, n1 = 0, n2 = 0, X1 = 0, X2 = 0;
  int d1 = 0, d2 = 0;
  char s1[100] = {0}, s2[100] = {0}, s3[100] = {0}, s4[100] = {0};
  char c1 = 0, c2 = 0;
  unsigned int o1 = 0, o2 = 0, u1 = 0, u2 = 0;
  int *p1 = 0, *p2 = 0;
  int their = s21_sscanf(
      "4 123 BobiJoe 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 ILYA- "
      "& bobijoe is cat?",
      "%12i%4d%20s%c%3e%7E%1f%9g%5G%6o%12u%11x%2X%10p%n%21s%%", &i1, &d1, s1,
      &c1, &e1, &E1, &f3, &f1, &G1, &o1, &u1, &x1, &X1, &p1, &n1, s3);
  int our = s21_sscanf(
      "4 123 BobiJoe 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 ILYA- "
      "& bobijoe is cat?",
      "%12i%4d%20s%c%3e%7E%1f%9g%5G%6o%12u%11x%2X%10p%n%21s%%", &i2, &d2, s2,
      &c2, &e2, &E2, &f4, &f2, &G2, &o2, &u2, &x2, &X2, &p2, &n2, s4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_float_eq(e1, e2);
  ck_assert_float_eq(E1, E2);
  ck_assert_float_eq(f3, f4);
  ck_assert_float_eq(f1, f2);
  ck_assert_float_eq(G1, G2);
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(X1, X2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(s3, s4);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(all1) {
  float e1 = 0, e2 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0, E1 = 0, E2 = 0, G1 = 0,
        G2 = 0;
  int i1 = 0, i2 = 0, x1 = 0, x2 = 0, n1 = 0, n2 = 0, X1 = 0, X2 = 0;
  int d1 = 0, d2 = 0;
  char s1[100] = {0}, s2[100] = {0}, s3[100] = {0}, s4[100] = {0};
  char c1 = 0, c2 = 0;
  unsigned int o1 = 0, o2 = 0, u1 = 0, u2 = 0;
  int *p1 = 0, *p2 = 0;
  int their = sscanf(
      "4 123 BobiJoe 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 ILYA- "
      "& bobijoe is cat?",
      "%*i%12i%4d%20s%c%3e%7E%*i%1f%9g%5G%6o%12u%*x%11x%2X%10p%n%21s%%", &i1,
      &d1, s1, &c1, &e1, &E1, &f3, &f1, &G1, &o1, &u1, &x1, &X1, &p1, &n1, s3);
  int our = s21_sscanf(
      "4 123 BobiJoe 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 ILYA- "
      "& bobijoe is cat?",
      "%*i%12i%4d%20s%c%3e%7E%*i%1f%9g%5G%6o%12u%*x%11x%2X%10p%n%21s%%", &i2,
      &d2, s2, &c2, &e2, &E2, &f4, &f2, &G2, &o2, &u2, &x2, &X2, &p2, &n2, s4);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_float_eq(e1, e2);
  ck_assert_float_eq(E1, E2);
  ck_assert_float_eq(f3, f4);
  ck_assert_float_eq(f1, f2);
  ck_assert_float_eq(G1, G2);
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(X1, X2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(s3, s4);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(all2) {
  long double Le1 = 0, Le2 = 0, Le3 = 0, Le4 = 0, Lg1 = 0, Lg2 = 0, Lg3 = 0,
              Lg4 = 0;
  float f1 = 0, f2 = 0;
  short int si1 = 0, si2 = 0;
  long unsigned int lo1 = 0, lo2 = 0, lu1 = 0, lu2 = 0;
  int x1 = 0, x2 = 0, n1 = 0, n2 = 0, X1 = 0, X2 = 0;
  short int sd1 = 0, sd2 = 0;
  char s1[100] = {0}, s2[100] = {0}, s3[100] = {0}, s4[100] = {0};
  char c1 = 0, c2 = 0;
  int *p1 = 0, *p2 = 0;
  int their = sscanf(
      "4 123 BobiJoe 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 ILYA- "
      "& bobijoe is cat?",
      "%*i%12hi%4hd%20s%c%3Le%7LE%*i%1f%9Lg%5LG%6lo%12lu%*x%11x%2X%10p%n%21s%%",
      &si1, &sd1, s1, &c1, &Le1, &Le3, &f1, &Lg1, &Lg3, &lo1, &lu1, &x1, &X1,
      &p1, &n1, s4);
  int our = s21_sscanf(
      "4 123 BobiJoe 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 ILYA- "
      "& bobijoe is cat?",
      "%*i%12hi%4hd%20s%c%3Le%7LE%*i%1f%9Lg%5LG%6lo%12lu%*x%11x%2X%10p%n%21s%%",
      &si2, &sd2, s2, &c2, &Le2, &Le4, &f2, &Lg2, &Lg4, &lo2, &lu2, &x2, &X2,
      &p2, &n2, s3);
  ck_assert_int_eq(si1, si2);
  ck_assert_int_eq(sd1, sd2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_float_eq(Le1, Le2);
  ck_assert_float_eq(Le3, Le4);
  ck_assert_float_eq(f1, f2);
  ck_assert_float_eq(Lg1, Lg2);
  ck_assert_float_eq(Lg3, Lg4);
  ck_assert_int_eq(lo1, lo2);
  ck_assert_int_eq(lu1, lu2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(X1, X2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(their, our);
}
END_TEST

START_TEST(test_sign) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337354354534534534534534545345 +1 -1 -1";
  const char fstr[] = "%15lld %1lld %1lld %5lld";

  int their = sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int our = s21_sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(their, our);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_empty_1) {
  char format[] = "%d";
  char str[] = "";
  int p1 = 0, p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_2) {
  char format[] = "%d";
  char str[] = "     ";
  int p1 = 0, p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_3) {
  char format[] = "%d";
  char str[] = "\n";
  int p1 = 0, p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_4) {
  char format[] = "%d";
  char str[] = "\t";
  int p1 = 0, p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_5) {
  char format[] = "%d";
  char str[] = "\t\n\n   \n  \t";
  int p1 = 0, p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_6) {
  char format[] = "";
  char str[] = "\t\n\n   \n  \t";
  int p1 = 0, p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_7) {
  char format[] = "\t";
  char str[] = "\t\n\n   \n  \t";
  int p1 = 0, p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST
START_TEST(sscanf_spec_c_2) {
  char format[] = "%c";
  char str[] = "\t\n\n  1 \n  \t";
  char c1, c2;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_4) {
  char format[] = "%c";
  char str[] = "\t\n\n   \n  \ta";
  char c1, c2;
  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_5) {
  char format[] = "%c%c%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_6) {
  char format[] = "%c %c \t%c";
  char str[] = "\t\n\n  1    2 3 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_7) {
  char format[] = "%c %c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_8) {
  char format[] = "%c %*c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c21, c22;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12);
  int16_t res2 = sscanf(str, format, &c21, &c22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
}
END_TEST

START_TEST(sscanf_spec_hd_1) {
  char format[] = "%hd";
  char str[] = "123";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_2) {
  char format[] = "%hd";
  char str[] = "-123";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_3) {
  char format[] = "%hd";
  char str[] = "+123";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_4) {
  char format[] = "%3hd";
  char str[] = "-123";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_5) {
  char format[] = "%4hd";
  char str[] = "-123";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_6) {
  char format[] = "%10hd";
  char str[] = "-123";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_7) {
  char format[] = "%1hd";
  char str[] = "-123";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_8) {
  char format[] = "%3hd";
  char str[] = "+123";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_9) {
  char format[] = "%4hd";
  char str[] = "+123";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_10) {
  char format[] = "%10hd";
  char str[] = "+123";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_11) {
  char format[] = "%1hd";
  char str[] = "+123";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_12) {
  char format[] = "%*1hd";
  char str[] = "+123";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_13) {
  char format[] = "%*hd";
  char str[] = "123";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_14) {
  char format[] = "%hd";
  char str[] = "2147483647";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_15) {
  char format[] = "%hd";
  char str[] = "+2147483648";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_16) {
  char format[] = "%hd";
  char str[] = "214743483648";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_17) {
  char format[] = "%hd";
  char str[] = "-2147483648";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_18) {
  char format[] = "%hd";
  char str[] = "-2147483649";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_19) {
  char format[] = "%hd";
  char str[] = "-214748364239";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_20) {
  char format[] = "%hd";
  char str[] = "−9223372036854775808";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_21) {
  char format[] = "%hd";
  char str[] = "−9223372036854775809";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_22) {
  char format[] = "%hd";
  char str[] = "−922337203685477582309";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_23) {
  char format[] = "%hd";
  char str[] = "9223372036854775807";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_24) {
  char format[] = "%hd";
  char str[] = "9223372036854775808";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_25) {
  char format[] = "%hd";
  char str[] = "922337203685477582309";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_1) {
  char format[] = "%d";
  char str[] = "123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_2) {
  char format[] = "%d";
  char str[] = "-123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_3) {
  char format[] = "%d";
  char str[] = "+123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_4) {
  char format[] = "%3d";
  char str[] = "-123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_5) {
  char format[] = "%4d";
  char str[] = "-123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_6) {
  char format[] = "%10d";
  char str[] = "-123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_7) {
  char format[] = "%1d";
  char str[] = "-123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_8) {
  char format[] = "%3d";
  char str[] = "+123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_9) {
  char format[] = "%4d";
  char str[] = "+123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_10) {
  char format[] = "%10d";
  char str[] = "+123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_11) {
  char format[] = "%1d";
  char str[] = "+123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_12) {
  char format[] = "%*1d";
  char str[] = "+123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_13) {
  char format[] = "%*d";
  char str[] = "123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_14) {
  char format[] = "%d";
  char str[] = "2147483647";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_15) {
  char format[] = "%d";
  char str[] = "+2147483648";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_16) {
  char format[] = "%d";
  char str[] = "214743483648";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_17) {
  char format[] = "%d";
  char str[] = "-2147483648";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_18) {
  char format[] = "%d";
  char str[] = "-2147483649";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_19) {
  char format[] = "%d";
  char str[] = "-214748364239";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_20) {
  char format[] = "%d";
  char str[] = "−9223372036854775808";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_21) {
  char format[] = "%d";
  char str[] = "−9223372036854775809";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_22) {
  char format[] = "%d";
  char str[] = "−922337203685477582309";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_23) {
  char format[] = "%d";
  char str[] = "9223372036854775807";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_24) {
  char format[] = "%d";
  char str[] = "9223372036854775808";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_25) {
  char format[] = "%d";
  char str[] = "922337203685477582309";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_1) {
  char format[] = "%ld";
  char str[] = "123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_2) {
  char format[] = "%ld";
  char str[] = "-123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_3) {
  char format[] = "%ld";
  char str[] = "+123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_4) {
  char format[] = "%3ld";
  char str[] = "-123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_5) {
  char format[] = "%4ld";
  char str[] = "-123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_6) {
  char format[] = "%10ld";
  char str[] = "-123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_7) {
  char format[] = "%1ld";
  char str[] = "-123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_8) {
  char format[] = "%3ld";
  char str[] = "+123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_9) {
  char format[] = "%4ld";
  char str[] = "+123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_10) {
  char format[] = "%10ld";
  char str[] = "+123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_11) {
  char format[] = "%1ld";
  char str[] = "+123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_12) {
  char format[] = "%*1ld";
  char str[] = "+123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_13) {
  char format[] = "%*ld";
  char str[] = "123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_14) {
  char format[] = "%ld";
  char str[] = "2147483647";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_15) {
  char format[] = "%ld";
  char str[] = "+2147483648";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_16) {
  char format[] = "%ld";
  char str[] = "214743483648";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_17) {
  char format[] = "%ld";
  char str[] = "-2147483648";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_18) {
  char format[] = "%ld";
  char str[] = "-2147483649";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_19) {
  char format[] = "%ld";
  char str[] = "-214748364239";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_20) {
  char format[] = "%ld";
  char str[] = "−9223372036854775808";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_21) {
  char format[] = "%ld";
  char str[] = "−9223372036854775809";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_22) {
  char format[] = "%ld";
  char str[] = "−922337203685477582309";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_23) {
  char format[] = "%ld";
  char str[] = "9223372036854775807";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_24) {
  char format[] = "%ld";
  char str[] = "9223372036854775808";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_25) {
  char format[] = "%ld";
  char str[] = "922337203685477582309";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_1) {
  char format[] = "%lld";
  char str[] = "123";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_2) {
  char format[] = "%lld";
  char str[] = "-123";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_3) {
  char format[] = "%lld";
  char str[] = "+123";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_4) {
  char format[] = "%3lld";
  char str[] = "-123";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_5) {
  char format[] = "%4lld";
  char str[] = "-123";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_6) {
  char format[] = "%10lld";
  char str[] = "-123";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_7) {
  char format[] = "%1lld";
  char str[] = "-123";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_8) {
  char format[] = "%3lld";
  char str[] = "+123";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_9) {
  char format[] = "%4lld";
  char str[] = "+123";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_10) {
  char format[] = "%10lld";
  char str[] = "+123";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_11) {
  char format[] = "%1lld";
  char str[] = "+123";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_12) {
  char format[] = "%*1lld";
  char str[] = "+123";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_13) {
  char format[] = "%*lld";
  char str[] = "123";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_14) {
  char format[] = "%lld";
  char str[] = "2147483647";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_15) {
  char format[] = "%lld";
  char str[] = "+2147483648";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_16) {
  char format[] = "%lld";
  char str[] = "214743483648";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_17) {
  char format[] = "%lld";
  char str[] = "-2147483648";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_18) {
  char format[] = "%lld";
  char str[] = "-2147483649";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_19) {
  char format[] = "%lld";
  char str[] = "-214748364239";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_20) {
  char format[] = "%lld";
  char str[] = "−9223372036854775808";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_21) {
  char format[] = "%lld";
  char str[] = "−9223372036854775809";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_22) {
  char format[] = "%lld";
  char str[] = "−922337203685477582309";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_23) {
  char format[] = "%lld";
  char str[] = "9223372036854775807";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_24) {
  char format[] = "%lld";
  char str[] = "9223372036854775808";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_lld_25) {
  char format[] = "%lld";
  char str[] = "922337203685477582309";
  long long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_1) {
  char format[] = "%hi%hi%hi";
  char str[] = "123 +198 -87";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_2) {
  char format[] = "%hi %hi %hi";
  char str[] = "123 +198 -87";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_3) {
  char format[] = "%1hi %1hi %1hi";
  char str[] = "13 +137 -8";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_4) {
  char format[] = "%2hi %2hi %2hi";
  char str[] = "13 +137 -8";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_5) {
  char format[] = "%3hi %3hi %3hi";
  char str[] = "13 +137 -8";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_6) {
  char format[] = "%30hi %24hi %21hi";
  char str[] = "13 +137 -8";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_7) {
  char format[] = "%hi %hi %hi %hi";
  char str[] = "2147483647 +2147483648 -2147483648 -2147483649";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;
  unsigned short w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_8) {
  char format[] = "%hi %hi %hi %hi";
  char str[] =
      "9223372036854775807 +9223372036854775808 -9223372036854775808 "
      "-9223372036854775809";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;
  unsigned short w1 = 0, w2 = 0;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_1) {
  char format[] = "%hi%hi%hi";
  char str[] = "0123 +0198 -087";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_2) {
  char format[] = "%hi %hi %hi";
  char str[] = "0123 +0198 -087";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_3) {
  char format[] = "%1hi %1hi %1hi";
  char str[] = "013 +0137 -08";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_4) {
  char format[] = "%2hi %2hi %2hi";
  char str[] = "013 +0137 -08";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_5) {
  char format[] = "%3hi %3hi %3hi";
  char str[] = "013 +0137 -08";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_6) {
  char format[] = "%30hi %24hi %21hi";
  char str[] = "013 +0137 -08";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_7) {
  char format[] = "%hi %hi %hi %hi";
  char str[] = "037777777777 +040000000000 -040000000000 -040000000001";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;
  unsigned short w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_8) {
  char format[] = "%hi %hi %hi %hi";
  char str[] =
      "01777777777777777777777 +02000000000000000000000 "
      "-02000000000000000000000 -02000000000000000000001";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;
  unsigned short w1 = 0, w2 = 0;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_1) {
  char format[] = "%hi%hi%hi";
  char str[] = "0x123 +0X198 -0x87";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_2) {
  char format[] = "%hi %hi %hi";
  char str[] = "0X123 +0x198 -0X87";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_3) {
  char format[] = "%1hi %1hi %1hi";
  char str[] = "0X13 +0x137 -0x8";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_5) {
  char format[] = "%3hi %3hi %3hi";
  char str[] = "0x13 +0x137 -0x8";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_6) {
  char format[] = "%30hi %24hi %21hi";
  char str[] = "0x13 +0x1a -0x8";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_7) {
  char format[] = "%hi %hi %hi %hi";
  char str[] = "0xffffffff +0xffffffeab -0xFfFfffFf -0x39cdb3aa";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;
  unsigned short w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_8) {
  char format[] = "%hi %hi %hi %hi";
  char str[] =
      "0xFFFFFFFFFFFFFFFF 0x8000000000000000 -0xFFFFFFFFFFFFFFFF "
      "-0x348923848239742389328";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;
  unsigned short w1 = 0, w2 = 0;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_1) {
  char format[] = "%i%i%i";
  char str[] = "123 +198 -87";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_2) {
  char format[] = "%i %i %i";
  char str[] = "123 +198 -87";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_3) {
  char format[] = "%1i %1i %1i";
  char str[] = "13 +137 -8";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_4) {
  char format[] = "%2i %2i %2i";
  char str[] = "13 +137 -8";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_5) {
  char format[] = "%3i %3i %3i";
  char str[] = "13 +137 -8";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_6) {
  char format[] = "%30i %24i %21i";
  char str[] = "13 +137 -8";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_7) {
  char format[] = "%i %i %i %i";
  char str[] = "2147483647 +2147483648 -2147483648 -2147483649";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;
  unsigned int w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_8) {
  char format[] = "%i %i %i %i";
  char str[] =
      "9223372036854775807 +9223372036854775808 -9223372036854775808 "
      "-9223372036854775809";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;
  unsigned int w1 = 0, w2 = 0;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_1) {
  char format[] = "%i%i%i";
  char str[] = "0123 +0198 -087";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_2) {
  char format[] = "%i %i %i";
  char str[] = "0123 +0198 -087";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_3) {
  char format[] = "%1i %1i %1i";
  char str[] = "013 +0137 -08";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_4) {
  char format[] = "%2i %2i %2i";
  char str[] = "013 +0137 -08";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_5) {
  char format[] = "%3i %3i %3i";
  char str[] = "013 +0137 -08";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_6) {
  char format[] = "%30i %24i %21i";
  char str[] = "013 +0137 -08";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_7) {
  char format[] = "%i %i %i %i";
  char str[] = "037777777777 +040000000000 -040000000000 -040000000001";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;
  unsigned int w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_8) {
  char format[] = "%i %i %i %i";
  char str[] =
      "01777777777777777777777 +02000000000000000000000 "
      "-02000000000000000000000 -02000000000000000000001";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;
  unsigned int w1 = 0, w2 = 0;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_1) {
  char format[] = "%i%i%i";
  char str[] = "0x123 +0X198 -0x87";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_2) {
  char format[] = "%i %i %i";
  char str[] = "0X123 +0x198 -0X87";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_3) {
  char format[] = "%1i %1i %1i";
  char str[] = "0X13 +0x137 -0x8";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_5) {
  char format[] = "%3i %3i %3i";
  char str[] = "0x13 +0x137 -0x8";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_6) {
  char format[] = "%30i %24i %21i";
  char str[] = "0x13 +0x1a -0x8";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_7) {
  char format[] = "%i %i %i %i";
  char str[] = "0xffffffff +0xffffffeab -0xFfFfffFf -0x39cdb3aa";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;
  unsigned int w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_8) {
  char format[] = "%i %i %i %i";
  char str[] =
      "0xFFFFFFFFFFFFFFFF 0x8000000000000000 -0xFFFFFFFFFFFFFFFF "
      "-0x348923848239742389328";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;
  unsigned int w1 = 0, w2 = 0;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_1) {
  char format[] = "%li%li%li";
  char str[] = "123 +198 -87";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_2) {
  char format[] = "%li %li %li";
  char str[] = "123 +198 -87";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_3) {
  char format[] = "%1li %1li %1li";
  char str[] = "13 +137 -8";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_4) {
  char format[] = "%2li %2li %2li";
  char str[] = "13 +137 -8";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_5) {
  char format[] = "%3li %3li %3li";
  char str[] = "13 +137 -8";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_6) {
  char format[] = "%30li %24li %21li";
  char str[] = "13 +137 -8";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_7) {
  char format[] = "%li %li %li %li";
  char str[] = "2147483647 +2147483648 -2147483648 -2147483649";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;
  unsigned long int w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_8) {
  char format[] = "%li %li %li %li";
  char str[] =
      "9223372036854775807 +9223372036854775808 -9223372036854775808 "
      "-9223372036854775809";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;
  unsigned long int w1 = 0, w2 = 0;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_1) {
  char format[] = "%li%li%li";
  char str[] = "0123 +0198 -087";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_2) {
  char format[] = "%li %li %li";
  char str[] = "0123 +0198 -087";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_3) {
  char format[] = "%1li %1li %1li";
  char str[] = "013 +0137 -08";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_4) {
  char format[] = "%2li %2li %2li";
  char str[] = "013 +0137 -08";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_5) {
  char format[] = "%3li %3li %3li";
  char str[] = "013 +0137 -08";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_6) {
  char format[] = "%30li %24li %21li";
  char str[] = "013 +0137 -08";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_7) {
  char format[] = "%li %li %li %li";
  char str[] = "037777777777 +040000000000 -040000000000 -040000000001";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;
  unsigned long int w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_8) {
  char format[] = "%li %li %li %li";
  char str[] =
      "01777777777777777777777 +02000000000000000000000 "
      "-02000000000000000000000 -02000000000000000000001";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;
  unsigned long int w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_1) {
  char format[] = "%li%li%li";
  char str[] = "0x123 +0X198 -0x87";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_2) {
  char format[] = "%li %li %li";
  char str[] = "0X123 +0x198 -0X87";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_3) {
  char format[] = "%1li %1li %1li";
  char str[] = "0X13 +0x137 -0x8";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_5) {
  char format[] = "%3li %3li %3li";
  char str[] = "0x13 +0x137 -0x8";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_6) {
  char format[] = "%30li %24li %21li";
  char str[] = "0x13 +0x1a -0x8";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_7) {
  char format[] = "%li %li %li %li";
  char str[] = "0xffffffff +0xffffffeab -0xFfFfffFf -0x39cdb3aa";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;
  unsigned long int w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_8) {
  char format[] = "%li %li %li %li";
  char str[] =
      "0xFFFFFFFFFFFFFFFF 0x8000000000000000 -0xFFFFFFFFFFFFFFFF "
      "-0x348923848239742389328";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;
  unsigned long int w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_lli_dec_1) {
  char format[] = "%lli%lli%li";
  char str[] = "123 +198 -87";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lli_dec_2) {
  char format[] = "%lli %lli %lli";
  char str[] = "123 +198 -87";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lli_dec_3) {
  char format[] = "%1lli %1lli %1lli";
  char str[] = "13 +137 -8";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lli_dec_4) {
  char format[] = "%2lli %2lli %2lli";
  char str[] = "13 +137 -8";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lli_dec_5) {
  char format[] = "%3lli %3lli %3lli";
  char str[] = "13 +137 -8";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lli_dec_6) {
  char format[] = "%30lli %24lli %21lli";
  char str[] = "13 +137 -8";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lli_dec_7) {
  char format[] = "%lli %lli %lli %lli";
  char str[] = "2147483647 +2147483648 -2147483648 -2147483649";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;
  unsigned long long int w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_lli_dec_8) {
  char format[] = "%lli %lli %lli %lli";
  char str[] =
      "9223372036854775807 +9223372036854775808 -9223372036854775808 "
      "-9223372036854775809";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;
  unsigned long long int w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_lli_oct_1) {
  char format[] = "%lli%lli%lli";
  char str[] = "0123 +0198 -087";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lli_oct_2) {
  char format[] = "%lli %lli %lli";
  char str[] = "0123 +0198 -087";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lli_oct_3) {
  char format[] = "%1lli %1lli %1lli";
  char str[] = "013 +0137 -08";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lli_oct_4) {
  char format[] = "%2lli %2lli %2lli";
  char str[] = "013 +0137 -08";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lli_oct_5) {
  char format[] = "%3lli %3lli %3lli";
  char str[] = "013 +0137 -08";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lli_oct_6) {
  char format[] = "%30lli %24lli %21lli";
  char str[] = "013 +0137 -08";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lli_oct_7) {
  char format[] = "%lli %lli %lli %lli";
  char str[] = "037777777777 +040000000000 -040000000000 -040000000001";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;
  unsigned long long int w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_lli_oct_8) {
  char format[] = "%lli %lli %lli %lli";
  char str[] =
      "01777777777777777777777 +02000000000000000000000 "
      "-02000000000000000000000 -02000000000000000000001";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;
  unsigned long long int w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_lli_hex_1) {
  char format[] = "%lli%lli%lli";
  char str[] = "0x123 +0X198 -0x87";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lli_hex_2) {
  char format[] = "%lli %lli %lli";
  char str[] = "0X123 +0x198 -0X87";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lli_hex_3) {
  char format[] = "%1lli %1lli %1lli";
  char str[] = "0X13 +0x137 -0x8";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lli_hex_5) {
  char format[] = "%3lli %3lli %3lli";
  char str[] = "0x13 +0x137 -0x8";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lli_hex_6) {
  char format[] = "%30lli %24lli %21lli";
  char str[] = "0x13 +0x1a -0x8";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lli_hex_7) {
  char format[] = "%lli %lli %lli %lli";
  char str[] = "0xffffffff +0xffffffeab -0xFfFfffFf -0x39cdb3aa";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;
  unsigned long long int w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_lli_hex_8) {
  char format[] = "%lli %lli %lli %lli";
  char str[] =
      "0xFFFFFFFFFFFFFFFF 0x8000000000000000 -0xFFFFFFFFFFFFFFFF "
      "-0x348923848239742389328";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;
  unsigned long long int w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST
START_TEST(sscanf_spec_n_1) {
  char format[] = "%n";
  char str[] = "Ilyusha";
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &n1);
  int16_t res2 = sscanf(str, format, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_spec_n_2) {
  char format[] = "%d %n";
  char str[] = "80 Ilyusha";
  int d1 = 0, d2 = 0;
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &n1);
  int16_t res2 = sscanf(str, format, &d2, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_spec_n_3) {
  char format[] = "%d %d %n %d %d %d";
  char str[] = "80 50 70 371 327";
  int d1 = 0, d2 = 0;
  int dd1 = 0, dd2 = 0;
  int f1 = 0, f2 = 0;
  int ff1 = 0, ff2 = 0;
  int k1 = 0, k2 = 0;
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &dd1, &n1, &f1, &ff1, &k1);
  int16_t res2 = sscanf(str, format, &d2, &dd2, &n2, &f2, &ff2, &k2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(dd1, dd2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(ff1, ff2);
  ck_assert_int_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_spec_n_4) {
  char format[] = "Hello %n ";
  char str[] = "Hello";
  int *n1 = 0, *n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &n1);
  int16_t res2 = sscanf(str, format, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_spec_n_5) {
  char format[] = "%d %hn %d %hhn %d %d %hhn %d";
  char str[] = "80 50 70 371 327";
  int d1 = 0, d2 = 0;
  int dd1 = 0, dd2 = 0;
  int f1 = 0, f2 = 0;
  int ff1 = 0, ff2 = 0;
  int k1 = 0, k2 = 0;
  short hn1 = 0, hn2 = 0;
  unsigned char hhn1 = 0, hhn2 = 0;
  unsigned char n1 = 0, n2 = 0;

  int16_t res1 =
      s21_sscanf(str, format, &d1, &hn1, &dd1, &hhn1, &f1, &ff1, &n1, &k1);
  int16_t res2 =
      sscanf(str, format, &d2, &hn2, &dd2, &hhn2, &f2, &ff2, &n2, &k2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(dd1, dd2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(ff1, ff2);
  ck_assert_int_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(hn1, hn2);
  ck_assert_int_eq(hhn1, hhn2);
}
END_TEST

START_TEST(sscanf_spec_n_6) {
  char format[] = "%d %ln %d %lln %d %d %lln %d";
  char str[] = "3263 225 724 38 482";
  int d1 = 0, d2 = 0;
  int dd1 = 0, dd2 = 0;
  int f1 = 0, f2 = 0;
  int ff1 = 0, ff2 = 0;
  int k1 = 0, k2 = 0;
  long int hn1 = 0, hn2 = 0;
  long long int hhn1 = 0, hhn2 = 0;
  long long int n1 = 0, n2 = 0;

  int16_t res1 =
      s21_sscanf(str, format, &d1, &hn1, &dd1, &hhn1, &f1, &ff1, &n1, &k1);
  int16_t res2 =
      sscanf(str, format, &d2, &hn2, &dd2, &hhn2, &f2, &ff2, &n2, &k2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(dd1, dd2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(ff1, ff2);
  ck_assert_int_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(hn1, hn2);
  ck_assert_int_eq(hhn1, hhn2);
}
END_TEST

START_TEST(sscanf_spec_n_7) {
  char format[] = "%%%c";
  char str[] = "%p";
  char d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_n_8) {
  char format[] = "%s %n %s %n %s %s %s %n";
  char str[] = "Hello, my name is Jinny";
  char s1[30], s2[30], s3[30], s4[30], s5[30], s6[30], s7[30], s8[30], s9[30],
      s10[30];
  int n1 = 0, n2 = 0;
  int hn1 = 0, hn2 = 0;
  int hhn1 = 0, hhn2 = 0;

  int16_t res1 =
      s21_sscanf(str, format, &s1, &hn1, &s3, &hhn1, &s5, &s7, &s9, &n1);
  int16_t res2 =
      sscanf(str, format, &s2, &hn2, &s4, &hhn2, &s6, &s8, &s10, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s3, s4);
  ck_assert_pstr_eq(s5, s6);
  ck_assert_pstr_eq(s7, s8);
  ck_assert_pstr_eq(s9, s10);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(hn1, hn2);
  ck_assert_int_eq(hhn1, hhn2);
}
END_TEST

START_TEST(sscanf_spec_n_9) {
  char format[] = "%lf %lf %lf %lf %n %lf";
  char str[] = ".0 66.34 9877.66 1.99 0.999";
  long double d1 = 0, d2 = 0;
  long double dd1 = 0, dd2 = 0;
  long double f1 = 0, f2 = 0;
  long double ff1 = 0, ff2 = 0;
  long double k1 = 0, k2 = 0;
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &dd1, &f1, &ff1, &n1, &k1);
  int16_t res2 = sscanf(str, format, &d2, &dd2, &f2, &ff2, &n2, &k2);
  ck_assert_ldouble_eq(res1, res2);
  ck_assert_ldouble_eq(d1, d2);
  ck_assert_ldouble_eq(dd1, dd2);
  ck_assert_ldouble_eq(f1, f2);
  ck_assert_ldouble_eq(ff1, ff2);
  ck_assert_ldouble_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_spec_n_10) {
  char format[] = "%s %s";
  char str[] = "hi \t\n";
  char s1[20], s2[20] = {0}, s3[20], s4[20] = {0};

  int16_t res1 = s21_sscanf(str, format, s1, s2);
  int16_t res2 = sscanf(str, format, s3, s4);
  ck_assert_ldouble_eq(res1, res2);
  ck_assert_pstr_eq(s1, s3);
  ck_assert_pstr_eq(s2, s4);
}
END_TEST

START_TEST(sscanf_spec_ho_1) {
  char format[] = "%ho%ho%ho";
  char str[] = "123 +198 -87";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_ho_2) {
  char format[] = "%ho%ho%ho";
  char str[] = "123 +1564 -1723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_ho_3) {
  char format[] = "%1ho %1ho %1ho";
  char str[] = "1 +04 -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_ho_4) {
  char format[] = "%2ho %2ho %2ho";
  char str[] = "0123 +04 -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_ho_5) {
  char format[] = "%3ho %3ho %3ho";
  char str[] = "0123 +04 -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_ho_6) {
  char format[] = "%*ho %*ho %*ho";
  char str[] = "0123 +04 -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_o_1) {
  char format[] = "%o%o%o";
  char str[] = "123 +198 -87";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_o_2) {
  char format[] = "%o%o%o";
  char str[] = "123 +1564 -1723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_o_3) {
  char format[] = "%1o %1o %1o";
  char str[] = "1 +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_o_4) {
  char format[] = "%2o %2o %2o";
  char str[] = "0123 +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_o_5) {
  char format[] = "%3o %3o %3o";
  char str[] = "0123 +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_o_6) {
  char format[] = "%*o %*o %*o";
  char str[] = "0123 +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lo_1) {
  char format[] = "%lo%lo%lo";
  char str[] = "123 +198 -87";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lo_2) {
  char format[] = "%lo%lo%lo";
  char str[] = "123 +1564 -1723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lo_3) {
  char format[] = "%1lo %1lo %1lo";
  char str[] = "1 +04 -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lo_4) {
  char format[] = "%2lo %2lo %2lo";
  char str[] = "0123 +04 -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lo_5) {
  char format[] = "%3lo %3lo %3lo";
  char str[] = "0123 +04 -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lo_6) {
  char format[] = "%*lo %*lo %*lo";
  char str[] = "0123 +04 -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_llo_1) {
  char format[] = "%llo%llo%llo";
  char str[] = "123 +198 -87";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_llo_2) {
  char format[] = "%llo%llo%llo";
  char str[] = "123 +1564 -1723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_llo_3) {
  char format[] = "%1llo %1llo %1llo";
  char str[] = "1 +04 -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_llo_4) {
  char format[] = "%2llo %2llo %2llo";
  char str[] = "0123 +04 -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_llo_5) {
  char format[] = "%3llo %3llo %3llo";
  char str[] = "0123 +04 -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_llo_6) {
  char format[] = "%*llo %*llo %*llo";
  char str[] = "0123 +04 -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST
START_TEST(sscanf_spec_p_1) {
  char format[] = "%p";
  char str[] = "0xAAAA";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_2) {
  char format[] = "%5p";
  char str[] = "0xAAAA";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_3) {
  char format[] = "%p";
  char str[] = "0xFFFFFF";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_4) {
  char format[] = "%p";
  char str[] = "0x0000";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_5) {
  char format[] = "%p";
  char str[] = "0xA2361598";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_6) {
  char format[] = "%p";
  char str[] = "0x34567hjk";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_7) {
  char format[] = "%p";
  char str[] = "0x34567hjk678";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_8) {
  char format[] = "%p";
  char str[] = "0x34ABcd68";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_9) {
  char format[] = "%p";
  char str[] = "1234567890ABCDEF";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_10) {
  char format[] = "%5p";
  char str[] = "0x237481";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_11) {
  char format[] = "%6p";
  char str[] = "0xdksajh";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_12) {
  char format[] = "%6p";
  char str[] = "0xAGAGUIY";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_13) {
  char format[] = "%p";
  char str[] = "0xAGAGUIYUYGFSV";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_14) {
  char format[] = "%p";
  char str[] = "0xAA64BB";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_15) {
  char format[] = "%p";
  char str[] = "0xGGH7TY";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST
START_TEST(sscanf_spec_real_1) {
  char format[] = "%f %f %f";
  char str[] = "123 +198 -87";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_real_2) {
  char format[] = "%fg %f w%fx";
  char str[] = "75g +19.8w -87.x";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_real_3) {
  char format[] = "%f %f %f %f";
  char str[] = "NAN nan -INF +inf";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(d1);
  ck_assert_float_nan(d2);
  ck_assert_float_nan(q1);
  ck_assert_float_nan(q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_real_4) {
  char format[] = "%f";
  char str[] = "Nap";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_real_5) {
  char format[] = "%f";
  char str[] = "Np";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_real_6) {
  char format[] = "%f";
  char str[] = "iNd";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_real_7) {
  char format[] = "%f";
  char str[] = "id";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_real_8) {
  char format[] = "%f %f %f %f";
  char str[] = "34.56e3 83.2e-4 .43e+1 +2.43e3";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_9) {
  char format[] = "%1f %1f %2f %1f";
  char str[] = "34.5+6e3 83.2e-4 .43e+1 +2.43e3";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_10) {
  char format[] = "%*0f %7f %*f %*f";
  char str[] = "34.5+6e3 83.2e-4 +43e+1 +2.43e3";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_real_11) {
  char format[] = "%fr %7f p";
  char str[] = "34.5r 83.2ep4";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_real_12) {
  char format[] = "%1f %1f %1f %1f";
  char str[] = "34 32. +45.e +23E3 -0.3e4";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_13) {
  char format[] = "%2f %2f %2f %2f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_14) {
  char format[] = "%3f %3f %4f %3f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_15) {
  char format[] = "%4f %4f %4f %4f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_18) {
  char format[] = "%f %fx %2f1 %2fx %*f %*f";
  char str[] = "1.1 2.x 1.1 2.x 1.1 2.x";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_19) {
  char format[] = "%f %4f %5fq %6f %*f q%*f";
  char str[] = "1.3e1 1.4eq2 1.3e1q 1.4 1.3eq 1.4e2";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_hx_1) {
  char format[] = "%hx%hx%hx";
  char str[] = "123 +198 -87";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_2) {
  char format[] = "%hx%hx%hx";
  char str[] = "12a3 +156B4 -17C23";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_3) {
  char format[] = "%hx%hx";
  char str[] = "0 +0x";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_hx_4) {
  char format[] = "%hx%hx%hx";
  char str[] = "0 -0XABC -0X";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_5) {
  char format[] = "%hx%hx%hx";
  char str[] = "0abc4 -0XABC 0x";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_6) {
  char format[] = "%1hx %1hx %1hx";
  char str[] = "1a +04 -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_7) {
  char format[] = "%1hx %1hx %1hx";
  char str[] = "1a 0x -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_8) {
  char format[] = "%2hx %2hx %2hx";
  char str[] = "1a bc 0x -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_9) {
  char format[] = "%2hx %2hx %2hx";
  char str[] = "1a bCc 0x -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_10) {
  char format[] = "%3hx %3hx %3hx";
  char str[] = "0x123 +0X4 -37x23";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_11) {
  char format[] = "%*hx %*hx %*hx";
  char str[] = "0x123 +04 -372f3";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_1) {
  char format[] = "%x%x%x";
  char str[] = "123 +198 -87";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_2) {
  char format[] = "%x%x%x";
  char str[] = "12a3 +156B4 -17C23";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_3) {
  char format[] = "%x%x";
  char str[] = "0 +0x";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_x_4) {
  char format[] = "%x%x%x";
  char str[] = "0 -0XABC -0X";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_5) {
  char format[] = "%x%x%x";
  char str[] = "0abc4 -0XABC 0x";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_6) {
  char format[] = "%1x %1x %1x";
  char str[] = "1a +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_7) {
  char format[] = "%1x %1x %1x";
  char str[] = "1a 0x -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_8) {
  char format[] = "%2x %2x %2x";
  char str[] = "1a bc 0x -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_9) {
  char format[] = "%2x %2x %2x";
  char str[] = "1a bCc 0x -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_10) {
  char format[] = "%3x %3x %3x";
  char str[] = "0x123 +0X4 -37x23";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_11) {
  char format[] = "%*x %*x %*x";
  char str[] = "0x123 +04 -372f3";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_1) {
  char format[] = "%lx%lx%lx";
  char str[] = "123 +198 -87";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_2) {
  char format[] = "%lx%lx%lx";
  char str[] = "12a3 +156B4 -17C23";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_3) {
  char format[] = "%lx%lx";
  char str[] = "0 +0x";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_lx_4) {
  char format[] = "%lx%lx%lx";
  char str[] = "0 -0XABC -0X";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_5) {
  char format[] = "%lx%lx%lx";
  char str[] = "0abc4 -0XABC 0x";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_6) {
  char format[] = "%1lx %1lx %1lx";
  char str[] = "1a +04 -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_7) {
  char format[] = "%1lx %1lx %1lx";
  char str[] = "1a 0x -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_8) {
  char format[] = "%2lx %2lx %2lx";
  char str[] = "1a bc 0x -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_9) {
  char format[] = "%2lx %2lx %2lx";
  char str[] = "1a bCc 0x -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_10) {
  char format[] = "%3lx %3lx %3lx";
  char str[] = "0x123 +0X4 -37x23";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_11) {
  char format[] = "%*lx %*lx %*lx";
  char str[] = "0x123 +04 -372f3";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_llx_1) {
  char format[] = "%llx%llx%llx";
  char str[] = "123 +198 -87";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_llx_2) {
  char format[] = "%llx%llx%llx";
  char str[] = "12a3 +156B4 -17C23";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_llx_3) {
  char format[] = "%llx%llx";
  char str[] = "0 +0x";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_llx_4) {
  char format[] = "%llx%llx%llx";
  char str[] = "0 -0XABC -0X";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_llx_5) {
  char format[] = "%llx%llx%llx";
  char str[] = "0abc4 -0XABC 0x";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_llx_6) {
  char format[] = "%1llx %1llx %1llx";
  char str[] = "1a +04 -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_llx_7) {
  char format[] = "%1llx %1llx %1llx";
  char str[] = "1a 0x -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_llx_8) {
  char format[] = "%2llx %2llx %2llx";
  char str[] = "1a bc 0x -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_llx_9) {
  char format[] = "%2llx %2llx %2llx";
  char str[] = "1a bCc 0x -3723";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_llx_10) {
  char format[] = "%3llx %3llx %3llx";
  char str[] = "0x123 +0X4 -37x23";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_llx_11) {
  char format[] = "%*llx %*llx %*llx";
  char str[] = "0x123 +04 -372f3";
  unsigned long long int d1 = 0, d2 = 0;
  unsigned long long int q1 = 0, q2 = 0;
  unsigned long long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

Suite *s21_sscanf_suite(void) {
  Suite *s = suite_create("-=S21_SSCANF=-");
  TCase *tc = tcase_create("s21_sscanf");
  tcase_add_test(tc, test_skip);
  tcase_add_test(tc, test_sign);
  tcase_add_test(tc, test_e);
  tcase_add_test(tc, test_e_1);
  tcase_add_test(tc, test_e_2);
  tcase_add_test(tc, test_Lf1);
  tcase_add_test(tc, test_u);
  tcase_add_test(tc, test_u_hard);
  tcase_add_test(tc, test_u_owerfl);
  tcase_add_test(tc, test_u_owerfl_minus);
  tcase_add_test(tc, test_h);
  tcase_add_test(tc, test_s);
  tcase_add_test(tc, test_s_hard);
  tcase_add_test(tc, test_f);
  tcase_add_test(tc, test_double);
  tcase_add_test(tc, test_o);
  tcase_add_test(tc, test_o_1);
  tcase_add_test(tc, test_proc);
  tcase_add_test(tc, test_o_owerfl_minus);
  tcase_add_test(tc, test_x);
  tcase_add_test(tc, test_x_hard);
  tcase_add_test(tc, test_i);
  tcase_add_test(tc, test_i_hard);
  tcase_add_test(tc, test_ptr);
  tcase_add_test(tc, test_n);
  tcase_add_test(tc, test_n1);
  tcase_add_test(tc, test_d);
  tcase_add_test(tc, test_d_1);
  tcase_add_test(tc, test_d_hard);
  tcase_add_test(tc, test_c);
  tcase_add_test(tc, test_g);
  tcase_add_test(tc, test_g_1);
  tcase_add_test(tc, all);
  tcase_add_test(tc, all1);
  tcase_add_test(tc, all2);
  tcase_add_test(tc, d);
  tcase_add_test(tc, d_s);
  tcase_add_test(tc, d_s_c);
  tcase_add_test(tc, i_d_s_c);
  tcase_add_test(tc, i_d_s_c_e);
  tcase_add_test(tc, i_d_s_c_e_g);
  tcase_add_test(tc, i_d_s_c_e_g_f);
  tcase_add_test(tc, i_d_s_c_e_g_f_o);
  tcase_add_test(tc, i_d_s_c_e_g_f_o_x);
  tcase_add_test(tc, i_d_s_c_e_g_f_o_x_proc_n);
  tcase_add_test(tc, i_d_s_c_e_g_f_o_x_proc_n_u);
  tcase_add_test(tc, i_d_s_c_e_g_f_o_x_proc_n_u_p);
  tcase_add_test(tc, sscanf_empty_1);
  tcase_add_test(tc, sscanf_empty_2);
  tcase_add_test(tc, sscanf_empty_3);
  tcase_add_test(tc, sscanf_empty_4);
  tcase_add_test(tc, sscanf_empty_5);
  tcase_add_test(tc, sscanf_empty_6);
  tcase_add_test(tc, sscanf_empty_7);
  tcase_add_test(tc, sscanf_spec_c_2);
  tcase_add_test(tc, sscanf_spec_c_4);
  tcase_add_test(tc, sscanf_spec_c_5);
  tcase_add_test(tc, sscanf_spec_c_6);
  tcase_add_test(tc, sscanf_spec_c_7);
  tcase_add_test(tc, sscanf_spec_c_8);
  tcase_add_test(tc, sscanf_spec_hd_1);
  tcase_add_test(tc, sscanf_spec_hd_2);
  tcase_add_test(tc, sscanf_spec_hd_3);
  tcase_add_test(tc, sscanf_spec_hd_4);
  tcase_add_test(tc, sscanf_spec_hd_5);
  tcase_add_test(tc, sscanf_spec_hd_6);
  tcase_add_test(tc, sscanf_spec_hd_7);
  tcase_add_test(tc, sscanf_spec_hd_8);
  tcase_add_test(tc, sscanf_spec_hd_9);
  tcase_add_test(tc, sscanf_spec_hd_10);
  tcase_add_test(tc, sscanf_spec_hd_11);
  tcase_add_test(tc, sscanf_spec_hd_12);
  tcase_add_test(tc, sscanf_spec_hd_13);
  tcase_add_test(tc, sscanf_spec_hd_14);
  tcase_add_test(tc, sscanf_spec_hd_15);
  tcase_add_test(tc, sscanf_spec_hd_16);
  tcase_add_test(tc, sscanf_spec_hd_17);
  tcase_add_test(tc, sscanf_spec_hd_18);
  tcase_add_test(tc, sscanf_spec_hd_19);
  tcase_add_test(tc, sscanf_spec_hd_20);
  tcase_add_test(tc, sscanf_spec_hd_21);
  tcase_add_test(tc, sscanf_spec_hd_22);
  tcase_add_test(tc, sscanf_spec_hd_23);
  tcase_add_test(tc, sscanf_spec_hd_24);
  tcase_add_test(tc, sscanf_spec_hd_25);
  tcase_add_test(tc, sscanf_spec_d_1);
  tcase_add_test(tc, sscanf_spec_d_2);
  tcase_add_test(tc, sscanf_spec_d_3);
  tcase_add_test(tc, sscanf_spec_d_4);
  tcase_add_test(tc, sscanf_spec_d_5);
  tcase_add_test(tc, sscanf_spec_d_6);
  tcase_add_test(tc, sscanf_spec_d_7);
  tcase_add_test(tc, sscanf_spec_d_8);
  tcase_add_test(tc, sscanf_spec_d_9);
  tcase_add_test(tc, sscanf_spec_d_10);
  tcase_add_test(tc, sscanf_spec_d_11);
  tcase_add_test(tc, sscanf_spec_d_12);
  tcase_add_test(tc, sscanf_spec_d_13);
  tcase_add_test(tc, sscanf_spec_d_14);
  tcase_add_test(tc, sscanf_spec_d_15);
  tcase_add_test(tc, sscanf_spec_d_16);
  tcase_add_test(tc, sscanf_spec_d_17);
  tcase_add_test(tc, sscanf_spec_d_18);
  tcase_add_test(tc, sscanf_spec_d_19);
  tcase_add_test(tc, sscanf_spec_d_20);
  tcase_add_test(tc, sscanf_spec_d_21);
  tcase_add_test(tc, sscanf_spec_d_22);
  tcase_add_test(tc, sscanf_spec_d_23);
  tcase_add_test(tc, sscanf_spec_d_24);
  tcase_add_test(tc, sscanf_spec_d_25);
  tcase_add_test(tc, sscanf_spec_ld_1);
  tcase_add_test(tc, sscanf_spec_ld_2);
  tcase_add_test(tc, sscanf_spec_ld_3);
  tcase_add_test(tc, sscanf_spec_ld_4);
  tcase_add_test(tc, sscanf_spec_ld_5);
  tcase_add_test(tc, sscanf_spec_ld_6);
  tcase_add_test(tc, sscanf_spec_ld_7);
  tcase_add_test(tc, sscanf_spec_ld_8);
  tcase_add_test(tc, sscanf_spec_ld_9);
  tcase_add_test(tc, sscanf_spec_ld_10);
  tcase_add_test(tc, sscanf_spec_ld_11);
  tcase_add_test(tc, sscanf_spec_ld_12);
  tcase_add_test(tc, sscanf_spec_ld_13);
  tcase_add_test(tc, sscanf_spec_ld_14);
  tcase_add_test(tc, sscanf_spec_ld_15);
  tcase_add_test(tc, sscanf_spec_ld_16);
  tcase_add_test(tc, sscanf_spec_ld_17);
  tcase_add_test(tc, sscanf_spec_ld_18);
  tcase_add_test(tc, sscanf_spec_ld_19);
  tcase_add_test(tc, sscanf_spec_ld_20);
  tcase_add_test(tc, sscanf_spec_ld_21);
  tcase_add_test(tc, sscanf_spec_ld_22);
  tcase_add_test(tc, sscanf_spec_ld_23);
  tcase_add_test(tc, sscanf_spec_ld_24);
  tcase_add_test(tc, sscanf_spec_ld_25);
  tcase_add_test(tc, sscanf_spec_lld_1);
  tcase_add_test(tc, sscanf_spec_lld_2);
  tcase_add_test(tc, sscanf_spec_lld_3);
  tcase_add_test(tc, sscanf_spec_lld_4);
  tcase_add_test(tc, sscanf_spec_lld_5);
  tcase_add_test(tc, sscanf_spec_lld_6);
  tcase_add_test(tc, sscanf_spec_lld_7);
  tcase_add_test(tc, sscanf_spec_lld_8);
  tcase_add_test(tc, sscanf_spec_lld_9);
  tcase_add_test(tc, sscanf_spec_lld_10);
  tcase_add_test(tc, sscanf_spec_lld_11);
  tcase_add_test(tc, sscanf_spec_lld_12);
  tcase_add_test(tc, sscanf_spec_lld_13);
  tcase_add_test(tc, sscanf_spec_lld_14);
  tcase_add_test(tc, sscanf_spec_lld_15);
  tcase_add_test(tc, sscanf_spec_lld_16);
  tcase_add_test(tc, sscanf_spec_lld_17);
  tcase_add_test(tc, sscanf_spec_lld_18);
  tcase_add_test(tc, sscanf_spec_lld_19);
  tcase_add_test(tc, sscanf_spec_lld_20);
  tcase_add_test(tc, sscanf_spec_lld_21);
  tcase_add_test(tc, sscanf_spec_lld_22);
  tcase_add_test(tc, sscanf_spec_lld_23);
  tcase_add_test(tc, sscanf_spec_lld_24);
  tcase_add_test(tc, sscanf_spec_lld_25);
  tcase_add_test(tc, sscanf_spec_i_dec_1);
  tcase_add_test(tc, sscanf_spec_i_dec_2);
  tcase_add_test(tc, sscanf_spec_i_dec_3);
  tcase_add_test(tc, sscanf_spec_i_dec_4);
  tcase_add_test(tc, sscanf_spec_i_dec_5);
  tcase_add_test(tc, sscanf_spec_i_dec_6);
  tcase_add_test(tc, sscanf_spec_i_dec_7);
  tcase_add_test(tc, sscanf_spec_i_dec_8);

  tcase_add_test(tc, sscanf_spec_i_oct_1);
  tcase_add_test(tc, sscanf_spec_i_oct_2);
  tcase_add_test(tc, sscanf_spec_i_oct_3);
  tcase_add_test(tc, sscanf_spec_i_oct_4);
  tcase_add_test(tc, sscanf_spec_i_oct_5);
  tcase_add_test(tc, sscanf_spec_i_oct_6);
  tcase_add_test(tc, sscanf_spec_i_oct_7);
  tcase_add_test(tc, sscanf_spec_i_oct_8);
  tcase_add_test(tc, sscanf_spec_i_hex_1);
  tcase_add_test(tc, sscanf_spec_i_hex_2);
  tcase_add_test(tc, sscanf_spec_i_hex_3);
  tcase_add_test(tc, sscanf_spec_i_hex_5);
  tcase_add_test(tc, sscanf_spec_i_hex_6);
  tcase_add_test(tc, sscanf_spec_i_hex_7);
  tcase_add_test(tc, sscanf_spec_i_hex_8);
  tcase_add_test(tc, sscanf_spec_hi_dec_1);
  tcase_add_test(tc, sscanf_spec_hi_dec_2);
  tcase_add_test(tc, sscanf_spec_hi_dec_3);
  tcase_add_test(tc, sscanf_spec_hi_dec_4);
  tcase_add_test(tc, sscanf_spec_hi_dec_5);
  tcase_add_test(tc, sscanf_spec_hi_dec_6);
  tcase_add_test(tc, sscanf_spec_hi_dec_7);
  tcase_add_test(tc, sscanf_spec_hi_dec_8);
  tcase_add_test(tc, sscanf_spec_hi_oct_1);
  tcase_add_test(tc, sscanf_spec_hi_oct_2);
  tcase_add_test(tc, sscanf_spec_hi_oct_3);
  tcase_add_test(tc, sscanf_spec_hi_oct_4);
  tcase_add_test(tc, sscanf_spec_hi_oct_5);
  tcase_add_test(tc, sscanf_spec_hi_oct_6);
  tcase_add_test(tc, sscanf_spec_hi_oct_7);
  tcase_add_test(tc, sscanf_spec_hi_oct_8);
  tcase_add_test(tc, sscanf_spec_hi_hex_1);
  tcase_add_test(tc, sscanf_spec_hi_hex_2);
  tcase_add_test(tc, sscanf_spec_hi_hex_3);
  tcase_add_test(tc, sscanf_spec_hi_hex_5);
  tcase_add_test(tc, sscanf_spec_hi_hex_6);
  tcase_add_test(tc, sscanf_spec_hi_hex_7);
  tcase_add_test(tc, sscanf_spec_hi_hex_8);
  tcase_add_test(tc, sscanf_spec_li_dec_1);
  tcase_add_test(tc, sscanf_spec_li_dec_2);
  tcase_add_test(tc, sscanf_spec_li_dec_3);
  tcase_add_test(tc, sscanf_spec_li_dec_4);
  tcase_add_test(tc, sscanf_spec_li_dec_5);
  tcase_add_test(tc, sscanf_spec_li_dec_6);
  tcase_add_test(tc, sscanf_spec_li_dec_7);
  tcase_add_test(tc, sscanf_spec_li_dec_8);
  tcase_add_test(tc, sscanf_spec_li_oct_1);
  tcase_add_test(tc, sscanf_spec_li_oct_2);
  tcase_add_test(tc, sscanf_spec_li_oct_3);
  tcase_add_test(tc, sscanf_spec_li_oct_4);
  tcase_add_test(tc, sscanf_spec_li_oct_5);
  tcase_add_test(tc, sscanf_spec_li_oct_6);
  tcase_add_test(tc, sscanf_spec_li_oct_7);
  tcase_add_test(tc, sscanf_spec_li_oct_8);
  tcase_add_test(tc, sscanf_spec_li_hex_1);
  tcase_add_test(tc, sscanf_spec_li_hex_2);
  tcase_add_test(tc, sscanf_spec_li_hex_3);
  tcase_add_test(tc, sscanf_spec_li_hex_5);
  tcase_add_test(tc, sscanf_spec_li_hex_6);
  tcase_add_test(tc, sscanf_spec_li_hex_7);
  tcase_add_test(tc, sscanf_spec_li_hex_8);
  tcase_add_test(tc, sscanf_spec_lli_dec_1);
  tcase_add_test(tc, sscanf_spec_lli_dec_2);
  tcase_add_test(tc, sscanf_spec_lli_dec_3);
  tcase_add_test(tc, sscanf_spec_lli_dec_4);
  tcase_add_test(tc, sscanf_spec_lli_dec_5);
  tcase_add_test(tc, sscanf_spec_lli_dec_6);
  tcase_add_test(tc, sscanf_spec_lli_dec_7);
  tcase_add_test(tc, sscanf_spec_lli_dec_8);
  tcase_add_test(tc, sscanf_spec_lli_oct_1);
  tcase_add_test(tc, sscanf_spec_lli_oct_2);
  tcase_add_test(tc, sscanf_spec_lli_oct_3);
  tcase_add_test(tc, sscanf_spec_lli_oct_4);
  tcase_add_test(tc, sscanf_spec_lli_oct_5);
  tcase_add_test(tc, sscanf_spec_lli_oct_6);
  tcase_add_test(tc, sscanf_spec_lli_oct_7);
  tcase_add_test(tc, sscanf_spec_lli_oct_8);
  tcase_add_test(tc, sscanf_spec_lli_hex_1);
  tcase_add_test(tc, sscanf_spec_lli_hex_2);
  tcase_add_test(tc, sscanf_spec_lli_hex_3);
  tcase_add_test(tc, sscanf_spec_lli_hex_5);
  tcase_add_test(tc, sscanf_spec_lli_hex_6);
  tcase_add_test(tc, sscanf_spec_lli_hex_7);
  tcase_add_test(tc, sscanf_spec_lli_hex_8);
  tcase_add_test(tc, sscanf_spec_n_1);
  tcase_add_test(tc, sscanf_spec_n_2);
  tcase_add_test(tc, sscanf_spec_n_3);
  tcase_add_test(tc, sscanf_spec_n_4);
  tcase_add_test(tc, sscanf_spec_n_5);
  tcase_add_test(tc, sscanf_spec_n_6);
  tcase_add_test(tc, sscanf_spec_n_7);
  tcase_add_test(tc, sscanf_spec_n_8);
  tcase_add_test(tc, sscanf_spec_n_9);
  tcase_add_test(tc, sscanf_spec_n_10);
  tcase_add_test(tc, sscanf_spec_ho_1);
  tcase_add_test(tc, sscanf_spec_ho_2);
  tcase_add_test(tc, sscanf_spec_ho_3);
  tcase_add_test(tc, sscanf_spec_ho_4);
  tcase_add_test(tc, sscanf_spec_ho_5);
  tcase_add_test(tc, sscanf_spec_ho_6);
  tcase_add_test(tc, sscanf_spec_o_1);
  tcase_add_test(tc, sscanf_spec_o_2);
  tcase_add_test(tc, sscanf_spec_o_3);
  tcase_add_test(tc, sscanf_spec_o_4);
  tcase_add_test(tc, sscanf_spec_o_5);
  tcase_add_test(tc, sscanf_spec_o_6);
  tcase_add_test(tc, sscanf_spec_lo_1);
  tcase_add_test(tc, sscanf_spec_lo_2);
  tcase_add_test(tc, sscanf_spec_lo_3);
  tcase_add_test(tc, sscanf_spec_lo_4);
  tcase_add_test(tc, sscanf_spec_lo_5);
  tcase_add_test(tc, sscanf_spec_lo_6);
  tcase_add_test(tc, sscanf_spec_llo_1);
  tcase_add_test(tc, sscanf_spec_llo_2);
  tcase_add_test(tc, sscanf_spec_llo_3);
  tcase_add_test(tc, sscanf_spec_llo_4);
  tcase_add_test(tc, sscanf_spec_llo_5);
  tcase_add_test(tc, sscanf_spec_llo_6);
  tcase_add_test(tc, sscanf_spec_p_1);
  tcase_add_test(tc, sscanf_spec_p_2);
  tcase_add_test(tc, sscanf_spec_p_3);
  tcase_add_test(tc, sscanf_spec_p_4);
  tcase_add_test(tc, sscanf_spec_p_5);
  tcase_add_test(tc, sscanf_spec_p_6);
  tcase_add_test(tc, sscanf_spec_p_7);
  tcase_add_test(tc, sscanf_spec_p_8);
  tcase_add_test(tc, sscanf_spec_p_9);
  tcase_add_test(tc, sscanf_spec_p_10);
  tcase_add_test(tc, sscanf_spec_p_11);
  tcase_add_test(tc, sscanf_spec_p_12);
  tcase_add_test(tc, sscanf_spec_p_13);
  tcase_add_test(tc, sscanf_spec_p_14);
  tcase_add_test(tc, sscanf_spec_p_15);
  tcase_add_test(tc, sscanf_spec_real_1);
  tcase_add_test(tc, sscanf_spec_real_2);
  tcase_add_test(tc, sscanf_spec_real_3);
  tcase_add_test(tc, sscanf_spec_real_4);
  tcase_add_test(tc, sscanf_spec_real_5);
  tcase_add_test(tc, sscanf_spec_real_6);
  tcase_add_test(tc, sscanf_spec_real_7);
  tcase_add_test(tc, sscanf_spec_real_8);
  tcase_add_test(tc, sscanf_spec_real_9);
  tcase_add_test(tc, sscanf_spec_real_10);
  tcase_add_test(tc, sscanf_spec_real_11);
  tcase_add_test(tc, sscanf_spec_real_12);
  tcase_add_test(tc, sscanf_spec_real_13);
  tcase_add_test(tc, sscanf_spec_real_14);
  tcase_add_test(tc, sscanf_spec_real_15);
  tcase_add_test(tc, sscanf_spec_real_18);
  tcase_add_test(tc, sscanf_spec_real_19);
  tcase_add_test(tc, sscanf_spec_hx_1);
  tcase_add_test(tc, sscanf_spec_hx_2);
  tcase_add_test(tc, sscanf_spec_hx_3);
  tcase_add_test(tc, sscanf_spec_hx_4);
  tcase_add_test(tc, sscanf_spec_hx_5);
  tcase_add_test(tc, sscanf_spec_hx_6);
  tcase_add_test(tc, sscanf_spec_hx_7);
  tcase_add_test(tc, sscanf_spec_hx_8);
  tcase_add_test(tc, sscanf_spec_hx_9);
  tcase_add_test(tc, sscanf_spec_hx_10);
  tcase_add_test(tc, sscanf_spec_hx_11);
  tcase_add_test(tc, sscanf_spec_x_1);
  tcase_add_test(tc, sscanf_spec_x_2);
  tcase_add_test(tc, sscanf_spec_x_3);
  tcase_add_test(tc, sscanf_spec_x_4);
  tcase_add_test(tc, sscanf_spec_x_5);
  tcase_add_test(tc, sscanf_spec_x_6);
  tcase_add_test(tc, sscanf_spec_x_7);
  tcase_add_test(tc, sscanf_spec_x_8);
  tcase_add_test(tc, sscanf_spec_x_9);
  tcase_add_test(tc, sscanf_spec_x_10);
  tcase_add_test(tc, sscanf_spec_x_11);
  tcase_add_test(tc, sscanf_spec_lx_1);
  tcase_add_test(tc, sscanf_spec_lx_2);
  tcase_add_test(tc, sscanf_spec_lx_3);
  tcase_add_test(tc, sscanf_spec_lx_4);
  tcase_add_test(tc, sscanf_spec_lx_5);
  tcase_add_test(tc, sscanf_spec_lx_6);
  tcase_add_test(tc, sscanf_spec_lx_7);
  tcase_add_test(tc, sscanf_spec_lx_8);
  tcase_add_test(tc, sscanf_spec_lx_9);
  tcase_add_test(tc, sscanf_spec_lx_10);
  tcase_add_test(tc, sscanf_spec_lx_11);
  tcase_add_test(tc, sscanf_spec_llx_1);
  tcase_add_test(tc, sscanf_spec_llx_2);
  tcase_add_test(tc, sscanf_spec_llx_3);
  tcase_add_test(tc, sscanf_spec_llx_4);
  tcase_add_test(tc, sscanf_spec_llx_5);
  tcase_add_test(tc, sscanf_spec_llx_6);
  tcase_add_test(tc, sscanf_spec_llx_7);
  tcase_add_test(tc, sscanf_spec_llx_8);
  tcase_add_test(tc, sscanf_spec_llx_9);
  tcase_add_test(tc, sscanf_spec_llx_10);
  tcase_add_test(tc, sscanf_spec_llx_11);
  suite_add_tcase(s, tc);
  return s;
}
