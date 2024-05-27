/*
  Name:   main.c

  Purpose:  Check if number is positive, negative or zero

*/

#include <stdio.h>
#include <stdlib.h>
#include "positive_and_negative.h"


int main()
{
  int number;

  printf("Enter the number: ");
  scanf("%d", &number);

  printf("The number is %d", number_determining_if(number));
  printf("\n");
  printf("The number is %d", number_determining_switch(number));

  return 0;
} /* main */
