/*
  Name:        test_main.c

  Purpose:     File contains tests for functions decribed in string_manipulation.c
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <string.h>
#include "../src/string_manipulation.h"

void test_s_len(void **state);
void test_find_char(void **state);
void test_find_char_no_letter(void **state);
void test_trim_vowel(void **state);
void test_if_string_is_palindrome_true(void **state);
void test_if_string_is_palindrome_false(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_s_len),
    cmocka_unit_test(test_find_char),
    cmocka_unit_test(test_find_char_no_letter),
    cmocka_unit_test(test_trim_vowel),
    cmocka_unit_test(test_if_string_is_palindrome_true),
    cmocka_unit_test(test_if_string_is_palindrome_false)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}


/*
  Name:     test_s_len

  Purpose:  Test the function s_len

*/
void test_s_len(void **state)
{
  char* str = "This is an example string of part2-task09";
  int result = 0;
  
  result = s_len(str);

  assert_int_equal(result, 41);
} /* test_s_len */

/*
  Name:     test_find_char

  Purpose:  Test the function find_char

*/
void test_find_char(void **state)
{
  char* str = "This is an example string of part2-task09";
  char* result;
  char letter = 'a';

  result = find_char(letter, str, strlen(str));
  
  assert_int_equal(*result, 'a');
} /* test_find_char */

/*
  Name:     test_find_char

  Purpose:  Test the function find_char when letter non-exist in a string

*/
void test_find_char_no_letter(void **state)
{
  char* str = "This is an example string of part2-task09";
  char* result;
  char letter = 'z';

  result = find_char(letter, str, strlen(str));
  
  assert_int_equal(result, NULL);
} /* test_find_char */

/*
  Name:     test_trim_vowel

  Purpose:  Test the function trim_vowel

*/
void test_trim_vowel(void **state)
{
  char* str = "This is an example string of part2-task09";
  char* result = (char*)malloc(strlen(str)*sizeof(char));

  trim_vowel(str, result);

  assert_string_equal(result, "Ths s n xmpl strng f prt2-tsk09");
  free(result);
} /* test_trim_vowel */

/*
  Name:     test_if_string_is_palindrome_true

  Purpose:  Test the function is_palindrome when string is palindrome

*/
void test_if_string_is_palindrome_true(void **state)
{
  char* str = "abcdefgfedcba";
  int result = 0;

  result = is_palindrome(str);

  assert_int_equal(result, 1);
} /* test_if_string_is_palindrome_true */

/*
  Name:     test_if_string_is_palindrome_false

  Purpose:  Test the function is_palindrome when string is not palindrome

*/
void test_if_string_is_palindrome_false(void **state)
{
  char* str = "this is";
  int result = 0;

  result = is_palindrome(str);

  assert_int_equal(result, 0);
} /* test_if_string_is_palindrome_false */
