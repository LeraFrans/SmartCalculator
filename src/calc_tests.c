#include "s21_test.h"

START_TEST(test_1) {
  char *str = malloc(250 * sizeof(char));
  strcpy(str, "12.2345+(-235)");
  double output = simple_calculation(str);
  double true_res = -222.765500;
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_2) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "12.3-2");
  double true_res = 12.3 - 2;
  double output = simple_calculation(str);
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_3) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "2+3+(-3)");
  double true_res = 2 + 3 + (-3);
  double output = simple_calculation(str);
  ck_assert_double_eq(output, true_res);
  free(str);
}
END_TEST

START_TEST(test_4) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "/10");
  int true_res = 1;
  int error = validation(str);
  ck_assert_int_eq(error, true_res);
  free(str);
}
END_TEST

START_TEST(test_5) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "5(");
  int true_res = 1;
  int error = validation(str);
  ck_assert_int_eq(error, true_res);
  free(str);
}
END_TEST

START_TEST(test_6) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "s(10)+c(1)");
  int true_res = sin(10) + cos(1);
  double output = simple_calculation(str);
  ck_assert_int_eq(output, true_res);
  free(str);
}
END_TEST

START_TEST(test_7) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "c(3)");
  double true_res = cos(3);
  double output = simple_calculation(str);
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_8) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "t(3)+33");
  double true_res = tan(3) + 33;
  double output = simple_calculation(str);
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_9) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "a(1)");
  double true_res = acos(1);
  double output = simple_calculation(str);
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_10) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "i(1)");
  double true_res = asin(1);
  double output = simple_calculation(str);
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_11) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "n(3)");
  double true_res = atan(3);
  double output = simple_calculation(str);
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_12) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "q(9)+c(20)");
  double true_res = sqrt(9) + cos(20);
  double output = simple_calculation(str);
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_13) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "l(10)");
  double output = simple_calculation(str);
  double true_res = log(10);
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_14) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "o(10)");
  double output = simple_calculation(str);
  double true_res = log10(10);
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_15) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "t(3)");
  double output = simple_calculation(str);
  double true_res = tan(3);
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_16) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "n(3.3)");
  double true_res = atan(3.3);
  double output = simple_calculation(str);
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_17) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "5 * 2.2 / 2 - 1");
  double output = simple_calculation(str);
  double true_res = 5 * 2.2 / 2 - 1;
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_18) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "2 ^ 10");
  double output = simple_calculation(str);
  double true_res = pow(2, 10);
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_19) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "36m5");
  double output = simple_calculation(str);
  double true_res = 1;
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_20) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "36m5 + (9*4) / 2 + 3 -10");
  double output = simple_calculation(str);
  double true_res = 1 + (9 * 4) / 2 + 3 - 10;
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_21) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "c(20) + 1");
  double output = simple_calculation(str);
  double true_res = cos(20) + 1;
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_22) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "2^3^3");
  double output = simple_calculation(str);
  double true_res = 134217728;
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_23) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "2^3+3/1+(3*2)");
  double output = simple_calculation(str);
  double true_res = 17;
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_24) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "(((6*6)+c(30)-10))");
  double output = simple_calculation(str);
  double true_res = (((6 * 6) + cos(30) - 10));
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_25) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "c(s(t(5)))");
  double output = simple_calculation(str);
  double true_res = cos(sin(tan(5)));
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

START_TEST(test_26) {
  char *str = malloc(50 * sizeof(char));
  strcpy(str, "c(s(t(5)))+s(10)");
  double output = simple_calculation(str);
  double true_res = cos(sin(tan(5))) + sin(10);
  ck_assert_ldouble_eq_tol(true_res, output, 1e-06);
  free(str);
}
END_TEST

Suite *suite_s21_calc_notation(void) {
  Suite *s = suite_create("s21_calc");
  TCase *tc = tcase_create("s21_calc");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  tcase_add_test(tc, test_7);
  tcase_add_test(tc, test_8);
  tcase_add_test(tc, test_9);
  tcase_add_test(tc, test_10);
  tcase_add_test(tc, test_11);
  tcase_add_test(tc, test_12);
  tcase_add_test(tc, test_13);
  tcase_add_test(tc, test_14);
  tcase_add_test(tc, test_15);
  tcase_add_test(tc, test_16);
  tcase_add_test(tc, test_17);
  tcase_add_test(tc, test_18);
  tcase_add_test(tc, test_19);
  tcase_add_test(tc, test_20);
  tcase_add_test(tc, test_21);
  tcase_add_test(tc, test_22);
  tcase_add_test(tc, test_23);
  tcase_add_test(tc, test_24);
  tcase_add_test(tc, test_25);
  tcase_add_test(tc, test_26);
  suite_add_tcase(s, tc);
  return s;
}

int main(void) {
  run_tests();
  return 0;
}

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;
  if (counter_testcase > 1) counter_testcase++;
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void run_tests(void) {
  Suite *list_cases[] = {suite_s21_calc_notation(), NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}