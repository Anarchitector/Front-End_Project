/*
  Name:        test_main.c

  Purpose:     File contains tests for functions decribed in students.c

*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <string.h>
#include "../src/students.h"

void test_sort_by_descending(void **state);
void test_calculate_the_mean(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_sort_by_descending),
    cmocka_unit_test(test_calculate_the_mean)

  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}


/*
  Name:     test_sort_by_descending

  Purpose:  Test the function add_two_fractions for numerator

*/
void test_sort_by_descending(void **state)
{
  student list[4];
  
  strncpy(list[0].name, "John", 5);
  strncpy(list[0].surname, "Romero", 7);
  list[0].grade = 9;

  strncpy(list[1].name, "John", 5);
  strncpy(list[1].surname, "Carmack", 8);
  list[1].grade = 10;

  strncpy(list[2].name, "Tom", 4);
  strncpy(list[2].surname, "Hall", 5);
  list[2].grade = 7;

  strncpy(list[3].name, "Adrian", 7);
  strncpy(list[3].surname, "Carmack", 8);
  list[3].grade = 8;

  float result = 0;

  result = calculate_the_mean(list, sizeof(list)/sizeof(list[0]));
  printf("%f ", result);

  printf("\nList of students:");
  display_the_list_of_students(list, sizeof(list)/sizeof(list[0]));
  printf("\n\nList of promoted students:");
  display_the_promoted_student(list, sizeof(list)/sizeof(list[0]));
  sort_by_descending(list, sizeof(list)/sizeof(list[0]));
  printf("\nAfter sorting by descending");
  display_the_promoted_student(list, sizeof(list)/sizeof(list[0]));

} /* test_sort_by_descending */

/*
  Name:     test_calculate_the_mean

  Purpose:  Test the function calculate_the_mean

*/
void test_calculate_the_mean(void **state)
{
  student list[4];

  strncpy(list[0].name, "John", 5);
  strncpy(list[0].surname, "Romero", 7);
  list[0].grade = 9;

  strncpy(list[1].name, "John", 5);
  strncpy(list[1].surname, "Carmack", 8);
  list[1].grade = 10;

  strncpy(list[2].name, "Tom", 4);
  strncpy(list[2].surname, "Hall", 5);
  list[2].grade = 7;

  strncpy(list[3].name, "Adrian", 7);
  strncpy(list[3].surname, "Carmack", 8);
  list[3].grade = 8;

  float result = 0;

  result = calculate_the_mean(list, sizeof(list)/sizeof(list[0]));
  printf("%f ", result);

  assert_float_equal(result, 8.5, 1);

} /* test_calculate_the_mean */
