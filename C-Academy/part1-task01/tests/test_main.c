/*
  Name:      test_main.c

  Purpose:   File contains tests for functions decribed in rectangle.c
             that computes area and perimeter of a rectangle

*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../src/rectangle.h"

void test_rectangle_aria_valid(void **state);
void test_rectangle_aria_zero_length(void **state);
void test_rectangle_aria_zero_width(void **state);
void test_rectangle_perimeter_valid(void **state);
void test_rectangle_perimeter_zero_length(void **state);
void test_rectangle_perimeter_zero_width(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_rectangle_aria_valid),
    cmocka_unit_test(test_rectangle_aria_zero_length),
    cmocka_unit_test(test_rectangle_aria_zero_width),
    cmocka_unit_test(test_rectangle_perimeter_valid),
    cmocka_unit_test(test_rectangle_perimeter_zero_length),
    cmocka_unit_test(test_rectangle_perimeter_zero_width)

  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

void test_rectangle_aria_valid(void **state)
{
  int result = rectangle_area(100, 200);

  assert_int_equal(result, 20000);
}

void test_rectangle_aria_zero_length(void **state)
{
  int result = rectangle_area(0, 200);

  assert_int_equal(result, -1);
}

void test_rectangle_aria_zero_width(void **state)
{
  int result = rectangle_area(100, 0);

  assert_int_equal(result, -1);
}

void test_rectangle_perimeter_valid(void **state)
{
  int result = rectangle_perimeter(100, 200);

  assert_int_equal(result, 600);
}

void test_rectangle_perimeter_zero_length(void **state)
{
  int result = rectangle_perimeter(0, 200);

  assert_int_equal(result, -1);
}

void test_rectangle_perimeter_zero_width(void **state)
{
  int result = rectangle_perimeter(100, 0);

  assert_int_equal(result, -1);
}
