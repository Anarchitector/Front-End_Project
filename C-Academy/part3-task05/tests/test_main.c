/*
  Name:        test_main.c

  Purpose:     File contains tests for functions decribed in server_func.c
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "../src/server_func.h"

void test_check_str(void **state);
void test_double_the_number_str(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_check_str),
    cmocka_unit_test(test_double_the_number_str)

  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}


/*
  Name:     test_check_str

  Purpose:  Test the function check_str

*/
void test_check_str(void **state)
{
  char message[] = "example string 1234";
  char number_str[] = "1234";
  str_status result;
  
  result = check_str(message);
  assert_int_equal(result, STR_IS_STR);

  result = check_str(number_str);
  assert_int_equal(result, STR_IS_NUM);
} /* test_check_str */


/*
  Name:     test_check_str

  Purpose:  Test the function double_the_number_str

*/
void test_double_the_number_str(void **state)
{
  char number_str[] = "1234";
  char result_str[] = "2468";
  
  double_the_number_str(number_str);
  assert_string_equal(result_str, number_str);
} /* test_double_the_number_str */
