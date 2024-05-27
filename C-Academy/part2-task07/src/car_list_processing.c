/*
  Name:      car_list_processing.c

  Purpose:   contain functions to processig car list data
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "car_list_processing.h"

/*
  Name:     display_main_menu

  Purpose:  to display main menu

  Returns:  menu input number entered by user. The function only returns value from 1 to 4
*/
int display_main_menu()
{
  int menu_input = 0;

  do
  {
    system("clear");
    printf("\n********************************* MAIN MENU *********************************");
    printf("\n");
    printf("\n1. Add new car");
    printf("\n2. Display cars ordered by power");
    printf("\n3. Display cars from year");
    printf("\n4. Exit");
    printf("\n\n> ");
    scanf("%d", &menu_input);
  } while ((menu_input < 1) ||
           (menu_input > 4));

  return menu_input;
} /* display_main_menu */

/*
  Name:     add_new_car

  Purpose:  to add a new car in a list

  Params:   IN cars       - a list of cars
            IN cars_cnt   - number of added cars in a list
            IN user_input - parameters of car that the user will enter

  Returns:  Nothing
*/
void add_new_car(car *cars, int *cars_cnt, car user_input)
{
  system("clear");
  printf("\n********************************** ADD CAR **********************************");
  printf("\n");
  printf("Enter number of seats: ");
  scanf("%d", &user_input.seats);
  printf("Enter value of power: ");
  scanf("%d", &user_input.power);
  printf("Enter brand: ");
  scanf("%s", user_input.brand);
  printf("Enter color: ");
  scanf("%s", user_input.color);
  printf("Enter year: ");
  scanf("%d", &user_input.year);

  switch(add_cars(cars, cars_cnt, user_input))
  {
    case 1 :
    {
      printf("\nThe list of cars is full. Not enough space.");
      break;
    }
    case 2 :
    {
      printf("\nThe value of seats is incorrect");
      break;
    }
    case 3 :
    {
      printf("\nThe value of power is incorrect");
      break;
    }
    case 4 :
    {
      printf("\nThe value of year is incorrect");
      break;
    }
    default :
    {
      printf("\nSuccessfully added");
      *cars_cnt += 1;
      break;
    }
  }
}/* add_new_car */

/*
  Name:     add_cars

  Purpose:  to add a new car in a list

  Params:   IN cars       - a list of cars
            IN cars_cnt   - number of added cars in a list
            IN user_input - parameters of car that the user will enter and if user will enter 
                            them correctly the car will be added to a car list

  Returns:  One of the state of car_add_result
*/
int add_cars(car *cars, const int *cars_cnt, car user_input)
{
  time_t t = time(NULL);
  struct tm *tm;

  if (*cars_cnt > MAX_CARS)
  {
    return FULL_CAR_ARRAY;
  }

  if ((user_input.seats < 2) ||
      (user_input.seats > 8))
  {
    return INVALID_SEATS_PARAM;
  }
  
  if (user_input.power <= 0) 
  {
    return INVALID_POWER_PARAM;
  }

  tm = localtime(&t);
  if (user_input.year > tm->tm_year + 1900)
  {
    return INVALID_YEAR_PARAM;
  }

  *cars = user_input;

  return SUCCESS;
} /* add_cars */

/*
  Name:     order_by_power

  Purpose:  to sort cars by power in ascending

  Params:   IN  input_array   - list of cars
            IN  car_num       - number of added cars in a list
            OUT output_array  - list of cars ordered by power in ascending

  Returns:  One of the state of car_add_result
*/
void order_by_power(car *input_array, int car_num, car *output_array)
{
  int i;
  int j;
  car tmp;

  for (i = 0; i < car_num; i++)
  {
    output_array[i] = input_array[i];
  }

  for (i = 0; i < car_num - 1; i++)
  {
    for (j = 0; j < car_num - i - 1; j++)
    {
      if (output_array[j].power > output_array[j + 1].power)
      {
        tmp = output_array[j];
        output_array[j] = output_array[j + 1];
        output_array[j + 1] = tmp;
      }
    }
  }
} /* order_by_power */

/*
  Name:     filter_by_year

  Purpose:  to add a new car in a list

  Params:   IN  input_array    - list of cars
            IN  input_car_num  - number of added cars in a car list
            OUT output_array   - list of cars ordered by power in ascending
            OUT output_car_num - number of added cars in a car list filtered by year
            IN year            - Value of year entered by user

  Returns:  One of the state of car_add_result
*/
int filter_by_year(car *input_array, 
                   int input_car_num, 
                   car *output_array, 
                   int *output_car_num, 
                   int year)
{
  int i;
  *output_car_num = 0;
  
  if (input_car_num <= 0)
  {
    return NO_CARS_AT_INPUT_LIST;
  }
  for (i = 0; i < input_car_num; i++)
  {
    if (input_array[i].year == year)
    {
      output_array[*output_car_num] = input_array[i];
      *output_car_num += 1;
    }
  }

  if (*output_car_num <= 0)
  {
    return NO_CARS_AT_OUTPUT_LIST;
  }

  return SUCCESS;
} /* filter_by_year */
