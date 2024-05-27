/*
  Name:      test_main.c

  Purpose:   File contains tests for functions decribed in positive_and _negative.c
             that check if number is positive, negative or zero
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/positive_and_negative.h"

void test_number_determining_if_num_is_positive(void **state);
void test_number_determining_if_num_is_negative(void **state);
void test_number_determining_if_num_is_zero(void **state);
void test_number_determining_switch_num_is_positive(void **state);
void test_number_determining_switch_num_is_negative(void **state);
void test_number_determining_switch_num_is_zero(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_number_determining_if_num_is_positive),
    cmocka_unit_test(test_number_determining_if_num_is_negative),
    cmocka_unit_test(test_number_determining_if_num_is_zero),
    cmocka_unit_test(test_number_determining_switch_num_is_positive),
    cmocka_unit_test(test_number_determining_switch_num_is_negative),
    cmocka_unit_test(test_number_determining_switch_num_is_zero)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:     test_number_determining_if_num_is_positive

  Purpose:  Test the function number_determining_if for positive number

*/
void test_number_determining_if_num_is_positive(void **state)
{
  int result = number_determining_if(1);

  assert_int_equal(result, 1);
} /* void test_number_determining_if_num_is_positive(void **state) */


/*
  Name:     test_number_determining_if_num_is_negative

  Purpose:  Test the function number_determining_if for negative number

*/
void test_number_determining_if_num_is_negative(void **state)
{
  int result = number_determining_if(-1);

  assert_int_equal(result, -1);
} /* test_number_determining_if_num_is_negative */


/*
  Name:     test_number_determining_if_num_is_zero

  Purpose:  Test the function number_determining_if for zero

*/
void test_number_determining_if_num_is_zero(void **state)
{
  int result = number_determining_if(0);

  assert_int_equal(result, 0);
} /* test_number_determining_if_num_is_zero*/

/*
  Name:     test_number_determining_switch_num_is_positive

  Purpose:  Test the function number_determining_switch for positive number

*/
void test_number_determining_switch_num_is_positive(void **state)
{
  int result = number_determining_switch(1);

  assert_int_equal(result, 1);
}/* test_number_determining_switch_num_is_positive */


/*
  Name:     test_number_determining_switch_num_is_negative

  Purpose:  Test the function number_determining_switch for negative number

*/
void test_number_determining_switch_num_is_negative(void **state)
{
  int result = number_determining_switch(-1);

  assert_int_equal(result, -1);
} /* test_number_determining_switch_num_is_negative */


/*
  Name:     test_number_determining_switch_num_is_zero

  Purpose:  Test the function number_determining_switch for zero

*/
void test_number_determining_switch_num_is_zero(void **state)
{
  int result = number_determining_switch(0);

  assert_int_equal(result, 0);
} /* test_number_determining_switch_num_is_zero */
