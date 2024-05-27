/*
  Name:        test_main.c

  Purpose:     File contains tests for functions decribed in convert_symbols.c
               that convert lowercase alphabet symbols to uppercase.

*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "../src/convert_symbols.h"

void test_lowercase_to_uppercase(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_lowercase_to_uppercase)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:     test_lowercase_to_uppercase

  Purpose:  Test the function lowercase_to_uppercase

*/
void test_lowercase_to_uppercase(void **state)
{
  char result[18];
  char example[18] = "abcdEfGhI123&\n* $;";
  strcpy(result, lowercase_to_uppercase(example));
    
  assert_string_equal(result, "ABCDEFGHI123&\n* $;");
} /* test_lowercase_to_uppercase */
