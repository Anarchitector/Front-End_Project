/*
  Name:        test_main.c

  Purpose:     File contains tests for functions decribed in greater_age.c

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
#include "../src/greater_age.h"

void test_whose_age_is_greater_first_p(void **state);
void test_whose_age_is_greater_second_p(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_whose_age_is_greater_first_p),
    cmocka_unit_test(test_whose_age_is_greater_second_p),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:     test_whose_age_is_greater_first_p

  Purpose:  Test the function whose_age_is_greater when first person has greater age

*/
void test_whose_age_is_greater_first_p(void **state)
{
  person* result;

  person tom_hall;
  tom_hall.name = "Tom Hall";
  tom_hall.age = 56;

  person john_romero;
  john_romero.name = "John Romero";
  john_romero.age = 52;

  result = whose_age_is_greater(&tom_hall, &john_romero);

  printf("%s has greater age: %d\n", result->name, result->age);

  assert_string_equal(result->name, "Tom Hall");
  assert_int_equal(result->age, 56);
} /* test_whose_age_is_greater */

/*
  Name:     test_whose_age_is_greater_second_p

  Purpose:  Test the function whose_age_is_greater when second person has greater age

*/
void test_whose_age_is_greater_second_p(void **state)
{
  person* result;

  person john_carmack;
  john_carmack.name = "John Carmack";
  john_carmack.age = 50;

  person john_romero;
  john_romero.name = "John Romero";
  john_romero.age = 52;

  result = whose_age_is_greater(&john_carmack, &john_romero);
  printf("%s has greater age: %d\n", result->name, result->age);
  assert_string_equal(result->name, "John Romero");
  assert_int_equal(result->age, 52);
} /* test_whose_age_is_greater */
