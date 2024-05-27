/*
  Name:        test_main.c

  Purpose:     File contains the tests for testing functions described in triangle.c
               that check if triangle can be formed

*/


#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/triangle.h"

void test_triangle_angles_sum_180(void **state);
void test_triangle_angles_sum_lt_180(void **state);
void test_triangle_angles_sum_gt_180(void **state);
void test_triangle_angles_zero_angle(void **state);
void test_triangle_angles_negative_angle(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_triangle_angles_sum_180),
    cmocka_unit_test(test_triangle_angles_sum_lt_180),
    cmocka_unit_test(test_triangle_angles_sum_gt_180),
    cmocka_unit_test(test_triangle_angles_zero_angle),
    cmocka_unit_test(test_triangle_angles_negative_angle)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

void test_triangle_angles_sum_180(void **state)
{
  bool result = triangle_angles(60, 45, 75);

  assert_int_equal(result, true);
} /* test_triangle_angles_sum_180 */

void test_triangle_angles_sum_lt_180(void **state)
{
  bool result = triangle_angles(45, 45, 80);

  assert_int_equal(result, false);
} /* test_triangle_angles_sum_lt_180 */

void test_triangle_angles_sum_gt_180(void **state)
{
  bool result = triangle_angles(60, 90, 80);

  assert_int_equal(result, false);
} /* test_triangle_angles_sum_gt_180 */

void test_triangle_angles_zero_angle(void **state)
{
  bool result = triangle_angles(120, 60, 0);

  assert_int_equal(result, false);
} /* test_triangle_angles_zero_angle */

void test_triangle_angles_negative_angle(void **state)
{
  bool result = triangle_angles(90, 120, -30);

  assert_int_equal(result, false);
} /* test_triangle_angles_negative_angle */
