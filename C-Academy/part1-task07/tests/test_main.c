/*
  Name:        test_main.c

  Purpose:     File contains tests for functions decribed in sum.c
               that computes sum of the long number digits.

*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/sum.h"

void test_sum_of_digits_positive_num(void **state);
void test_sum_of_digits_negative_num(void **state);
void test_sum_of_digits_zero_num(void **state);
void test_sum_of_digits_long_num(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_sum_of_digits_positive_num),
    cmocka_unit_test(test_sum_of_digits_negative_num),
    cmocka_unit_test(test_sum_of_digits_zero_num),
    cmocka_unit_test(test_sum_of_digits_long_num)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}


/*
  Name:     void test_sum_of_digits_positive_num(void **state)

  Purpose:  Test the function sum_of_digits for positive number

*/
void test_sum_of_digits_positive_num(void **state)
{
  int result = sum_of_digits(123);

  assert_int_equal(result, 6);
} /* test_sum_of_digits_positive_num */


/*
  Name:     test_sum_of_digits_negative_num

  Purpose:  Test the function sum_of_digits for negative number

*/
void test_sum_of_digits_negative_num(void **state)
{
  int result = sum_of_digits(-512);

  assert_int_equal(result, 8);
} /* test_sum_of_digits_negative_num */


/*
  Name:     test_sum_of_digits_zero_num

  Purpose:  Test the function sum_of_digits for zero

*/
void test_sum_of_digits_zero_num(void **state)
{
  int result = sum_of_digits(0);

  assert_int_equal(result, 0);
} /* test_sum_of_digits_zero_num */

/*
  Name:     test_sum_of_digits_zero_num

  Purpose:  Test the function sum_of_digits for zero

*/
void test_sum_of_digits_long_num(void **state)
{
  int result = sum_of_digits(2147483647);

  assert_int_equal(result, 46);
} /* test_sum_of_digits_zero_num */
