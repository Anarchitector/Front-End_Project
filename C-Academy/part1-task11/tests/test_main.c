/*
  Name:      test_main.c

  Purpose:   File contains tests for functions decribed in check_eligibility.c
             that check the sum of the first 'N' natural numbers
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/check_eligibility.h"

void test_check_eligibility_1(void **state);
void test_check_eligibility_2(void **state);
void test_check_eligibility_3(void **state);
void test_check_eligibility_4(void **state);
void test_check_eligibility_5(void **state);


/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_check_eligibility_1),
    cmocka_unit_test(test_check_eligibility_2),
    cmocka_unit_test(test_check_eligibility_3),
    cmocka_unit_test(test_check_eligibility_4),
    cmocka_unit_test(test_check_eligibility_5)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

void test_check_eligibility_1(void **state)
{
  bool result = check_eligibility(60, 50, 40);

  assert_int_equal(result, false);
}

void test_check_eligibility_2(void **state)
{
  bool result = check_eligibility(65, 55, 50);

  assert_int_equal(result, false);
}


void test_check_eligibility_3(void **state)
{
  bool result = check_eligibility(70, 70, 50);

  assert_int_equal(result, true);
}

void test_check_eligibility_4(void **state)
{
  bool result = check_eligibility(70, 60, 40);

  assert_int_equal(result, false);
}

void test_check_eligibility_5(void **state)
{
  bool result = check_eligibility(65, 55, 70);

  assert_int_equal(result, true);
}

