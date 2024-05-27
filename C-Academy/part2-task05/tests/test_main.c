/*
  Name:        test_main.c

  Purpose:     File contains tests for functions decribed in convert_symbols.c
               that convert lowercase alphabet symbols to uppercase.

*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include "../src/fraction.h"

void test_add_two_fractions(void **state);
void test_add_two_fractions_f1_num_is_zero(void **state);
void test_add_two_fractions_f2_num_is_zero(void **state);
void test_add_two_fractions_f1_negative_den(void **state);
void test_add_two_fractions_f2_negative_den(void **state);
void test_add_two_fractions_f1_zero_den(void **state);
void test_add_two_fractions_f2_zero_den(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_add_two_fractions),
    cmocka_unit_test(test_add_two_fractions_f1_num_is_zero),
    cmocka_unit_test(test_add_two_fractions_f2_num_is_zero),
    cmocka_unit_test(test_add_two_fractions_f1_negative_den),
    cmocka_unit_test(test_add_two_fractions_f2_negative_den),
    cmocka_unit_test(test_add_two_fractions_f1_zero_den),
    cmocka_unit_test(test_add_two_fractions_f2_zero_den),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:     test_add_two_fractions_num

  Purpose:  Test the function add_two_fractions for numerator

*/
void test_add_two_fractions(void **state)
{
  fraction f1;
  fraction f2;
  fraction result;

  f1.num = 2;
  f1.den = 3;
  f2.num = 1;
  f2.den = 5;
   
  add_two_fractions(&f1, &f2, &result);
   
  assert_int_equal(result.num, 13);
  assert_int_equal(result.den, 15);
} /* test_add_two_fractions_num */

/*
  Name:     test_add_two_fractions_f1_num_is_zero

  Purpose:  Test the function add_two_fractions when numerator of the first fraction is zero

*/
void test_add_two_fractions_f1_num_is_zero(void **state)
{
  fraction f1;
  fraction f2;
  fraction result;

  f1.num = 0;
  f1.den = 3;
  f2.num = 1;
  f2.den = 5;
   
  add_two_fractions(&f1, &f2, &result);
   
  assert_int_equal(result.num, 1);
  assert_int_equal(result.den, 5);
} /* test_add_two_fractions_f1_num_is_zero */

/*
  Name:     test_add_two_fractions_f2_num_is_zero

  Purpose:  Test the function add_two_fractions when numerator of the second fraction is zero

*/
void test_add_two_fractions_f2_num_is_zero(void **state)
{
  fraction f1;
  fraction f2;
  fraction result;

  f1.num = 2;
  f1.den = 3;
  f2.num = 0;
  f2.den = 5;

  add_two_fractions(&f1, &f2, &result);

  assert_int_equal(result.num, 2);
  assert_int_equal(result.den, 3);
} /* test_add_two_fractions_f2_num_is_zero */

/*
  Name:     test_add_two_fractions_f1_negative_den

  Purpose:  Test the function add_two_fractions for negative denominator of the first fraction

*/
void test_add_two_fractions_f1_negative_den(void **state)
{
  fraction f1;
  fraction f2;
  fraction result;

  f1.num = 1;
  f1.den = -3;
  f2.num = 2;
  f2.den = 3;
   
  add_two_fractions(&f1, &f2, &result);

  assert_int_equal(result.num, 1);
  assert_int_equal(result.den, 3);
} /* test_add_two_fractions_f1_negative_den */

/*
  Name:     test_add_two_fractions_f2_negative_den

  Purpose:  Test the function add_two_fractions for negative denominator of the second fraction

*/
void test_add_two_fractions_f2_negative_den(void **state)
{
  fraction f1;
  fraction f2;
  fraction result;

  f1.num = 1;
  f1.den = 3;
  f2.num = 2;
  f2.den = -3;
   
  add_two_fractions(&f1, &f2, &result);

  assert_int_equal(result.num, 1);
  assert_int_equal(result.den, -3);
} /* test_add_two_fractions_f1_negative_den */

/*
  Name:     test_add_two_fractions_f1_zero_den

  Purpose:  Test the function add_two_fractions for zero denominator of the first fraction

*/
void test_add_two_fractions_f1_zero_den(void **state)
{
  fraction f1;
  fraction f2;
  fraction result;

  f1.num = 2;
  f1.den = 0;
  f2.num = 1;
  f2.den = -5;
   
  add_two_fractions(&f1, &f2, &result);
   
  assert_int_equal(result.num, 0);
  assert_int_equal(result.den, 0);
} /* test_add_two_fractions_f1_zero_den */

/*
  Name:     test_add_two_fractions_f2_zero_den

  Purpose:  Test the function add_two_fractions for zero denominator of the second fraction

*/
void test_add_two_fractions_f2_zero_den(void **state)
{
  fraction f1;
  fraction f2;
  fraction result;

  f1.num = 2;
  f1.den = 3;
  f2.num = 1;
  f2.den = 0;

  add_two_fractions(&f1, &f2, &result);

  assert_int_equal(result.num, 0);
  assert_int_equal(result.den, 0);
} /* test_add_two_fractions_f2_zero_den */
