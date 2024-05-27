/*
  Name:      test_main.c

  Purpose:   File contains tests for functions decribed in compute_the_sum.c
             that compute the sum of the first 'N' natural numbers
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/compute_the_sum.h"

void test_get_sum_of_natural_num_for(void **state);
void test_get_sum_of_natural_num_while(void **state);
void test_get_sum_of_natural_even_num(void **state);
void test_get_sum_of_natural_odd_num(void **state);


/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_get_sum_of_natural_num_for),
    cmocka_unit_test(test_get_sum_of_natural_num_while),
    cmocka_unit_test(test_get_sum_of_natural_even_num),
    cmocka_unit_test(test_get_sum_of_natural_odd_num)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

void test_get_sum_of_natural_num_for(void **state)
{
  int result = get_sum_of_natural_num_for(5);

  assert_int_equal(result, 15);
}

void test_get_sum_of_natural_num_while(void **state)
{
  int result = get_sum_of_natural_num_while(5);

  assert_int_equal(result, 15);
}

void test_get_sum_of_natural_even_num(void **state)
{
  int result = get_sum_of_natural_even_num(5);

  assert_int_equal(result, 6);
}

void test_get_sum_of_natural_odd_num(void **state)
{
  int result = get_sum_of_natural_odd_num(5);

  assert_int_equal(result, 9);
}

