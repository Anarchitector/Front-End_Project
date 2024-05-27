/*
  Name:        main.c

  Purpose:     The program reads a long and prints the sum of its digits.

*/
#include <stdio.h>
#include <stdlib.h>
#include "sum.h"

int main()
{
  long number;

  printf("Enter the number: ");
  scanf("%ld", &number);

  printf("The sum of %ld digits is %ld", number, sum_of_digits(number));

  return 0;
} /* main */
