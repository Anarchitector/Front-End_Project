/*
  Name:      test_main.c

  Purpose:   File contains tests for functions decribed in week_day.c
             that return day of the week

*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>
#include <string.h>
#include "../src/week_day.h"

void test_get_day_Monday(void **state);
void test_get_day_Tuesday(void **state);
void test_get_day_Wednesday(void **state);
void test_get_day_Thursday(void **state);
void test_get_day_Friday(void **state);
void test_get_day_Saturday(void **state);
void test_get_day_Sunday(void **state);
void test_get_day_nonexistend_zero_day(void **state);
void test_get_day_nonexistend_eight_day(void **state);
void test_get_day_nonexistend_negative_value(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{
  const struct CMUnitTest tests[] = {
  cmocka_unit_test(test_get_day_Monday),
  cmocka_unit_test(test_get_day_Tuesday),
  cmocka_unit_test(test_get_day_Wednesday),
  cmocka_unit_test(test_get_day_Thursday),
  cmocka_unit_test(test_get_day_Friday),
  cmocka_unit_test(test_get_day_Saturday),
  cmocka_unit_test(test_get_day_Sunday),
  cmocka_unit_test(test_get_day_nonexistend_zero_day),
  cmocka_unit_test(test_get_day_nonexistend_eight_day),
  cmocka_unit_test(test_get_day_nonexistend_negative_value)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        test_get_day_Monday

  Purpose:     Test the function get_day for Monday (day 1)

*/
void test_get_day_Monday(void **state)
{
  int result = get_day(1);

  assert_int_equal(result, Monday);
} /* test_get_day_Monday */

/*
  Name:        test_get_day_Monday

  Purpose:     Test the function get_day for Tuesday (day 2)

*/
void test_get_day_Tuesday(void **state)
{
  int result = get_day(2);

  assert_int_equal(result, Tuesday);
} /* test_get_day_Tuesday */

/*
  Name:        test_get_day_Wednesday

  Purpose:     Test the function get_day for Wednesday (day 3)

*/
void test_get_day_Wednesday(void **state)
{
  int result = get_day(3);

  assert_int_equal(result, Wednesday);
} /* test_get_day_Wednesday */

/*
  Name:        test_get_day_Thursday

  Purpose:     Test the function get_day for Thursday (day 4)

*/
void test_get_day_Thursday(void **state)
{
  int result = get_day(4);

  assert_int_equal(result, Thursday);
} /* test_get_day_Thursday */

/*
  Name:        test_get_day_Friday

  Purpose:     Test the function get_day for Friday (day 5)

*/
void test_get_day_Friday(void **state)
{
  int result = get_day(5);

  assert_int_equal(result, Friday);
} /* test_get_day_Friday */

/*
  Name:        test_get_day_Saturday

  Purpose:     Test the function get_day for Saturday (day 6)

*/
void test_get_day_Saturday(void **state)
{
  int result = get_day(6);

  assert_int_equal(result, Saturday);
} /* test_get_day_Saturday */

/*
  Name:        test_get_day_Sunday

  Purpose:     Test the function get_day for Sunday (day 7)

*/
void test_get_day_Sunday(void **state)
{
  int result = get_day(7);

  assert_int_equal(result, Sunday);
} /* test_get_day_Sunday */


/*
  Name:        test_get_day_nonexistend_zero_day

  Purpose:     Test the function get_day for non-existend zero day (day 0)

*/
void test_get_day_nonexistend_zero_day(void **state)
{
  int result = get_day(0);

  assert_int_equal(result, 0);
} /* test_get_day_nonexistend_zero_day */


/*
  Name:        test_get_day_nonexistend_eight_day

  Purpose:     Test the function get_day for non-existend eight day (day 8)

*/
void test_get_day_nonexistend_eight_day(void **state)
{
  int result = get_day(8);

  assert_int_equal(result, 0);
} /* test_get_day_nonexistend_eight_day */


/*
  Name:        test_get_day_nonexistend_negative_value

  Purpose:     Test the function get_day for non-existend negative number day (day -3)

*/
void test_get_day_nonexistend_negative_value(void **state)
{
  int result = get_day(-3);

  assert_int_equal(result, 0);
} /* test_get_day_nonexistend_negative_value */
