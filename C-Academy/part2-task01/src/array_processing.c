/*
  Name:      array_processing.c

  Purpose:   File contain functions to processing array of numbers    
*/

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "array_processing.h"

#define MAX_ELEMENTS 10

/*
  Name:     find_largest_element

  Purpose:  find the largest element of array

  Params:   IN  - *numbers     - pointer to an array of numbers
            IN  - max_elements - maximum

  Returns:  The largest element of array
*/
int find_largest_element(int *numbers, int max_elements)
{
  int larg = INT_MIN;
  int cnt;

  for (cnt = 0; cnt < max_elements; cnt++)
  {
    if (numbers[cnt] > larg)
    {
      larg = numbers[cnt];
    }
  }
  
  return larg;
} /* find_largest_element */

/*
  Name:     display_using_recursion

  Purpose:  display the lements of array using recursion

  Params:   IN  - *numbers     - pointer to an array of numbers
            IN  - array_num    - total elements of array

  Returns:  display the elements of array using recursion
*/
void display_using_recursion(int *numbers, int array_num)
{
  if(array_num < 0)
  {
    return;
  }
    printf("%d ", numbers[array_num]);
    display_using_recursion(numbers, array_num - 1);
} /* display_using_recursion */

/*
  Name:     find_min_max

  Purpose:  find the minimum adn maximum of array

  Params:   IN  - *numbers     - pointer to an array of numbers
            IN  - max_elements - maximum elements of array
            OUT - min_max_num  - the structure which contain minimum and maximum values of array

  Returns:  the structure which contain minimum and maximum values of array
*/
void find_min_max(int* numbers, int max_elements, min_max* min_max_num)
{
  min_max_num->min = INT_MAX;
  min_max_num->max = INT_MIN;

  for(int i = 0; i < max_elements; i++)
  {
    if (numbers[i] < min_max_num->min)
    {
      min_max_num->min = numbers[i];
    }
    if (numbers[i] > min_max_num->max)
    {
      min_max_num->max = numbers[i];
    }
  }
} /* find_max_and_min */

/*
  Name:     find_duplicated

  Purpose:  find the duplicated numbers

  Params:   IN  - *numbers     - pointer to an array of numbers
            IN  - max_elements - maximum elements of array

  Returns:  TRUE if array contain duplicated number or FALSE if not
*/
bool find_duplicated(int *numbers, int max_elements)
{
  int i = 0;
  int j = 0;
  
  for (i = 0; i < max_elements; i++)
  {
    for(j = i + 1; j < max_elements; j++)
    {
      if (numbers[i] == numbers[j])
      {
        return true;
      }
    }
  }
  return false;
} /* find_duplicated */

/*
  Name:     print_unique

  Purpose:  find the duplicated numbers

  Params:   IN  - *numbers     - pointer to an array of numbers
            OUT - *freq        - pointer to an array which captures 
                                 the number of elements in array "numbers"
            IN  - max_elements - maximum elements of array


  Returns:  print the unique elements of array
*/
void print_unique(int* numbers, int* freq, int max_elements)
{
  int i;
  int j;
  
  for(i = 0; i < max_elements; i++)
  {
    for(j = i + 1; j < max_elements; j++)
    {
      if(numbers[i] == numbers[j])
      {
        freq[i] = 1;
        freq[j] = 1;
        break;
      }
    }
  }

  printf("\nUnique elements in the array are: ");
  for(i = 0; i < max_elements; i++)
  {
    if(freq[i] == 0)
    {
      printf("%d ", numbers[i]);
    }
  }
} /* print_unique */
