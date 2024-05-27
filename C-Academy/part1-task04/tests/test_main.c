/*
  Name:        test_main.c

  Purpose:     File contains the tests for functions described in math_operations.c
               that compute sum, difference, product, division,
               modul, average, minimum and maximum of two values

*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../src/math_operations.h"

void test_sum(void **state);
void test_difference(void **state);
void test_product(void **state);
void test_division(void **state);
void test_division_divisor_is_zero(void **state);
void test_modul(void **state);
void test_modul_second_num_is_zero(void **state);
void test_average(void **state);
void test_minimum_first_num_is_min(void **state);
void test_minimum_second_num_is_min(void **state);
void test_maximum_first_num_is_max(void **state);
void test_maximum_second_num_is_max(void **state);

int main()
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_sum),
    cmocka_unit_test(test_difference),
    cmocka_unit_test(test_product),
    cmocka_unit_test(test_division),
    cmocka_unit_test(test_division_divisor_is_zero),
    cmocka_unit_test(test_modul),
    cmocka_unit_test(test_modul_second_num_is_zero),
    cmocka_unit_test(test_average),
    cmocka_unit_test(test_minimum_first_num_is_min),
    cmocka_unit_test(test_minimum_second_num_is_min),
    cmocka_unit_test(test_maximum_first_num_is_max),
    cmocka_unit_test(test_maximum_second_num_is_max)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:     test_sum

  Purpose:  Test the function "sum"
*/
void test_sum(void **state)
{
  int result = sum(2, 3);

  assert_int_equal(result, 5);
} /* test_sum */

/*
  Name:     test_difference

  Purpose:  Test the function "difference"
*/
void test_difference(void **state)
{
  int result = difference(4, 3);

  assert_int_equal(result, 1);
} /* test_difference */

/*
  Name:     test_product

  Purpose:  Test the function "product"
*/
void test_product(void **state)
{
  int result = product(4, 3);

  assert_int_equal(result, 12);
} /* test_product */

/*
  Name:     test_division

  Purpose:  Test the function "division"
*/
void test_division(void **state)
{
  float result = division(8, 2);

  assert_float_equal(result, 4, 2);
} /* test_division */

/*
  Name:     test_division_divisor_is_zero

  Purpose:  Test the function "division" when divisor is zero
*/
void test_division_divisor_is_zero(void **state)
{
  float result = division(8, 0);

  assert_float_equal(result, -1, 2);
} /* test_division_divisor_is_zero */

/*
  Name:     test_modul

  Purpose:  Test the function "modul"
*/
void test_modul(void **state)
{
  int result = modul(5, 2);

  assert_int_equal(result, 1);
} /* test_modul */

/*
  Name:     test_modul

  Purpose:  Test the function "modul" when second number is zero
*/
void test_modul_second_num_is_zero(void **state)
{
  int result = modul(8, 0);

  assert_int_equal(result, -1);
} /* test_division_divisor_is_zero */

/*
  Name:     test_average

  Purpose:  Test the function "average"
*/
void test_average(void **state)
{
  float result = average(4, 2);

  assert_float_equal(result, 3, 2);
} /* test_average */

/*
  Name:     test_minimum_first_num_is_min

  Purpose:  Test the function "minimum" when first number is lower than second
*/
void test_minimum_first_num_is_min(void **state)
{
  int result = minimum(1, 2);

  assert_int_equal(result, 1);
} /* test_minimum_first_num_is_min */

/*
  Name:     test_minimum_second_num_is_min

  Purpose:  Test the function "minimum" when second number is less than first
*/
void test_minimum_second_num_is_min(void **state)
{
  int result = minimum(2, 1);

  assert_int_equal(result, 1);
} /* test_minimum_second_num_is_min */

/*
  Name:     test_maximum_first_num_is_max

  Purpose:  Test the function "maximum" when first number is greater than second
*/
void test_maximum_first_num_is_max(void **state)
{
  int result = maximum(2, 1);

  assert_int_equal(result, 2);
} /* test_maximum_first_num_is_max */

/*
  Name:     test_maximum_second_num_is_max

  Purpose:  Test the function "maximum" when second number is greater than first
*/
void test_maximum_second_num_is_max(void **state)
{
  int result = maximum(1, 2);

  assert_int_equal(result, 2);
} /* test_maximum_second_num_is_max */
