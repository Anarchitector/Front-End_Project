/*
  Name:        test_main.c

  Purpose:     File contains tests for functions decribed in car_list_processing.c

*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../src/car_list_processing.h"

void test_add_cars(void **state);
void test_order_by_power(void **state);
void test_filter_by_year(void **state);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
int main()
{

  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_add_cars),
    cmocka_unit_test(test_order_by_power),
    cmocka_unit_test(test_filter_by_year)    

  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}


/*
  Name:     test_add_cars

  Purpose:  test the function add_cars

*/
void test_add_cars(void **state)
{
  car my_car;
  int cars_cnt = 1;
  int full_cars_cnt = 101;
  car cars[cars_cnt];
  car full_cars[full_cars_cnt];
  time_t t = time(NULL);
  struct tm *tm;
  tm = localtime(&t);
  int result;
  
  my_car.seats = 5;
  my_car.power = 1000;
  my_car.year = tm->tm_year + 1900;
  result = add_cars(full_cars, &full_cars_cnt, my_car);
  assert_int_equal(result, FULL_CAR_ARRAY);

  my_car.seats = 5;
  my_car.power = 1000;
  my_car.year = tm->tm_year + 1900;
  result = add_cars(cars, &cars_cnt, my_car);
  assert_int_equal(result, SUCCESS);

  my_car.year = tm->tm_year + 1901;
  result = add_cars(cars, &cars_cnt, my_car);
  assert_int_equal(result, INVALID_YEAR_PARAM);

  my_car.seats = 1;
  result = add_cars(cars, &cars_cnt, my_car);
  assert_int_equal(result, INVALID_SEATS_PARAM);

  my_car.seats = 9;
  result = add_cars(cars, &cars_cnt, my_car);
  assert_int_equal(result, INVALID_SEATS_PARAM);

  my_car.seats = 5;
  my_car.power = 0;
  result = add_cars(cars, &cars_cnt, my_car);
  assert_int_equal(result, INVALID_POWER_PARAM);

  my_car.power = -1;
  result = add_cars(cars, &cars_cnt, my_car);
  assert_int_equal(result, INVALID_POWER_PARAM);
} /* test_add_cars */

/*
  Name:     test_order_by_power

  Purpose:  test the function order_by_power

*/
void test_order_by_power(void **state)
{
  int i;
  const int cars_cnt = 3;
  car input_array[cars_cnt];
  car output_array[cars_cnt];
  car result_array[cars_cnt];

  input_array[0].power = 200;
  input_array[1].power = 180;
  input_array[2].power = 250;

  result_array[0].power = 180;
  result_array[1].power = 200;
  result_array[2].power = 250;

  order_by_power(input_array, cars_cnt, output_array);

  for (i = 0; i < cars_cnt; i++)
  {
    assert_int_equal(result_array[i].power, output_array[i].power);
  }
  
} /* test_order_by_power */

/*
  Name:     test_filter_by_year

  Purpose:  test the function filter_by_year

*/
void test_filter_by_year(void **state)
{
  int i;
  int result;
  int cars_cnt = 4;
  int filter_cnt = 0;
  int exp_filter_cnt = 2;
  car input_array[cars_cnt];
  car output_array[cars_cnt];
  car result_array[2];
  int year = 2003;
  
  input_array[0].year = 2003;
  input_array[1].year = 2005;
  input_array[2].year = 2003;
  input_array[3].year = 1999;

  result_array[0].year = 2003;
  result_array[1].year = 2003;
  
  result = filter_by_year(input_array, cars_cnt, output_array, &filter_cnt, year);
  assert_int_equal(result, SUCCESS);
  
  assert_int_equal(exp_filter_cnt, filter_cnt);
  for (i = 0; i < filter_cnt; i++)
  {
    assert_int_equal(result_array[i].year, output_array[i].year);
  }
    
  year = 2010;
  filter_cnt = 0;
  exp_filter_cnt = 0;
  result = filter_by_year(input_array, cars_cnt, output_array, &filter_cnt, year);
  assert_int_equal(result, NO_CARS_AT_OUTPUT_LIST);
  assert_int_equal(exp_filter_cnt, filter_cnt);

  cars_cnt = 0;
  result = filter_by_year(input_array, cars_cnt, output_array, &filter_cnt, year);
  assert_int_equal(result, NO_CARS_AT_INPUT_LIST);
  assert_int_equal(exp_filter_cnt, filter_cnt);
} /* test_filter_by_year */
