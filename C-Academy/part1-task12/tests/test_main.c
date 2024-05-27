/*
  Name:      test_main.c

  Purpose:   File contains tests for functions decribed in total_amount.c that 
             accepts 1 integer representing number of minutes used by an user and 
             computes the total amount (in cents) to pay. The charged is determined as follows:
                    - the first 50 minutes are free of charge;
                    - from  51 up to 199 the user pays 20 cents per minute;
                    - from 200 up to 399 the user pays 15 cents per minute;
                    - from 400 up to 499 the user pays 10 cents per minute;
                    - from 500 the user pays 5 cents per minute;
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../src/total_amount.h"

void test_total_amount_0_min(void **state);
void test_total_amount_41_min(void **state);
void test_total_amount_50_min(void **state);
void test_total_amount_76_min(void **state);
void test_total_amount_199_min(void **state);
void test_total_amount_282_min(void **state);
void test_total_amount_399_min(void **state);
void test_total_amount_420_min(void **state);
void test_total_amount_499_min(void **state);
void test_total_amount_500_min(void **state);
void test_total_amount_510_min(void **state);
void test_negative_value(void **state);

int main()
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_total_amount_0_min),
    cmocka_unit_test(test_total_amount_41_min),
    cmocka_unit_test(test_total_amount_50_min),
    cmocka_unit_test(test_total_amount_76_min),
    cmocka_unit_test(test_total_amount_199_min),
    cmocka_unit_test(test_total_amount_282_min),
    cmocka_unit_test(test_total_amount_399_min),
    cmocka_unit_test(test_total_amount_420_min),
    cmocka_unit_test(test_total_amount_499_min),
    cmocka_unit_test(test_total_amount_500_min),
    cmocka_unit_test(test_total_amount_510_min),
    cmocka_unit_test(test_negative_value)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:    test_total_amount_0_min

  Purpose: Test get_total_amount for zero minutes
*/
void test_total_amount_0_min(void **state)
{
  int result = get_total_amount(0);

  assert_int_equal(result, 0);
} /* test_total_amount_0_min */

/*
  Name:    test_total_amount_41_min

  Purpose: Test get_total_amount for 41 minutes
*/
void test_total_amount_41_min(void **state)
{
  int result = get_total_amount(41);

  assert_int_equal(result, 0);
} /* test_total_amount_41_min */

/*
  Name:    test_total_amount_50_min

  Purpose: Test get_total_amount for 50 minutes
*/
void test_total_amount_50_min(void **state)
{
  int result = get_total_amount(50);

  assert_int_equal(result, 0);
} /* test_total_amount_50_min */

/*
  Name:    test_total_amount_76_min

  Purpose: Test get_total_amount for 76 minutes
*/
void test_total_amount_76_min(void **state)
{
  int result = get_total_amount(76);

  assert_int_equal(result, 520);
} /* test_total_amount_76_min */

/*
  Name:    test_total_amount_199_min

  Purpose: Test get_total_amount for 199 minutes
*/
void test_total_amount_199_min(void **state)
{
  int result = get_total_amount(199);

  assert_int_equal(result, 2980);
} /* test_total_amount_199_min */

/*
  Name:    test_total_amount_282_min

  Purpose: Test get_total_amount for 282 minutes
*/
void test_total_amount_282_min(void **state)
{
  int result = get_total_amount(282);

  assert_int_equal(result, 4225);
} /* test_total_amount_282_min */

/*
  Name:    test_total_amount_399_min

  Purpose: Test get_total_amount for 399 minutes
*/
void test_total_amount_399_min(void **state)
{
  int result = get_total_amount(399);

  assert_int_equal(result, 5980);
} /* test_total_amount_399_min */

/*
  Name:    test_total_amount_420_min

  Purpose: Test get_total_amount for 420 minutes
*/
void test_total_amount_420_min(void **state)
{
  int result = get_total_amount(420);

  assert_int_equal(result, 6190);
} /* test_total_amount_420_min */

/*
  Name:    test_total_amount_499_min

  Purpose: Test get_total_amount for 499 minutes
*/
void test_total_amount_499_min(void **state)
{
  int result = get_total_amount(499);

  assert_int_equal(result, 6980);
} /* test_total_amount_499_min */

/*
  Name:    test_total_amount_500_min

  Purpose: Test get_total_amount for 500 minutes
*/
void test_total_amount_500_min(void **state)
{
  int result = get_total_amount(500);

  assert_int_equal(result, 6985);
} /* test_total_amount_500_min */

/*
  Name:    test_total_amount_510_min

  Purpose: Test get_total_amount for 510 minutes
*/
void test_total_amount_510_min(void **state)
{
  int result = get_total_amount(510);

  assert_int_equal(result, 7035);
} /* test_total_amount_510_min */

/*
  Name:    test_negative_value

  Purpose: Test get_total_amount for negative value of minutes
*/
void test_negative_value(void **state)
{
  int result = get_total_amount(-10);

  assert_int_equal(result, 0);
} /* test_negative_value */
