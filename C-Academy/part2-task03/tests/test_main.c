/*
  Name:       test_main.c

  Purpose:    File contains tests for functions decribed in count_symbols.c
              that counts alphabets, numbers and special symbols.

*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/count_symbols.h"

void test_count_alphabet(void **state);
void test_count_numbers(void **state);
void test_count_specials(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_count_alphabet),
    cmocka_unit_test(test_count_numbers),
    cmocka_unit_test(test_count_specials)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}


/*
  Name:     void test_count_alphabet(void **state)

  Purpose:  Test the function count_alphabet for counting alphabets in the string

*/
void test_count_alphabet(void **state)
{
  int result = count_alphabet("abcdEFG 123 !#*>");

  assert_int_equal(result, 7);
} /* test_count_alphabet */


/*
  Name:     test_count_numbers

  Purpose:  Test the function count_numbers for counting numbers in the string

*/
void test_count_numbers(void **state)
{
  int result = count_numbers("abcdEFG 123 !#*>");

  assert_int_equal(result, 3);
} /* test_count_numbers */


/*
  Name:     test_count_specials

  Purpose:  Test the function count_specials 
            for counting special symbols in the string (without spaces)

*/
void test_count_specials(void **state)
{
  int result = count_specials("abcdEFG 123 !#*>");

  assert_int_equal(result, 4);
} /* test_count_specials */
