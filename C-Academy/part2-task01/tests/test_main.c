/*
  Name:        test_main.c

  Purpose:     File contains tests for functions decribed in array_processing.c

*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdbool.h>
#include <stdio.h>
#include "../src/array_processing.h"

int numbers[] = {1, 1, 20, 4, 5, 6, 7, 6, 5, 3};

void test_find_largest(void **state);
void test_find_min_max(void **state);
void test_find_duplicated(void **state);
void test_print_unique(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_find_largest),
    cmocka_unit_test(test_find_min_max),
    cmocka_unit_test(test_find_duplicated),
    cmocka_unit_test(test_print_unique)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:     void test_find_largest(void **state)

  Purpose:  Test the function find_largest

*/
void test_find_largest(void **state)
{
  int result = find_largest_element(numbers, sizeof(numbers)/sizeof(numbers[0]));

  assert_int_equal(result, 20);
} /* test_sum_of_digits_positive_num */

/*
  Name:     test_find_min_max

  Purpose:  Test the function find_min_max

*/
void test_find_min_max(void **state)
{
  min_max result;
  find_min_max(numbers , sizeof(numbers)/sizeof(numbers[0]), &result);

  assert_int_equal(result.min, 1);
  assert_int_equal(result.max, 20);
} /* test_find_min_max_minimum_num */


/*
  Name:     test_find_duplicated

  Purpose:  Test the function find_duplicated

*/
void test_find_duplicated(void **state)
{
  int result = find_duplicated(numbers, sizeof(numbers)/sizeof(numbers[0]));

  assert_true(result);
} /* test_find_min_max_maximum_num */


/*
  Name:     test_print_unique

  Purpose:  Test the function print_unique

*/
void test_print_unique(void **state)
{
  int numbers[] = {1, 1, 20, 4, 5, 4};
  int freq[6] = {0};
  
  print_unique(numbers, freq, sizeof(numbers)/sizeof(numbers[0]));

  assert_int_equal(freq[0], 1);
  assert_int_equal(freq[1], 1);
  assert_int_equal(freq[2], 0);
  assert_int_equal(freq[3], 1);
  assert_int_equal(freq[4], 0);
  assert_int_equal(freq[5], 1);
  
} /* test_find_min_max_maximum_num */
