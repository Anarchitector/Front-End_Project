/*
  Name:        test_main.c

  Purpose:     File contains tests for functions decribed in file_manipulation.c
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <string.h>
#include "../src/file_manipulation.h"

void test_symbols_count(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_symbols_count)

  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}


/*
  Name:     test_words_count

  Purpose:  Test the function words_count

*/
void test_symbols_count(void **state)
{
  FILE *fptr;
  int words = 0;
  int chars = 0;
  int lines = 1;
  int digits = 0;

  fptr = fopen("text_file.txt","r");
  if (fptr == NULL)
  {
    printf(" File does not exist or can not be opened.");
  }
  else
  {
    symbols_count(fptr, &words, &chars, &lines, &digits);
  }
  fclose(fptr);

  assert_int_equal(words, 10);
  assert_int_equal(chars, 63);
  assert_int_equal(lines, 1);
  assert_int_equal(digits, 4);

} /* test_symbols_count */

