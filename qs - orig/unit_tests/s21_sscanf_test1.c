#include "unit_tests.h"

START_TEST(test_1_d_hd) {
  char str[S21_TEST_MAX_ARRAY_COUNT] = "100000 97";
  int a1, a2;
  short int b1, b2;
  int count1 = s21_sscanf(str, "%d %hd ", &a1, &b1);
  int count2 = sscanf(str, "%d %hd ", &a2, &b2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(test_1_ld_lld_LD) {
  char str[S21_TEST_MAX_ARRAY_COUNT] = "100 5900000000000 -30000000";
  long int b1, b2;
  long long c1, c2, d1, d2;
  int count1 = s21_sscanf(str, "%ld %Ld %lld", &b1, &c1, &d1);
  int count2 = sscanf(str, "%ld %lld %lld", &b2, &c2, &d2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(test_1_d_i_mix) {
  char str[S21_TEST_MAX_ARRAY_COUNT] =
      "100 test 35 -1234567859 7000000000000 -30000000 test ";
  int a1, a2;
  short int z1, z2;
  long int b1, b2;
  long long c1, c2, d1, d2;
  int count1 =
      s21_sscanf(str, "%d test %hd %ld %Li %lli test", &a1, &z1, &b1, &c1, &d1);
  int count2 =
      sscanf(str, "%d test %hd %ld %lli %lli test", &a2, &z2, &b2, &c2, &d2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(test_1_f_mix) {
  char str[S21_TEST_MAX_ARRAY_COUNT] =
      "3.14 123.5 test  1234545451.12123 4544551.123456789";
  float a1, a2;
  double b1, b2;
  long double c1, c2;
  long double d1, d2;

  int count1 = s21_sscanf(str, "%f %lf test  %Lf %Lf", &a1, &b1, &c1, &d1);
  int count2 = sscanf(str, "%f %lf test  %Lf %Lf", &a2, &b2, &c2, &d2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(test_2_f_mix) {
  char str[S21_TEST_MAX_ARRAY_COUNT] =
      "3.14 123.5 -1234545451.12123 4544551.123456789";

  float a1, a2;
  double b1, b2;
  long double c1, c2;
  long double d1, d2;

  int count1 = s21_sscanf(str, "%f %5lf %Lf %15Lf", &a1, &b1, &c1, &d1);
  int count2 = sscanf(str, "%f %5lf %Lf %15Lf", &a2, &b2, &c2, &d2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(test_1_u_mix) {
  char str[S21_TEST_MAX_ARRAY_COUNT] =
      "315554 1235 1234545451123 5454545451445513334";

  unsigned int a1, a2;
  unsigned short b1, b2;
  unsigned long c1, c2;
  unsigned long long d1, d2;

  int count1 = s21_sscanf(str, "%u %4hu %lu %Lu", &a1, &b1, &c1, &d1);
  int count2 = sscanf(str, "%u %4hu %lu %llu", &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(test_1_x_mix) {
  char str[S21_TEST_MAX_ARRAY_COUNT] = "a2c4 ff22 ddddfff55 fffffffff545";

  unsigned int a1, a2;
  unsigned short b1, b2;
  unsigned long c1, c2;
  unsigned long long d1, d2;

  int count1 = s21_sscanf(str, "%x %4hx %lx %Lx", &a1, &b1, &c1, &d1);
  int count2 = sscanf(str, "%x %4hx %lx %llx", &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(test_1_X_mix) {
  char str[S21_TEST_MAX_ARRAY_COUNT] = "A2C4 FF22 F45DDD67 FFFFFFFFF345";

  unsigned int a1, a2;
  unsigned short b1, b2;
  unsigned long c1, c2;
  unsigned long long d1, d2;

  int count1 = s21_sscanf(str, "%X %4hX %lX %LX", &a1, &b1, &c1, &d1);
  int count2 = sscanf(str, "%X %4hX %lX %llX", &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(test_1_o_mix) {
  char str[S21_TEST_MAX_ARRAY_COUNT] =
      "7234 33426 7333 1345123112323524 2342123132134234123";

  unsigned int a1, a2;
  unsigned short b1, b2;
  unsigned long c1, c2;
  unsigned long long d1, d2;

  int count1 = s21_sscanf(str, "%o %9ho %lo %Lo", &a1, &b1, &c1, &d1);
  int count2 = sscanf(str, "%o %9ho %lo %llo", &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(test_1_n_mix) {
  char str[S21_TEST_MAX_ARRAY_COUNT] = "11 22 33";
  unsigned int a1, a2;
  int b1, b2;
  unsigned long c1, c2;
  int d1, d2;

  int count1 = s21_sscanf(str, "%u %n%lu %n", &a1, &b1, &c1, &d1);
  int count2 = sscanf(str, "%u %n%lu %n", &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

#ifdef __APPLE__
//
#else
START_TEST(test_1_p) {
  char str1[40];
  char str2[45];
  char text[] = "Hello, School21!";
  char *ptr1 = s21_NULL;
  char *ptr2 = s21_NULL;

  sprintf(str1, "%p", (void *)text);
  sprintf(str2, "%p", (void *)text);
  int count1 = s21_sscanf(str1, "Адрес массива: %p", &ptr1);
  int count2 = sscanf(str2, "Адрес массива: %p", &ptr2);

  ck_assert_int_eq(count1, count2);
  ck_assert_str_eq(str1, str2);
}
END_TEST
#endif

START_TEST(test_1_c) {
  char c1, c2;
  char str[S21_TEST_MAX_ARRAY_COUNT] = "hello world";

  int count1 = s21_sscanf(str, "he%c", &c1);
  int count2 = sscanf(str, "he%c", &c2);

  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(test_2_c) {
  char c1, c2;
  char str[S21_TEST_MAX_ARRAY_COUNT] = "hello world";

  int count1 = s21_sscanf(str, "%1c", &c1);
  int count2 = sscanf(str, "%1c", &c2);

  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(test_3_c) {
  char s0[10] = {'\0'};
  char s1[10] = {'\0'};
  char str[S21_TEST_MAX_ARRAY_COUNT] = "hello world";

  int count1 = s21_sscanf(str, "%8c", s0);
  int count2 = sscanf(str, "%8c", s1);

  ck_assert_str_eq(s0, s1);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(test_4_c) {
  char s0[10] = {'\0'};
  char s1[10] = {'\0'};
  char str[S21_TEST_MAX_ARRAY_COUNT] = "hello world";

  int count1 = s21_sscanf(str, "%s", s0);
  int count2 = sscanf(str, "%s", s1);

  ck_assert_str_eq(s0, s1);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(test_5_c) {
  char s0[10] = {'\0'};
  char s1[10] = {'\0'};
  char str[S21_TEST_MAX_ARRAY_COUNT] = "hello world";

  int count1 = s21_sscanf(str, "%8s", s0);
  int count2 = sscanf(str, "%8s", s1);

  ck_assert_str_eq(s0, s1);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(test_6_c) {
  char s0[10] = {'\0'};
  char s1[10] = {'\0'};
  char s3[10] = {'\0'};
  char s4[10] = {'\0'};
  char str[S21_TEST_MAX_ARRAY_COUNT] = "hello world";

  int count1 = s21_sscanf(str, "%2s%3s", s0, s1);
  int count2 = sscanf(str, "%2s%3s", s3, s4);

  ck_assert_str_eq(s0, s3);
  ck_assert_str_eq(s1, s4);
  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(test_1_eE_mix) {
  char *str = "-1.23e4 87E5 0.12345e+10 2345E-3";

  long double e1, e2, E1, E2, e3, e4, E3, E4;

  int count1 = s21_sscanf(str, "%Le %LE %Le %LE", &e1, &E1, &e3, &E3);
  int count2 = sscanf(str, "%Le %LE %Le %LE", &e2, &E2, &e4, &E4);

  ck_assert_float_eq(e1, e2);
  ck_assert_float_eq(e3, e4);
  ck_assert_float_eq(E1, E2);
  ck_assert_float_eq(E3, E4);

  ck_assert_int_eq(count1, count2);
}

START_TEST(test_2_eE_mix) {
  char *str = "-1.23e4 1.1e345 0.12345e+10 2345E-3";

  long double e1, e2, E1, E2, e3, e4, E3, E4;

  int count1 = s21_sscanf(str, "%Le %LE %Le %LE", &e1, &E1, &e3, &E3);
  int count2 = sscanf(str, "%Le %LE %Le %LE", &e2, &E2, &e4, &E4);

  ck_assert_float_eq(e1, e2);
  ck_assert_float_eq(e3, e4);
  ck_assert_float_eq(E1, E2);
  ck_assert_float_eq(E3, E4);

  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(test_1_gG_mix) {
  char *str = "-1.234 87E5 0.12345e+10 2345E-3";

  long double e1, e2, E1, E2, e3, e4, E3, E4;

  int count1 = s21_sscanf(str, "%Lg %LG %Lg %LG", &e1, &E1, &e3, &E3);
  int count2 = sscanf(str, "%Lg %LG %Lg %LG", &e2, &E2, &e4, &E4);

  ck_assert_float_eq(e1, e2);
  ck_assert_float_eq(e3, e4);
  ck_assert_float_eq(E1, E2);
  ck_assert_float_eq(E3, E4);

  ck_assert_int_eq(count1, count2);
}
END_TEST

START_TEST(test_1_procent) {
  char str[] = "100%12345678.912345%-543210111";
  long long int a1, a2, c1, c2;
  double b1, b2;
  int count1 = s21_sscanf(str, "%lld%%%lf%%%8lld", &a1, &b1, &c1);
  int count2 = s21_sscanf(str, "%lld%%%lf%%%8lld", &a2, &b2, &c2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(c1, c2);
  ck_assert_float_eq(b1, b2);
  ck_assert_int_eq(count1, count2);
}
END_TEST

TCase *tests_s21_sscanf_1(void) {
  TCase *tc_core = tcase_create("tests_s21_sscanf_1");

  tcase_add_test(tc_core, test_1_d_hd);
  tcase_add_test(tc_core, test_1_ld_lld_LD);
  tcase_add_test(tc_core, test_1_d_i_mix);
  tcase_add_test(tc_core, test_1_f_mix);
  tcase_add_test(tc_core, test_2_f_mix);
  tcase_add_test(tc_core, test_1_u_mix);
  tcase_add_test(tc_core, test_1_x_mix);
  tcase_add_test(tc_core, test_1_X_mix);
  tcase_add_test(tc_core, test_1_o_mix);
  tcase_add_test(tc_core, test_1_n_mix);
  tcase_add_test(tc_core, test_1_c);
  tcase_add_test(tc_core, test_2_c);
  tcase_add_test(tc_core, test_3_c);
  tcase_add_test(tc_core, test_4_c);
  tcase_add_test(tc_core, test_5_c);
  tcase_add_test(tc_core, test_6_c);
  tcase_add_test(tc_core, test_1_eE_mix);
  tcase_add_test(tc_core, test_2_eE_mix);
  tcase_add_test(tc_core, test_1_gG_mix);
  tcase_add_test(tc_core, test_1_procent);
#ifdef __APPLE__
  //
#else
  tcase_add_test(tc_core, test_1_p);
#endif

  return tc_core;
}