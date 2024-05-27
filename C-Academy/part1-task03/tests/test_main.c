/*
  Name:        test_main.c

  Purpose:     File contains the tests for functions described in temperature.c
               that convert temperature Fahrenheit to Celsius

*/


#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/temperature.h"

void test_convert_fahrenheit_to_celsius(void **state);


/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_convert_fahrenheit_to_celsius)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

void test_convert_fahrenheit_to_celsius(void **state)
{
  float result = convert_fahrenheit_to_celsius(32);

  assert_int_equal(result, 0);
}/* test_convert_fahrenheit_to_celsius */
