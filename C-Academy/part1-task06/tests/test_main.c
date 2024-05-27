/*
  Name:      test_main.c

  Purpose:   File contains tests for functions decribed in minutes_to-years.c
             that convert minutes to years and left over days
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/minutes_to_years.h"

void test_convert_minutes_to_years(void **state);
void test_convert_minutes_to_left_over_days(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_convert_minutes_to_years),
    cmocka_unit_test(test_convert_minutes_to_left_over_days)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

void test_convert_minutes_to_years(void **state)
{
  int result = convert_minutes_to_years(525600);

  assert_int_equal(result, 1);
}

void test_convert_minutes_to_left_over_days(void **state)
{
  int result = convert_minutes_to_remaining_days(1440);

  assert_int_equal(result, 1);
}

void test_convert_minutes_to_years(void **state)
{
  int result = convert_minutes_to_years(528480);

  assert_int_equal(result, 1);
}

void test_convert_minutes_to_left_over_days(void **state)
{
  int result = convert_minutes_to_remaining_days(528480);

  assert_int_equal(result, 2);
}

