/*
  Name:        main.c

  Purpose:     The program processing the arrays

*/
#include <stdio.h>
#include <stdlib.h>
#include "array_processing.h"

#define MAX_ELEMENTS 10
#define START_NUM    0

int main()
{
  int numbers[MAX_ELEMENTS] = {1, 20, 3, 4, 5, 6, 7, 6, 5, 3};
  int freq[MAX_ELEMENTS] = {0};
  min_max min_max_num;
  
  printf("The largest num of array is: %d\n", find_largest_element(numbers, MAX_ELEMENTS));

  printf("Printing using recursion : ");
  display_using_recursion(numbers, START_NUM);

  find_min_max(numbers, MAX_ELEMENTS, &min_max_num);
  printf("Minimum number of array is: %d\n", min_max_num.min);
  printf("Maximum number of array is: %d\n", min_max_num.max);
  
  if(find_duplicated(numbers, MAX_ELEMENTS))
  {
    printf("Array has a duplicate number");
  }
  else
  {
    printf("Array has no duplicate number");
  }
  
  print_unique(numbers, freq, MAX_ELEMENTS);
  
  return 0;
}

