/*
  Name:        int_list.c

  Purpose:     File contains tests for functions decribed in int_list.c
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <string.h>
#include "../src/int_list.h"

void test_list_integers(void **state);
void test_list_integers_reversed(void **state);
void test_list_integers_ascending(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_list_integers),
    cmocka_unit_test(test_list_integers_reversed),
    cmocka_unit_test(test_list_integers_ascending)

  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}


/*
  Name:     test_list_integers

  Purpose:  Test the function list_integers

*/
void test_list_integers(void **state)
{
  int int_ptr[5] = {1,2,3,4,5};
    
  list_integers(int_ptr, 5);

} /* test_list_integers */

/*
  Name:     test_list_integers_reversed

  Purpose:  Test the function list_integers_reversed

*/
void test_list_integers_reversed(void **state)
{
  int int_ptr[5] = {1,2,3,4,5};
  
  list_integers_reversed(int_ptr, 5);

} /* test_list_integers_reversed */

/*
  Name:     test_list_integers_ascending

  Purpose:  Test the function list_integers_ascending

*/
void test_list_integers_ascending(void **state)
{
  int int_ptr[5] = {3,4,2,1,4};
  int example[5] = {1,2,3,4,4};
  int result[5];
  int i;
  
  list_integers_ascending(int_ptr, result, 5);

  for (i = 0; i < 5; i++)
  {
    assert_int_equal(result[i], example[i]);
  }

} /* test_list_integers_ascending */
