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
#include <stdbool.h>
#include "../src/find_in_file.h"

void test_is_word_in_file(void **state);
void test_update_file(void **state);
void test_compare_files(void **state);
void test_replace_word_1(void **state);
void test_replace_word_2(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_is_word_in_file),
    cmocka_unit_test(test_update_file),
    cmocka_unit_test(test_replace_word_1),
    cmocka_unit_test(test_replace_word_2),
    cmocka_unit_test(test_compare_files)
    
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:     test_is_word_in_file

  Purpose:  Test the function is_word_in_file

*/
void test_is_word_in_file(void **state)
{
  char word[] = "astazi";
  int result = -1;
  
  result = is_word_in_file("tests/test1/cmp_text_file.txt", word);
  
  assert_int_equal(result, 1);
} /* test_is_word_in_file */


/*
  Name:     test_update_file

  Purpose:  Test the function update_file

*/
void test_update_file(void **state)
{
  FILE *fptr;
  char filename[] = "tests/test2/text_file.txt";
  char word[] = "today";
  int result = -1;

  fptr = fopen(filename, "w");
  fclose(fptr);

  if (is_word_in_file(filename, word))
  {
    update_file(filename, word);
  }
  result = is_word_in_file(filename, word);
  
  assert_int_equal(result, SUCCESS);
} /* test_update_file */

/*
  Name:     test_replace_word_1

  Purpose:  Test the function replace_word when old_word is less than new_word

*/
void test_replace_word_1(void **state)
{
  char filename[] = "tests/test1/cmp_text_file.txt";
  char filename_exp[] = "tests/test1/expected_text_file1.txt";
  
  char *old_word = "la";
  char *new_word = "lac";
  int result = -1;

  replace_word(filename, old_word, new_word);
  result = compare_files(filename, filename_exp);
  assert_int_equal(result, SUCCESS);
} /* test_replace_word_1 */

/*
  Name:     test_replace_word_2

  Purpose:  Test the function replace_word when old_word is larger than new_word

*/
void test_replace_word_2(void **state)
{
  char filename[] = "tests/test1/cmp_text_file.txt";
  char filename_exp[] = "tests/test1/expected_text_file2.txt";
  char *old_word = "lac";
  char *new_word = "la";
  int result = -1;

  replace_word(filename, old_word, new_word);
  result = compare_files(filename, filename_exp);
  assert_int_equal(result, SUCCESS);
} /* test_replace_word_2 */

/*
  Name:     test_compare_files

  Purpose:  Test the function compare_files

*/
void test_compare_files(void **state)
{
  char filename[] = "tests/test3/cmp_text_file.txt";
  char filename_exp[] = "tests/test3/expected_text_file.txt";
  int result;

  result = compare_files(filename, filename_exp);

  assert_int_equal(result, SUCCESS);
}
